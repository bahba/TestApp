#include "scripthandler.h"
#include "testapp.h"

#include <QtScript>
#include <QMessageBox>
#include <iostream>

ScriptHandler::ScriptHandler(QWidget *parent)
	: QMainWindow(parent)
{

}

ScriptHandler::~ScriptHandler()
{

}

bool ScriptHandler::runScript(const QString & filename, const QStringList & args)
{
	//QString filename(":/test_button_script.js");

	QFile scriptFile(filename);
	
	if (!scriptFile.exists())
	{
		std::cerr << "Error: file " 
			<< qPrintable(filename) 
			<< ": " << qPrintable(scriptFile.errorString()) 
			<< std::endl;
		return false;
	}

	if (!scriptFile.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		std::cerr << "Error: Could not open file " 
			<< qPrintable(filename) 
			<< ": " << qPrintable(scriptFile.errorString()) 
			<< std::endl;
		return false;
	}
	
	QTextStream stream(&scriptFile);
	stream.setCodec("UTF-8");
	QString scriptContent = stream.readAll();
	scriptFile.close();

	//create a QScriptEngine and TestApp instance. create QScriptValue to refer to testapp instance and
	//set this as global property of the engine, making it accessible inside scripts as the testapp global variable 
	QScriptEngine engine; 

	TestApp testapp;
	QScriptValue qsTestapp = engine.newQObject(&testapp);
	engine.globalObject().setProperty("testapp", qsTestapp); 

	//now all TestApp slots and variables are available through testapp variable, to any script wanting to use it
	//Will do the same for args, using qScriptValueFromSequence since its a QStringlist.
	QScriptValue qsArgs = qScriptValueFromSequence(&engine, args);
	engine.globalObject().setProperty("args", qsArgs);

	//Q_ENUMS() useful in scripting by making enums available in scripts by registering meta-objects of its container class
	//adding testapp's meta-object as global variable of testapp
	QScriptValue qsMetaObject = engine.newQMetaObject(testapp.metaObject());
	engine.globalObject().setProperty("TestApp", qsMetaObject);

	//qScriptConnect(&testapp, SIGNAL(testapp.signalBoomTriggered()), qsTestapp, )

	engine.evaluate(scriptContent);
	if (engine.hasUncaughtException())
	{
		std::cerr << "\nUncaught exception at line "
			<< engine.uncaughtExceptionLineNumber() << ": "
			<< qPrintable(engine.uncaughtException().toString())
			<< std::endl << "Backtrace: "
			<< qPrintable(engine.uncaughtExceptionBacktrace().join(", "))
			<< std::endl;
		return false;
	}
	
	return true;
}

