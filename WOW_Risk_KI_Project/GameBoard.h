#ifndef GAMEBOARD_H
#define GAMEBOARD_H

// #include "Card.h"
#include "Territory.h"
#include "Faction.h"
#include "Attack.h"
#include "Player.h"
#include <iostream>

class GameBoard
{
private:
	// std::vector<Card*> vecCard;

	std::vector<Territory*> vecTerr;

	Attack attack;

	Player* playerOne;
	Player* playerTwo;

public:
	GameBoard(Player* player_One_Alliance, Player* player_two_Horde);
	~GameBoard();

	Territory& getSpecificTerritory(int terrNumber);

	// std::vector<Card*>& getVecCard();

	Player* getPlayer(const int& playerNumber) const;

	void fight(const int& attacker_TerritoryNumber, const int& defender_TerritoryNumber,const int& attackingUnitCount);
	
	void moveUnits(const int& unitCount, const int& fromTerr, const int& toTerr);

	// void drawCard(Player& currentPlayer);

	const bool checkIfPlayerWonTerrNumber(Player& currentPlayer, int& terrNumber);
	const bool checkIfPlayersNeighborsHostiles(Player* currentPlayer);

	const bool checkIfPlayerLostAllTerrs(Player* currentPlayer) const;
};

#endif // !GAMEBOARD_H