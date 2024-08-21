#include "ObtainSourcePage.h"
#include "QtToolkit/DSLLayout.hpp"

ObtainSourcePage::ObtainSourcePage(QWidget* parent /*= Q_NULLPTR*/) :
    QWidget(parent) {
    lblText_ = new QLabel("Create new issue with your email to obtain source code!");
    lblText_->setStyleSheet("font-size: 16px; font-weight: bold;");

    auto layout = tk::VBox(
        tk::Stretch(),
        tk::HBox(tk::Stretch(), lblText_, tk::Stretch()),
        tk::Stretch());

    setLayout(layout);
}
