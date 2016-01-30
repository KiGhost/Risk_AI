#ifndef TERRITORY_H
#define TERRITORY_H

#include "SFML\Graphics.hpp"
#include "Faction.h"
#include <vector>

class Player;

class Territory
{
private:
	std::string const terrName;
	int const terrNumber;
	Faction terrFactionControl;
	Player* terrOwner;
	std::vector<int> vectorNeighborNumber;
	int unitCount;

public:
	Territory(std::string name, int number, Faction faction, Player* owner);
	~Territory();

	const std::string& getTerrName() const;
	const int& getTerrNumber() const;
	const Faction& getTerrFaction() const;
	Player& getTerrOwner();
	const std::vector<int>& getVectorNeighborNumber() const;
	
	const int& getUnitCount() const;

	void setTerrFaction(const Faction& newFaction);
	void setNeighborNumber(const int& number);
	void changeUnitCount(const int& differenceUnitCount);
	
	void setNewTerrOwner(Player* newOwner);
};

#endif // !TERRITORY_H