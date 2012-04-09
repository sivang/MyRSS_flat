#include <QtGui/QApplication>
#include <QtCore/QDir>
#include <QDebug>
#include <QString>
#include "qmlapplicationviewer.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));
    QScopedPointer<QmlApplicationViewer> viewer(QmlApplicationViewer::create());

    viewer->setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    qDebug() << QDir::current();
    qDebug() << QDir::currentPath();
    QDir currentDir = QDir(QDir::currentPath());
    qDebug() << currentDir.entryList();
    viewer->setMainQmlFile(QLatin1String("qml/MyRSS/main.qml"));
    viewer->showExpanded();

    return app->exec();
}
