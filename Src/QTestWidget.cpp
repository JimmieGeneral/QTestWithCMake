//
// Created by generaldarknor on 23-8-5.
//

// You may need to build the project (run Qt uic code generator) to get "ui_QTestWidget.h" resolved

#include "QTestWidget.h"
#include "ui_QTestWidget.h"

#include <QtGui/QGuiApplication>
#include <QtGui/QScreen>
#include <QtGui/QCursor>
#include <QtCore/QList>
#include <QtCore/QRect>

QTestWidget::QTestWidget(QWidget *parent) :
	QWidget(parent), ui(new Ui::QTestWidget) {

	ui->setupUi(this);

	connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(OnBtnClicked()));

	SetWidgetPosition();
}

QTestWidget::~QTestWidget()
{
  delete ui;
}

void QTestWidget::OnBtnClicked()
{
	ui->plainTextEdit->appendPlainText(QString("Point, x()[%1], y()[%2]").arg(QCursor::pos().x()).arg(QCursor::pos().y()));
	QList<QScreen*> qlistScreen = QGuiApplication::screens();
	for(int i = 0; i < qlistScreen.size(); ++i)
	{
		QString qstrScreenX = QString::number(qlistScreen[i]->geometry().x());
		QString qstrScreenY = QString::number(qlistScreen[i]->geometry().y());
		QString qstrScreenWidth = QString::number(qlistScreen[i]->geometry().width());
		QString qstrScreenHeight = QString::number(qlistScreen[i]->geometry().height());

		ui->plainTextEdit->appendPlainText(QString("Screen[%1], x()[%2], y()[%3], width()[%4], height()[%5]").arg(i).arg(qstrScreenX).arg(qstrScreenY).arg(qstrScreenWidth).arg(qstrScreenHeight));
	}
}

void QTestWidget::SetWidgetPosition()
{
	int iPointCurrentScreenX = QCursor::pos().x();
	int iPointCurrentScreenY = QCursor::pos().y();

	QList<QScreen*> qlistScreen = QGuiApplication::screens();
	for(int i = 0; i < qlistScreen.size(); ++i)
	{
		int X_Up = qlistScreen[i]->geometry().x();
		int Y_Up = qlistScreen[i]->geometry().y();
		int X_Down = X_Up + qlistScreen[i]->geometry().width();
		int Y_Down = Y_Up + qlistScreen[i]->geometry().height();
		if (iPointCurrentScreenX >= X_Up && iPointCurrentScreenX <= X_Down
			&& iPointCurrentScreenY >= Y_Up && iPointCurrentScreenY <= Y_Down)
		{
			move(X_Up + (qlistScreen[i]->geometry().width() - this->width())/2,
				Y_Up + (qlistScreen[i]->geometry().height() - this->height())/2);
			return;
		}
	}

	int X_Up = qlistScreen[0]->geometry().x();
	int Y_Up = qlistScreen[0]->geometry().y();
	int X_Down = X_Up + qlistScreen[0]->geometry().width();
	int Y_Down = Y_Up + qlistScreen[0]->geometry().height();

	move(X_Up + (qlistScreen[0]->geometry().width() - this->width())/2,
		Y_Up + (qlistScreen[0]->geometry().height() - this->height())/2);

	return ;
}
