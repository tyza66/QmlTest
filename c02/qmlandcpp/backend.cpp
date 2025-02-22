#include "backend.h"

Backend* Backend::m_instance = nullptr;
Backend::Backend(QObject *parent)
    : QObject{parent}
{

}

void Backend::receive(const QString &msg){
    // 在这里可以执行一些操作
    emit message(msg);
}

Backend2::Backend2(QObject *parent)
    : QObject{parent}
{

}

void Backend2::receive(const QString &msg){
    // 一样是可以在这里执行一些操作
    emit message(msg);
}
