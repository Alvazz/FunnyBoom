#ifndef STTDOWNSIDEFRAME_H
#define STTDOWNSIDEFRAME_H

#include <./KNSUIFramework/knsqframe.h>
#include <QFrame>

class STTDownSideFrame : public KNSQFrame
{
    Q_OBJECT
public:
    STTDownSideFrame(QWidget *parent = nullptr);
    ~STTDownSideFrame();
};

#endif // STTDOWNSIDEFRAME_H
