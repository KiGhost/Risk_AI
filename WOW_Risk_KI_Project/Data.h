#ifndef DATA_H
#define DATA_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>


class Data
{
private:
	sf::Font font;
	std::vector <sf::Text> text_UnitCountVec;

	std::vector <sf::Texture> tex_terrBlueVec;
	std::vector <sf::Texture> tex_terrRedVec;
	std::vector <sf::Texture> tex_terrYellVec;

	std::vector <sf::Sprite> spr_terrBlueVec;
	std::vector <sf::Sprite> spr_terrRedVec;
	std::vector <sf::Sprite> spr_terrYellVec;

public:
	Data();
	~Data();

	std::vector <sf::Text>& getText_UnitCountVec();
	std::vector <sf::Shape>& getShape_TerrVec();

	void text_updateUnitCount(const int& terrNumber, const int& new_UnitCount);

	sf::Sprite getSpecificTerrSpriteColor(const int& terrNumber, const char& color);
};

#endif // !DATA_H