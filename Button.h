#pragma once
#include <SFML/Graphics.hpp>
#include "ParticleSystem.h"
#include "FontManager.h"
#include "MenuComponentStyle.h"

/// <summary>
/// Action of the button, ADD CUSTOMIZE ACTION
/// </summary>

enum e_button_action {
	/// <summary>
	/// No action, action return when the click was'nt in the hitbox
	/// </summary>
	NO_ACTION = 0,
	/// <summary>
	/// Go to the main button action
	/// </summary>
	GO_OPTION,
	/// <summary>
	/// Go to Audio's option
	/// </summary>
	GO_AUDIO,
	/// <summary>
	/// Go to the main menu
	/// </summary>
	GO_MAIN_MENU,
	/// <summary>
	/// Launch the game loop
	/// </summary>
	START,
	/// <summary>
	/// Quit the game
	/// </summary>
	QUIT_GAME,

	VOLUME_UP,
	VOLUME_DOWN,
};

enum e_animation {
	FALLING_PARTICLE,
};



enum e_ButtonState {
	DEFAULT,
	OVER,
	CLICK,
};

class Button : public sf::Drawable
{
	sf::RectangleShape hitbox;
	sf::Text text;
	e_button_action action;
	e_ButtonState state;
	MenuComponentStyle buttonStyle;
	MenuComponentStyle buttonStyleOver;
	MenuComponentStyle buttonStyleClick;
	

	//Gestion animation
	
	


public:
	
	Button(sf::Vector2f const& pos, sf::Vector2f const& size, e_button_action const& action_, std::string const& content,MenuComponentStyle const& MenuComponentStyle_ = MenuComponentStyle(sf::Color(255,255,255)));
	/// <summary>
	/// If the click is in the box, return the action
	/// </summary>
	/// <param name="posClick">Click position (mouse)</param>
	/// <returns>Return the action</returns>
	e_button_action click(sf::Vector2f const& posClick)const;
	/// <summary>
	/// Update the button, it can update the animation, the appearance of the button will the mouse is over the button
	/// </summary>
	/// <param name="dt">Delta time, time elapsed since the last update</param>
	/// <param name="mousePos">Position of the mouse relative to the window (AND view so)</param>
	void update(sf::Time const& dt, sf::Vector2f mousePos);
	void draw(sf::RenderTarget & target, sf::RenderStates states)const;
	void setColorText(sf::Color const& color);
	void setMenuComponentStyle(MenuComponentStyle const& style);
	void setMenuComponentStyleOver(MenuComponentStyle const& style);
	void setContent(std::string const& content);
	void setMenuComponentStyleClick(MenuComponentStyle const& style);
};

