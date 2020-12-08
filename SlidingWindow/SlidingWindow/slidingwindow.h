#ifndef SLIDINGWINDOW_H
#define SLIDINGWINDOW_H

#include <QtGui>

class SlidingWindow : public QWidget
{
    Q_OBJECT

public:
    SlidingWindow(QWidget *parent = 0);
    ~SlidingWindow();

protected:
    void mousePressEvent ( QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void resizeEvent(QResizeEvent *event);
    bool eventFilter(QObject *obj, QEvent *event);

private:
    void setBtnPos();
    void setBtnIcon();

private slots:
    void slotClickedBtn();
    void slotSplitterMoved(int pos, int index);

private:
    QPoint dragPosition;
    bool bPressFlag;
    QSplitter *splitter;
    QFrame *contentFrame;
    QFrame *listFrame;
    QPushButton *pushButton;
    QIcon leftIcon;
    QIcon rightIcon;
};

#endif // SLIDINGWINDOW_H
