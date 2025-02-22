#include "mainwindow.h"
#include <QPushButton>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    QPushButton *button = new QPushButton("Open New Window", this);
    layout->addWidget(button);

    connect(button, &QPushButton::clicked, this, &MainWindow::openNewWindow);

    centralWidget->setLayout(layout);
}

void MainWindow::openNewWindow() {
    NewWindow *newWindow = new NewWindow(this);
    newWindow->show();
}
