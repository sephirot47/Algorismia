#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
    sf::Image img;
    img.loadFromFile("img.jpg");
    img.getPixel(0, 1);
    for(int i = 0; i < img.getSize().x; ++i)
    {
        for(int j = 0; j < img.getSize().y; ++j)
        {
            cout << "(" << (int)img.getPixel(i, j).r << ", " << (int)img.getPixel(i, j).g << ", " << (int)img.getPixel(i, j).b << ")" << endl;
        }
    }


    sf::RenderWindow window(sf::VideoMode(img.getSize().x, img.getSize().y), "Hola caracolaaa!");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }

    return 0;
}
