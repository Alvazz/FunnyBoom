#ifndef STTTOPSIDEFRAME_H
#define STTTOPSIDEFRAME_H

#include <./KNSUIFramework/knsqframe.h>

#include <QFrame>
#include <QPushButton>

class STTTopSideFrame : public KNSQFrame
{
    Q_OBJECT
public:
    STTTopSideFrame(QWidget *parent = nullptr);
    ~STTTopSideFrame();

public:
    void initUI();

private:
    QPushButton *deviceBtn;
    QPushButton *profileBtn;

    QPushButton *storeBtn;
    QPushButton *settingBtn;


};

#endif // STTTOPSIDEFRAME_H
