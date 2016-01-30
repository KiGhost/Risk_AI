#include "Territory.h"


Territory::Territory(std::string name, int number, Faction faction, Player* owner)
		:	terrName(name),
			terrNumber(number),
			terrFactionControl(faction),
			unitCount(0),
			terrOwner(owner)
{
	
}

Territory::~Territory()
{

}

// GETTER
const std::string& Territory::getTerrName() const
{
	return terrName;
}

const int& Territory::getTerrNumber() const
{
	return terrNumber;
}

const Faction& Territory::getTerrFaction() const
{
	return terrFactionControl;
}

Player& Territory::getTerrOwner()
{
	return *terrOwner;
}

const std::vector<int>& Territory::getVectorNeighborNumber() const
{
	return vectorNeighborNumber;
}

const int& Territory::getUnitCount() const
{
	return unitCount;
}


// SETTER
void Territory::setTerrFaction(const Faction& newFactionControl)
{
	terrFactionControl = newFactionControl;
}

void Territory::setNeighborNumber(const int& number)
{
	vectorNeighborNumber.push_back(number - 1);
}

void Territory::changeUnitCount(const int& differenceUnitCount)
{
	unitCount += differenceUnitCount;
}

void Territory::setNewTerrOwner(Player* newOwner)
{
	terrOwner = newOwner;
}