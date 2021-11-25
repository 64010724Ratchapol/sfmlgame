#include<SFML/Graphics.hpp>
#include<time.h>
#include <SFML\Audio.hpp>
#include<sstream>
#include<windows.h>

using namespace sf;using namespace std;

struct point
{
    int x, y;
};
struct point1
{
    int x, y;
}; 
struct point2
{
    int x, y;
}; 


int main()
{
	menu:
	int score=0;
	sf::Text scoreText;
	Font font;
	font.loadFromFile("font/font.ttf");
	scoreText.setFont(font);
	scoreText.setString("Hight = 0 ");
	scoreText.setCharacterSize(20);
	scoreText.setFillColor(Color::Red);
	scoreText.setPosition(10,10);
	
	SoundBuffer buffer;
	buffer.loadFromFile("sound/jump.wav");
	Sound sound;
	sound.setBuffer(buffer);
	
	SoundBuffer buffer1;
	buffer1.loadFromFile("sound/namedeadpool.wav");
	Sound sound1;
	sound1.setBuffer(buffer1);
	
	SoundBuffer buffer2;
	buffer2.loadFromFile("sound/loser.wav");
	Sound sound2;
	sound2.setBuffer(buffer2);
	
	SoundBuffer buffer3;
	buffer3.loadFromFile("sound/gamebegin.wav");
	Sound sound3;
	sound3.setBuffer(buffer3);
	
	SoundBuffer buffer4;
	buffer4.loadFromFile("sound/laugh.wav");
	Sound sound4;
	sound4.setBuffer(buffer4);
	
	SoundBuffer buffer5;
	buffer5.loadFromFile("sound/why.wav");
	Sound sound5;
	sound5.setBuffer(buffer5);
	
	SoundBuffer buffer6;
	buffer6.loadFromFile("sound/shit.wav");
	Sound sound6;
	sound6.setBuffer(buffer6);
	
	SoundBuffer buffer7;
	buffer7.loadFromFile("sound/click.wav");
	Sound sound7;
	sound7.setBuffer(buffer7);
	
	SoundBuffer buffer8;
	buffer8.loadFromFile("sound/jumps.wav");
	Sound sound8;
	sound8.setBuffer(buffer8);
	
	SoundBuffer buffer9;
	buffer9.loadFromFile("sound/click2.wav");
	Sound sound9;
	sound9.setBuffer(buffer9);
	
	//game over
	Text gameoverText;
	Texture backgroundTexture1;
	backgroundTexture1.loadFromFile("player/deadpool02.png");
     Sprite over(backgroundTexture1);
	gameoverText.setFont(font);
	gameoverText.setString("Game Over!");
	gameoverText.setCharacterSize(80);
	gameoverText.setFillColor(sf::Color::Red);
	RectangleShape gameoverBackground(sf::Vector2f(600, 640));
	gameoverBackground.setFillColor(sf::Color::Black);
	
	RectangleShape howtoBackground(sf::Vector2f(600, 640));
	howtoBackground.setFillColor(sf::Color::Black);
	
	
	
    srand(time(0));

    RenderWindow window(VideoMode(600, 640), "Game : TO THE TOP");
    window.setFramerateLimit(60);
    

    Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13;
    t1.loadFromFile("bg/cute1.png");
    t2.loadFromFile("player/platform.png");
    t3.loadFromFile("player/deadpool.png");
    t4.loadFromFile("player/groot.png");
    t5.loadFromFile("bg/bg3.png");
    t6.loadFromFile("player/flash01.png");
    t7.loadFromFile("bg/bg12.png");
    t8.loadFromFile("player/ghot1.png");
    t10.loadFromFile("player/base.png");
    t12.loadFromFile("player/batman.png");
    t13.loadFromFile("bg/bg6.png");

    Sprite sBackground(t1), sPlat(t2), sPers(t3), wove(t4), xx2(t5), flash(t6), bg(t7), sitem(t8), sdead(t10), bg1(t13), batman(t12);

     Texture m1, m2, h1;
     m1.loadFromFile("bg/xxx.png");
     m2.loadFromFile("player/stop.png");
     h1.loadFromFile("player/howtoplays.png");
     Sprite menu1(m1);
     Sprite menu2(m2);
     Sprite howto(h1);
     menu2.setPosition(0,250);
     
     sf::Text gameText;
     gameText.setFont(font);
	gameText.setString("TO THE TOP");
	gameText.setCharacterSize(20);
	gameText.setFillColor(Color::Green);
	gameText.setPosition(20,20);
	
     sf::Text startText;
     startText.setFont(font);
	startText.setString("START");
	startText.setCharacterSize(50);
	startText.setFillColor(Color::White);
	startText.setPosition(200,80);
	
	
	sf::Text howtoText;
     howtoText.setFont(font);
	howtoText.setString("HOW TO PLAY");
	howtoText.setCharacterSize(50);
	howtoText.setFillColor(Color::White);
	howtoText.setPosition(120,180);
	
	sf::Text exitText;
     exitText.setFont(font);
	exitText.setString("EXIT");
	exitText.setCharacterSize(50);
	exitText.setFillColor(Color::White);
	exitText.setPosition(220,280);
	
	sf::Text menuText;
     menuText.setFont(font);
	menuText.setString("BACK TO MENU");
	menuText.setCharacterSize(40);
	menuText.setFillColor(Color::Red);
     menuText.setPosition(10, 400);
     
     sf::Text nameText;
     nameText.setFont(font);
	nameText.setString("By  Ratchapol Rujiwatch  64010724");
	nameText.setCharacterSize(12);
	nameText.setFillColor(Color::Yellow);
     nameText.setPosition(10, 400);

 

    point plat[10];
    point1 item[1];
    point2 dead[1];
    /// enermy01
     for (int i = 0; i < 1; i++)
    {
        item[i].x = rand() % 540;
        item[i].y = rand() % 600;
    }

        //randome plat
    for (int i = 0; i < 10; i++)
    {
        plat[i].x = rand() % 540;
        plat[i].y = rand() % 600;
    }
    
         //enamy02
    for (int i = 0; i < 1; i++)
    {
        dead[i].x = rand() % 540;
        dead[i].y = rand() % 600;
    }
    
    //set x y dx dy
    int x = 100, y = 100, h = 200;
    float dx = 0, dy = 0;
    
  
     while (window.isOpen())
    {
        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
            {
            	window.close();
		  }                
        }
        
        if (startText.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
        {
        	startText.setFillColor(sf::Color::Green);
	   }	   
	   else if (howtoText.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
        {
        	howtoText.setFillColor(sf::Color::Yellow);
	   }	   
	   else if (exitText.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
        {
        	exitText.setFillColor(sf::Color::Red);
	   }
	   else
	   {
	   	sound7.play();
	   	startText.setFillColor(sf::Color::White);
	   	howtoText.setFillColor(sf::Color::White);
	   	exitText.setFillColor(sf::Color::White);
	   }
	   
	   
	   if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	   {
	   	  if (startText.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
            {
            	sound9.play();
        	     goto play;
	       }	   
	       else if (howtoText.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
            {
            	sound9.play();
               goto howtoplay;
	       }	   
	       else if (exitText.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
            {
            	sound9.play();
          	window.close();
	       }
	   }
	   
        window.clear();
        window.draw(menu1);
        window.draw(menu2);
        window.draw(gameText);
        window.draw(startText);
        window.draw(howtoText);
        window.draw(nameText);
        window.draw(exitText);
        window.display();
    }
    
    
    howtoplay :
    while (window.isOpen())
    {
        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
            {
            	window.close();
		  }                
        }
        if (menuText.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
          {
        	     menuText.setFillColor(sf::Color::Green);
	     }
		else
		{
		     menuText.setFillColor(sf::Color::Red);
			sound7.play();
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	     {
	   	  if (menuText.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
            {
        	     goto menu;
	       }	   	 
	     }
	     window.draw(howtoBackground);
	     window.draw(howto);
	     howto.setPosition(20, 20);
	     menuText.setPosition(130, 570);
	     window.draw(menuText);
		window.display();
    }

    play :
    while (window.isOpen())
    {
        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
            {
            	window.close();
		  }                
        }
        if (Keyboard::isKeyPressed(Keyboard::D)) x += 10;
        if (Keyboard::isKeyPressed(Keyboard::A)) x -= 10;
        if (Keyboard::isKeyPressed(Keyboard::X))
        {
        		sound5.play();
			gameoverText.setPosition(90, 20);
			scoreText.setPosition(40, 550);
			menuText.setPosition(10, 420);
			menuText.setCharacterSize(30);
			over.setPosition(60, 60);
			goto gameover;
	   }
        ////
        if(x>600) x=-80;
        if(x<-80) x=600;
        ////
               
        if(y<h)   //plate put
        {
            for (int i = 0; i < 10; i++)
		   {
                y = h;
                plat[i].y = plat[i].y - dy;
                if (plat[i].y > 640) 
			 { 
			   plat[i].y = 0; 
			   plat[i].x = rand() % 580; 
			 }
             }
             for (int i = 0; i < 2; i++)
		   {
                y = h;
                item[i].y = item[i].y - dy;
                if (item[i].y > 640) 
			 { 
			   item[i].y = 0; 
			   item[i].x = rand() % 580; 
			 }
             }
             for (int i = 0; i < 2; i++)
		   {
                y = h;
                dead[i].y = dead[i].y - dy;
                if (dead[i].y > 640) 
			 { 
			   dead[i].y = 0; 
			   dead[i].x = rand() % 580; 
			 }
             }
         }
         
         for (int i = 0; i < 10; i++)
          {
        	 if ((x > dead[i].x-50) && (x < dead[i].x+50 ) && (y + 80 < dead[i].y + 14) && (y + 80 > dead[i].y) && (dy > 0))
		    {
		    	 sound8.play();
        	 	 dy = -25;
		    }             
	     }
         
         for (int i = 0; i < 1; i++)
          {
        	 if ((x > item[i].x-50) && (x < item[i].x+50 ) && (y  < item[i].y + 50) && (y+80 > item[i].y) )
		    {
		    	sound6.play();
			gameoverText.setPosition(90, 20);
			scoreText.setPosition(40, 550);
			menuText.setPosition(10, 420);
			menuText.setCharacterSize(30);
			over.setPosition(60, 60);
			goto gameover; 	       
		    }             
	     }
	     
	     	     
	     
	       //score++        
	   	if (y == h && dy < (-5))
		{
			score += 1;
		     std::stringstream ss;
	          ss << "Hight = " << score;    
               scoreText.setString(ss.str());
		}
		
	        
        sPers.setPosition(x, y);
        wove.setPosition(x, y);
        flash.setPosition(x, y);
        batman.setPosition(x, y);
        
        
        if(score<1000)
        {
        	dy += 0.3;
           y += dy;
        	for (int i = 0; i < 10; i++)
          {
        	 if ((x > plat[i].x-50) && (x < plat[i].x+50 ) && (y + 80 < plat[i].y + 14) && (y + 80 > plat[i].y) && (dy > 0))
		    {
		    	 sound.play();
        	 	 dy = -13;
		    }             
	     }
        	window.draw(sBackground);
	   }
	   
	   if(score>=1000 && score<2000)
        {
        	dy += 0.4;
          y += dy;
          for (int i = 0; i < 10; i++)
          {
        	 if ((x > plat[i].x-50) && (x < plat[i].x+50 ) && (y + 80 < plat[i].y + 14) && (y + 80 > plat[i].y) && (dy > 0))
		    {
		    	 sound.play();
        	 	 dy = -15;
		    }           
	     }
        	window.draw(xx2);
	   }
	   
	   if(score>=2000 && score<3000)
        {
        	dy += 0.7;
          y += dy;
          for (int i = 0; i < 10; i++)
          {
        	 if ((x > plat[i].x-50) && (x < plat[i].x+50 ) && (y + 80 < plat[i].y + 14) && (y + 80 > plat[i].y) && (dy > 0))
		    {
		    	 sound.play();
        	 	 dy = -20;
		    }
              
	     }
        	window.draw(bg1);
	   }
	   
	   if(score>=3000)
        {
        	dy += 0.9;
          y += dy;
          for (int i = 0; i < 10; i++)
          {
        	 if ((x > plat[i].x-50) && (x < plat[i].x+50 ) && (y + 80 < plat[i].y + 14) && (y + 80 > plat[i].y) && (dy > 0))
		    {
		    	 sound.play();
        	 	 dy = -25;
		    }
              
	     }
        	window.draw(bg);
	   }

     
        for (int i = 0; i < 10; i++)
        {
            sPlat.setPosition(plat[i].x, plat[i].y);
            window.draw(sPlat);
        }
        
     
	   window.draw(scoreText);
        if(score<1000 &&  !Keyboard::isKeyPressed(Keyboard::E))
        {
        	window.draw(sPers);
	   }
	    if(score>=1000 && score<2000)
        {
        	window.draw(wove);
	   }
	   if(score>=2000 && score<3000)
	   {
	   	window.draw(batman);
	   }
	    if(score>=3000)
	   {
	   	window.draw(flash);
	   }
        
        if(score==100)
        {
        	sound1.play();
	   }
	   if(score==10)
        {
        	sound3.play();
	   }
	   if(score==1000 || score==2000 || score==3000 || score==4000 || score==5000)
        {
        	sound4.play();
	   }


	for (int i = 0; i < 1; i++)
        {
            sitem.setPosition(item[i].x, item[i].y);
            window.draw(sitem);
        }
     
	for (int i = 0; i < 2; i++)
        {
            sdead.setPosition(dead[i].x, dead[i].y);
            window.draw(sdead);
        } 
	       	  	   
        
        if (y > 700)
		{
			sound2.play();
			gameoverText.setPosition(90, 20);
			scoreText.setPosition(40, 550);
			menuText.setPosition(10, 420);
			menuText.setCharacterSize(30);
			over.setPosition(60, 60);
			goto gameover;
		}
	
        window.display(); 
    }
    
     
     gameover:
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();   
		}
		window.clear();
		if (menuText.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
          {
        	     menuText.setFillColor(sf::Color::Green);
	     }
		else
		{
		     menuText.setFillColor(sf::Color::Red);
		     sound7.play();
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	     {
	   	  if (menuText.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
            {
        	     goto menu;
	       }	   	 
	     }
	     window.clear();
		window.draw(gameoverBackground);
		window.draw(over);
		window.draw(gameoverText);
		window.draw(scoreText);
		window.draw(menuText);
		window.display();
	}
	
    return 0; 
}
