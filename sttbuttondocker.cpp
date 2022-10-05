#include "sttbuttondocker.h"

#include <QLabel>
#include <QHBoxLayout>
#include <QMimeData>
#include <QDrag>
#include <QMouseEvent>
#include <QApplication>
#include <QPainter>
#include "GlobalDefine.h"
#include "sttpreviewwidget.h"

static inline QString fridgetMagnetsMimeType() { return QStringLiteral("application/x-fridgemagnet"); }


STTButtonDocker::STTButtonDocker(QWidget *parent)
    : QFrame(parent)
{
//    installEventFilter(this);
    setFixedSize(QSize(80,80));
//    setMinimumSize(QSize(78,78));
    setAcceptDrops(true);

//    setAutoFillBackground(true);

//    setFocusPolicy(Qt::ClickFocus);

//    setFrameStyle(1);
//    setStyleSheet("QFrame{background-color: green; } QFrame:focus:pressed{background-color: pink; border: 3px solid green; border-radius:14px;} QFrame:focus{background-color: blue; border: 3px solid white; border-radius:14px;} ");
//    setContentsMargins(2,2,2,0);


//    installEventFilter(new STTLongPress(this, [this] {
//        // do some stuff
//    }));

//    QPixmap bgImg;
//    frontLabel = new STTPreviewWidget("bbd", bgImg, this);

//    textLabel = new STTPreviewText("TAFfasdfasdlkfjas3224325",this);

//    frontLabel->setText(tr("FFF"));

//    QHBoxLayout *hLayout = new QHBoxLayout();
//    hLayout->addWidget(frontLabel);

//    setLayout(hLayout);
}

STTButtonDocker::~STTButtonDocker()
{
    //deleteUI();
//    delete frontLabel;
}

void STTButtonDocker::createContextMenu()
{


}

//bool TestDocker::eventFilter(QObject *o, QEvent *e)
//{
//    if (e->type() == QEvent::Paint) {
//        paintEvent((QPaintEvent *)e);
//    }
//    return QFrame::eventFilter(o, e);
//}

void STTButtonDocker::resizeEvent(QResizeEvent *event)
{
//    QRect r(0,0,72,72);

////    qDebug("resizeEvent rect: x: %f, y: %f, rx: %f, ry: %f", r.x(), r.y(), r.width(), r.height());

//    m_btnPath = QPainterPath();
//     m_btnPath.setFillRule(Qt::WindingFill);
//     m_btnPath.addRoundedRect(rect(), m_corner, m_corner);

//     //最后调用父类的resizeEvent
//     QFrame::resizeEvent(event);
}

void STTButtonDocker::paintEvent(QPaintEvent *e)
{

//    qDebug("Hello paint");
    QBitmap bmp(this->size());
    bmp.clear();
    QPainter qp(this);
    drawWidget(qp, bmp);

    QFrame::paintEvent(e);

//    QFrame::paintEvent(e);


//    QPainter painter(this);
//    painter.save();
//    painter.setRenderHint(QPainter::Antialiasing);  // 设置反锯齿;



//    QBrush m_clrSelectedBk;
//    QColor red(Qt::red);
//    m_clrSelectedBk.setColor(red);

//    QBrush m_clrResetBk;
//    QColor blue(Qt::blue);
//    m_clrResetBk.setColor(blue);

//    QBrush m_clrBorder;
//    QColor yellow(Qt::yellow);
//    m_clrBorder.setColor(yellow);

//    painter.fillPath(m_btnPath, m_clrSelectedBk);   //先填充路径
//    painter.setPen(QPen(m_clrBorder, 3));
//    painter.drawRoundedRect(QRect(0,0,72,72).adjusted(1,1,-1,-1), m_corner, m_corner);  //再画边框

//    //若选中状态时，绘制边框
//    if(hasFocus())
//    {
//        painter.fillPath(m_btnPath, m_clrSelectedBk);   //先填充路径
//        painter.setPen(QPen(m_clrBorder, 3));
//        painter.drawRoundedRect(QRect(0,0,72,72).adjusted(1,1,-1,-1), m_corner, m_corner);  //再画边框
//    }
//    else
//    {
//        painter.fillPath(m_btnPath, m_clrResetBk);
//    }
//    painter.setRenderHints(QPainter::Antialiasing, false);   //关闭反走样

//    painter.restore();

//    QFrame::paintEvent(e);

//    QPainter painter(this);
//    QPen pen;
//    pen.setColor(Qt::darkGray);
//    pen.setWidth(3);
//    painter.setPen(pen);
//    painter.drawRoundedRect(this->rect(), 14, 14);

//    painter.setRenderHint(QPainter::Antialiasing);
//    painter.end();
//    qDebug("m_dragOver is --> %d", m_dragOver);
//    QPainter painter(this);
//    painter.setBrush(m_dragOver? m_borderHoverColor: m_borderColor);   //有拖动，颜色变亮
//////    painter->drawRect(0, 0, 150, 150);

//    painter.drawRoundedRect(QRect(0,0,72,72),14,14);

//////    painter->save();
//////    QPainter p(this);
}

void STTButtonDocker::drawWidget(QPainter &qp, QBitmap &bmp)
{


    qp.setRenderHint(QPainter::Antialiasing);
    QPainterPath path;
    path.addRoundedRect(QRectF(3, 3, 74, 74), 10, 10);
    if(hasFocus()){
        QPen pen(Qt::cyan, 3);
        qp.setPen(pen);
        qp.fillPath(path, QColor(34,34,34));
        qp.drawPath(path);
    }else{
        QPen pen(Qt::gray, 3);
        qp.setPen(pen);
        qp.fillPath(path, QColor(34,34,34));
        qp.drawPath(path);
    }

    setMask(bmp);
}

bool PASTE_ACTION = false;

void STTButtonDocker::createNormalContextMenu(QMouseEvent *e)
{

    QMenu  *m_contextMenu = new QMenu(this);
    QAction *m_copyAction = new QAction("copy",this);
    m_contextMenu->addAction(m_copyAction);
    if(PASTE_ACTION)
    {
        QAction *m_pasteAction = new QAction("paste",this);
        m_contextMenu->addAction(m_pasteAction);
        m_contextMenu->addSeparator();
    }else{
        m_contextMenu->addSeparator();
    }


    QAction *m_delAction = new QAction("delete",this);
    QAction *m_moveToFolder = new QAction("move to Folder", this);
    QAction *m_moveToMutil = new QAction("move to Mutil", this);

    m_contextMenu->addAction(m_delAction);
    m_contextMenu->addSeparator();
    m_contextMenu->addAction(m_moveToFolder);
    m_contextMenu->addSeparator();
    m_contextMenu->addAction(m_moveToMutil);
    m_contextMenu->exec(e->globalPos());
}

void STTButtonDocker::mousePressEvent(QMouseEvent *e)
{
//    e->ignore();
    if (e->button() == Qt::LeftButton) {
        m_dragStartPosition = e->pos();
//        qDebug("mousePressEvent : drag pos :%f, %f, %f, %f", m_dragStartPosition.x(), m_dragStartPosition.y(), m_dragStartPosition.rx(), m_dragStartPosition.ry());
        setFocus();
        e->accept();
    } else if (e->button() == Qt::MiddleButton) {
        //emit resetValue();
        m_dragStartPosition = QPoint(-1, -1);
    } else if(e->button() == Qt::RightButton){
        qDebug("right clicked");
//        if(hasFocus()){
            setFocus();
//        }else{
//          clearFocus();
//        }
//
        STTPreviewWidget *child = static_cast<STTPreviewWidget*>(childAt(e->position().toPoint()));
        if(!child){
            QMenu  *m_contextMenu = new QMenu(this);
            if(PASTE_ACTION)
            {
                QAction *m_pasteAction = new QAction("paste",this);
                m_contextMenu->addAction(m_pasteAction);
                m_contextMenu->addSeparator();
            }

            QAction *m_createAction = new QAction("create new folder",this);


            QAction *m_mutilAction = new QAction("create mutil action",this);
            m_contextMenu->addAction(m_createAction);
            m_contextMenu->addSeparator();
            m_contextMenu->addAction(m_mutilAction);
            m_contextMenu->exec(e->globalPos());

        }else{
            ChildRightKeyType ckt = child->getChildKeyType();
            switch(ckt){
                case ChildRightKeyType::Normal:
                    {
                        createNormalContextMenu(e);
                    }
                default:
                    break;
            }
        }
    }
    else {
        QFrame::mousePressEvent(e);
    }
}

void STTButtonDocker::mouseReleaseEvent(QMouseEvent *e)
{
//    e->ignore();
    if (e->button() == Qt::MiddleButton) {
        e->accept();
        return;
    }
    if (e->modifiers() == Qt::ControlModifier) {
        //emit setInTimeline();
        e->accept();
        return;
    }
//    if (m_dragMode) {
        //setNewValue(m_value, true);
        m_dragStartPosition = {0,0};
//        e->accept();
//    }
}

void STTButtonDocker::mouseMoveEvent(QMouseEvent *e)
{
//    e->ignore();
//    qDebug("%f, %f, %f, %f",e->globalPosition().x(), e->globalPosition().y(), e->globalPosition().rx(), e->globalPosition().ry());
//    qDebug("pos: %f, %f, %f, %f",e->pos().x(), e->pos().y(), e->pos().rx(), e->pos().ry());
//    qDebug("dragStart: %f, %f, %f, %f", m_dragStartPosition.x(), m_dragStartPosition.y(), m_dragStartPosition.rx(), m_dragStartPosition.ry());


    //    QLineF line(event->globalPosition(), event->pos());
//    //左键按下的电到当前点的距离小于程序默认的拖动距离，表明没有拖动，则返回
//    if(line.length() < QApplication::startDragDistance())
//    {
//        return;
//    }


    if ((e->buttons() & Qt::LeftButton) && m_dragStartPosition != QPoint(-1, -1)) {
//        qDebug("mantattan: %d", (e->pos() - m_dragStartPosition).manhattanLength());
//        qDebug("startDragDistance: %d", QApplication::startDragDistance());
        if ((e->pos() - m_dragStartPosition).manhattanLength() > QApplication::startDragDistance()) {

//            m_dragLastPosition = e->pos();

            STTPreviewWidget *child = static_cast<STTPreviewWidget*>(childAt(e->position().toPoint()));
//            STTPreviewText *childText = static_cast<STTPreviewText*>(childAt(e->position().toPoint()));
            if (!child)
                return;

            QPoint hotSpot = e->position().toPoint();

            QByteArray itemData;
            QDataStream dataStream(&itemData, QIODevice::WriteOnly);
            dataStream << child->labelText() << QPoint(hotSpot) << child->pixmap(Qt::ReturnByValue) << child;

            QMimeData *mimeData = new QMimeData;
            mimeData->setData(fridgetMagnetsMimeType(), itemData);
//            mimeData->setText(child->labelText());
            if(child->pixmap(Qt::ReturnByValue).isNull())
            {
                return;
            }
            QDrag *drag = new QDrag(this);
            drag->setMimeData(mimeData);
            drag->setPixmap(child->pixmap(Qt::ReturnByValue));
            drag->setHotSpot(hotSpot);


        //! [16]
//            drag->exec();
            if (drag->exec(Qt::MoveAction) == Qt::MoveAction)
                child->close();
//            else
//                child->show();


            e->accept();
            return;
        }
    } else {
        return;
    }

}


void STTButtonDocker::dragEnterEvent(QDragEnterEvent *event)
{

    m_dragOver = true;
//    setFocus();
//
//! [4] //! [5]
//!
    if (event->mimeData()->hasFormat(fridgetMagnetsMimeType())) {
        if (children().contains(event->source())) {




            event->setDropAction(Qt::MoveAction);

            event->accept();

//            this->setFocus(Qt::OtherFocusReason);
//            setStyleSheet("QFrame{background-color: blue; border: 3px solid white; border-radius:14px;} QFrame:focus{background-color: blue; border: 3px solid white; border-radius:14px;}");

        } else {
            qDebug("come in dragEnterEvent");
            setFocus();

            event->acceptProposedAction();
//! [5] //! [6]
        }


//! [6] //! [7]
    } else if (event->mimeData()->hasText()) {
        event->acceptProposedAction();
    } else {
        event->ignore();
    }

}
//! [7]

//! [8]
void STTButtonDocker::dragMoveEvent(QDragMoveEvent *event)
{
    m_dragOver = false;

    if (event->mimeData()->hasFormat(fridgetMagnetsMimeType())) {
        if (children().contains(event->source())) {
//            event->setDropAction(Qt::MoveAction);

//            event->accept();
            event->setDropAction(Qt::MoveAction);

            event->accept();


        } else {


            event->acceptProposedAction();

//
        }
    } else if (event->mimeData()->hasText()) {
        event->acceptProposedAction();
    } else {
        event->ignore();
    }
}
//! [8]

//! [9]
//! put downed
void STTButtonDocker::dropEvent(QDropEvent *event)
{
    m_dragOver = true;

    if (event->mimeData()->hasFormat(fridgetMagnetsMimeType())) {
        const QMimeData *mime = event->mimeData();
//! [9] //! [10]
        if (event->source() == this) {

        }else{
            QList<STTPreviewWidget*> oldList = findChildren<STTPreviewWidget*>();
            qDebug("child list is--> %d", oldList.size());
            for(int i = 0; i<oldList.size(); i++){
                STTPreviewWidget *tempWidget = oldList.at(i);
                tempWidget->close();
            }
        }


        QByteArray itemData = mime->data(fridgetMagnetsMimeType());
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QString text;
        QPoint offset;
        QPixmap newPix;
//        STTPreviewWidget sourceChild;
        dataStream >> text >> offset >> newPix;
//! [10]
//! [11]
//        DragLabel *newLabel = new DragLabel(text, this);
//        newLabel->move(event->position().toPoint() - offset);
//        newLabel->show();
//        newLabel->setAttribute(Qt::WA_DeleteOnClose);
//        event->mimeData()->imageData();
//        m_imgData = qvariant_cast<QPixmap>(event->mimeData()->imageData());

//        m_textData = qvariant_cast<QString>(event->mimeData()->text());

        qDebug("m_textData is -> %s", qPrintable(text));




        auto *frontLabelff = new STTPreviewWidget("bbd", newPix, ChildRightKeyType::Normal, DbClickEventType::Normal, this);
        frontLabelff->move(4,4);
        frontLabelff->show();
        frontLabelff->setLabelText(text);
        frontLabelff->setActionPixmap(newPix);
        frontLabelff->setAttribute(Qt::WA_DeleteOnClose);

        if (event->source() == this) {


            event->setDropAction(Qt::MoveAction);

            event->accept();
        } else {


            event->acceptProposedAction();



        }



//! [11] //! [12]
    } else if (event->mimeData()->hasText()) {
//        QStringList pieces = event->mimeData()->text().split(
//            QRegularExpression(QStringLiteral("\\s+")), Qt::SkipEmptyParts);
//        QPoint position = event->position().toPoint();

//        for (const QString &piece : pieces) {
//            DragLabel *newLabel = new DragLabel(piece, this);
//            newLabel->move(position);
//            newLabel->show();
//            newLabel->setAttribute(Qt::WA_DeleteOnClose);

//            position += QPoint(newLabel->width(), 0);
//        }

        event->acceptProposedAction();
    } else {
        event->ignore();
    }
}

void STTButtonDocker::dragLeaveEvent(QDragLeaveEvent *event)
{
//    event->accept();
    qDebug("dragLeaveEvent called");
    clearFocus();

//    clearFocus();
    m_dragOver = false;
//    update();
}

