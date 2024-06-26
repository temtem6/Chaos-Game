// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>

// Make code easier to type with "using namespace"
using namespace sf;
using namespace std;

int main()
{
    // Create a video mode object
	VideoMode vm(1920, 1080);
	// Create and open a window for the game
	RenderWindow window(vm, "Timber Game!!", Style::Default);

    vector<Vector2f> vertices;
    vector<Vector2f> points;
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "Unable to upload file" << std::endl;
    }
    sf::Text text;
    text.setFont(font);
    text.setString("Click on 3 points to draw the triangle.");
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold);

    
    while (window.isOpen())
    {
        /*
        ****************************************
        Handle the players input
        ****************************************
        */
        //I made additions from the font/text sfml until the window.draw(text)

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                // Quit the game when the window is closed
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    std::cout << "the left button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;

                    if (vertices.size() < 3)
                    {
                        vertices.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
                    }
                    else if (points.size() == 0)
                    {
                        ///fourth click
                        ///push back to points vector
                        //I went ahead and added the std::cout and the push_back. Lemme know
                        //if that the implementation requires changes
                        std::cout << "click a point inside the triangle" << std::endl;
                        points.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
                    }
                }
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }
        /*
   ****************************************
   Update
   ****************************************
   */
        //window.clear();
        //window.draw(text);
            for (int i = 0; i < 1; i++)
            {
                if (points.size() > 0)
                {
                    /*
                    ///generate more point(s)
                    ///select random vertex
                    ///calculate midpoint between random vertex and the last point in the vector
                    ///push back the newly generated coord.
                    int a;
                    a = rand() % 3;
                    //we will use rand to give us the random vertex
                    float x;
                    float y;
                    //So in this case, we make x for the x-coordinate when we take the diff
                    //y for the y-coordinate for the y dif
                    //then we just push this new coordinate into the points vector.
                    if (points.at(points.size() -1 ).x < vertices.at(a).x)
                    {
                        x = (vertices.at(a).x - points.at(points.size() - 1).x) / 2 + points.at(points.size() - 1).x;
                    }
                    else {
                        x = points.at(points.size() - 1).x - (points.at(points.size() - 1).x - vertices.at(a).x) / 2;
                    }
                    if (points.at(points.size() - 1).y < vertices.at(a).y)
                    {
                        y = (vertices.at(a).y - points.at(points.size() - 1).y) / 2 + points.at(points.size() - 1).y;
                    }
                    else
                    {
                        y = points.at(points.size() - 1).y - (points.at(points.size() - 1).y - vertices.at(a).y) / 2;
                    }
                    points.push_back(Vector2f(x, y));
                    */
                 
                    int a = rand() % 3;
                    float x;
                    float y;
                    
                    
                        x = (vertices.at(a).x + points.at(points.size() - 1).x) / 2;
                   
                        y = (vertices.at(a).y + points.at(points.size() - 1).y) / 2;
                   
                    points.push_back(Vector2f(x, y));
                }
            }
            /*
        ****************************************
        Draw
        ****************************************
        */
            window.clear();
            window.draw(text);
        for (int i = 0; i < vertices.size(); i++)
        {
            RectangleShape rect(Vector2f(10, 10));
            rect.setPosition(Vector2f(vertices.at(i).x, vertices.at(i).y));
            rect.setFillColor(Color::Yellow);
            window.draw(rect);
        }
        int n = points.size();// / 10;
        for (int j = 0; j < n; j++)
        { 
            //for (int i = j; i < j*10 + 10; i++) {
                RectangleShape rect(Vector2f(3, 3));
                rect.setPosition(Vector2f(points.at(j).x, points.at(j).y));
                rect.setFillColor(Color::Yellow);
                window.draw(rect);
            //}
        }
        window.display();
            
    }
	return 0;
}
