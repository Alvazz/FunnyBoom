#ifndef STTPREVIEWWIDGET_H
#define STTPREVIEWWIDGET_H

#include <QLabel>
#include "GlobalDefine.h"

class STTPreviewWidget : public QLabel
{
    Q_OBJECT
public:
    explicit STTPreviewWidget(QWidget *parent = nullptr);
    explicit STTPreviewWidget(const QString &text, const QPixmap &pix, const ChildRightKeyType &keyType, const DbClickEventType &dbceType, QWidget *parent = nullptr);
    ~STTPreviewWidget();

protected:
    void paintEvent(QPaintEvent *) override;

//    void mousePressEvent(QMouseEvent *event) override;
//    void mouseReleaseEvent(QMouseEvent *event) override;
//    void mouseMoveEvent(QMouseEvent *event) override;
//    void dragMoveEvent(QDragMoveEvent *event) override;

//    void dragEnterEvent(QDragEnterEvent *event) override;
//    void dragMoveEvent(QDragMoveEvent *event) override;
//    void dropEvent(QDropEvent *event) override;
public:
    QString labelText() const;

    void setLabelText(const QString &newText);

    QPixmap getActionPixmap() const;

    void setActionPixmap(const QPixmap &pix);

    ChildRightKeyType getChildKeyType() const;
    DbClickEventType getDbceType() const;

private:
    QString m_labelText;
    QPixmap m_actionPix;
    QPoint m_dragStartPosition;
    QPoint m_dragLastPosition;
    ChildRightKeyType m_keyType;
    DbClickEventType m_dbceTYpe;
};

#endif // STTPREVIEWWIDGET_H
