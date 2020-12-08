#include "dialog.h"
#include "ui_dialog.h"
#include <QPixmap>
#include <QPalette>
#include <QIcon>
#include <QMenu>
#include <QAction>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QShortcut>
#include <QGraphicsDropShadowEffect>
#include <QFileDialog>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setupUi();

    QSqlQuery query;
    query.exec("select * from Bizi_DATA");//壁纸数据
    query.next();
    QString FileName = query.value(0).toString();
    if(FileName.isEmpty())
        m_picture.load(":/image/image/background/bg4.jpg");
    else
        m_picture.load(FileName);
    m_palette.setBrush(QPalette::Window,QBrush(m_picture.scaled(size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(m_palette);//设置壁纸

    //从数据库里获得透明数据
    query.exec("select * from Toumin_DATA");//透明度数据
    query.next();
    QString temp = query.value(0).toString();
    if(temp.isEmpty())
        m_transparency = 1.0;
    else
        m_transparency = temp.toDouble();
    this->setWindowOpacity(m_transparency);//设置透明度

    m_flag        = false;
    m_currentFile = "D:/";

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setupUi(void)
{
    this->setAutoFillBackground(true);

    ui->pushButton_2->setIconSize(QSize(24,24));
    ui->pushButton_2->setIcon(QIcon(":/image/image/image/pase.png"));

    ui->pushButton->setToolTip(QString::fromUtf8("上一首"));
    ui->pushButton_2->setToolTip(QString::fromUtf8("暂停"));
    ui->pushButton_3->setToolTip(QString::fromUtf8("下一首"));
    ui->pushButton_4->setToolTip(QString::fromUtf8("关闭"));
    ui->pushButton_5->setToolTip(QString::fromUtf8("最小化"));
    ui->horizontalSlider->setToolTip(QString::fromUtf8("播放进度"));

    m_music  = new QMediaPlayer(this);
    connect(m_music, &QMediaPlayer::metaDataAvailableChanged, this, &Dialog::updateText);
    connect(m_music, &QMediaPlayer::positionChanged,          this, &Dialog::updatePosition);
    connect(m_music, &QMediaPlayer::durationChanged,          this, &Dialog::updateDuration);
    connect(m_music, &QMediaPlayer::stateChanged,             this, &Dialog::stateChange);

    m_playlist = new QMediaPlaylist(this);
    m_playlist->setPlaybackMode(QMediaPlaylist::Loop);
    connect(m_playlist, &QMediaPlaylist::playbackModeChanged, this, &Dialog::PlaybackModel);

    m_play  = new QAction(this);//播放
    m_play->setIcon(QIcon(":/image/image/zt13.png"));
    m_play->setText(QString::fromUtf8("播放"));
    connect(m_play, &QAction::triggered, this, &Dialog::play_slot);

    m_pause = new QAction(this);//暂停
    m_pause->setIcon(QIcon(":/image/image/bofang1.png"));
    m_pause->setText(QString::fromUtf8("暂停"));
    connect(m_pause, &QAction::triggered, this ,&Dialog::pause_slot);

    m_next  = new QAction(this);//下一首
    m_next->setIcon(QIcon(":/image/image/next1.png"));
    m_next->setText(QString::fromUtf8("下一首"));
    connect(m_next, &QAction::triggered, this, &Dialog::next_slot);

    m_pre   = new QAction(this);//上一首
    m_pre->setIcon(QIcon(":/image/image/pre1.png"));
    m_pre->setText(QString::fromUtf8("上一首"));
    connect(m_pre, &QAction::triggered, this, &Dialog::pre_slot);

    m_back  = new QAction(this);//返回
    m_back->setIcon(QIcon(":/image/image/退出 (3).png"));
    m_back->setText(QString::fromUtf8("返回主窗口"));
    connect(m_back, &QAction::triggered, this, &Dialog::back_slot);

    action  = new QAction(this);//设置皮肤
    action->setIcon(QIcon(":/image/image/pf.png"));
    action->setText(QString::fromUtf8("设置皮肤"));

    action1 = new QAction(this);//默认皮肤1
    action1->setIcon(QIcon(":/image/image/pf2.png"));
    action1->setText(QString::fromUtf8("棕色"));
    connect(action1, &QAction::triggered, this, &Dialog::action1_slot);

    action2 = new QAction(this);//默认皮肤2
    action2->setIcon(QIcon(":/image/image/pf5.png"));
    action2->setText(QString::fromUtf8("晨曦"));
    connect(action2, &QAction::triggered, this, &Dialog::action2_slot);

    action3 = new QAction(this);//默认皮肤3
    action3->setIcon(QIcon(":/image/image/pf3.png"));
    action3->setText(QString::fromUtf8("天空"));
    connect(action3, &QAction::triggered, this, &Dialog::action3_slot);

    action4 = new QAction(this);//自定义皮肤
    action4->setIcon(QIcon(":/image/image/pf4.png"));
    action4->setText(QString::fromUtf8("自定义"));
    connect(action4, &QAction::triggered, this, &Dialog::action4_slot);

    QMenu *Menu = new QMenu(this);//皮肤菜单
    Menu->addAction(action1);
    Menu->addAction(action2);
    Menu->addAction(action3);
    Menu->addAction(action4);
    Menu->setStyleSheet("QMenu{background-color: white; border: 3px solid white;}\
                        QMenu::item{background-color: transparent;\
                                    padding:5px 30px;                 \
                                    margin:0px 0px;                  \
                                    border-bottom:0px solid #DBDBDB;}  \
                        QMenu::item:selected {background-color: rgba(122,122,122,100);}"
                        );

    action->setMenu(Menu);

    Action  = new QAction(this);//设置透明度
    Action->setIcon(QIcon(":/image/image/ooopic_1500874104.png"));
    Action->setText(QString::fromUtf8("设置透明度"));

    Action1 = new QAction(this);//透明度加
    Action1->setIcon(QIcon(":/image/image/add.png"));
    Action1->setText(QString::fromUtf8("+5%"));
    connect(Action1, &QAction::triggered, this, &Dialog::Action1_slot);

    Action2 = new QAction(this);//透明度减
    Action2->setIcon(QIcon(":/image/image/sub.png"));
    Action2->setText(QString::fromUtf8("-5%"));
    connect(Action2, &QAction::triggered, this, &Dialog::Action2_slot);

    QMenu *Menu1 = new QMenu(this);//透明度菜单
    Menu1->addAction(Action1);
    Menu1->addAction(Action2);
    Menu1->setStyleSheet("QMenu {background-color: white;border: 3px solid white;}\
                         QMenu::item {background-color: transparent;padding:5px 30px;/margin:0px 0px;border-bottom:0px solid #DBDBDB;}\
                         QMenu::item:selected {background-color: rgba(122,122,122,100);}"
                         );

    Action->setMenu(Menu1);
    m_quit = new QAction(this);
    m_quit->setIcon(QIcon(":/image/image/tc.png"));
    m_quit->setText(QString::fromUtf8("退出"));
    connect(m_quit,&QAction::triggered,this,&Dialog::quit_slot);
    connect(ui->horizontalSlider, &QSlider::sliderMoved, m_music, &QMediaPlayer::setPosition);

    ui->pushButton_7->setIconSize(QSize(20,20));
    ui->pushButton_7->setIcon(QIcon(":/image/image/image/loop.png"));
    ui->pushButton_7->setToolTip(QString::fromUtf8("顺序播放"));

    ui->pushButton_8->setIconSize(QSize(20,20));
    ui->pushButton_8->setIcon(QIcon(":/image/image/Music_32px_1144946_easyicon.net.png"));
    ui->pushButton_8->setToolTip(QString::fromUtf8("本地音乐列表"));

    //任务栏菜单
    QMenu *ToolMenu=new QMenu(this);
    if(QtWin::isCompositionEnabled())
    {
        QtWin::enableBlurBehindWindow(ToolMenu);
    }
    else
    {
        QtWin::disableBlurBehindWindow(ToolMenu);
        ToolMenu->hide();
    }

    toolbar = new QWinThumbnailToolBar(this);
    toolbar->setWindow(windowHandle());

    m_toolBarNext  = new QWinThumbnailToolButton(this);
    m_toolBarNext->setToolTip(QString::fromUtf8("下一首"));
    m_toolBarNext->setIcon(QIcon(":/image/image/next1.png"));
    connect(m_toolBarNext,&QWinThumbnailToolButton::clicked,this,&Dialog::on_pushButton_3_clicked);

    m_toolBarPre   = new QWinThumbnailToolButton(this);
    m_toolBarPre->setToolTip(QString::fromUtf8("上一首"));
    m_toolBarPre->setIcon(QIcon(":/image/image/pre1.png"));
    connect(m_toolBarPre,&QWinThumbnailToolButton::clicked,this,&Dialog::on_pushButton_clicked);

    m_toolBarPause = new QWinThumbnailToolButton(this);
    m_toolBarPause->setToolTip(QString::fromUtf8("暂停"));
    m_toolBarPause->setIcon(QIcon(":/image/image/bf13.png"));
    connect(m_toolBarPause,&QWinThumbnailToolButton::clicked,this,&Dialog::on_pushButton_2_clicked);

    toolbar->addButton(m_toolBarPre);
    toolbar->addButton(m_toolBarPause);
    toolbar->addButton(m_toolBarNext);

    m_taskbotton   = new QWinTaskbarButton(this);
    m_taskbotton->setWindow(windowHandle());

    m_taskProgress = new QWinTaskbarProgress(this);
    m_taskProgress = m_taskbotton->progress();

    connect(ui->horizontalSlider, &QSlider::valueChanged, m_taskProgress, &QWinTaskbarProgress::setValue);
    connect(ui->horizontalSlider, &QSlider::rangeChanged, m_taskProgress, &QWinTaskbarProgress::setRange);
}

void Dialog::updateIndex(int value)
{
    if(m_index.indexOf(value) == -1)
    {
        m_index.push_back(value);
    }
}

void Dialog::on_pushButton_4_clicked()//退出
{
    QCoreApplication::quit();
}

void Dialog::on_pushButton_5_clicked()//最小化
{
    showMinimized();
}

void Dialog::mousePressEvent(QMouseEvent *event)//拖动窗体
{
    m_offSet = event->globalPos() - pos();
    event->accept();
    if(event->button() == Qt::LeftButton)
    {
        setCursor(Qt::OpenHandCursor);
    }
}

void Dialog::mouseMoveEvent(QMouseEvent *event)//拖动窗体
{
    move(event->globalPos() - m_offSet);
    event->accept();
    setCursor(Qt::ClosedHandCursor);
}

void Dialog::mouseReleaseEvent(QMouseEvent *event)//拖动窗体
{
    m_offSet = QPoint();
    event->accept();
    setCursor(Qt::ArrowCursor);
}

void Dialog::mouseDoubleClickEvent(QMouseEvent *)//双击返回主窗口
{
    setCursor(Qt::ArrowCursor);
    emit Data(m_playlist->currentIndex(), m_music->position(), m_playlist, m_music->state(), m_playlist->playbackMode(), m_index);
    m_music->pause();
    accept();
}

void Dialog::setPlaylist(QMediaPlaylist *list, int row, int position, int volume, QMediaPlayer::State state, QMediaPlaylist::PlaybackMode playmodel, int i)//设置数据
{
    m_playlist = list;
    m_music->setPlaylist(m_playlist);

    m_playlist->setCurrentIndex(row);
    m_music->setPosition(position);
    m_music->setVolume(volume);

    if(state == QMediaPlayer::PlayingState)
        m_music->play();
    m_playlist->setPlaybackMode(playmodel);
    PlaybackModel(playmodel);
    if(i == 0)
    {
        ui->pushButton_8->setIcon(QIcon(":/image/image/Music_32px_1144946_easyicon.net.png"));
        ui->pushButton_8->setToolTip(QString::fromUtf8("本地歌曲列表"));
        m_flag = true;
    }
    else if(i == 1)
    {
        ui->pushButton_8->setIcon(QIcon(":/image/image/like_32px_1101682_easyicon.net.png"));
        ui->pushButton_8->setToolTip(QString::fromUtf8("我喜欢列表"));
    }
    else if(i == 2)
    {
        ui->pushButton_8->setIcon(QIcon(":/image/image/list_32px_1074296_easyicon.net.png"));
        ui->pushButton_8->setToolTip(QString::fromUtf8("我的收藏列表"));
    }
    else if(i == 3)
    {
        ui->pushButton_8->setIcon(QIcon(":/image/image/list_32px_1074296_easyicon.net.png"));
        ui->pushButton_8->setToolTip(QString::fromUtf8("播放记录列表"));
    }
}

void Dialog::updateText()//更新文本
{
    QString Text;
    if(m_music->isMetaDataAvailable())
    {
        QString Title = m_music->metaData(QStringLiteral("Title")).toString();
        if(!Title.isEmpty())
        {
            Text = Title;
        }
        else
        {
            Text += QString::fromUtf8("未知歌曲");
        }

        Text += "-";
        QString Author = m_music->metaData(QStringLiteral("Author")).toString();
        if(!Author.isEmpty())
        {
            Text += Author;
        }
        else
        {
            Text += QString::fromUtf8("未知作者");
        }
    }
    ui->label->setText(Text);
}

static QString Time(qint64 time)//转换时间
{
    int  sec = time/1000;
    int  min = sec/60;
    sec  -= min*60;

    return QStringLiteral("%1:%2").arg(min, 2, 10, QLatin1Char('0')).arg(sec, 2, 10, QLatin1Char('0'));
}

void Dialog::updatePosition(qint64 position)//更新位置
{
    ui->horizontalSlider->setValue(position);
    ui->label_2->setText(Time(position) + "/" + Time(m_music->duration()));
}

void Dialog::updateDuration(qint64 duration)//更新状态
{
    ui->horizontalSlider->setRange(0,duration);
    ui->horizontalSlider->setEnabled(duration>0);
    ui->horizontalSlider->setPageStep(duration/10);
}

void Dialog::on_pushButton_2_clicked()//播放/暂停
{
    if(m_music->state() == QMediaPlayer::PlayingState)
    {
        m_music->pause();
        ui->pushButton_2->setIcon(QIcon(":/image/image/image/pase.png"));
        ui->pushButton_2->setToolTip(QString::fromUtf8("暂停"));
        m_toolBarPause->setToolTip(QString::fromUtf8("暂停"));
        m_toolBarPause->setIcon(QIcon(":/image/image/bf13.png"));
    }
    else
    {
        m_music->play();
        ui->pushButton_2->setIcon(QIcon(":/image/image/image/play.png"));
        ui->pushButton_2->setToolTip(QString::fromUtf8("播放"));
        m_toolBarPause->setToolTip(QString::fromUtf8("播放"));
        m_toolBarPause->setIcon(QIcon(":/image/image/zt13.png"));
    }
}

void Dialog::stateChange(QMediaPlayer::State state)//状态改变
{

    if(state == QMediaPlayer::PlayingState)
    {
        ui->pushButton_2->setIcon(QIcon(":/image/image/image/play.png"));
        ui->pushButton_2->setToolTip(QString::fromUtf8("播放"));
        m_toolBarPause->setToolTip(QString::fromUtf8("播放"));
        m_toolBarPause->setIcon(QIcon(":/image/image/zt13.png"));
        m_taskProgress->show();
        m_taskProgress->resume();
    }
    else
    {

        ui->pushButton_2->setIcon(QIcon(":/image/image/image/pase.png"));
        ui->pushButton_2->setToolTip(QString::fromUtf8("暂停"));
        m_toolBarPause->setToolTip(QString::fromUtf8("暂停"));
        m_toolBarPause->setIcon(QIcon(":/image/image/bf13.png"));
        m_taskProgress->show();
        m_taskProgress->pause();
    }
}

void Dialog::on_pushButton_3_clicked()//下一曲
{
    int currentIndex;
    if(m_playlist->playbackMode() == QMediaPlaylist::Random)
    {
        int row = m_playlist->mediaCount();
        currentIndex = qrand()%row;
    }
    else
    {
        currentIndex       = m_playlist->currentIndex();
        if(++currentIndex == m_playlist->mediaCount())
        {
            currentIndex=0;
        }
    }
    if(m_flag && m_index.indexOf(currentIndex) == -1)
    {
        m_index.push_back(currentIndex);
    }
    m_playlist->setCurrentIndex(currentIndex);
}

void Dialog::on_pushButton_clicked()//上一曲
{
    int currentIndex;
    if(m_playlist->playbackMode() == QMediaPlaylist::Random)
    {
        int row = m_playlist->mediaCount();
        currentIndex = qrand()%row;
    }
    else
    {
        currentIndex = m_playlist->currentIndex();
        if(--currentIndex < 0)
        {
            currentIndex = 0;
        }
    }

    if(m_flag&&m_index.indexOf(currentIndex) == -1)
    {
        m_index.push_back(currentIndex);
    }
    m_playlist->setCurrentIndex(currentIndex);
}

void Dialog::contextMenuEvent(QContextMenuEvent *)//右键菜单栏
{
    m_menu = new QMenu(this);
    m_menu->setStyleSheet(" QMenu {background-color: white; border: 3px solid white;}\
                          QMenu::item {background-color: transparent;\
                                       padding:5px 30px;\
                                       margin:0px 0px;\
                                       border-bottom:0px solid #DBDBDB;}\
                          QMenu::item:selected {background-color: rgba(122,122,122,100);}"
                          );

    if(m_music->state() == QMediaPlayer::PlayingState)
    {
        m_menu->addAction(m_pause);
    }
    else
    {
        m_menu->addAction(m_play);
    }
    m_menu->addAction(m_next);
    m_menu->addAction(m_pre);
    m_menu->addAction(m_back);
    m_menu->addAction(action);
    m_menu->addAction(Action);
    m_menu->addAction(m_quit);
    m_menu->exec(QCursor::pos());
}

void Dialog::play_slot()//播放
{
    m_music->play();
}

void Dialog::pause_slot()//暂停
{
    m_music->pause();
}

void Dialog::next_slot()//下一首
{
    int currentIndex;
    if(m_playlist->playbackMode() == QMediaPlaylist::Random)
    {
        int row = m_playlist->mediaCount();
        currentIndex = qrand()%row;
    }
    else
    {
        currentIndex       = m_playlist->currentIndex();
        if(++currentIndex == m_playlist->mediaCount())
        {
            currentIndex = 0;
        }
    }

    if(m_flag && m_index.indexOf(currentIndex) == -1)
    {
        m_index.push_back(currentIndex);
    }
    m_playlist->setCurrentIndex(currentIndex);
}

void Dialog::pre_slot()//上一首
{
    int currentIndex;
    if(m_playlist->playbackMode() == QMediaPlaylist::Random)
    {
        int row      = m_playlist->mediaCount();
        currentIndex = qrand()%row;
    }
    else
    {
        currentIndex = m_playlist->currentIndex();
        if(--currentIndex < 0)
        {
            currentIndex = 0;
        }
    }
    m_playlist->setCurrentIndex(currentIndex);

    if(m_flag && m_index.indexOf(currentIndex) == -1)
    {
        m_index.push_back(currentIndex);
    }
}

void Dialog::action1_slot()//默认皮肤1
{
    QString FileName = ":/image/image/background/bg4.jpg";

    QSqlQuery query;
    query.exec("select * from Bizi_DATA");
    query.exec("delete from Bizi_DATA");
    query.exec(QString("insert into Bizi_DATA values ('%1')").arg(FileName));

    m_picture.load(FileName);
    m_palette.setBrush(QPalette::Window, QBrush(m_picture.scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    setPalette(m_palette);
}

void Dialog::action2_slot()//默认皮肤2
{
    QString FileName = ":/image/image/background/bg5.jpg";
    QSqlQuery query;
    query.exec("select * from Bizi_DATA");
    query.exec("delete from Bizi_DATA");
    query.exec(QString("insert into Bizi_DATA values ('%1')").arg(FileName));

    m_picture.load(FileName);
    m_palette.setBrush(QPalette::Window, QBrush(m_picture.scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    setPalette(m_palette);
}

void Dialog::action3_slot()//默认皮肤3
{
    QString FileName = ":/image/image/background/bg6.jpg";
    QSqlQuery query;
    query.exec("select * from Bizi_DATA");
    query.exec("delete from Bizi_DATA");
    query.exec(QString("insert into Bizi_DATA values ('%1')").arg(FileName));

    m_picture.load(FileName);
    m_palette.setBrush(QPalette::Window, QBrush(m_picture.scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    setPalette(m_palette);
}

void Dialog::action4_slot()//自定义皮肤
{

    QString FileName = QFileDialog::getOpenFileName(this,QString::fromUtf8("文件"),m_currentFile,QString::fromUtf8("图片文件(*jpg *png)"));
    if(!FileName.isEmpty())
    {
        QString file  = FileName;
        QString file1 = FileName.split("//").last();
        m_currentFile = file.remove(file1);

        QSqlQuery query;
        query.exec("select * from Bizi_DATA");
        query.exec("delete from Bizi_DATA");
        query.exec(QString("insert into Bizi_DATA values ('%1')").arg(FileName));

        m_picture.load(FileName);
        m_palette.setBrush(QPalette::Window, QBrush(m_picture.scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
        setPalette(m_palette);
    }
}

void Dialog::Action1_slot()//透明度加
{
    QSqlQuery query;
    query.exec("select * from Toumin_DATA");
    query.exec("delete from Toumin_DATA");
    if(m_transparency < 1.0)
    {
        m_transparency += 0.05;
        query.exec(QString("insert into Toumin_DATA values (%1)").arg(m_transparency));
    }
    setWindowOpacity(m_transparency);
}

void Dialog::Action2_slot()//透明度减
{
    QSqlQuery query;
    query.exec("select * from Toumin_DATA");
    query.exec("delete from Toumin_DATA");
    if(m_transparency > 0.4)
    {
        m_transparency -= 0.05;

        query.exec(QString("insert into Toumin_DATA values (%1)").arg(m_transparency));
    }
    setWindowOpacity(m_transparency);
}

void Dialog::quit_slot()//退出
{
    QCoreApplication::quit();
}

void Dialog::on_pushButton_7_clicked()//播放模式
{

    if(m_playlist->playbackMode() == QMediaPlaylist::Loop)
    {
        ui->pushButton_7->setIcon(QIcon(":/image/image/image/play-random.png"));
        ui->pushButton_7->setToolTip(QString::fromUtf8("随机播放"));
        m_playlist->setPlaybackMode(QMediaPlaylist::Random);
    }
    else if(m_playlist->playbackMode() == QMediaPlaylist::Random)
    {
        ui->pushButton_7->setIcon(QIcon(":/image/image/image/loop-one.png"));
        ui->pushButton_7->setToolTip(QString::fromUtf8("单曲循环"));
        m_playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    }
    else if(m_playlist->playbackMode() == QMediaPlaylist::CurrentItemInLoop)
    {
        ui->pushButton_7->setIcon(QIcon(":/image/image/image/loop.png"));
        ui->pushButton_7->setToolTip(QString::fromUtf8("顺序播放"));
        m_playlist->setPlaybackMode(QMediaPlaylist::Loop);
    }
}

void Dialog::PlaybackModel(QMediaPlaylist::PlaybackMode model)//播放模式改变
{

    if(model == QMediaPlaylist::Loop)
    {
        ui->pushButton_7->setIcon(QIcon(":/image/image/image/loop.png"));
        ui->pushButton_7->setToolTip(QString::fromUtf8("顺序播放"));
    }
    else if(model == QMediaPlaylist::Random)
    {
        ui->pushButton_7->setIcon(QIcon(":/image/image/image/play-random.png"));
        ui->pushButton_7->setToolTip(QString::fromUtf8("随机播放"));
    }
    else if(model == QMediaPlaylist::CurrentItemInLoop)
    {
        ui->pushButton_7->setIcon(QIcon(":/image/image/image/loop-one.png"));
        ui->pushButton_7->setToolTip(QString::fromUtf8("单曲循环"));
    }
}

void Dialog::back_slot(){

    setCursor(Qt::ArrowCursor);
    emit Data(m_playlist->currentIndex(),m_music->position(),m_playlist,m_music->state(),m_playlist->playbackMode(),m_index);
    m_music->pause();
    accept();
}
