#ifndef INC_02_QTEST__QTESTWIDGET_H_
#define INC_02_QTEST__QTESTWIDGET_H_

#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class QTestWidget; }
QT_END_NAMESPACE

class QTestWidget : public QWidget {
	Q_OBJECT

public:
	explicit QTestWidget(QWidget *parent = nullptr);
	~QTestWidget() override;

	void SetWidgetPosition();

public slots:
	void OnBtnClicked();

private:
	Ui::QTestWidget *ui;
};

#endif //INC_02_QTEST__QTESTWIDGET_H_
