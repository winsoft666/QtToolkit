#pragma once

#include "QtToolkit/TKGlobal.h"

namespace tk {
struct TK_API RectVertex {
    int topLeft;
    int topRight;
    int bottomLeft;
    int bottomRight;

    RectVertex() :
        topLeft(0),
        topRight(0),
        bottomLeft(0),
        bottomRight(0) {
    }

    RectVertex(int tl, int tr, int bl, int br) :
        topLeft(tl),
        topRight(tr),
        bottomLeft(bl),
        bottomRight(br) {
    }

    bool isAllZero() const {
        return topLeft == 0 && topRight == 0 && bottomLeft == 0 && bottomRight == 0;
    }
};
}  // namespace tk