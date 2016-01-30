#ifndef UNIT_H
#define UNIT_H

#include "Faction.h"
#include <SFML\Graphics\Color.hpp>

class Unit
{
private:
	sf::Color unitColor;

public:
	Unit(Faction faction);
	~Unit();

	//void setUnitColor(const Faction& faction);

	//const int& getUnitNumber() const;
};

#endif // !UNIT_H