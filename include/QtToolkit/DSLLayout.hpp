#ifndef TK_DSL_LAYOUT_H_
#define TK_DSL_LAYOUT_H_
#pragma once

#include <tuple>

// via: https://stackoverflow.com/a/16387374

// Alternate solution:
//     - https://stackoverflow.com/a/26912970
//           + Port of std::index_sequence for c++11: https://stackoverflow.com/a/32223343
//
// In case of post c++11 version - use it:
//     - https://www.fluentcpp.com/2019/03/08/stl-algorithms-on-tuples/

namespace tk {
namespace meta {
namespace detail {
template <int... Is>
struct seq {};

template <int N, int... Is>
struct gen_seq : gen_seq<N - 1, N - 1, Is...> {};

template <int... Is>
struct gen_seq<0, Is...> : seq<Is...> {};

template <typename T, typename F, int... Is>
inline void for_each(T& tuple, F&& func, seq<Is...>) {
    auto l = {(func(std::get<Is>(tuple)), 0)...};
    (void)l;  // Suppress compiler warning
}

template <typename T, typename F, int... Is>
inline void for_each(const T& tuple, F&& func, seq<Is...>) {
    auto l = {(func(std::get<Is>(tuple)), 0)...};
    (void)l;  // Suppress compiler warning
}
}  // namespace detail

template <typename... Ts, typename F>
inline void for_each_in_tuple(std::tuple<Ts...>& tuple, F&& func) {
    constexpr auto COUNT = sizeof...(Ts);
    detail::for_each(tuple, func, detail::gen_seq<COUNT>());
}

template <typename... Ts, typename F>
inline void for_each_in_tuple(const std::tuple<Ts...>& tuple, F&& func) {
    constexpr auto COUNT = sizeof...(Ts);
    detail::for_each(tuple, func, detail::gen_seq<COUNT>());
}
}  // namespace meta
}  // namespace tk

// =============================================================================

#include <QLayout>

namespace tk {

// Set Widget info
struct WidgetInfo {
    // Default values, which passes into: QBoxLayout::addWidget()
    // https://doc.qt.io/Qt-5/qboxlayout.html#addWidget

    QWidget* widget = nullptr;
    int stretch = 0;
    Qt::Alignment alignment = Qt::Alignment();

    explicit WidgetInfo(QWidget* w, int s = 0, Qt::Alignment a = Qt::Alignment()) :
        widget(w), stretch(s), alignment(a) {}
};

// Set Layout info
struct LayoutInfo {
    // Default values, which passes into: QBoxLayout::addLayout()
    // https://doc.qt.io/qt-5/qboxlayout.html#addLayout

    QLayout* layout = nullptr;
    int stretch = 0;

    explicit LayoutInfo(QLayout* l, int s = 0) :
        layout(l), stretch(s) {}
};

struct Stretch {
    int _stretch = 0;
    explicit Stretch(int s = 0) :
        _stretch(s) {}
};

struct Spacing {
    int _spacing = 0;
    explicit Spacing(int s) :
        _spacing(s) {}
};

template <typename WidgetT>
struct WidgetWrapper {
    // Captured
    WidgetT* _widget = nullptr;

    // Default
    int _stretch = 0;
    Qt::Alignment _alignment = Qt::Alignment();

   public:
    explicit WidgetWrapper(WidgetT* w) :
        _widget(w) {}

    WidgetWrapper& setStretch(int s) {
        _stretch = s;
        return *this;
    }

    WidgetWrapper& setAlignment(Qt::Alignment a) {
        _alignment = a;
        return *this;
    }
};

namespace detail {
template <typename BaseLayoutT>
struct LayoutFiller {
    static_assert(std::is_base_of<QLayout, BaseLayoutT>::value == true,
                  "BaseLayoutT must be derived from QLayout");

    // Captured
    BaseLayoutT* lay = nullptr;

    // Make capture
    explicit LayoutFiller(BaseLayoutT* lay_) :
        lay(lay_) {}

    // Call .addWidget(), if item is QWidget
    void operator()(QWidget* widget) {
        lay->addWidget(widget);
    }

    // Call .addLayout(), if item is QLayout
    void operator()(QLayout* layout) {
        lay->addLayout(layout);
    }

    // Call .addWidget(widget*, int stretch, Qt::Alignment align), if item is struct with info about it
    void operator()(const WidgetInfo& i) {
        lay->addWidget(i.widget, i.stretch, i.alignment);
    }

    // Call .addLayout(layout*, int stretch), if item is struct with info about it
    void operator()(const LayoutInfo& i) {
        lay->addLayout(i.layout, i.stretch);
    }

    // Call .addSpacing(int spacing), if item is struct with info about Spacing
    void operator()(const Spacing& s) {
        lay->addSpacing(s._spacing);
    }

    // Call .addStretch(int stretch), if item is struct with info about Stretch
    void operator()(const Stretch& s) {
        lay->addStretch(s._stretch);
    }

    template <typename W_t>
    void operator()(const WidgetWrapper<W_t>& wrapper) {
        lay->addWidget(wrapper._widget, wrapper._stretch, wrapper._alignment);
    }
};

}  // namespace detail

// TODO: C++17
//     - Use std::apply instead of for_each_in_tuple
//     - Use std::visit instead of detail::LayoutFiller<LayoutT>
//
//     - Or instead of using `tuple`, simply use fold expressions
//       - https://en.cppreference.com/w/cpp/language/fold

// Univercal reference (Items&& ... items) everywhere, because in function can be
// passed pointers (QLayout*, QWidget*) and non-pointers (info{widget, stretch, alignment})

/// Fill existing @a layout by @a items (layouts and widgets)
template <typename LayoutT, typename... Items>
LayoutT* FillBox(LayoutT* layout, Items&&... items) {
    // const std::tuple<Items&& ...> t {items ...}; // <-- not works, produces compiling errors
    const auto t = std::forward_as_tuple(items...);  // Pack variadic argumets into tuple for iteration over it

    detail::LayoutFiller<LayoutT> filler(layout);  // Capture layout
    meta::for_each_in_tuple(t, filler);            // Call detail::LayoutFiller<LayoutT>::() operator for each item in tuple

    return layout;
}

/// Create new layout and fill it by @a items (layouts and widgets)
template <typename LayoutT, typename... Items>
LayoutT* Box(Items&&... items) {
    LayoutT* layout = new LayoutT;
    return FillBox<LayoutT>(layout, items...);
}

template <typename... Items>
QHBoxLayout* HBox(Items&&... items) {
    QHBoxLayout* layout = new QHBoxLayout;
    return FillBox<QHBoxLayout>(layout, items...);
}

template <typename... Items>
QVBoxLayout* VBox(Items&&... items) {
    QVBoxLayout* layout = new QVBoxLayout;
    return FillBox<QVBoxLayout>(layout, items...);
}

/// Create new layout (spacing is 0 and contentsMargin is 0) and fill it by @a items (layouts and widgets)
template <typename LayoutT, typename... Items>
LayoutT* ZeroBox(Items&&... items) {
    LayoutT* layout = new LayoutT;
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);
    return FillBox<LayoutT>(layout, items...);
}

template <typename... Items>
QHBoxLayout* ZeroHBox(Items&&... items) {
    QHBoxLayout* layout = new QHBoxLayout;
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);
    return FillBox<QHBoxLayout>(layout, items...);
}

template <typename... Items>
QVBoxLayout* ZeroVBox(Items&&... items) {
    QVBoxLayout* layout = new QVBoxLayout;
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);
    return FillBox<QVBoxLayout>(layout, items...);
}

template <typename LayoutT>
struct LayoutWrapper {
    static_assert(std::is_base_of<QLayout, LayoutT>::value == true,
                  "LayoutT must be derived from QLayout");

    LayoutT* captured = nullptr;

    explicit LayoutWrapper(LayoutT* lay) :
        captured(lay) {}

    LayoutWrapper& setSpacing(int spacing) {
        captured->setSpacing(spacing);
        return *this;
    }

    LayoutWrapper& setMargin(int margin) {
        captured->setMargin(margin);
        return *this;
    }

    LayoutWrapper& setContentsMargins(int left, int top, int right, int bottom) {
        captured->setContentsMargins(left, top, right, bottom);
        return *this;
    }

    // Implicit conversion to layout
    operator LayoutT*() {
        return captured;
    }
};

template <typename LayoutT, typename... Items>
LayoutWrapper<LayoutT> BoxEx(Items&&... items) {
    return LayoutWrapper<LayoutT>(Box<LayoutT>(items...));
}

template <typename... Items>
LayoutWrapper<QVBoxLayout> VBoxEx(Items&&... items) {
    return LayoutWrapper<QVBoxLayout>(Box<QVBoxLayout>(items...));
}

template <typename... Items>
LayoutWrapper<QHBoxLayout> HBoxEx(Items&&... items) {
    return LayoutWrapper<QHBoxLayout>(Box<QHBoxLayout>(items...));
}

template <typename WidgetT>
WidgetWrapper<WidgetT> Widget(WidgetT* widget) {
    return WidgetWrapper<WidgetT>(widget);
}

}  // namespace tk

#endif  // !TK_DSL_LAYOUT_H_
