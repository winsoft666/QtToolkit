#include "DSLLayoutPage.h"
#include "QtToolkit/DSLLayout.hpp"

DSLLayoutPage::DSLLayoutPage(QWidget* parent /*= nullptr*/) :
    QWidget(parent) {
    layoutDebugger_ = new tk::LayoutDebugger(this);
    setupUi();

    connect(chkEnableLayoutDebug_, &QCheckBox::toggled, this, [this](bool checked) {
        if (checked)
            this->installEventFilter(layoutDebugger_);
        else
            this->removeEventFilter(layoutDebugger_);
    });
}

void DSLLayoutPage::setupUi() {
    chkEnableLayoutDebug_ = new QCheckBox("Enable Layout Debug");

    using namespace tk;
    auto layout = Box<QVBoxLayout>(
        Box<QHBoxLayout>(
            chkEnableLayoutDebug_,
            Stretch()),
        Box<QHBoxLayout>(
            new QPushButton("Button1"),
            new QPushButton("Button2"),
            new QPushButton("Button3"),
            Stretch()),
        ZeroBox<QHBoxLayout>(
            new QPushButton("Button4"),
            new QPushButton("Button5"),
            new QPushButton("Button6"),
            Stretch()),
        Box<QHBoxLayout>(
            Stretch(),
            new QLineEdit("Edit1"),
            Spacing(100),
            new QLineEdit("Edit2"),
            Stretch()),
        BoxEx<QHBoxLayout>(
            new QPushButton("Button7"),
            new QPushButton("Button8"),
            new QPushButton("Button9"),
            Stretch())
            .setSpacing(30)
            .setContentsMargins(20, 20, 20, 20),
        Widget(new QLineEdit("Edit")),
        Stretch());
    this->setLayout(layout);
}
