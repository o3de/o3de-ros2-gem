/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>

#include "RobotImporter/RobotImporterWidget.h"

#include <AzCore/Utils/Utils.h>

namespace ROS2
{
    namespace Internal
    {
        AZStd::optional<QString> QueryUserForPath(
            const AZStd::string& extensionDescription, QFileDialog::FileMode mode, QWidget* parent = nullptr)
        {
            QFileDialog importFileDialog(parent);
            importFileDialog.setDirectory(AZ::Utils::GetProjectPath().c_str());
            importFileDialog.setFileMode(mode);
            importFileDialog.setNameFilter(QObject::tr(extensionDescription.c_str()));
            importFileDialog.setViewMode(QFileDialog::Detail);

            int result = importFileDialog.exec();
            if (result != QDialog::DialogCode::Accepted)
            {
                return AZStd::nullopt;
            }

            return importFileDialog.selectedFiles().first();
        }

        ExistingPrefabAction QueryUserForExistingPrefabAction(QWidget* parent = nullptr)
        {
            QMessageBox msgBox(parent);
            msgBox.setWindowTitle(QObject::tr("Prefab file exists"));
            msgBox.setText(QObject::tr("The prefab file already exists."));
            msgBox.setInformativeText(QObject::tr("Do you want to overwrite it or save it with another file name?"));
            msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
            msgBox.setDefaultButton(QMessageBox::Discard);
            msgBox.setButtonText(QMessageBox::Save, QObject::tr("Overwrite"));
            msgBox.setButtonText(QMessageBox::Discard, QObject::tr("Save As..."));

            switch (msgBox.exec())
            {
            case QMessageBox::Save:
                return ExistingPrefabAction::Overwrite;
            case QMessageBox::Discard:
                return ExistingPrefabAction::CreateWithNewName;
            default:
                return ExistingPrefabAction::Cancel;
            }
        }
    } // namespace Internal

    RobotImporterWidget::RobotImporterWidget(QWidget* parent)
        : QWidget(parent)
        , m_statusLabel("", this)
        , m_robotImporter(*this)
    {
        setWindowTitle(QObject::tr("Robot definition file importer"));
        QVBoxLayout* mainLayout = new QVBoxLayout(this);
        mainLayout->setSpacing(20);
        QLabel* captionLabel = new QLabel(QObject::tr("Select a robot definition (URDF) file to import"), this);
        captionLabel->setWordWrap(true);
        mainLayout->addWidget(captionLabel);
        QPushButton* selectFileButton = new QPushButton(QObject::tr("Load"), this);
        mainLayout->addWidget(selectFileButton);
        mainLayout->addWidget(&m_statusLabel);
        mainLayout->addStretch();

        QObject::connect(
            selectFileButton,
            &QPushButton::clicked,
            this,
            [&robotImporter = m_robotImporter]()
            {
                robotImporter.Import();
            });
        setLayout(mainLayout);
    }

    void RobotImporterWidget::ReportError(const AZStd::string& errorMessage)
    {
        QMessageBox::critical(this, QObject::tr("Error"), QObject::tr(errorMessage.c_str()));
        m_statusLabel.setText(errorMessage.c_str());
        AZ_Error("RobotImporterWidget", false, errorMessage.c_str());
    }

    void RobotImporterWidget::ReportInfo(const AZStd::string& infoMessage)
    {
        m_statusLabel.setText(QObject::tr(infoMessage.c_str()));
        AZ_TracePrintf("RobotImporterWidget", infoMessage.c_str());
    }

    AZStd::optional<AZStd::string> RobotImporterWidget::GetURDFPath()
    {
        std::optional<QString> path = Internal::QueryUserForPath("Unified Robot Description Format (*.urdf)", QFileDialog::ExistingFiles);
        if (!path)
        {
            return AZStd::nullopt;
        }

        if (path->isEmpty())
        {
            QMessageBox::critical(this, QObject::tr("Empty path provided"), QObject::tr("No path was provided. Please try again"));
            return GetURDFPath();
        }

        if (!QFile::exists(path.value()))
        {
            QMessageBox::critical(this, QObject::tr("Does not exist"), QObject::tr("Provided path does not exist. Please try again"));
            return GetURDFPath();
        }

        return path->toStdString().c_str();
    }

    AZStd::optional<AZStd::string> RobotImporterWidget::ValidatePrefabPathExistenceAndGetNewIfNecessary(const AZStd::string& path)
    {
        if (!QFile::exists(path.c_str()))
        {
            return path;
        }

        switch (Internal::QueryUserForExistingPrefabAction(this))
        {
        case ExistingPrefabAction::Cancel:
            return AZStd::nullopt;
        case ExistingPrefabAction::Overwrite:
            return path;
        case ExistingPrefabAction::CreateWithNewName:
            // I am aware that similar functionality might be available by QFileDialog::setAcceptMode
            // However, the prompt to confirm the overwrite showed up under the file selection dialog, which made a terrible UX
            // TODO: It should be fixed at some point in the future
            AZStd::optional<QString> newPathCandidate = Internal::QueryUserForPath("Prefab (*.prefab)", QFileDialog::AnyFile);
            if (!newPathCandidate || newPathCandidate->isEmpty())
            {
                return AZStd::nullopt;
            }
            return ValidatePrefabPathExistenceAndGetNewIfNecessary(newPathCandidate.value().toStdString().c_str());
        }
    }

} // namespace ROS2
