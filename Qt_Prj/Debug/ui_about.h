/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_about
{
public:
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QLabel *label_8;
    QVBoxLayout *verticalLayout_5;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *lbe_sub;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *lbe_sub_2;
    QLabel *label_9;

    void setupUi(QDialog *about)
    {
        if (about->objectName().isEmpty())
            about->setObjectName(QStringLiteral("about"));
        about->resize(495, 391);
        verticalLayout_6 = new QVBoxLayout(about);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_6 = new QLabel(about);
        label_6->setObjectName(QStringLiteral("label_6"));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(15);
        label_6->setFont(font);
        label_6->setWordWrap(true);

        verticalLayout_2->addWidget(label_6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_4 = new QLabel(about);
        label_4->setObjectName(QStringLiteral("label_4"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(13);
        label_4->setFont(font1);
        label_4->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(label_4);

        label_8 = new QLabel(about);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font1);
        label_8->setStyleSheet(QStringLiteral("color: rgb(0, 0, 255);"));
        label_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(label_8);


        horizontalLayout->addLayout(verticalLayout);

        horizontalLayout->setStretch(0, 4);
        horizontalLayout->setStretch(1, 30);

        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout_2->setStretch(0, 4);
        verticalLayout_2->setStretch(1, 9);

        verticalLayout_6->addLayout(verticalLayout_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label = new QLabel(about);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(613, 461));
        label->setFont(font);

        verticalLayout_5->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        lbe_sub = new QLabel(about);
        lbe_sub->setObjectName(QStringLiteral("lbe_sub"));
        lbe_sub->setStyleSheet(QStringLiteral("image: url(:/QRCode/my_sub.jpg);"));
        lbe_sub->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_3->addWidget(lbe_sub);

        label_3 = new QLabel(about);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_3);

        verticalLayout_3->setStretch(0, 7);
        verticalLayout_3->setStretch(1, 2);

        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        lbe_sub_2 = new QLabel(about);
        lbe_sub_2->setObjectName(QStringLiteral("lbe_sub_2"));
        lbe_sub_2->setStyleSheet(QStringLiteral("image: url(:/QRCode/my_blog.jpg);"));

        verticalLayout_4->addWidget(lbe_sub_2);

        label_9 = new QLabel(about);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font1);
        label_9->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_9);

        verticalLayout_4->setStretch(0, 7);
        verticalLayout_4->setStretch(1, 2);

        horizontalLayout_2->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout_2);

        verticalLayout_5->setStretch(0, 1);
        verticalLayout_5->setStretch(1, 5);

        verticalLayout_6->addLayout(verticalLayout_5);

        verticalLayout_6->setStretch(0, 4);
        verticalLayout_6->setStretch(1, 8);

        retranslateUi(about);

        QMetaObject::connectSlotsByName(about);
    } // setupUi

    void retranslateUi(QDialog *about)
    {
        about->setWindowTitle(QApplication::translate("about", "Dialog", Q_NULLPTR));
        label_6->setText(QApplication::translate("about", "\351\200\232\350\256\257\345\215\217\350\256\256", Q_NULLPTR));
        label_4->setText(QApplication::translate("about", "\344\270\213\345\217\221\346\240\274\345\274\217\357\274\232R+\346\225\260\345\200\274+G+\346\225\260\345\200\274+B+\346\225\260\345\200\274+*", Q_NULLPTR));
        label_8->setText(QApplication::translate("about", "  \347\244\272\344\276\213\357\274\232R10G123B7*, R255G25B119*", Q_NULLPTR));
        label->setText(QApplication::translate("about", "\345\205\263\344\272\216\346\210\221", Q_NULLPTR));
        lbe_sub->setText(QString());
        label_3->setText(QApplication::translate("about", "\346\210\221\347\232\204\345\205\254\344\274\227\345\217\267", Q_NULLPTR));
        lbe_sub_2->setText(QString());
        label_9->setText(QApplication::translate("about", "\346\210\221\347\232\204\345\215\232\345\256\242", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class about: public Ui_about {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
