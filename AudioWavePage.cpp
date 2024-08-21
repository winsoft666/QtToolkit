#include "AudioWavePage.h"
#include "QtToolkit/WidgetCreator.h"
#include <QFile>
#include <QTimer>

AudioWavePage::AudioWavePage(QWidget* parent /*= Q_NULLPTR*/) :
    QWidget(parent) {
    data_ = readFile(":/Sample/audio_data/data2.txt");

    QLinearGradient lg;
    lg.setColorAt(0.0, QColor(0x791e09));
    lg.setColorAt(0.5, QColor(0x6d7909));
    lg.setColorAt(1.0, QColor(0x00d4ff));

    dataStep_ = data_.size() / 50;

    audioWave1_ = new tk::AudioWaveWidget();
    audioWave1_->setWaveStyle(tk::AudioWaveWidget::WaveStyleLine);
    audioWave1_->setShowMarkerLine(true);

    audioWave2_ = new tk::AudioWaveWidget();
    audioWave2_->setWaveStyle(tk::AudioWaveWidget::WaveStyleSmooth);
    audioWave2_->setDataLinearGradientColor(lg);
    audioWave2_->setDataLineWidth(2);
    audioWave2_->setShowMarkerLine(true);

    audioWave3_ = new tk::AudioWaveWidget();
    audioWave3_->setWaveStyle(tk::AudioWaveWidget::WaveStyleBar);
    audioWave3_->setDataLinearGradientColor(lg);
    audioWave3_->setShowMarkerLine(true);

    QVBoxLayout* v = tk::CreateVLayout();
    {
        v->addWidget(audioWave1_);
        v->addWidget(audioWave2_);
        v->addWidget(audioWave3_);
    }

    setLayout(v);

    dataUpdateTimer_ = new QTimer(this);
    dataUpdateTimer_->setInterval(1000);
    connect(dataUpdateTimer_, &QTimer::timeout, this, &AudioWavePage::onDataUpdateTimeout);
    dataUpdateTimer_->start();
}

void AudioWavePage::onDataUpdateTimeout() {
    QVector<float>& dataRef = data_;

    int startPos = dataPos_;
    int endPos = startPos + dataStep_;

    if (endPos >= dataRef.size()) {
        endPos = dataRef.size() - 1;
        dataPos_ = 0;
    }
    else {
        dataPos_ = endPos + 1;
    }

    QVector<float> data;
    for (int i = startPos; i <= endPos; i++) {
        data.append(dataRef[i]);
    }

    audioWave1_->setData(data);
    audioWave2_->setData(data);
    audioWave3_->setData(data);
}

QVector<float> AudioWavePage::readFile(const QString& file) {
    QVector<float> data;
    QFile f(file);
    if (f.open(QFile::ReadOnly)) {
        QString str = f.readAll();
        QStringList list = str.split(" ");
        foreach (QString s, list) {
            data.append(s.toDouble());
        }
    }

    return data;
}
