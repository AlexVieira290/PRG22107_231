#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "jogadorwidget.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);

public slots:
    void jogadorWidgetFechado();

private slots:
    void jogar();
    void sair();

private:
    QPushButton* btnJogar;
    QPushButton* btnSair;
    JogadorWidget* jogadorWidget;
};

#endif // MAINWINDOW_H
