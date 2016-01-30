#ifndef Player_H
#define Player_H

#include "Faction.h"
#include "Unit.h"
#include "Card.h"
#include "Territory.h"
#include <vector>
#include <stack>
#include <iostream>


class Player
{
protected:
	Faction playerFaction;

	bool isAgent;

	std::stack<Unit*> playerUnitStack;

	std::vector<bool> playerTerrVec;
	std::vector<bool> playerCardVec;

	int unitsOnBoard;
	int unitsToPlaceOnBoard;

	int territoryCount;
	int cardCount;
	int exchangedCardsInUnitsValue;

	bool isOnTurn;
	bool activateExchangeCards;

	// Terr [20] to [30] (sum = 11 Territories)
	bool conqueredNorthEasternKingdoms;

	// Terr [31] to [41] (sum = 11 Territories)
	bool conqueredSouthEasternKingdoms;

	// Terr [1] to [8] + [10] + [11] (sum = 10 Territories)
	bool conqueredNorthKalimdor;

	// Terr [9] + [12] to [19] (sum = 9 Territories)
	bool conqueredSouthKalimdor;

	bool newTerritoryInTurn;

public:
	Player(Faction faction, bool agent);
	~Player();

	// AI relevant
	bool getIsAgent();
	virtual const std::string getCurrentState() const;
	virtual std::vector<int> chooseAction(const int& phaseNumber, std::string currentState);
	

	void pushUnit(const int& unitCount);
	void popUnit(const int& unitCount);

	const Faction& getPlayerFaction() const;

	const int& getTerritoryCount();
	// const int& getCardCount();

	const int& getUnitsOnBoard() const;
	const int& getUnitsToPlaceOnBoard() const;

	const bool& getIsOnTurn() const;
	// const bool& isExchangeCardsActive() const;
	const bool& getNewTerritoryInTurn() const;

	const bool& getConqueredNorthEasternKingdoms() const;
	const bool& getConqueredSouthEasternKingdoms() const;
	const bool& getConqueredNorthKalimdor() const;
	const bool& getConqueredSouthKalimdor() const;

	const bool ownsTerritoryNumber(const int& number);
	// const bool ownsCardNumber(const int& number);

	void changeUnitsToPlaceOnBoard(const int& count);

	// void setNewCard(const int& cardNumber);
	// void deleteCard(const int& cardNumber);

	const int& unitsForExchangeCards();

	void changeOwnsTerrNumber(const int& terrNumber);

	void setIsOnTurn(const bool& b);
	// void setActivateExchangeCards(const bool& b);

	void setConqueredNorthEasternKingdoms(const bool& b);
	void setConqueredSouthEasternKingdoms(const bool& b);
	void setConqueredNorthKalimdor(const bool& b);
	void setConqueredSouthKalimdor(const bool& b);

	void setNewTerritoryInTurn(const bool& b);

	// void displayCardVector();
};

#endif // !PLAYER_H