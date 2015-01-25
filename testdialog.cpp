#include "testdialog.h"
#include <QDebug>
int naytaKuvaTimerID=0;
const QString SAVE_FILE_DIR = QDir::rootPath();
bool bFileToOperateExist = false;
QTime t = QTime::QTime();
int aloitus =0;
int kokonais =0;
int kuvaToisto = 0;
int testRep = 0;
int aanenToisto =0;
QString aloitusAika;
QString lopetusAika;

TestDialog::TestDialog(QWidget *parent) :
        QDialog(parent), ui(new Ui::TestDialogClass){
    ui->setupUi(this);
    testList << "Avaa tiedostoikkuna" << "Avaa kuva" << "Musiikin toisto";
    ui->selectTest->insertItems(0, testList);
}

TestDialog::~TestDialog(){
    delete ui;
}
void TestDialog::openTestWindow(MultimediaX *mMedia){
    multimediaX = mMedia;
    show();
    connect(this, SIGNAL(signalStop()), this, SLOT(stopFile()));
    _vlceventmanager = libvlc_media_player_event_manager( multimediaX->_vlcmediaplayer,  &_vlcexcep);
    libvlc_event_attach(_vlceventmanager, libvlc_MediaPlayerPlaying, vlcCallback, this, &_vlcexcep);
}

void TestDialog::stop(){
    emit signalStop();
}

void TestDialog::vlcCallback(const libvlc_event_t *p_event, void *p_user_data){
    TestDialog *player = (TestDialog*)p_user_data;
    player->stop();
}

void TestDialog::stopFile(){
    multimediaX->stopFile();
    kokonais += t.msecsTo(t.currentTime()) - aloitus;
    aanenToisto ++;
    if(testRep != aanenToisto){
        playFile();
    }else{
        lopetusAika = t.currentTime().toString();
        showResult(kokonais, aloitusAika, lopetusAika);
        multimediaX->setTesting(false);
    }
}

void TestDialog::playFile(){
    aloitus = t.msecsTo(t.currentTime());
    multimediaX->playFile();
}

void TestDialog::runTest(){
    runTesting();
}

int TestDialog::selectedTestNro(){
    return ui->selectTest->currentIndex();
}

int TestDialog::testRepetitions(){
    int repeat;
    bool ok;
    ui->testRepeat->selectAll();
    if(ui->testRepeat->selectedText().isEmpty()){
        repeat =0;
    }else{
        repeat = ui->testRepeat->selectedText().toInt(&ok);
        if(!ok){
            repeat = 0;
        }
    }

    return repeat;
}

void TestDialog::saveToFile(){
    saveFileDialog = new QFileDialog(this);
    QString saveFile =
            saveFileDialog->getSaveFileName(this,
            "Save test result to file",SAVE_FILE_DIR);

    QFile file(saveFile+".txt");
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream stream(&file);
        stream<<"Aloitus aika | Lopetus aika |Testi nro | Aika s. | Aika ms. | Toistot\n";
        file.close();
        fileToSave = saveFile;
        bFileToOperateExist = true;
    }
}

void TestDialog::showResult( int duration, QString startTime, QString endTime){
    selectedTestName = ui->selectTest->currentText();
    selectedTest= ui->selectTest->currentIndex();
    ui->testRepeat->selectAll();
    testRepetition = ui->testRepeat->selectedText();

    if(testRepetition.isEmpty()){
        testRepeat = 0;
    }else{
        testRepeat = testRepetition.toInt();
    }
    float toSec =0;
    int dur = 0;
    dur = duration;
    toSec = (float)dur /1000;
    ui->testRepeat->deselect();
    ui->testResult->setPlainText(selectedTestName +": "
                   +QString::number(selectedTest)
                   +"\nAika:"+QString::number(toSec) +" s"
                   +"\nAika:"+QString::number(duration)+" ms"
                   +"\nToisto kerrat: "+testRepetition );

    if(bFileToOperateExist){
        QFile file(fileToSave+".txt");
        if(file.open(QIODevice::Append | QIODevice::Text)){
            QTextStream stream(&file);
            stream<<startTime+
                   +";"+endTime
                   +";"+QString::number(selectedTest)
                   +";"+QString::number(toSec)
                   +";"+QString::number(duration)
                   +";"+testRepetition+"\n";
            file.close();
        }
    }
}

void TestDialog::runTesting() {
    multimediaX->setTesting(true);
    aloitus = 0;
    kokonais = 0;
    int testNro = selectedTestNro();
    int testRepetition = testRepetitions();

    aloitusAika = t.currentTime().toString();
    switch(testNro){
    case 0:
        aloitus = t.msecsTo(t.currentTime());
        for (int i=0; i<testRepetition; i++){
            multimediaX->openImages();
            multimediaX->fileDialog->setVisible(false);
        }
        kokonais = t.msecsTo(t.currentTime()) - aloitus ;
        lopetusAika = t.currentTime().toString();
        showResult(kokonais, aloitusAika, lopetusAika);
        multimediaX->setTesting(false);
        break;

    case 1:
        testRep = testRepetitions();
        kuvaToisto = 0;
        naytaKuvaTimerID = startTimer(100);
        break;

     case 2:
        testRep = testRepetitions();
        aanenToisto =0;
        playFile();
        break;
    }
}

void TestDialog::timerEvent(QTimerEvent *event){
    if(event->timerId() == naytaKuvaTimerID){
        aloitus = t.msecsTo(t.currentTime());
        multimediaX->showImages();
        kokonais += t.msecsTo(t.currentTime())- aloitus;
        kuvaToisto++;
        if(kuvaToisto == testRep){
            killTimer(naytaKuvaTimerID);
            lopetusAika = t.currentTime().toString();
            showResult(kokonais, aloitusAika, lopetusAika);
            multimediaX->setTesting(false);
        }
    }

}
