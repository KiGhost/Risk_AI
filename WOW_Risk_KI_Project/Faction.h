#ifndef FACTION_H
#define FACTION_H

#include "SFML\Graphics\Color.hpp"
#include <string>

class Faction
{
private:
	sf::Color factionColor;
	std::string factionName;

public:
	Faction(std::string faction);
	~Faction();

	const std::string& getFactionName() const;
	const sf::Color& getFactionColor() const;
};

#endif // !FACTION_H