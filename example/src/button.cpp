#include "../include/Button.hpp"
#include <iostream>


Button::Button(dk::RenderWindow& window) :
window(window),
idleTexture(window, { 100, 50 }, { 255, 0, 0 }),
hoverTexture(window, { 100, 50 }, {0, 255, 255 }) {
    rect = idleTexture.getRect();
    rect.setCenter({ WIN_SIZE.x - 100, 75 });
}

void Button::update() {
    if (rect.collidePoint(dk::input::getMousePos())) {
        hoverTexture.drawAt(rect);
        if (dk::input::getMouseButtonPressed() == DK_BUTTON_LEFT) {
            std::cout << "Left Click on Button" << std::endl;
        }
    } else {
        idleTexture.drawAt(rect);
    }
}
