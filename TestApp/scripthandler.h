#ifndef SCRIPTHANDLER_H
#define SCRIPTHANDLER_H

#include <QtWidgets/QMainWindow>
#include <QtScript>


class ScriptHandler : public QMainWindow
{
	Q_OBJECT

public:
	ScriptHandler(QWidget *parent = 0);
	~ScriptHandler();

	bool runScript(const QString & filename, const QStringList & args);

private:


};

#endif // SCRIPTHANDLER_H
