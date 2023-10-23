#include <iostream>

#include <SFML/Graphics.hpp>

using namespace std;

bool enableMass[8] = { 0,0,0,0,0,0,0,0 };


//имитирует клик и мен€ет три кружка
void clickMass(bool* Mass, int click_index) {
    click_index %= 8;
    int indp1 = click_index + 1;
    int indm1 = click_index - 1;
    Mass[(indm1 < 0) ? 7 : indm1] = !Mass[(indm1 < 0) ? 7 : indm1];
    Mass[click_index] = !Mass[click_index];
    Mass[(indp1 > 7) ? 0 : indp1] = !Mass[(indp1 > 7) ? 0 : indp1];
}

//провер€ет сопадают ли массивы с учетом закольцованности
int eqMass(bool* Mass1, bool* Mass2) {
    for (size_t i = 0; i < 8; i++)
    {
        bool eq = true;
        for (size_t j = 0; j < 8; j++)
        {
            eq = eq && (Mass1[(i + j)%8] == Mass2[j]);
        }
        if (eq) return i;
        
    }
    return -1;
}

//главна€ функци€ автоматического алгоритма
void step(bool* Mass) {
    int countOfEnabled = 0;
    for (size_t i = 0; i < 8; i++)
        countOfEnabled += (enableMass[i]) ? 1 : 0;  //количество включенных
    
    if (countOfEnabled == 0) {
        clickMass(enableMass, 0);
    }
    else if (countOfEnabled == 1) {
        bool mass1[] = { 1,0,0,0,0,0,0,0 };     //шаблон который ищем в массиве отображени€ (1 - значит активированный кружок)
        int ind = eqMass(enableMass, mass1);    //находим индекс
        if (ind != -1) clickMass(enableMass, ind+1);    //если индекс найден, т.е. не равен -1 то кликаем в зависимости от того, куда надо
    }
    else if (countOfEnabled == 2) {
        bool mass1[] = { 1,0,0,1,0,0,0,0 };
        int ind = eqMass(enableMass, mass1);
        if (ind != -1) return clickMass(enableMass, ind + 3);

        bool mass2[] = { 1,1,0,0,0,0,0,0 };
        ind = eqMass(enableMass, mass2);
        if (ind != -1) return clickMass(enableMass, ind + 3);
        
        bool mass3[] = { 1,0,0,0,1,0,0,0 };
        ind = eqMass(enableMass, mass3);
        if (ind != -1) return clickMass(enableMass, ind + 2);

        bool mass4[] = { 1,0,1,0,0,0,0,0 };
        ind = eqMass(enableMass, mass4);
        if (ind != -1) return clickMass(enableMass, ind + 1);
    }
    else if (countOfEnabled == 3) {
        bool mass1[] = { 1,1,1,0,0,0,0,0 };
        int ind = eqMass(enableMass, mass1);
        if (ind != -1) return clickMass(enableMass, ind + 2);

        bool mass2[] = { 1,0,1,0,1,0,0,0 };
        ind = eqMass(enableMass, mass2);
        if (ind != -1) return clickMass(enableMass, ind + 4);

        bool mass3[] = { 1,1,0,1,0,0,0,0 };
        ind = eqMass(enableMass, mass3);
        if (ind != -1) return clickMass(enableMass, ind + 1);

        bool mass4[] = { 1,0,1,1,0,0,0,0 };
        ind = eqMass(enableMass, mass4);
        if (ind != -1) return clickMass(enableMass, ind + 2);

        bool mass5[] = { 1,0,0,1,1,0,0,0 };
        ind = eqMass(enableMass, mass5);
        if (ind != -1) return clickMass(enableMass, ind + 3);

        bool mass6[] = { 1,1,0,0,1,0,0,0 };
        ind = eqMass(enableMass, mass6);
        if (ind != -1) return clickMass(enableMass, ind + 1);

        bool mass7[] = { 1,0,0,1,0,1,0,0 };
        ind = eqMass(enableMass, mass7);
        if (ind != -1) return clickMass(enableMass, ind + 4);
    }
    else if (countOfEnabled == 4) {
        bool mass1[] = { 1,0,1,1,0,1,0,0 };
        int ind = eqMass(enableMass, mass1);
        if (ind != -1) return clickMass(enableMass, ind + 5);

        bool mass2[] = { 1,1,1,1,0,0,0,0 };
        ind = eqMass(enableMass, mass2);
        if (ind != -1) return clickMass(enableMass, ind + 1);

        bool mass3[] = { 1,0,1,1,1,0,0,0 };
        ind = eqMass(enableMass, mass3);
        if (ind != -1) return clickMass(enableMass, ind + 3);

        bool mass4[] = { 1,1,1,0,1,0,0,0 };
        ind = eqMass(enableMass, mass4);
        if (ind != -1) return clickMass(enableMass, ind + 1);

        bool mass5[] = { 1,1,1,0,0,1,0,0 };
        ind = eqMass(enableMass, mass5);
        if (ind != -1) return clickMass(enableMass, ind + 1);

        bool mass6[] = { 1,1,0,0,1,1,0,0 };
        ind = eqMass(enableMass, mass6);
        if (ind != -1) return clickMass(enableMass, ind);

        bool mass7[] = { 1,1,0,1,1,0,0,0 };
        ind = eqMass(enableMass, mass7);
        if (ind != -1) return clickMass(enableMass, ind + 2);

        bool mass8[] = { 1,1,0,0,0,1,1,0 };
        ind = eqMass(enableMass, mass8);
        if (ind != -1) return clickMass(enableMass, ind + 7);

        bool mass9[] = { 1,0,1,0,1,0,1,0 };
        ind = eqMass(enableMass, mass9);
        if (ind != -1) return clickMass(enableMass, ind + 1);
    }
    else if (countOfEnabled == 5) {
        bool mass1[] = { 1,0,1,1,1,0,1,0 };
        int ind = eqMass(enableMass, mass1);
        if (ind != -1) return clickMass(enableMass, ind + 6);

        bool mass2[] = { 0,0,0,1,1,1,1,1 };
        ind = eqMass(enableMass, mass2);
        if (ind != -1) return clickMass(enableMass, ind + 1);

        bool mass3[] = { 1,0,1,1,1,1,0,0 };
        ind = eqMass(enableMass, mass3);
        if (ind != -1) return clickMass(enableMass, ind + 4);

        bool mass4[] = { 0,0,1,1,1,1,0,1 };
        ind = eqMass(enableMass, mass4);
        if (ind != -1) return clickMass(enableMass, ind + 3);

        bool mass5[] = { 1,1,1,0,1,0,1,0 };
        ind = eqMass(enableMass, mass5);
        if (ind != -1) return clickMass(enableMass, ind + 1);

        bool mass6[] = { 1,1,1,0,0,1,1,0 };
        ind = eqMass(enableMass, mass6);
        if (ind != -1) return clickMass(enableMass, ind + 1);

        bool mass7[] = { 1,1,1,0,1,1,0,0 };
        ind = eqMass(enableMass, mass7);
        if (ind != -1) return clickMass(enableMass, ind + 1);

        bool mass8[] = { 0,1,0,1,1,0,1,1 };
        ind = eqMass(enableMass, mass8);
        if (ind != -1) return clickMass(enableMass, ind + 5);
    }
    else if (countOfEnabled == 6) {
        bool mass1[] = { 0,1,1,1,1,0,1,1 };
        int ind = eqMass(enableMass, mass1);
        if (ind != -1) return clickMass(enableMass, ind + 6);

        bool mass2[] = { 1,1,1,1,1,1,0,0 };
        ind = eqMass(enableMass, mass2);
        if (ind != -1) return clickMass(enableMass, ind + 1);

        bool mass3[] = { 1,1,1,1,1,0,1,0 };
        ind = eqMass(enableMass, mass3);
        if (ind != -1) return clickMass(enableMass, ind + 1);

        bool mass4[] = { 1,1,1,0,1,1,1,0 };
        ind = eqMass(enableMass, mass4);
        if (ind != -1) return clickMass(enableMass, ind);
    }
    else if (countOfEnabled == 7) {
        bool mass1[] = { 1,1,1,1,1,1,1,0 };
        int ind = eqMass(enableMass, mass1);
        if (ind != -1) return clickMass(enableMass, ind + 1);
    }
}

//функци€ провер€юща€ нажата ли область внутри кргуа
bool checkClick(sf::CircleShape obj, sf::Vector2i posMouse) {
    sf::Vector2f posObj = obj.getPosition();
    float R = obj.getRadius();
    float center_x = posObj.x + R;
    float center_y = posObj.y + R;
    return sqrt(pow(posMouse.x - center_x, 2) + pow(posMouse.y - center_y, 2)) <= R;
}

int main()
{
    // 1 - автоматический шаг
    // 2 - сменить режим игры (по 1 или по 3)
    /////////////  INIT
    sf::Color enableColor = sf::Color::Cyan;
    sf::Color disableColor = sf::Color::Red;

    int width = 270, height = 270;
    int radius_sphere = 40;

    bool edit_mode = false;
    /////////////  INIT

    //создаем окно sfml
    sf::RenderWindow window(sf::VideoMode(width, height), "The Game!");
    
    //массив дл€ кружков
    sf::CircleShape circle_mass[8];
    for (size_t i = 0; i < 8; i++)
    {
        circle_mass[i] = sf::CircleShape(40);       //создаем кружок радиуса 40
        circle_mass[i].setFillColor(disableColor);  //заполн€ем выключенным цветом
    }

    //размещаем все кружки по пиксельно
    circle_mass[0].setPosition(0, 0);
    circle_mass[1].setPosition(90, 0);
    circle_mass[2].setPosition(180, 0);
    circle_mass[7].setPosition(0, 90);
    circle_mass[3].setPosition(180, 90);
    circle_mass[6].setPosition(0, 180);
    circle_mass[5].setPosition(90, 180);
    circle_mass[4].setPosition(180, 180);
    //FPS
    window.setFramerateLimit(60);

    //пока окно открыто
    while (window.isOpen())
    {
        sf::Event event;
        //пока есть событи€
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            //если было нажатие левой клавиши мыши
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                //получаем позицию мыши
                sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                //провер€ем все 8 кружков на клик внутри них  
                for (size_t i = 0; i < 8; i++)
                {
                    //еслиесть клик то в зависимости от режима мен€ем один или 3 круга
                    if (checkClick(circle_mass[i], localPosition)) {
                        if (edit_mode)
                            enableMass[i] = !enableMass[i];
                        else
                            clickMass(enableMass, i);
                    }
                }
            }
            
            //событи€ клавиутры (клик на цифру 1 или 2
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Num1) 
                    step(enableMass);           //автоматический шаг
                if (event.key.code == sf::Keyboard::Num2) 
                    edit_mode = !edit_mode;     //смена режима
            }
        }

        //очистка окна перед перерисовкой
        window.clear();
        //отрисовка всех кружков в зависимости от их состо€ни€
        for (size_t i = 0; i < 8; i++)
        {   
            if (enableMass[i]) 
                circle_mass[i].setFillColor(enableColor);
            else 
                circle_mass[i].setFillColor(disableColor);
            window.draw(circle_mass[i]);
        }
        window.display();
    }

    return 0;
}