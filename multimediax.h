#ifndef MULTIMEDIAX_H
#define MULTIMEDIAX_H

#include <QtGui/QWidget>
#include <QTimer>
#include <QDateTime>
#include <QtGui/QFileDialog>
#include "ui_multimediax.h"
#include "vlc/vlc.h"
#include "testdialog.h"

namespace Ui
{
    class MultimediaX;
}
class TestDialog;
class DialogSelectFiles;

class MultimediaX : public QWidget
{
    Q_OBJECT

public:
    MultimediaX(QWidget *parent = 0);
    ~MultimediaX();

    void showImages();
    void setTesting(bool testing);
    void setText(QString text);

private:
    void timerEvent(QTimerEvent *event);
    void openFileDialog(QDir path, QString fileFilter, int fileMode);
    void raise(libvlc_exception_t * ex);
    void updateProgressBar();

public slots:
    void openMusic();
    void playFile();
    void stopFile();
    void openImages();

private slots:
    void openTestWindow();
    void copyToVariaple();

private:
    Ui::MultimediaX ui;
    libvlc_instance_t *_vlcinstance;
    libvlc_media_t *_vlcmedia;
    libvlc_state_t _vlcstate;
    libvlc_time_t _vlcplaytime;
    libvlc_time_t _vlcsonglenght;
    libvlc_exception_t _vlcexcep;

public:
    libvlc_media_player_t *_vlcmediaplayer;
    QFileDialog *fileDialog;
    QStringList songList;
    QString songName;
    QStringList imageList;
    QPixmap pixmap;
    DialogSelectFiles *dialogSelectFiles;
    TestDialog *testDialog;
};

#endif // MULTIMEDIAX_H
