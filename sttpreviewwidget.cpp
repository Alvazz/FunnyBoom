#include "sttpreviewwidget.h"
#include <QPainter>
#include <QPainterPath>
#include <QMimeData>
#include <QDrag>
#include <QMouseEvent>
#include <QApplication>

static inline QString fridgetMagnetsMimeType() { return QStringLiteral("application/x-fridgemagnet"); }


STTPreviewWidget::STTPreviewWidget(QWidget *parent)
    : QLabel(parent)
{
    // nothing to see here
//    setAcceptDrops(true);
//    setFixedSize(QSize(78,78));
//    setFocusPolicy(Qt::ClickFocus);
//    setStyleSheet("QLabel{border: 3px solid yellow; border-radius:14px;} QLabel:focus{border: 3px solid #00bfff; border-radius:14px;}");
//    setStyleSheet("");
}

STTPreviewWidget::STTPreviewWidget(const QString &text, const QPixmap &pix, const ChildRightKeyType &keyType, const DbClickEventType &dbceType, QWidget *parent)
    : QLabel(text, parent),
      m_actionPix(pix),
      m_keyType(keyType),
      m_dbceTYpe(dbceType)
{
    // here, nothing to see is
    //setFixedSize(QSize(85,85));
//    setStyleSheet("");



    m_labelText = text;
    m_actionPix = pix;

    if(m_actionPix.isNull()){
        qDebug("STTPreviewWidget m_actionPix isNull");
    }

//    setAcceptDrops(true);
    setFixedSize(QSize(72,72));
    setFocusPolicy(Qt::ClickFocus);
//    setStyleSheet("QLabel{border: 3px solid transparent; border-radius:14px;} QLabel:focus{border: 3px solid transparent; border-radius:14px;}");
}

STTPreviewWidget::~STTPreviewWidget()
{

}

//void STTPreviewWidget::dragMoveEvent(QDragMoveEvent *event)
//{

//}

void STTPreviewWidget::paintEvent(QPaintEvent *e)
{
//    setText(text().toUpper());


//    QPixmap bgImg(":/button/2.png");
    if(!m_actionPix.isNull()){
        QPainter painter(&m_actionPix);
        QPen pen;
        pen.setColor(QColor("#f2ed33"));
        painter.setPen(pen);
    //    painter.begin(&m_actionPix);
    //    painter.setPen(Qt::white);
        painter.drawText(4,0,70,70, Qt::AlignBottom, m_labelText);

    //    painter.end();
        setPixmap(m_actionPix);
    }
    QLabel::paintEvent(e);

//    pathBox.addRoundedRect(QRectF(0, 0, 72, 72), 14, 14);
//    QPen penBox(Qt::green, 3);


//    painter.setPen(penBox);
//    painter->fillPath(path, Qt::red);
//    painter.drawPath(pathBox);



}



//void STTPreviewWidget::mousePressEvent(QMouseEvent *e)
//{
////	mousePos = event->pos();
////	moving = true;
//    //setStyleSheet("border: 3px solid #00bfff; border-radius:14px;");

//    if (e->button() == Qt::LeftButton) {
//        m_dragStartPosition = e->pos();
//        qDebug("mousePressEvent : drag pos :%f, %f, %f, %f", m_dragStartPosition.x(), m_dragStartPosition.y(), m_dragStartPosition.rx(), m_dragStartPosition.ry());
//        e->accept();
//    } else if (e->button() == Qt::MiddleButton) {
//        //emit resetValue();
//        m_dragStartPosition = QPoint(-1, -1);
//    } else {
//        QLabel::mousePressEvent(e);
//    }


//}

//void STTPreviewWidget::mouseReleaseEvent(QMouseEvent *e)
//{
////    moving = false;
////    QWidget* p = dynamic_cast<QWidget*>(QFrame::parent());
////    emit movedTo(p->pos());
//    //setStyleSheet("border: 3px solid #ef22ed; border-radius:14px;");

//    if (e->button() == Qt::MiddleButton) {
//        e->accept();
//        return;
//    }
//    if (e->modifiers() == Qt::ControlModifier) {
//        //emit setInTimeline();
//        e->accept();
//        return;
//    }
////    if (m_dragMode) {
//        //setNewValue(m_value, true);
//        m_dragStartPosition = {0,0};
//        e->accept();
////    }
////    m_dragMode = false;

//}

//void STTPreviewWidget::mouseMoveEvent(QMouseEvent *e)
//{

//    qDebug("%f, %f, %f, %f",e->globalPosition().x(), e->globalPosition().y(), e->globalPosition().rx(), e->globalPosition().ry());
//    qDebug("pos: %f, %f, %f, %f",e->pos().x(), e->pos().y(), e->pos().rx(), e->pos().ry());
//    qDebug("dragStart: %f, %f, %f, %f", m_dragStartPosition.x(), m_dragStartPosition.y(), m_dragStartPosition.rx(), m_dragStartPosition.ry());
////    QLineF line(event->globalPosition(), event->pos());
////    //左键按下的电到当前点的距离小于程序默认的拖动距离，表明没有拖动，则返回
////    if(line.length() < QApplication::startDragDistance())
////    {
////        return;
////    }


//    if ((e->buttons() & Qt::LeftButton) && m_dragStartPosition != QPoint(-1, -1)) {
//        qDebug("mantattan: %d", (e->pos() - m_dragStartPosition).manhattanLength());
//        qDebug("startDragDistance: %d", QApplication::startDragDistance());
//        if ((e->pos() - m_dragStartPosition).manhattanLength() >= QApplication::startDragDistance()) {

////            m_dragLastPosition = e->pos();

//            STTPreviewWidget *child = static_cast<STTPreviewWidget*>(childAt(e->position().toPoint()));
////            STTPreviewText *childText = static_cast<STTPreviewText*>(childAt(e->position().toPoint()));
//            if (!child)
//                return;

//            QPoint hotSpot = e->position().toPoint();

//            QByteArray itemData;
//            QDataStream dataStream(&itemData, QIODevice::WriteOnly);
//            dataStream << child->labelText() << QPoint(hotSpot);

//            QMimeData *mimeData = new QMimeData;
//            mimeData->setData(fridgetMagnetsMimeType(), itemData);
////            mimeData->setText(child->labelText());

//            QDrag *drag = new QDrag(this);
//            drag->setMimeData(mimeData);
//            drag->setPixmap(child->pixmap(Qt::ReturnByValue));

//            drag->setHotSpot(hotSpot);

//        //    child->hide();
//        //! [16]
//            drag->exec();

//            e->accept();
//            return;
//        }
//    } else {
//        return;
//    }


//    STTPreviewWidget *child = static_cast<STTPreviewWidget*>(childAt(e->position().toPoint()));
//    if (!child)
//        return;

//    QPoint hotSpot = e->position().toPoint();

//    QByteArray itemData;
//    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
//    dataStream << child->labelText() << QPoint(hotSpot);
////! [14]

////! [15]
//    QMimeData *mimeData = new QMimeData;
//    mimeData->setData(fridgetMagnetsMimeType(), itemData);
//    mimeData->setText(child->labelText());
////! [15]

////! [16]
//    QDrag *drag = new QDrag(this);
//    drag->setMimeData(mimeData);
//    drag->setPixmap(child->pixmap(Qt::ReturnByValue));
////    drag->setHotSpot(QPoint(drag->pixmap().width()/2,drag->pixmap().height() / 2));
//    drag->setHotSpot(hotSpot);

////    child->hide();
////! [16]
//    drag->exec();

//    if (!moving) return;
//    QPoint dpos = event->pos() - mousePos;
//    //PLANETC_GC QWidget* p = dynamic_cast<QWidget*>(QFrame::parent());
//    QPoint targetPos = p->pos() + dpos;

//    if (p == parent()) { //PLANETC_GC
//    // Prevent the title bar from being dragged to an unreachable position.
//    QWidget& mainWindow = StelMainView::getInstance();
//    int leftBoundX = 10 - width();
//    int rightBoundX = mainWindow.width() - 10;
//    if (targetPos.x() < leftBoundX)
//        targetPos.setX(leftBoundX);
//    else if (targetPos.x() > rightBoundX)
//        targetPos.setX(rightBoundX);

//    int lowerBoundY = mainWindow.height() - height();
//    if (targetPos.y() < 0)
//        targetPos.setY(0);
//    else if (targetPos.y() > lowerBoundY)
//        targetPos.setY(lowerBoundY);
//    }//PLANETC_GC
//    p->move(targetPos);
//    //emit movedTo(targetPos);


//! [17]
//    if (drag->exec(Qt::MoveAction | Qt::CopyAction, Qt::CopyAction) == Qt::MoveAction)
//        child->close();
//    else
//        child->show();


//}

//void STTPreviewWidget::mousePressEvent(QMouseEvent *event)
//{
//    QLabel::mousePressEvent(event);
//}

//void STTPreviewWidget::mouseReleaseEvent(QMouseEvent *event)
//{

//}

//void STTPreviewWidget::mouseMoveEvent(QMouseEvent *event)
//{
//
//}

void STTPreviewWidget::setLabelText(const QString &newText)
{
    m_labelText = newText;
}

QString STTPreviewWidget::labelText() const
{
    return m_labelText;
}

void STTPreviewWidget::setActionPixmap(const QPixmap &pix)
{
    m_actionPix = pix;
}

QPixmap STTPreviewWidget::getActionPixmap() const
{
    return m_actionPix;
}

ChildRightKeyType STTPreviewWidget::getChildKeyType() const
{
    return m_keyType;
}

DbClickEventType STTPreviewWidget::getDbceType() const
{
    return m_dbceTYpe;
}


