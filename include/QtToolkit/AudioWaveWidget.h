#ifndef TK_AUDIO_WAVE_H_
#define TK_AUDIO_WAVE_H_
#pragma once

#include <QWidget>
#include "QtToolkit/TKGlobal.h"
#include <QBrush>

namespace tk {
/*
* 音频波形图
* 支持三种线条样式
* 最多同时显示3条波形曲线，可分别设置3条波形曲线的颜色和样式
*/
class TK_API AudioWaveWidget : public QWidget {
    Q_OBJECT
    Q_ENUMS(WaveStyle)
    Q_PROPERTY(bool showMarkerLine_ READ getShowMarkerLine WRITE setShowMarkerLine)
    Q_PROPERTY(int markerLineWidth_ READ getMarkerLineWidth WRITE setMarkerLineWidth)

    Q_PROPERTY(QColor bgColor_ READ getBgColor WRITE setBgColor)
    Q_PROPERTY(QColor markerLineColor_ READ getMarkerLineColor WRITE setMarkerLineColor)
    Q_PROPERTY(QColor dataColor_ READ getDataColor WRITE setDataColor)
    Q_PROPERTY(QColor dataColor2_ READ getDataColor2 WRITE setDataColor2)
    Q_PROPERTY(QColor dataColor3_ READ getDataColor3 WRITE setDataColor3)
    Q_PROPERTY(WaveStyle waveStyle_ READ getWaveStyle WRITE setWaveStyle)

   public:
    enum WaveStyle {
        WaveStyleLine = 0,    //线条风格
        WaveStyleSmooth = 1,  //平滑风格
        WaveStyleBar = 2      //柱状风格，柱状条宽度自适应，柱状条间隔为柱条宽度的40%
    };

    explicit AudioWaveWidget(QWidget* parent = 0);

   public:
    bool getShowMarkerLine() const;
    int getMarkerLineWidth() const;

    QColor getBgColor() const;
    QColor getMarkerLineColor() const;
    QColor getDataColor() const;
    QColor getDataColor2() const;
    QColor getDataColor3() const;
    int getDataLineWidth() const;
    WaveStyle getWaveStyle() const;

    int getLength() const;
    int getPosition() const;

    QVector<float> getData() const;
    QVector<float> getData2() const;
    QVector<float> getData3() const;

    QSize sizeHint() const;
    QSize minimumSizeHint() const;

   public Q_SLOTS:
    // 设置是否显示标记线
    void setShowMarkerLine(bool showLine);

    // 标记线宽度
    void setMarkerLineWidth(int lineWidth);

    // 标记线颜色
    void setMarkerLineColor(const QColor& lineColor);

    //设置背景颜色，单一纯色
    void setBgColor(const QColor& bgColor);

    //设置背景渐变色，优先级高于单一纯色
    void setBgLinearGradientColor(const QLinearGradient& bgLinearGradientColor);

    // 设置数据线条颜色或渐变色
    // 渐变色优先级高于单一纯色
    void setDataColor(const QColor& dataColor);
    void setDataLinearGradientColor(const QLinearGradient& dataLinearGradientColor);

    void setDataColor2(const QColor& dataColor2);
    void setDataLinearGradientColor2(const QLinearGradient& dataLinearGradientColor2);

    void setDataColor3(const QColor& dataColor3);
    void setDataLinearGradientColor3(const QLinearGradient& dataLinearGradientColor3);

    // 设置数据线的宽度（对WaveStyleBar样式无效）
    void setDataLineWidth(int w);

    //设置数据样式
    void setWaveStyle(const WaveStyle& waveStyle);

    //设置总长度+当前位置
    void setLength(int length);
    void setPosition(int position);

    //设置当前数据+清空数据
    void setData(const QVector<float>& data);
    void setData2(const QVector<float>& data2);
    void setData3(const QVector<float>& data3);
    void clearData();

   protected:
    void mousePressEvent(QMouseEvent*);
    void paintEvent(QPaintEvent*);
    void drawBg(QPainter* painter);
    void drawData(QPainter* painter,
                  const QVector<float>& data,
                  bool dataLgValid,
                  const QColor& dataColor,
                  QLinearGradient dataLgColor);
    void drawMarkerLine(QPainter* painter);

   Q_SIGNALS:
    void positionChanged(int position);

   protected:
    bool showMarkerLine_;     //显示标记线条
    int markerLineWidth_;     // 标记线条宽度
    QColor markerLineColor_;  //线条颜色

    QColor bgColor_;  //背景色
    bool bgLgColorValid_ = false;
    QLinearGradient bgLgColor_;  // 背景渐变色

    int dataLineWidth_;  // 数据线条宽度

    QColor dataColor_;  // 数据曲线颜色
    bool dataLgColorValid_ = false;
    QLinearGradient dataLgColor_;  // 数据曲线渐变颜色

    QColor dataColor2_;  // 数据曲线颜色2
    bool dataLgColor2Valid_ = false;
    QLinearGradient dataLgColor2_;  // 数据曲线2渐变颜色

    QColor dataColor3_;  // 数据曲线颜色3
    bool dataLgColor3Valid_ = false;
    QLinearGradient dataLgColor3_;  // 数据曲线3渐变颜色

    WaveStyle waveStyle_;  // 数据线条样式

    int length_;    // 采样点长度
    int position_;  // 当前位置

    QVector<float> data_;   // 采样点数据
    QVector<float> data2_;  // 采样点数据2
    QVector<float> data3_;  // 采样点数据3
};
}  // namespace tk
#endif  // TK_AUDIO_WAVE_H_
