#include "dialogselectfiles.h"



DialogSelectFiles::DialogSelectFiles(QWidget *parent) :
    QDialog(parent), m_ui(new Ui::DialogSelectFiles)
{
    m_ui->setupUi(this);
//    QString filePath = "E:My Files/";
    QFileSystemModel *model = new QFileSystemModel();
    model->setFilter(QDir::Drives | QDir::Dirs | QDir::NoDotAndDotDot);
    model->setRootPath(QDir::homePath());
    m_ui->treeView->setModel(model);
    m_ui->treeView->hideColumn(1);
    m_ui->treeView->hideColumn(2);
    m_ui->treeView->hideColumn(3);
    m_ui->treeView->setSelectionMode(QAbstractItemView::SingleSelection);
}

DialogSelectFiles::~DialogSelectFiles()
{
    delete m_ui;
}

void DialogSelectFiles::openSelectFilesWindow(MultimediaX *mMedia)
{
    multimediaX = mMedia;
//    setVisible(true);
    show();
//    if(multimediaX->testing){
//        connect(this,SIGNAL(ac),this,SLOT(close()));

//     connect(this,SIGNAL(accepted()),this,SLOT(reject()));
//        closeSelectFilesWindow();
//    }
}

void DialogSelectFiles::closeSelectFilesWindow()
{
//    setVisible(false);
    close();
}

void DialogSelectFiles::showFiles()
{
    QFileSystemModel *model = new QFileSystemModel();
    model->setRootPath(QDir::homePath());
    m_ui->listView->setModel(model);
    m_ui->listView->setSelectionMode(QAbstractItemView::MultiSelection);
    m_ui->listView->setCurrentIndex(m_ui->treeView->currentIndex());
}

void DialogSelectFiles::changeEvent(QEvent *e)
{

    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

