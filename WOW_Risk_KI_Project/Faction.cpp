#include "Faction.h"


Faction::Faction(std::string faction)
	: factionName(faction)
{
	// Set color: Allianz(blue)/ Horde(red)
	if(faction.compare("Allianz") == 0)
	{
		factionColor = sf::Color::Blue;
	}

	if(faction.compare("Horde") == 0)
	{
		factionColor = sf::Color::Red;
	}
}

Faction::~Faction()
{

}

// Return factionname
const std::string& Faction::getFactionName() const
{
	return factionName;
}

// Return factioncolor
const sf::Color& Faction::getFactionColor() const
{
	return factionColor;
}