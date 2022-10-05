#ifndef STTBUTTONDOCKER_H
#define STTBUTTONDOCKER_H

#include <QFrame>
#include <QPainterPath>
#include <QMenu>

class STTPreviewWidget;

QT_BEGIN_NAMESPACE
class QDragEnterEvent;
class QDropEvent;
QT_END_NAMESPACE

class STTButtonDocker : public QFrame
{
    Q_OBJECT
public:
    explicit STTButtonDocker(QWidget *parent = nullptr);
    ~STTButtonDocker();
public:
//    STTPreviewWidget *frontLabel;

private:
    QPoint m_dragStartPosition;
    QPoint m_dragLastPosition;
    QPixmap m_imgData;
    QString m_textData;

    bool m_dragMode;
    bool m_dragOver;  //标志是否有拖动进入



//    QColor m_borderColor;
//    QColor m_borderHoverColor;

//    QPainterPath m_btnPath;

//    int m_corner;

private:
    void createContextMenu();

    void createNormalContextMenu(QMouseEvent *e);

protected:
    void paintEvent(QPaintEvent *e) override;
    void drawWidget(QPainter &qp,  QBitmap &bmp);

    void resizeEvent(QResizeEvent *event) override;

    void mousePressEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;
    void mouseMoveEvent(QMouseEvent *e) override;

//    bool eventFilter(QObject *o, QEvent *e) override;

    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void dragLeaveEvent(QDragLeaveEvent *event) override;
//    virtual void focusInEvent(QFocusEvent *event);
//    virtual void focusOutEvent(QFocusEvent *event);

};

#endif // STTBUTTONDOCKER_H
