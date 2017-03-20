#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "gestionjeu.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    GestionJeu unJeu;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("vueJeu", &unJeu);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
