#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QTimer>
#include "Monitor.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    
private slots:
    void updateStatus();
    void addWebsite();
    void removeSelectedWebsite();

private:
    Monitor monitor;
    QTableWidget *tableWidget;
    QLineEdit *inputLine;
    QPushButton *addButton;
    QPushButton *removeButton;  // New remove button
    QTimer *timer;
    void setupUI();
};

#endif // MAINWINDOW_H