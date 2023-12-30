#include "../include/Draw.hpp"


namespace kn {
namespace draw {

void rect(RenderWindow& window, Rect& rect, const SDL_Color& color, int thickness) {
    SDL_SetRenderDrawColor(window.getRenderer(), color.r, color.g, color.b, color.a);
    if (thickness == 0) {
        SDL_RenderFillRectF(window.getRenderer(), &rect);
        return;
    }

    if (thickness > rect.w / 2 || thickness > rect.h / 2) {
        thickness = (int)std::min(rect.w / 2, rect.h / 2);
    }

    for (int i = 0; i < thickness; i++) {
        Rect layerRect = { rect.x + i, rect.y + i, rect.w - i * 2, rect.h - i * 2 };
        SDL_RenderDrawRectF(window.getRenderer(), &layerRect);
    }
}

}
}
