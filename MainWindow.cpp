#include "MainWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Add default websites.
    monitor.addWebsite("https://www.google.com");
    monitor.addWebsite("https://www.meta.com");
    monitor.addWebsite("https://www.apple.com");
    monitor.addWebsite("https://www.microsoft.com");
    monitor.addWebsite("https://www.amazon.com");

    setupUI();


    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateStatus);
    timer->start(5000); // Timer updates every 5 seconds

    updateStatus();
}

MainWindow::~MainWindow() {}

void MainWindow::setupUI() { // (Re)arrange widgets
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    tableWidget = new QTableWidget(this);
    tableWidget->setColumnCount(2);
    tableWidget->setHorizontalHeaderLabels(QStringList() << "Website" << "Status");
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    mainLayout->addWidget(tableWidget);

    QHBoxLayout *inputLayout = new QHBoxLayout();
    inputLine = new QLineEdit(this);
    inputLine->setPlaceholderText("Enter website URL");
    addButton = new QPushButton("Add Website", this);
    removeButton = new QPushButton("Remove Selected", this); // New button

    connect(addButton, &QPushButton::clicked, this, &MainWindow::addWebsite);
    connect(removeButton, &QPushButton::clicked, this, &MainWindow::removeSelectedWebsite);

    inputLayout->addWidget(inputLine);
    inputLayout->addWidget(addButton);
    inputLayout->addWidget(removeButton);
    mainLayout->addLayout(inputLayout);

    setCentralWidget(centralWidget);
    setWindowTitle("Website Status Monitor");
    resize(600, 400);
}

// Update, Add, and Remove methods use Monitor class

void MainWindow::updateStatus() { 

    monitor.checkAll();
    auto statuses = monitor.getStatus();

    tableWidget->setRowCount(statuses.size());
    int row = 0;
    for (const auto &entry : statuses) {
        QTableWidgetItem *urlItem = new QTableWidgetItem(QString::fromStdString(entry.first));
        QTableWidgetItem *statusItem = new QTableWidgetItem(QString::fromStdString(entry.second ? "ONLINE" : "OFFLINE"));
        tableWidget->setItem(row, 0, urlItem);
        tableWidget->setItem(row, 1, statusItem);
        row++;
    }
}

void MainWindow::addWebsite() {
    QString website = inputLine->text().trimmed();
    if (!website.isEmpty()) {
        monitor.addWebsite(website.toStdString());
        inputLine->clear();
        updateStatus();
    } else {
        QMessageBox::warning(this, "Input Error", "Please enter a valid website URL.");
    }
}

void MainWindow::removeSelectedWebsite() {
    // Get the selected row from the table widget.
    auto selectedItems = tableWidget->selectedItems();
    if (selectedItems.isEmpty()) {
        QMessageBox::information(this, "Remove Website", "Please select a website to remove.");
        return;
    }
    // Assume first column holds the website URL.
    QString website = selectedItems.first()->text();
    monitor.removeWebsite(website.toStdString());
    updateStatus();
}