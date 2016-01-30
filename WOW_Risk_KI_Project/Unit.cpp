#include "Unit.h"

Unit::Unit(Faction faction)
{
	unitColor = faction.getFactionColor();
}

Unit::~Unit()
{

}

/*

// Set the color of this Unit in his factioncolor
void Unit::setUnitColor(const Faction& faction)
{
	unitColor = faction.getFactionColor();
}

/////////// TO DO: Bei Stack(Unit-Pool mit push/pop notwendig? ////////

const int& Unit::getUnitNumber() const
{
	return unitNumber;
}

*/