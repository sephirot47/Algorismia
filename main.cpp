#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>

using namespace std;

int colorSquaredDist(int r1, int g1, int b1, int r2, int g2, int b2) {
    return (double)(r1-r2)*(r1-r2) + (double)(g1-g2)*(g1-g2) + (double)(b1-b2)*(b1-b2);
}

int main()
{
    sf::Image imgTemplate;
    imgTemplate.loadFromFile("sample2.jpg");

    int widthTemplate = imgTemplate.getSize().x;
    int heightTemplate = imgTemplate.getSize().y;
    
    const unsigned char *pixelsTemplate =  imgTemplate.getPixelsPtr();

    sf::Image imgSample;
    imgSample.loadFromFile("sample2.jpg");

    int widthSample = imgSample.getSize().x;
    int heightSample = imgSample.getSize().y;
    
    const unsigned char *pixelsSample =  imgSample.getPixelsPtr();

    int totalDist = 0;
    for(int i = 0; i < widthSample; ++i)
    {
        for(int j = 0; j < heightSample; ++j)
        {
            const unsigned char *ps = &pixelsSample[i*widthSample+j];
            const unsigned char *pt = &pixelsTemplate[i*widthTemplate+j];
            totalDist += colorSquaredDist(ps[0],ps[1],ps[2],pt[0],pt[1],pt[2]);    
        }
    }
    cout << "totalDist: " << abs(totalDist) << endl;

    sf::RenderWindow window(sf::VideoMode(imgTemplate.getSize().x, imgTemplate.getSize().y), "Hola caracolaaa!");

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
