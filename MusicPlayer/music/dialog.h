#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QPoint>
#include<QMouseEvent>
#include<QPixmap>
#include<QPalette>
#include<QMediaPlayer>
#include<QMediaPlaylist>
#include<QAction>
#include<QtWinExtras>
#include<QAction>
#include"widget.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    void setPlaylist(QMediaPlaylist *list, int row, int position, int volume, QMediaPlayer::State state, QMediaPlaylist::PlaybackMode playmodel, int i);//设置数据

signals:
    void Data(int row, int position, QMediaPlaylist *list, QMediaPlayer::State state, QMediaPlaylist::PlaybackMode model, QList<int> m_index);//发出数据

private:
    void setupUi(void);
    void updateText();//更新文本
    void updatePosition(qint64 position);//更新位置
    void updateDuration(qint64 duration);//更新状态
    void stateChange(QMediaPlayer::State state);//状态改变
    void PlaybackModel(QMediaPlaylist::PlaybackMode model);//播放模式改变

private slots:
    void on_pushButton_4_clicked();//退出
    void on_pushButton_5_clicked();//最小化
    void on_pushButton_2_clicked();//播放/暂停
    void on_pushButton_3_clicked();//下一曲
    void on_pushButton_clicked();//上一曲

    void play_slot();//播放
    void pause_slot();//暂停
    void pre_slot();//上一首
    void next_slot();//下一首

    void action1_slot();//默认皮肤1
    void action2_slot();//默认皮肤2
    void action3_slot();//默认皮肤3
    void action4_slot();//自定义皮肤

    void back_slot();
    void Action1_slot();//透明度加
    void Action2_slot();//透明度减
    void quit_slot();//退出
    void on_pushButton_7_clicked();//播放模式
    void updateIndex(int value);

protected:
    void mousePressEvent(QMouseEvent *event);//拖动窗体
    void mouseMoveEvent(QMouseEvent *event);//拖动窗体
    void mouseReleaseEvent(QMouseEvent *event);//拖动窗体
    void mouseDoubleClickEvent(QMouseEvent *);//双击返回主窗口
    void contextMenuEvent(QContextMenuEvent *);//右键菜单栏

private:
    Ui::Dialog *ui;
    QPoint    m_offSet;//点击的位置
    QPixmap   m_picture;//图片
    QPalette  m_palette;//调色板

    QAction  *m_play;//播放
    QAction  *m_pause;//暂停
    QAction  *m_next;//下一首
    QAction  *m_pre;//上一首
    QAction  *m_back;//返回

    QAction  *action;//设置皮肤
    QAction  *action1;//默认皮肤1
    QAction  *action2;//默认皮肤2
    QAction  *action3;//默认皮肤3
    QAction  *action4;//自定义皮肤

    QAction  *Action;//设置透明度
    QAction  *Action1;//透明度加
    QAction  *Action2;//透明度减

    QAction  *m_quit;//退出
    QMenu    *m_menu;//右键菜单
    double    m_transparency;//透明度

    QMediaPlayer   *m_music;//音乐
    QMediaPlaylist *m_playlist;//播放列表

    //任务栏
    QWinThumbnailToolBar    *toolbar;//任务栏工具栏
    QWinThumbnailToolButton *m_toolBarNext;//下一首
    QWinThumbnailToolButton *m_toolBarPre;//上一首
    QWinThumbnailToolButton *m_toolBarPause;//播放/暂停
    QWinTaskbarButton       *m_taskbotton;//任务栏
    QWinTaskbarProgress     *m_taskProgress;//任务栏进度条

    QString    m_currentFile;
    QList<int> m_index;
    bool       m_flag;
};

#endif // DIALOG_H
