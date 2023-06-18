#include <SFML/Graphics.hpp>
#include <time.h>
#include <SFML/Audio.hpp>
#include <SFML/Audio/AlResource.hpp>
#include<iostream>
#include<SFML/Audio.hpp>


using namespace std;
using namespace sf;
struct point
{
    int x,y;
};

int main()
{
    // Lobster

    sf:: Music music ;
    if(!music.openFromFile("fill.wav"))
    {
        std::cout << "ERROR" << std::endl;
    }
    music.setVolume(30);

    Font font,font2;
    font.loadFromFile("poorfamily.ttf");
    font2.loadFromFile("logooo.ttf");
    Text Play;
    Play.setFont(font);
    Play.setColor(sf::Color::Red);
    Play.setString("Play");
    Play.setCharacterSize(70);
    Play.setPosition(sf::Vector2f(120, 150));

    Text GameName;
    GameName.setFont(font);
    GameName.setString("Doooddle Jump");
    GameName.setColor(sf::Color(252, 186, 3));
    GameName.setCharacterSize(70);
    GameName.setPosition(120,25);
    GameName.setOutlineColor(sf::Color::White);
    GameName.setOutlineThickness(2);

    Text Exit;

    Exit.setFont(font);
    Exit.setColor(sf::Color::White);
    Exit.setCharacterSize(70);
    Exit.setString("Exit");
    Exit.setPosition(350,420);



    int screenNumber=0;
    int selection=0;
    int g = 0 ;

    srand(time(0));

    RenderWindow app(VideoMode(600, 600), "Doooddle Jump!!!!!!!");
    app.setFramerateLimit(60);
//    Music music ;
    //  if(!music.openFromFile("fill.wav"))
    //{
    //  std::cout << "ERROR" << std::endl;
    // }




    Texture t1,t2,t3,t4,t5,t6, t7,t8;
    t1.loadFromFile("back.jpg");
    t2.loadFromFile("platform.png");
    t3.loadFromFile("otty.png");
    t4.loadFromFile("bloplat.png");
    t5.loadFromFile("heart.png");
    t6.loadFromFile("heart.png");
    t7.loadFromFile("5.png");
    t8.loadFromFile("backy.jpg");

    Sprite sBackground(t1), sPlat(t2), sPers(t3), jumpPad(t4),love(t5),love1(t5),love2(t5), bglove(t6), gameover(t7),bako(t8);
    love.setScale(0.1f,0.1f);
    love2.setScale(0.1f,0.1f);
    love1.setScale(0.1f,0.1f);
    bglove.setScale(0.1f,0.1f);
    jumpPad.setScale(0.08,0.08);

    jumpPad.setPosition(0,510);
    jumpPad.setScale(.1,.1);
    //sBackground.scale(0.1,0.6);
    // sPers.setScale(5,5);





    love.setPosition(550,30);
    love1.setPosition(500,30);
    love2.setPosition(450,30);


    point plat[20];

    for (int i=0; i<10; i++)
    {
        plat[i].x=rand()%400;
        plat[i].y=rand()%533;
    }

    int x=100,y=100,h=200;
    float dx=0.0,dy=0.0;
    Music back_sound;
    back_sound.openFromFile("ragnar.wav");
    back_sound.play();

    while (app.isOpen())
    {

        Event e;
        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
                app.close();
        }



        if(screenNumber==0)
        {

            if(Keyboard::isKeyPressed(Keyboard::O))
            {

                if (selection==1)
                {
                    selection-=1;
                }

            }
            else if(Keyboard::isKeyPressed(Keyboard::L))
            {

                if (selection==0)
                {
                    selection+=1;
                }
            }

            if(Keyboard::isKeyPressed(Keyboard::Enter))
            {


                if (selection==0)
                {
                    screenNumber=1;
                }
                else  if (selection==1)
                {
                    return 0;
                }
            }


            if (selection==0)
            {

                Play.setColor(sf::Color::Red);
                Exit.setColor(sf::Color::White);
            }
            else if(selection==1)
            {

                Exit.setColor(sf::Color::Red);
                Play.setColor(sf::Color::White);
            }
            app.draw(bako);
            app.draw(GameName);
            app.draw(Play);
            app.draw(Exit);


        }
        else if (screenNumber==1)
        {



            if (Keyboard::isKeyPressed(Keyboard::Right))
            {
                if( sPers.getPosition().x >= 540  )
                {
                    x = x *1;
                }
                /*  else if( sPers.getPosition().y >= 480  )
                      {

                      x = x *1;

                      }

                     */ else
                {
                    x+=3;

                }
            }

            if (Keyboard::isKeyPressed(Keyboard::Left))
            {
                if( sPers.getPosition().x <= 1  )
                {
                    x = x *1;
                }
                /*
                else if( sPers.getPosition().y >= 480  ){
                             x = x *1;

                }
                */

                else
                {
                    x-=3;
                }
            }

            dy+=0.2;
            y+=dy;
            if (y>500)  dy=-10;

            if (y<h)
                for (int i=0; i<10; i++)
                {

                    y=h;
                    plat[i].y=plat[i].y-dy;
                    if (plat[i].y>533)
                    {
                        plat[i].y=0;
                        plat[i].x=rand()%400;
                    }
                }

            for (int i=0; i<10; i++)

                if ((x+50>plat[i].x) && (x+20<plat[i].x+68)
                        && (y+70>plat[i].y) && (y+70<plat[i].y+14) && (dy>0)  )
                {

                    dy=-10;

                    cout <<"aaaaaaaaaaaaaa";
                    music.play();
                    music.play();
                    cout <<"sssssssssss";

                }


            if( sPers.getPosition().y >= 480  )
            {

                dy = 0 ;


            }



            sPers.setPosition(x,y);
            sPers.setScale(0.07,0.07);



            app.draw(sBackground);
            app.draw(sPers);
            app.draw(jumpPad);


            if(g==0)
            {
                app.draw(love);

            }
            else
            {

            }

            if(g==1)
            {
                app.draw(love1);

            }
            else
            {

            }

            if(g==2)
            {
                app.draw(love2);

            }
            else
            {

            }

            for (int i=0; i<10; i++)
            {
                sPlat.setPosition(plat[i].x,plat[i].y);
                sPlat.setScale(.8,.8);
                app.draw(sPlat);

            }


            if( sPers.getPosition().y >= 480 && sPers.getPosition().x <= 150 && g < 3  )
            {
                if(Keyboard::isKeyPressed(Keyboard::Space))
                {

                    dy = -220  ;
                    cout<<" ana  henaaaaaa ya fozee" ;
                    g++ ;
                }

            }




            else if (sPers.getPosition().y >= 480 && sPers.getPosition().x <= 500 && (g == 3))
            {
                gameover.setPosition(200,250);
                gameover.setScale(.4,.4);
                app.draw(gameover);

            }






            if( sPers.getPosition().y >= 480 && sPers.getPosition().x <= 500 && g == 3  )
            {

//app.close();
            }

            app.draw(jumpPad);
        }



        app.display();
    }

}
