#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QEvent>
#include <QStyle>
#include <QStyleFactory>
#include <QFont>
#include <QFontDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow (parent),
    ui(new Ui::MainWindow),
    m_translator(this),
    m_shortcuts(this)
{
    qApp->setStyle(QStyleFactory::create("Fusion"));
    ui->setupUi(this);
    connect(&m_shortcuts.open, SIGNAL(activated()), this, SLOT(on_open_triggered()));
    connect(&m_shortcuts.save, SIGNAL(activated()), this, SLOT(on_save_triggered()));
    connect(&m_shortcuts.exit, SIGNAL(activated()), this, SLOT(on_exit_triggered()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_open_triggered()
{
    if(openFileAs_())
        setReadOnly_(false);
}

void MainWindow::on_open_only_for_read_triggered()
{
    if(openFileAs_())
        setReadOnly_(true);
}

void MainWindow::on_save_triggered()
{
    if(m_file_name)
        saveFile_(*m_file_name);
    else
        saveFileAs_();
}

void MainWindow::on_save_as_triggered()
{
    saveFileAs_();
}

void MainWindow::on_about_programm_triggered()
{
    QFile file(":/txt_files/reference.txt");
    QString info;
    if(!file.open(QIODevice::ReadOnly))
        info = tr("Data cannot be retrieved.");
    else
        info = QTextStream(&file).readAll();
    QMessageBox::information(this, tr("About program"), info);
}

void MainWindow::on_exit_triggered()
{
    this->close();
}

void MainWindow::setLanguage_(const QString &language)
{
    if(m_translator.load(":qm_files/TextEditor_" + language + ".qm"))
        qApp->installTranslator(&m_translator);
}

void MainWindow::setReadOnly_(const bool value)
{
    ui->text_edit->setReadOnly(value);
    setSaveAbility_(value);
}

void MainWindow::setSaveAbility_(const bool ability)
{
    ui->save->setDisabled(ability);
    ui->save_as->setDisabled(ability);
}

bool MainWindow::openFileAs_()
{
    m_file_name = QFileDialog::getOpenFileName(this, tr("Open file"), "", "*.txt");
    if(!m_file_name)
        return false;
    QFile file(*m_file_name);
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(this, tr("File opening error."), tr("It is impossible to make a read."));
        return false;
    }
    ui->text_edit->setPlainText(QTextStream(&file).readAll());
    return true;
}

void MainWindow::print_(QPrinter &printer) const
{
    QString printStr = ui->text_edit->toPlainText();
    QChar *list = printStr.data();
    QStringList strlst;
    int line = 20;
    int cursor = 0;
    for (bool getst = true; getst;)
    {
        int index = printStr.indexOf("\n", cursor);
        QString s = "";
        if (index == -1)
        {
            getst = false;
            s.append(&list[cursor], printStr.length() - cursor);
        }
        else
            s.append(&list[cursor], index - cursor);
        cursor = index + 1;
        strlst << s;
    }
    QPainter painter;
    painter.begin(&printer);
    int h = painter.window().height();
    int amount = strlst.count();
    QFont font = painter.font();
    QFontMetrics fmetrics(font);
    for (int i = 0; i < amount; i++)
    {
        QPointF pf;
        pf.setX(10);
        pf.setY(line);
        painter.drawText(pf, strlst.at(i));
        line += fmetrics.height();
        if (h - line <= fmetrics.height())
        {
            printer.newPage();
            line = 0;
        }
    }
    painter.end();
}

void MainWindow::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::LanguageChange)
    {
        ui->file->setTitle(tr("File"));
            ui->open->setText(tr("Open"));
            ui->open_only_for_read->setText(tr("Open read-only"));
            ui->save->setText(tr("Save"));
            ui->save_as->setText(tr("Save as"));
            ui->print->setText(tr("Print"));
            ui->exit->setText(tr("Exit"));
        ui->view->setTitle(tr("View"));
            ui->language->setTitle(tr("Language"));
            ui->language_rus->setText(tr("Russian"));
            ui->language_eng->setText(tr("English"));
            ui->decoration->setTitle(tr("Decoration"));
            ui->decor_dark->setText(tr("Dark"));
            ui->decor_bright->setText(tr("Bright"));
        ui->format->setTitle(tr("Format"));
            ui->font->setText(tr("Font"));
            ui->align->setTitle(tr("Align by"));
            ui->left->setText(tr("Left"));
            ui->center->setText(tr("Center"));
            ui->right->setText(tr("Right"));
            ui->copy_format->setText(tr("Copy"));
            ui->paste_format->setText(tr("Paste"));
        ui->reference->setTitle(tr("Reference"));
            ui->about_programm->setText(tr("About programm"));
    }
    else
        QMainWindow::changeEvent(event);
}

void MainWindow::saveFile_(const QString &file_name)
{
    if(file_name.isEmpty())
        return;
    QFile file(file_name);
    if(!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(this, tr("Error saving the file."), tr("It is impossible to make a write."));
        return;
    }
    QTextStream text_stream(&file);
    text_stream << ui->text_edit->toPlainText();
    text_stream.flush();
    return;
}

void MainWindow::saveFileAs_()
{
    const QString file_name = QFileDialog::getSaveFileName(this, tr("Save file."), "", "*.txt");
    saveFile_(file_name);
    m_file_name = file_name;
}

void MainWindow::on_language_rus_triggered()
{
    setLanguage_("ru");
}


void MainWindow::on_language_eng_triggered()
{
    setLanguage_("en");
}


void MainWindow::on_decor_dark_triggered()
{
    QPalette dark_palette;
    dark_palette.setColor(QPalette::Window, QColor(53, 53, 53));
    dark_palette.setColor(QPalette::WindowText, Qt::white);
    dark_palette.setColor(QPalette::Base, QColor(25, 25, 25));
    dark_palette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
    dark_palette.setColor(QPalette::ToolTipBase, Qt::white);
    dark_palette.setColor(QPalette::ToolTipText, Qt::white);
    dark_palette.setColor(QPalette::Text, Qt::white);
    dark_palette.setColor(QPalette::Button, QColor(53, 53, 53));
    dark_palette.setColor(QPalette::ButtonText, Qt::white);
    dark_palette.setColor(QPalette::BrightText, Qt::red);
    dark_palette.setColor(QPalette::Link, QColor(42, 130, 218));
    dark_palette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    dark_palette.setColor(QPalette::HighlightedText, Qt::black);
    qApp->setPalette(dark_palette);
}


void MainWindow::on_decor_bright_triggered()
{
    qApp->setPalette(style()->standardPalette());
}

void MainWindow::on_print_triggered()
{
    QPrinter printer;
    QPrintDialog dlg(&printer, this);
    dlg.setWindowTitle(tr("Print"));
    if (dlg.exec() != QDialog::Accepted)
        return;
    print_(printer);
}


void MainWindow::on_font_triggered()
{
    bool is_ok = false;
    const QFont font = QFontDialog::getFont(&is_ok);
    if(is_ok)
    {
        auto char_format = ui->text_edit->textCursor().charFormat();
        char_format.setFont(font);
        ui->text_edit->textCursor().setCharFormat(char_format);
    }
}


void MainWindow::on_left_triggered()
{
    ui->text_edit->setAlignment(Qt::AlignLeft);
}


void MainWindow::on_right_triggered()
{
    ui->text_edit->setAlignment(Qt::AlignRight);
}


void MainWindow::on_center_triggered()
{
    ui->text_edit->setAlignment(Qt::AlignCenter);
}

void MainWindow::on_copy_format_triggered()
{
    m_char_format = ui->text_edit->textCursor().charFormat();
}


void MainWindow::on_paste_format_triggered()
{
    ui->text_edit->textCursor().setCharFormat(m_char_format);
}

