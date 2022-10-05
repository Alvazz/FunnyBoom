#include "stttopsideframe.h"
#include <QVBoxLayout>
#include "sttbuttondocker.h"


STTTopSideFrame::STTTopSideFrame(QWidget *parent)
    : KNSQFrame(parent)
{
//    setMinimumHeight(430);
    setContentsMargins(0,0,0,0);
    setStyleSheet("QFrame{background-color: green; } QFrame:focus:pressed{background-color: blue;}");
    setFocusPolicy(Qt::ClickFocus);
    initUI();


}

STTTopSideFrame::~STTTopSideFrame(){}

void STTTopSideFrame::initUI()
{

    QVBoxLayout *mainVLayout = new QVBoxLayout();
    QHBoxLayout *topAreaHLayout = new QHBoxLayout();
    QHBoxLayout *previewAreaHLayout = new QHBoxLayout();
    QGridLayout *previewAreaGLayout = new QGridLayout();


    deviceBtn = new QPushButton();
    deviceBtn->setText(tr("device"));

    topAreaHLayout->addWidget(deviceBtn);

    profileBtn = new QPushButton();
    profileBtn->setText("profile");

    topAreaHLayout->addWidget(profileBtn);

    storeBtn = new QPushButton();
    storeBtn->setText("store");
    topAreaHLayout->addWidget(storeBtn);

    settingBtn = new QPushButton();
    settingBtn->setText("store");
    topAreaHLayout->addWidget(settingBtn);

    mainVLayout->addLayout(topAreaHLayout);
    QSpacerItem *spacerTopAreaItem = new QSpacerItem(0,0, QSizePolicy::Fixed, QSizePolicy::Fixed);
    mainVLayout->addSpacerItem(spacerTopAreaItem);


    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            STTButtonDocker *testBtnDocker = new STTButtonDocker(this);

            previewAreaGLayout->addWidget(testBtnDocker, i + 1, j + 1);

            // ...

        }
    }

    // Vertical spacers
//    previewAreaGLayout->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding), 0, 0, 1, 3 + 2);
//    previewAreaGLayout->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding), 3 + 1, 0, 1, 3 + 2);

//    // Horizontal spacers
//    previewAreaGLayout->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum), 1, 0, 3, 1);
//    previewAreaGLayout->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum), 1, 3 + 1, 3, 1);

    previewAreaHLayout->addLayout(previewAreaGLayout);
    mainVLayout->addLayout(previewAreaHLayout);
    setLayout(mainVLayout);
}
