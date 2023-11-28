#include "../include/Button.hpp"
#include <iostream>


Button::Button(dk::RenderWindow& window) :
window(window),
idleTexture(window, { 100, 50 }, { 255, 0, 0 }),
hoverTexture(window, { 100, 50 }, { 0, 255, 0 }) {
    rect = idleTexture.getRect();
    rect.setCenter({ WIN_SIZE.x - 100, 75 });
}

void Button::handleEvents(const SDL_Event& event) {
    if (event.type == DK_MOUSEBUTTONDOWN) {
        if (event.button.button == DK_BUTTON_LEFT && rect.collidePoint(dk::input::getMousePos())) {
            std::cout << "Left Click on Button" << std::endl;
        } else {}
    } else {}
}

void Button::update() {
    rect.collidePoint(dk::input::getMousePos()) ? hoverTexture.drawAt(rect) : idleTexture.drawAt(rect);
}
