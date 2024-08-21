#pragma once
#include <QWidget>
#include <QLabel>

class ObtainSourcePage : public QWidget {
    Q_OBJECT
   public:
    ObtainSourcePage(QWidget* parent = Q_NULLPTR);

   private:
    QLabel* lblText_ = nullptr;
};
