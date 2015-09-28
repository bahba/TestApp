#include "testapp.h"
#include "scripthandler.h"

#include <QDebug>
#include <QtScript>
#include <QMessageBox>
#include <QPushButton>
#include <iostream>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ScriptHandler scriptHandler;

	QStringList args = QApplication::arguments();
	if (args.count() >= 3 && args[1] == "-script")
	{
		if (!scriptHandler.runScript(args[2], args.mid(3)))
		{
			std::cerr << "Error: runScript() failed" << std::endl;
			return 1;
		}
		return 0;
	}
	else if (args.count() == 1)
	{
		TestApp testapp;
		testapp.show();
		return a.exec();
	}
	else
	{
		std::cerr << "Usage: testapp [-script scriptName.js <arguments>]" << std::endl;
		return 2;
	}


	//// start engine and link objects to the application
	//QScriptEngine engine;

	//QScriptValue scriptTestapp = engine.newQObject(&testapp);
	//engine.globalObject().setProperty("TestApp", scriptTestapp);

	//QList<QPushButton*> buttons = testapp.findChildren<QPushButton*>();
	//Q_FOREACH(QPushButton* button, buttons)
	//{
	//	QScriptValue scriptButton = engine.newQObject(button);
	//	engine.globalObject().setProperty("button_testapp", scriptButton);
	//}
	//
	//QString filename(":/test_button_script.js");
	//QFile scriptFile(filename);
	//
	//if (!scriptFile.exists())
	//	return scriptFile.ResourceError;

	//if (!scriptFile.open(QIODevice::ReadOnly | QIODevice::Text))
	//	return scriptFile.OpenError;
	//
	//QTextStream stream(&scriptFile);
	//QString scriptContent = stream.readAll();
	//scriptFile.close();

	//// do static check so far in the code
	//if (!engine.canEvaluate(scriptContent))
	//	qDebug() << "***[QScript ERROR] static check failed\n";

	//QScriptValue result = engine.evaluate(scriptContent, filename);

	//if (result.isError())
	//{
	//	QMessageBox::critical(0, "_ScriptHandler_", QString::fromLatin1("%0:%1: %2")
	//		.arg(filename)
	//		.arg(result.property("lineNumber").toInt32())
	//		.arg(result.toString()));
	//	return -1;
	//}
	//
	//testapp.show();

	//return a.exec();
}
