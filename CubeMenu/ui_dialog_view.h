/********************************************************************************
** Form generated from reading UI file 'dialog_view.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_VIEW_H
#define UI_DIALOG_VIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_view
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QDoubleSpinBox *EyesXSpinBox;
    QLabel *label_3;
    QDoubleSpinBox *EyesYSpinBox;
    QDoubleSpinBox *EyesZSpinBox;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QLabel *label_5;
    QDoubleSpinBox *directXSpinBox;
    QLabel *label_6;
    QDoubleSpinBox *directYSpinBox;
    QDoubleSpinBox *directZSpinBox;

    void setupUi(QDialog *Dialog_view)
    {
        if (Dialog_view->objectName().isEmpty())
            Dialog_view->setObjectName(QStringLiteral("Dialog_view"));
        Dialog_view->resize(400, 300);
        buttonBox = new QDialogButtonBox(Dialog_view);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        gridLayoutWidget = new QWidget(Dialog_view);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 50, 160, 80));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        EyesXSpinBox = new QDoubleSpinBox(gridLayoutWidget);
        EyesXSpinBox->setObjectName(QStringLiteral("EyesXSpinBox"));

        gridLayout->addWidget(EyesXSpinBox, 0, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        EyesYSpinBox = new QDoubleSpinBox(gridLayoutWidget);
        EyesYSpinBox->setObjectName(QStringLiteral("EyesYSpinBox"));

        gridLayout->addWidget(EyesYSpinBox, 1, 1, 1, 1);

        EyesZSpinBox = new QDoubleSpinBox(gridLayoutWidget);
        EyesZSpinBox->setObjectName(QStringLiteral("EyesZSpinBox"));

        gridLayout->addWidget(EyesZSpinBox, 2, 1, 1, 1);

        gridLayoutWidget_2 = new QWidget(Dialog_view);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(210, 50, 160, 80));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(gridLayoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        directXSpinBox = new QDoubleSpinBox(gridLayoutWidget_2);
        directXSpinBox->setObjectName(QStringLiteral("directXSpinBox"));

        gridLayout_2->addWidget(directXSpinBox, 0, 1, 1, 1);

        label_6 = new QLabel(gridLayoutWidget_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_6, 2, 0, 1, 1);

        directYSpinBox = new QDoubleSpinBox(gridLayoutWidget_2);
        directYSpinBox->setObjectName(QStringLiteral("directYSpinBox"));

        gridLayout_2->addWidget(directYSpinBox, 1, 1, 1, 1);

        directZSpinBox = new QDoubleSpinBox(gridLayoutWidget_2);
        directZSpinBox->setObjectName(QStringLiteral("directZSpinBox"));

        gridLayout_2->addWidget(directZSpinBox, 2, 1, 1, 1);


        retranslateUi(Dialog_view);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog_view, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog_view, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog_view);
    } // setupUi

    void retranslateUi(QDialog *Dialog_view)
    {
        Dialog_view->setWindowTitle(QApplication::translate("Dialog_view", "Dialog", 0));
        label_2->setText(QApplication::translate("Dialog_view", "Eyes.Y", 0));
        label->setText(QApplication::translate("Dialog_view", "Eyes.X", 0));
        label_3->setText(QApplication::translate("Dialog_view", "Eyes.Z", 0));
        label_4->setText(QApplication::translate("Dialog_view", "Direct.Y", 0));
        label_5->setText(QApplication::translate("Dialog_view", "Direct.X", 0));
        label_6->setText(QApplication::translate("Dialog_view", "Direct.Z", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog_view: public Ui_Dialog_view {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_VIEW_H
