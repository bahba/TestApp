#include "testapp.h"

#include <QDebug>


TestApp::TestApp(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	ui.labelBoom->setVisible(false);
	ui.labelKapow->setVisible(false);

	connect(ui.pushButtonKapow, SIGNAL(clicked()), this, SLOT(kapowTriggered()));
	connect(ui.pushButtonBoom, SIGNAL(clicked()), this, SLOT(boomTriggered()));
	connect(ui.comboBoxPickImg, SIGNAL(currentIndexChanged(int)), this, SLOT(comboBoxPickImgTriggered(int)));
	connect(ui.pushButtonClearScreen, SIGNAL(clicked()), this, SLOT(clearScreenTriggered()));

}

TestApp::~TestApp()
{

}

void TestApp::kapowTriggered()
{
	ui.labelBoom->setVisible(false);
	ui.labelKapow->setVisible(true);
	emit signalKapowTriggered(true);
}

void TestApp::boomTriggered()
{
	ui.labelBoom->setVisible(true);
	ui.labelKapow->setVisible(false);
	emit signalBoomTriggered(true);
}

void TestApp::method(const QString & outputMsg)
{
	qDebug() << "\n[Method()]: " << outputMsg << "\n";

}

void TestApp::comboBoxPickImgTriggered(int index)
{
	if (BOOM == index)
	{
		boomTriggered();
	}
	else if (KAPOW == index)
	{
		kapowTriggered();
	}
	else 
		qDebug() << "Could not find index: " << index << "\n";
}

void TestApp::clearScreenTriggered()
{
	ui.labelKapow->setVisible(false);
	ui.labelBoom->setVisible(false);
	emit signalClearScreenTriggered(true);
}

