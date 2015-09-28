#ifndef TESTAPP_H
#define TESTAPP_H

#include "ui_testapp.h"

#include <QtWidgets/QMainWindow>


class TestApp : public QMainWindow
{
	Q_OBJECT
	Q_ENUMS(Images)

public:
	TestApp(QWidget *parent = 0);
	~TestApp();

	enum Images
	{
		BOOM = 1,
		KAPOW
	};

signals:
	void signalKapowTriggered(bool state = false);
	void signalBoomTriggered(bool state = false);
	void signalClearScreenTriggered(bool state = false);

public slots:
	void method(const QString & outputMsg);
	void kapowTriggered();
	void boomTriggered();
	void comboBoxPickImgTriggered(int index);
	void clearScreenTriggered();

private:
	Ui::TestAppClass ui;

};

#endif // TESTAPP_H
