#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "tipcalculatorobject.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<TipCalculatorObject>("com.esteban.tip", 1,0,"Tip");

    const QUrl url(u"qrc:/TipCalculator/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
