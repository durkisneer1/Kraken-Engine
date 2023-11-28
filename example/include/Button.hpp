#include <DurkGame.hpp>


class Button {
public:
    Button(dk::RenderWindow& window);
    ~Button() = default;

    void update();
private:
    dk::RenderWindow& window;
    dk::Texture idleTexture;
    dk::Texture hoverTexture;
    dk::Rect rect;
};
