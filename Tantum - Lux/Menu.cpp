#include "Menu.h"
#include <iostream>


Menu::Menu(e_menu_type const& menu):id(menu)
{
	buttons = std::vector<Button>();
	tempAction = NO_ACTION;
	sf::Color blue = sf::Color(0,235,150);
	action = NO_ACTION;
	switch (id)
	{
		case MAIN_MENU:
		{
			Button play = Button(sf::Vector2f(-250, -50), sf::Vector2f(500, 100), START, "PLAY", MenuComponentStyle(blue));
			Button opt = Button(sf::Vector2f(-250, 100), sf::Vector2f(500, 100), GO_OPTION, "OPTION", MenuComponentStyle(sf::Color(50, 50, 50)));
			Button quit = Button(sf::Vector2f(-250, 300), sf::Vector2f(500, 100), QUIT_GAME, "QUIT", MenuComponentStyle(sf::Color(50, 50, 50)));
			
			opt.setColorText(blue);
			quit.setColorText(blue);

			buttons.push_back(play);
			buttons.push_back(opt);
			buttons.push_back(quit);
			break;
		}
		case OPTION:
		{
			Button audio = Button(sf::Vector2f(-250, -50), sf::Vector2f(500, 100), GO_AUDIO,"AUDIO", MenuComponentStyle(sf::Color(50, 50, 50)));
			Button mainMenu = Button(sf::Vector2f(-250, 300), sf::Vector2f(500, 100), GO_MAIN_MENU, "RETURN", MenuComponentStyle(sf::Color(50, 50, 50)));
			
			mainMenu.setColorText(blue);
			
			buttons.push_back(audio);
			buttons.push_back(mainMenu);			
			break;
		}
		case AUDIO:
		{
			Info vol = Info(sf::Vector2f(-250, -50), sf::Vector2f(500, 100), "SoundManager::getVol()", MenuComponentStyle(sf::Color(50,50,50)));


			Button volumeDown = Button(sf::Vector2f(-370, -50), sf::Vector2f(100, 100), VOLUME_UP, "-", MenuComponentStyle(sf::Color(50, 50, 50)));
			Button volumeUp = Button(sf::Vector2f(270, -50), sf::Vector2f(100, 100), VOLUME_DOWN, "+", MenuComponentStyle(sf::Color(50, 50, 50)));
			Button opt = Button(sf::Vector2f(-250, 300), sf::Vector2f(500, 100), GO_OPTION, "RETURN", MenuComponentStyle(sf::Color(50, 50, 50)));

			opt.setColorText(blue);

			buttons.push_back(opt);
			buttons.push_back(volumeUp);
			buttons.push_back(volumeDown);

			infos.push_back(vol);

			break;
		}
		case PAUSE:
		{

			break;
		}
	}
}

void Menu::update(sf::Time const& dt, sf::Vector2f const& mousePos)
{
	for (size_t i = 0; i < buttons.size(); i++)
	{
		buttons[i].update(dt, mousePos);
	}

	action = NO_ACTION;

	//FLAG CLICK
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (clickFlag) { click = true; clickFlag = false; }
		else { click = false; }
	}else{click = false; clickFlag = true;}
	//FLAG UNCLICK
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (unclickFlag) { unclick = true; unclickFlag = false; }
		else { unclick = false; }
	}
	else { unclick = false; unclickFlag = true; }


	if (click)
		for (size_t i = 0; i < buttons.size(); i++)
		{
			if (buttons[i].click(mousePos))
				tempAction = buttons[i].click(mousePos);
		}
	if (unclick)
	{
		for (size_t i = 0; i < buttons.size(); i++)
		{
			if (buttons[i].click(mousePos) == tempAction)
				action = tempAction;
		}
	}
}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (size_t i = 0; i < buttons.size(); i++)
	{
		target.draw(buttons[i]);
	}
	for (size_t i = 0; i < infos.size(); i++)
	{
		target.draw(infos[i]);
	}
}

e_button_action Menu::getAction() const
{
	return action;
}z