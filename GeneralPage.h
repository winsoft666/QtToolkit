#pragma once
#include <QPushButton>
#include <QCheckBox>
#include "QtToolkit/FlowLayout.h"
#include "QtToolkit/MaskFeature.h"
#include "QtToolkit/ToastWidget.h"
#include "QtToolkit/RollLabel.h"
#include "QtToolkit/LayoutDebugger.h"
#include <vector>

class GeneralPage : public QWidget,
                    public tk::MaskFeature {
    Q_OBJECT
   public:
    GeneralPage(QWidget* parent = Q_NULLPTR);

   private:
    void setupUi();
    void bindSignals();

   private:
    tk::LayoutDebugger* layoutDebugger_ = Q_NULLPTR;
    QCheckBox* chkEnableLayoutDebug_ = Q_NULLPTR;
    tk::FlowLayout* flowlayout_ = Q_NULLPTR;
    QPushButton* btnMask_ = Q_NULLPTR;
    QPushButton* btnToast_ = Q_NULLPTR;
    tk::RollLabel* rollLabel_ = Q_NULLPTR;
    QLabel* lblInvertColor_ = Q_NULLPTR;
};