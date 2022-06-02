#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QTranslator>
#include <QShortcut>
#include <QKeySequence>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QTextCharFormat>
#include <optional>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:

    void setLanguage_(const QString& language);
    void setReadOnly_(const bool value);
    void setSaveAbility_(const bool ability);
    void saveFile_(const QString& file_name);
    void saveFileAs_();
    void openFile_(const QString& file_name);
    bool openFileAs_();
    void print_(QPrinter& printer) const;
    void changeEvent(QEvent* event) override;

    Ui::MainWindow *ui;
    std::optional<QString> m_file_name;
    QTranslator m_translator;
    QTextCharFormat m_char_format;

    struct Shortcuts
    {
        QShortcut open;
        QShortcut save;
        QShortcut exit;

        Shortcuts(QObject* parent) :
            open(parent),
            save(parent),
            exit(parent)
        {
            setDefaultKeys();
        }

        void setDefaultKeys()
        {
            open.setKey(QKeySequence(Qt::CTRL | Qt::Key_O));
            save.setKey(QKeySequence(Qt::CTRL | Qt::Key_S));
            exit.setKey(QKeySequence(Qt::CTRL | Qt::Key_Q));
        }

    };

    Shortcuts m_shortcuts;

private slots:

    void on_decor_dark_triggered();

    void on_decor_bright_triggered();

    void on_open_triggered();

    void on_open_only_for_read_triggered();

    void on_save_triggered();

    void on_save_as_triggered();

    void on_about_programm_triggered();

    void on_exit_triggered();

    void on_language_rus_triggered();

    void on_language_eng_triggered();

    void on_print_triggered();

    void on_font_triggered();

    void on_left_triggered();

    void on_right_triggered();

    void on_center_triggered();

    void on_copy_format_triggered();
    void on_paste_format_triggered();
};
#endif // MAINWINDOW_H
