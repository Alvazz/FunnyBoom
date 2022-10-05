#include "sttdownsideframe.h"

STTDownSideFrame::STTDownSideFrame(QWidget *parent)
    : KNSQFrame(parent)
{
    setContentsMargins(0,0,0,0);
    setStyleSheet("QFrame{background-color: yellow; } QFrame:focus:pressed{background-color: yellow;}");
}

STTDownSideFrame::~STTDownSideFrame(){}
