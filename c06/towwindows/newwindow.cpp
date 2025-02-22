#include "newwindow.h"
#include <QLabel>
#include <QVBoxLayout>

NewWindow::NewWindow(QWidget *parent) : QMainWindow(parent) {
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    QLabel *label = new QLabel("This is a new window!", this);
    layout->addWidget(label);

    centralWidget->setLayout(layout);
    setWindowTitle("New Window");
}
