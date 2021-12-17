#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Button.h"
#include "Info.h"

enum e_menu_type
{
	MAIN_MENU = 0,
	OPTION = 1,
	AUDIO = 2,
	PAUSE,
};

class Menu : public sf::Drawable
{
	e_menu_type id;
	std::vector<Button> buttons;
	std::vector<Info> infos;


	//-----CLICK----

	/// <summary>
	/// Contain the last button action's, to prevent miss-click
	/// The player have to click AND unclick while aiming the same button !
	/// So we stock the ACTION at each cLick
	/// </summary>
	
	e_button_action tempAction;
	e_button_action action;

	bool click;
	bool clickFlag;

	bool unclick;
	bool unclickFlag;

	//---------------

public :

	Menu(e_menu_type const& menu = MAIN_MENU);
	void update(sf::Time const& dt, sf::Vector2f const& mousePos);
	void draw(sf::RenderTarget & target,sf::RenderStates states)const;
	e_button_action getAction()const;
};