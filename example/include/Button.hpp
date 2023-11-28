#include <DurkGame.hpp>


class Button {
public:
    Button(dk::RenderWindow& window);
    ~Button() = default;

    void update();
    void handleEvents(const SDL_Event& event);
private:
    dk::RenderWindow& window;
    dk::Texture idleTexture;
    dk::Texture hoverTexture;
    dk::Rect rect;
};
