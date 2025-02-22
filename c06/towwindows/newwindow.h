#ifndef NEWWINDOW_H
#define NEWWINDOW_H

#include <QMainWindow>

class NewWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit NewWindow(QWidget *parent = nullptr);
};

#endif // NEWWINDOW_H
