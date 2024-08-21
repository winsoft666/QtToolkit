#pragma once
#include "QtToolkit/AudioWaveWidget.h"

class AudioWavePage : public QWidget {
    Q_OBJECT
   public:
    AudioWavePage(QWidget* parent = Q_NULLPTR);

   private slots:
    void onDataUpdateTimeout();

   private:
    QVector<float> readFile(const QString& file);

   private:
    tk::AudioWaveWidget* audioWave1_ = Q_NULLPTR;
    tk::AudioWaveWidget* audioWave2_ = Q_NULLPTR;
    tk::AudioWaveWidget* audioWave3_ = Q_NULLPTR;

    QVector<float> data_;

    QTimer* dataUpdateTimer_;
    int dataPos_ = 0;
    int dataStep_ = 0;
};