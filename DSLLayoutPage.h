#pragma once
#include <QtWidgets>
#include "QtToolkit/LayoutDebugger.h"

class DSLLayoutPage : public QWidget {
    Q_OBJECT
   public:
    DSLLayoutPage(QWidget* parent = nullptr);

   private:
    void setupUi();

   private:
    tk::LayoutDebugger* layoutDebugger_ = Q_NULLPTR;
    QCheckBox* chkEnableLayoutDebug_ = Q_NULLPTR;
};
