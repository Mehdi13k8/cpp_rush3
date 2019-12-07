#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "my.hpp"

int main(int ac, char **av) {
    sf::RenderWindow win (sf::VideoMode(900, 1080), "MyGKrellm");
    sf::Texture t_background;
    if (!t_background.loadFromFile("background.jpg"))
        return EXIT_FAILURE;   
    
    sf::Sprite background;
    background.setTexture(t_background);

    background.setScale(1, 1.7);
    sf::Music music;
    if (!music.openFromFile("Holograms.ogg"))
        return EXIT_FAILURE;
    music.play();
    music.setVolume(30);

    sf::Font font;
    if(!font.loadFromFile("arial.ttf")) {

    }

    sf::Text box1;
    sf::Vector2f x;
    x.x = 325;
    x.y = 400;
    Process b;
    Date_Time a;
    Name n;
    Version ver;
    box1.setFont(font);
    std::string str = "Version : ";
    str += ver.getVersion();
    box1.setString(str);
    box1.setCharacterSize(23);
    box1.setColor(sf::Color::Blue);
    box1.setPosition(x);

    sf::Text box2;
    x.x = 20;
    x.y = 150;
    box2.setFont(font);
    str = "Date is : ";
    str += a.getDate();
    box2.setString(str);
    box2.setCharacterSize(24);
    box2.setColor(sf::Color::Red);
    box2.setPosition(x);
    sf::Text box3;
    x.x = 10;
    x.y = 400;
    box3.setFont(font);
    str = "Cpu Usage is at ";
    str += b.getCpuUsage();
    box3.setString(str);
    box3.setCharacterSize(24);
    box3.setColor(sf::Color::Blue);
    box3.setPosition(x);
    sf::Text box4;
    x.x = 325;
    x.y = 150;
    box4.setFont(font);
    str = "It is ";
    str += a.getTime();
    str += " hour O'Clock";
    box4.setString(str);
    box4.setCharacterSize(24);
    box4.setColor(sf::Color::Red);
    box4.setPosition(x);
    sf::Text box5;
    x.x = 10;
    x.y = 600;
    box5.setFont(font);
    str = "The Host of the machine is ";
    str += n.getHostname();
    box5.setString(str);
    box5.setCharacterSize(26);
    box5.setColor(sf::Color::Blue);
    box5.setPosition(x);
    sf::Text box6;
    x.x = 25;
    x.y = 25;
    box6.setFont(font);
    str = "The User using currently this machine is  ";
    str += n.getUsername();
    box6.setString(str);
    box6.setCharacterSize(26);
    box6.setColor(sf::Color::Red);
    box6.setPosition(x);
    

    sf::RectangleShape version(sf::Vector2f(120, 50));
    version.setSize(sf::Vector2f(sf::VideoMode::getDesktopMode().width/2 + 15, sf::VideoMode::getDesktopMode().height/10));
    version.setFillColor(sf::Color(255, 255, 255, 128));
    
    sf::RectangleShape host(sf::Vector2f(120, 50));
    host.setSize(sf::Vector2f(sf::VideoMode::getDesktopMode().width/5, sf::VideoMode::getDesktopMode().height/5));
    host.setFillColor(sf::Color(255, 255, 255, 128));
    host.setPosition(0, sf::VideoMode::getDesktopMode().height/10 + 10);
    
    sf::RectangleShape login(sf::Vector2f(120, 50));
    login.setSize(sf::Vector2f(sf::VideoMode::getDesktopMode().width/5, sf::VideoMode::getDesktopMode().height/5));
    login.setFillColor(sf::Color(255, 255, 255, 128));
    login.setPosition(sf::VideoMode::getDesktopMode().width/5 + 15, sf::VideoMode::getDesktopMode().height/10 + 10);
    
    sf::RectangleShape date(sf::Vector2f(120, 50));
    date.setSize(sf::Vector2f(sf::VideoMode::getDesktopMode().width/5, sf::VideoMode::getDesktopMode().height/4));
    date.setFillColor(sf::Color(255, 255, 255, 128));
    date.setPosition(0, sf::VideoMode::getDesktopMode().height/10 + sf::VideoMode::getDesktopMode().height/5 + 20);

    sf::RectangleShape hour(sf::Vector2f(120, 50));
    hour.setSize(sf::Vector2f(sf::VideoMode::getDesktopMode().width/5, sf::VideoMode::getDesktopMode().height/4));
    hour.setFillColor(sf::Color(255, 255, 255, 128));
    hour.setPosition(sf::VideoMode::getDesktopMode().width/5 + 15, sf::VideoMode::getDesktopMode().height/10 + sf::VideoMode::getDesktopMode().height/5 + 20);

    sf::RectangleShape cpu(sf::Vector2f(120, 50));
    cpu.setSize(sf::Vector2f(sf::VideoMode::getDesktopMode().width/2 + 15, sf::VideoMode::getDesktopMode().height/3));
    cpu.setFillColor(sf::Color(255, 255, 255, 128));
    cpu.setPosition(0, sf::VideoMode::getDesktopMode().height/10 + sf::VideoMode::getDesktopMode().height/5 + sf::VideoMode::getDesktopMode().height/4 + 30);
    
    while (win.isOpen()) {
        sf::Event event;
        while (win.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                win.close();
        }

        win.clear();
        win.draw(background);
        win.draw(version);
        win.draw(box1);
        win.draw(host);
        win.draw(box2);
        win.draw(login);
        win.draw(box3);
        win.draw(date);
        win.draw(box4);
        win.draw(hour);
        win.draw(box5);
        win.draw(cpu);
        win.draw(box6);
        win.display();
    }
    return EXIT_SUCCESS;
}
