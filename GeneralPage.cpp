#include "GeneralPage.h"
#include "QtToolkit/WidgetCreator.h"
#include <QTimer>
#include "QtToolkit/Misc.h"
#include "QtToolkit/DSLLayout.hpp"

using namespace tk;

GeneralPage::GeneralPage(QWidget* parent /*= Q_NULLPTR*/) :
    QWidget(parent),
    MaskFeature(this, QMargins(0, 0, 0, 0), 0) {
    layoutDebugger_ = new tk::LayoutDebugger(this);

    setupUi();
    bindSignals();
}

void GeneralPage::setupUi() {
    chkEnableLayoutDebug_ = new QCheckBox("Enable Layout Debug");

    btnMask_ = CreateButton("btnMask", "Mask");
    btnToast_ = CreateButton("btnToast", "Toast");

    rollLabel_ = new tk::RollLabel();
    rollLabel_->setFixedWidth(160);
    rollLabel_->setText("This is tk::TKRollLabel sample.");

    lblInvertColor_ = new QLabel("Invert Color Sample");
    lblInvertColor_->setFixedSize(200, 26);
    QColor bgColor(251, 195, 32);
    lblInvertColor_->setStyleSheet(QStringLiteral("font-size: 14px;background-color:%1;color:%2;")
                                       .arg(bgColor.name())
                                       .arg(tk::GetInvertColor(bgColor).name()));

    setLayout(VBoxEx(
        HBox(chkEnableLayoutDebug_, Stretch()),
        HBox(btnMask_, btnToast_, Stretch()),
        HBox(rollLabel_, Stretch()),
        HBox(lblInvertColor_, Stretch()),
        Stretch()).setSpacing(10));
}

void GeneralPage::bindSignals() {
    connect(chkEnableLayoutDebug_, &QCheckBox::toggled, this, [this](bool checked) {
        if (checked)
            this->installEventFilter(layoutDebugger_);
        else
            this->removeEventFilter(layoutDebugger_);
    });

    connect(btnMask_, &QPushButton::clicked, this, [this]() {
        showMask();
        QTimer::singleShot(2000, [this]() { hideMask(); });
    });

    connect(btnToast_, &QPushButton::clicked, this, [this]() {
        ToastWidget* toast = new ToastWidget("This is a toast sample, it will close after 2.5 seconds.", this);
        toast->show();
    });
}
