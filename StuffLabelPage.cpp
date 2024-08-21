#include "StuffLabelPage.h"
#include "QtToolkit/WidgetCreator.h"

StuffLabelPage::StuffLabelPage(QWidget* parent /*= Q_NULLPTR*/) :
    QWidget(parent) {

    QFont font;
    font.setPixelSize(60);

    QFont font2;
    font2.setPointSize(12);

    QString qss = QString("font-size: 60px;");

    stuffLabel1_ = new tk::StuffLabel("中华人民共和国");
    stuffLabel1_->setMaximumFontPixelSize(600);
    stuffLabel1_->setMinimumFontPixelSize(10);
    stuffLabel1_->setFont(font);
    stuffLabel1_->setWordWrap(true);

    stuffLabel2_ = new tk::StuffLabel("中华人民共和国");
    stuffLabel2_->setMaximumFontPixelSize(600);
    stuffLabel2_->setMinimumFontPixelSize(10);
    stuffLabel2_->setStyleSheet(qss);

    stuffLabel3_ = new tk::StuffLabel("中华人民共和国");
    stuffLabel3_->setMaximumFontPixelSize(600);
    stuffLabel3_->setMinimumFontPixelSize(10);
    stuffLabel3_->setFont(font2);

    stuffLabel4_ = new tk::StuffLabel("中华人民共和国");
    stuffLabel4_->setMaximumFontPixelSize(600);
    stuffLabel4_->setMinimumFontPixelSize(10);

    QHBoxLayout* h1 = tk::CreateHLayout();
    {
        h1->addWidget(stuffLabel1_);
        h1->addWidget(stuffLabel2_);
    }

    QHBoxLayout* h2 = tk::CreateHLayout();
    {
        h2->addWidget(stuffLabel3_);
        h2->addWidget(stuffLabel4_);
    }

    QVBoxLayout* v1 = tk::CreateVLayout();
    {
        v1->addLayout(h1);
        v1->addLayout(h2);
    }

    setLayout(v1);
}
