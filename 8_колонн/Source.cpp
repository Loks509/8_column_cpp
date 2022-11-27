#include <iostream>

#include <SFML/Graphics.hpp>

using namespace std;

bool enableMass[8] = { 0,0,0,0,0,0,0,0 };


void clickMass(bool* Mass, int click_index) {
    int indp1 = click_index + 1;
    int indm1 = click_index - 1;
    Mass[(indm1 < 0) ? 7 : indm1] = !Mass[(indm1 < 0) ? 7 : indm1];
    Mass[click_index] = !Mass[click_index];
    Mass[(indp1 > 7) ? 0 : indp1] = !Mass[(indp1 > 7) ? 0 : indp1];
}

void step(bool* Mass) {
    int countOfEnabled = 0;
    for (size_t i = 0; i < 8; i++)
        countOfEnabled += (enableMass[i]) ? 1 : 0;
    
    switch (countOfEnabled)
    {
    case 0:
        clickMass(enableMass, 0);
        break;
    case 1:

        break;
    case 2:
        break;
    case 3:
        
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    default:
        break;
    }

}

bool checkClick(sf::CircleShape obj, sf::Vector2i posMouse) {
    sf::Vector2f posObj = obj.getPosition();
    float R = obj.getRadius();
    float center_x = posObj.x + R;
    float center_y = posObj.y + R;
    return sqrt(pow(posMouse.x - center_x, 2) + pow(posMouse.y - center_y, 2)) <= R;
}

int main()
{
    /////////////  INIT
    sf::Color enableColor = sf::Color::Cyan;
    sf::Color disableColor = sf::Color::Red;

    int width = 270, height = 270;
    int radius_sphere = 40;
    /////////////  INIT

    
    sf::RenderWindow window(sf::VideoMode(width, height), "The Game!");
    
    sf::CircleShape circle_mass[8];
    for (size_t i = 0; i < 8; i++)
    {
        circle_mass[i] = sf::CircleShape(40);
        circle_mass[i].setFillColor(disableColor);
    }

    circle_mass[0].setPosition(0, 0);
    circle_mass[1].setPosition(90, 0);
    circle_mass[2].setPosition(180, 0);
    circle_mass[7].setPosition(0, 90);
    circle_mass[3].setPosition(180, 90);
    circle_mass[6].setPosition(0, 180);
    circle_mass[5].setPosition(90, 180);
    circle_mass[4].setPosition(180, 180);
    window.setFramerateLimit(60);


    while (window.isOpen())
    {
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                for (size_t i = 0; i < 8; i++)
                {
                    if (checkClick(circle_mass[i], localPosition)) {
                        clickMass(enableMass, i);
                    }
                }
            }
            
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Num1) {
                    step(enableMass);
                }
            }
        }

        window.clear();
        for (size_t i = 0; i < 8; i++)
        {
            if (enableMass[i]) {
                circle_mass[i].setFillColor(enableColor);
            }
            else {
                circle_mass[i].setFillColor(disableColor);
            }
            window.draw(circle_mass[i]);
        }
        window.display();
    }

    return 0;
}