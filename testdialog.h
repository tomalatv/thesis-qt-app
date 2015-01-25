#ifndef TESTDIALOG_H
#define TESTDIALOG_H
#include <QtGui/QDialog>
#include <QTimer>
#include "ui_testdialog.h"
#include "multimediax.h"
namespace Ui {
    class TestDialog;
}
class MultimediaX;

class TestDialog : public QDialog{
    Q_OBJECT
public:
    TestDialog(QWidget *parent = 0);
    ~TestDialog();
    void openTestWindow(MultimediaX *mMedia =0);
    static void vlcCallback(const libvlc_event_t *p_event, void *p_user_data);
    void stop();

signals:
    void signalStop();

private:
    Ui::TestDialogClass *ui;
    int selectedTestNro();
    void showResult(int duration, QString startTime, QString endTime);
    int testRepetitions();
    void runTesting();
    void timerEvent(QTimerEvent *event);
    void playFile();

public slots:
    void runTest();
    void saveToFile();
    void stopFile();

private:
    QFileDialog *saveFileDialog;
    MultimediaX *multimediaX;
    QStringList testList;
    int selectedTest;
    int testRepeat;
    QString selectedTestName;
    QString testRepetition;
    QString fileToSave;
    libvlc_event_manager_t *_vlceventmanager;
    libvlc_exception_t _vlcexcep;
};

#endif // TESTDIALOG_H
