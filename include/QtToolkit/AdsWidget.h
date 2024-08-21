#ifndef ADSWIDGET_H
#define ADSWIDGET_H
#pragma once

#include "QtToolkit/TKGlobal.h"
#include <QWidget>
#include <QMap>

class QLabel;
class QPushButton;
class QHBoxLayout;
class QSpacerItem;
class QSequentialAnimationGroup;
class QPropertyAnimation;

namespace tk {
class TK_API AdsWidget : public QWidget {
    Q_OBJECT
   public:
    enum NavPosition {
        NavPositionLeft = 0,    //左边
        NavPositionCenter = 1,  //中间
        NavPositionRight = 2    //右边
    };
    Q_ENUM(NavPosition);

    enum NavStyle {
        NavStyleEllipse = 0,  //椭圆条状
        NavStyleCircle = 1,   //圆形
        NavStyleRect = 2,     //矩形
        NavStyleDot = 3,      //小圆点
        NavStyleLongRect = 4  //长条状
    };
    Q_ENUM(NavStyle);

    struct Metadata {
        QString imageUrl;
        QString description;
        QString extraData;
    };

    explicit AdsWidget(QWidget* parent = 0);
    ~AdsWidget();

   signals:
    void clicked(QString extraData);

   public Q_SLOTS:
    //设置轮播数据
    void setMetadata(const QList<Metadata>& metaList);

    // 设置背景色
    // 如果不设置，默认为图片的主题色
    void setBgColor(const QColor& color);

    //设置鼠标悬停时停止轮播
    void setStopWhenHover(bool hoverStop);

    //设置是否显示序号
    void setShowNumber(bool showNumber);

    //设置指示器高度
    void setNavMinHeight(int minHeight);

    //设置指示器最小拉伸宽度
    void setNavMinWidth(int minWidth);

    //设置指示器最大拉伸宽度
    void setNavMaxWidth(int maxWidth);

    //设置切换间隔
    void setSwitchInterval(int interval);

    //设置指示器圆角角度
    void setNavRadius(int navRadius);

    //设置指示器背景色
    void setNavBgColor(const QColor& navColor);

    //设置指示器文字颜色
    void setNavTextColor(const QColor& textColor);

    //设置当前指示器背景色
    void setCurrentNavBgColor(const QColor& navColor);

    //设置当前指示器文字颜色
    void setCurrentNavTextColor(const QColor& textColor);

    //设置描述文字颜色
    void setDescriptionColor(const QColor& descColor);

    //设置指示器位置
    void setNavPosition(const NavPosition& navPosition);

    //设置指示器样式
    void setNavStyle(const NavStyle& navStyle);

   public:
    bool stopWhenHover() const;
    bool showIndexNumber() const;

    int navMinHeight() const;
    int navMinWidth() const;
    int navMaxWidth() const;

    int switchInterval() const;
    int navRadius() const;

    QColor bgColor() const;
    QColor navBgColor() const;
    QColor navTextColor() const;
    QColor descriptionColor() const;

    QList<Metadata> metadata() const;

    NavPosition navPosition() const;
    NavStyle navStyle() const;

    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    bool isNavAnimationEnable() const;
   protected Q_SLOTS:
    void initWidget();
    void initForm();
    void initQSS();
    void changedAds();
    void changedAds(QPushButton* lab);
    void changedMin2Max(const QVariant&);
    void changedMax2Min(const QVariant&);
    void navBtnClicked();
    void updateMetadata();

   protected:
    bool eventFilter(QObject* obj, QEvent* e);
    void enterEvent(QEvent*);
    void leaveEvent(QEvent*);
    void showEvent(QShowEvent*);
    void paintEvent(QPaintEvent*);

   protected:
    bool hoverStop_ = true;         //鼠标悬停停止轮播
    bool showIndexNumber_ = false;  //是否显示序号

    int navMinHeight_;  //指示器最小高度
    int navMinWidth_;   //指示器最小拉伸宽度
    int navMaxWidth_;   //指示器最大拉伸宽度
    int navRadius_;     //指示器圆角角度

    int switchInterval_ = 3000;  //图片切换间隔,单位毫秒

    QColor bgColor_;          // 背景色
    QColor navBgColor_;       //指示器背景色
    QColor navTextColor_;     //指示器文字颜色
    QColor curNavBgColor_;    //当前指示器背景色
    QColor curNavTextColor_;  //当前指示器文字颜色

    QColor descColor_;  //描述文字颜色

    QList<Metadata> metaList_;

    NavPosition navPosition_;  //指示器位置
    NavStyle navStyle_;        //指示器样式

    QList<QPushButton*> btnNavs_;  //存储指示器集合

    int currentIndex_;  //当前图片索引
    int previousIndex;  //上一张图片索引

    QString qssNormal_;   //正常状态样式
    QString qssCurrent_;  //当前状态样式

    QTimer* switchTimer_ = Q_NULLPTR;       //定时器切换
    QHBoxLayout* layout_ = Q_NULLPTR;       //指示器所在布局
    QSpacerItem* spacerLeft_ = Q_NULLPTR;   //左侧弹簧
    QSpacerItem* spacerRight_ = Q_NULLPTR;  //右侧弹簧
    QWidget* widgetNav_ = Q_NULLPTR;        //存放导航指示器的容器

    QMap<QString, QColor> imageThemeColorMap_;

    //动画切换
    QSequentialAnimationGroup* animationGroup_ = Q_NULLPTR;
    QPropertyAnimation* animationMin2Max_ = Q_NULLPTR;
    QPropertyAnimation* animationMax2Min_ = Q_NULLPTR;
};
}  // namespace tk
#endif  // ADSWIDGET2_H
