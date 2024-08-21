#pragma once

#include <QtWidgets/QMainWindow>

class Sample : public QMainWindow {
    Q_OBJECT
   public:
    Sample(QWidget* parent = nullptr);
    ~Sample();

   private:
    void setupUi();
    void appendTab(const QString& title, QWidget* widget);

   private:
    QTabWidget* tab_ = Q_NULLPTR;
};
