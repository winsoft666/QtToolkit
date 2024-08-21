#include "AdsWidgetPage.h"
#include "QtToolkit/WidgetCreator.h"

AdsWidgetPage::AdsWidgetPage(QWidget* parent /*= Q_NULLPTR*/) :
    QWidget(parent) {
    adsWidget_ = new tk::AdsWidget();
    adsWidget_->setMinimumSize(0, 0);
    adsWidget_->resize(761, 267);

    QList<tk::AdsWidget::Metadata> metaList = {
        {":/Sample/image/ad1.jpeg",
         "Ad1",
         "https://baidu.com"},
        {":/Sample/image/ad2.jpeg",
         "Ad2",
         "https://baidu.com"}};

    adsWidget_->setShowNumber(true);
    adsWidget_->setNavStyle(tk::AdsWidget::NavStyleCircle);
    adsWidget_->setMetadata(metaList);

    QHBoxLayout* h = tk::CreateHLayout();
    {
        h->addWidget(adsWidget_);
    }
    setLayout(h);
}
