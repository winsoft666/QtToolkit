#include "Sample.h"
#include "QtToolkit/WidgetCreator.h"
#include "GeneralPage.h"
#include "AdsWidgetPage.h"
#include "SelectWidgetPage.h"
#include "ClockPage.h"
#include "StuffLabelPage.h"
#include "AudioWavePage.h"
#include "DSLLayoutPage.h"
#include "ProgressPage.h"
#include "GaugePage.h"
#include "PaginationPage.h"
#include "WidgetTablePage.h"
#include "ObtainSourcePage.h"

Sample::Sample(QWidget* parent) :
    QMainWindow(parent) {
    setWindowTitle("A sample for QtToolkit library");

    setupUi();

    appendTab("General", new GeneralPage());
    appendTab("Ads", new AdsWidgetPage());
    appendTab("Select", new SelectWidgetPage());
    appendTab("Clock", new ClockPage());
    appendTab("Stuff Label", new StuffLabelPage());
    appendTab("Audio Wave", new AudioWavePage());
    appendTab("DSL Layout", new DSLLayoutPage());
    appendTab("Progress", new ProgressPage());
    appendTab("Gauge", new GaugePage());
    appendTab("Pagination", new PaginationPage());
    appendTab("Widget Table", new WidgetTablePage());
    appendTab("Obtain Source Code", new ObtainSourcePage());
}

Sample::~Sample() {}

void Sample::setupUi() {
    tab_ = new QTabWidget();
    tab_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    setCentralWidget(tab_);

    resize(860, 600);
}

void Sample::appendTab(const QString& title, QWidget* widget) {
    Q_ASSERT(widget);
    tab_->addTab(widget, title);
}
