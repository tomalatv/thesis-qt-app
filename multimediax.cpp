#include "multimediax.h"
#include <QDebug>

qint32 kuvienMaara = 0;
qint32 kuvalaskuri = 0;
int progressID=0;
int imageID=0;
int fileMo=0;
bool testingStatus=false;

const QString IMAGE_DIR = QDir::rootPath();
const QString MUSIC_DIR = QDir::rootPath();
const int PROGRESS_TIMER_DELAY = 500;
const int IMAGE_TIMER_DELAY = 3000;

MultimediaX::MultimediaX(QWidget *parent) :
        QWidget(parent) {
    ui.setupUi(this);
    ui.progressBar->reset();
    ui.imageLabel->setUpdatesEnabled(true);

    fileDialog = new QFileDialog(this);
    connect(fileDialog, SIGNAL(accepted()), this, SLOT(copyToVariaple()));

    testDialog = new TestDialog();
    _vlcmedia=0;
    const char * const vlc_args[] = {
        "-I",
        "dummy", /* Don't use any interface */
        "--ignore-config", /* Don't use VLC's config */
        "-I", // interface
        "--verbose=0", //be much more verbose then normal
        "--plugin-path=C:\\Gradu\\Qt\\plugins",
        "--key-loop=repeat" };

    /*intialize libvlc exception*/
    libvlc_exception_init(&_vlcexcep);

    /*create new libvlc instance */
    _vlcinstance = libvlc_new(sizeof(vlc_args) / sizeof(vlc_args[0]), vlc_args,
                              &_vlcexcep);
    raise(&_vlcexcep);

    /*create empty  mediap layer object*/
    _vlcmediaplayer = libvlc_media_player_new(_vlcinstance, &_vlcexcep);

    raise(&_vlcexcep);
}

MultimediaX::~MultimediaX() {
    /*Free media */
    if(_vlcmedia!=0){
        libvlc_media_release(_vlcmedia);
    }

    /* Stop playing */
    libvlc_media_player_stop(_vlcmediaplayer, &_vlcexcep);
    raise(&_vlcexcep);

    /* Free the media_player */
    libvlc_media_player_release(_vlcmediaplayer);

    delete fileDialog;
    delete testDialog;
}

void MultimediaX::openImages() {
    QDir myPics;
    myPics.setPath(IMAGE_DIR);
    QString filter;
    filter = "*.jpg *.png";
    fileMo=1;
    openFileDialog(myPics,filter,fileMo);
}

void MultimediaX::openFileDialog(QDir path, QString fileFilter, int fileMode){
    switch (fileMode){
    case 0:
        //Open one music file
        fileDialog->setFileMode(QFileDialog::ExistingFile);
        break;
    case 1:
        //Open multiple image files
        fileDialog->setFileMode(QFileDialog::ExistingFiles);
        break;
    default:
        //Open multiple files
        fileDialog->setFileMode(QFileDialog::ExistingFiles);
        break;
    }
    fileDialog->setDirectory(path);
    fileDialog->setNameFilter(fileFilter);
    fileDialog->setModal(false);
    fileDialog->show();
}

void MultimediaX::openMusic() {
    if(!songName.isEmpty()){
        stopFile();
    }

    QDir myMusic;
    myMusic.setPath(MUSIC_DIR);
    QString filter;
    filter = "*.mp3";
    fileMo =0;
    openFileDialog(myMusic,filter,fileMo);
}

void MultimediaX::copyToVariaple(){
    if(fileMo==0){
        songList = fileDialog->selectedFiles();
        songName = songList.at(0);
        ui.songName->setText(songName);

        /* Create a new media descriptor */
        _vlcmedia = libvlc_media_new(_vlcinstance, songName.toAscii(), &_vlcexcep);
        raise(&_vlcexcep);

        /* set media to media player*/
        libvlc_media_player_set_media(_vlcmediaplayer, _vlcmedia, &_vlcexcep);
        raise(&_vlcexcep);
    }
    if(fileMo==1){
        imageList = fileDialog->selectedFiles();
        kuvienMaara = imageList.size();
    }
}

void MultimediaX::playFile() {
    if (!songName.isEmpty()) {
        /* get media file state */
        _vlcstate = libvlc_media_get_state(_vlcmedia, &_vlcexcep);
        raise(&_vlcexcep);
        switch(_vlcstate) {

        case libvlc_Playing:
            /* Pause  file */
            libvlc_media_player_pause(_vlcmediaplayer, &_vlcexcep);
            _vlcstate = libvlc_Paused;
            raise(&_vlcexcep);
            ui.playButton->setText("Play");
            ui.playButton->setShortcut(QApplication::translate("MultimediaX",
                                                               "P", 0, QApplication::UnicodeUTF8));
            break;

        default:
            /* Play  file*/
            libvlc_media_player_play(_vlcmediaplayer, &_vlcexcep);
            _vlcstate = libvlc_Playing;
            raise(&_vlcexcep);
            if(!testingStatus){
                progressID = startTimer(PROGRESS_TIMER_DELAY);
                ui.playButton->setText("Pause");
                ui.playButton->setShortcut(QApplication::translate("MultimediaX",
                                                                   "P", 0, QApplication::UnicodeUTF8));
            }
            break;

        }
        if(!testingStatus){
            showImages();
            imageID = startTimer(IMAGE_TIMER_DELAY);
        }
    }
}

void MultimediaX::stopFile() {
    if (_vlcstate == libvlc_Playing || _vlcstate == libvlc_Paused) {
        /* Stop file playing */
        libvlc_media_player_stop(_vlcmediaplayer, &_vlcexcep);
        _vlcstate = libvlc_Stopped;
        raise(&_vlcexcep);
    }

    if(!testingStatus){
        //Stop timer events
        killTimer(imageID);
        killTimer(progressID);
        ui.playButton->setText("Play");
        ui.playButton->setShortcut(QApplication::translate("MultimediaX", "P", 0,
                                                           QApplication::UnicodeUTF8));
    }

}

void MultimediaX::updateProgressBar() {
    /* Get files played time*/
    int64_t pos=0;
    pos = libvlc_media_player_get_time(_vlcmediaplayer, &_vlcexcep);
    raise(&_vlcexcep);

    /* Get files lenght */
    int64_t length=0;
    length = libvlc_media_player_get_length(_vlcmediaplayer, &_vlcexcep);
    raise(&_vlcexcep);

    int pros=0;

    if (length != 0) {
        float f1 = 0;
        float f2 = 0;
        f1 = pos;
        f2 = length;
        pros = (int) ((f1 / f2) * 100);
        ui.progressBar->setValue(pros);
    }

    QString str;
    str = QString("Aika: %1:%2 \nPituus: %3:%4 \nBiisi: %5  \nsoitto: %6 %")
          .arg(pos / 60000)
          .arg((pos / 1000) % 60)
          .arg(length / 60000)
          .arg((length / 1000) % 60) .arg(songName)
          .arg(pros);

    ui.songInformation->setPlainText(str);
}

void MultimediaX::raise(libvlc_exception_t * ex) {
    if (libvlc_exception_raised(ex)) {
        fprintf(stderr, "error: %s\n", libvlc_exception_get_message(ex));
        exit(-1);
    }
}

void MultimediaX::showImages() {
    if (!imageList.isEmpty()) {
        if (kuvalaskuri == kuvienMaara) {
            kuvalaskuri = 0;
        }
        pixmap.load(imageList.at(kuvalaskuri), "JPG", Qt::AutoColor);
        ui.imageLabel->setPixmap(pixmap.scaled(ui.imageLabel->size()));
        ui.imageLabel->repaint();
        kuvalaskuri++;
    }
}

void MultimediaX::timerEvent(QTimerEvent *event){
    if (event->timerId() == imageID) {
        showImages();
    }else if(event->timerId()== progressID){
        updateProgressBar();
    }
}

void MultimediaX::openTestWindow() {
    testDialog->openTestWindow(this);
}

void MultimediaX::setTesting(bool testing){
    testingStatus = testing;
}

void MultimediaX::setText(QString text){
    ui.songInformation->setPlainText(text);
}
