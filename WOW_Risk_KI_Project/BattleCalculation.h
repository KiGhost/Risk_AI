#ifndef BATTLECALCULATION_H
#define BATTLECALCULATION_H

#include "Dice.h"
#include "Territory.h"
#include "Player.h"

class BattleCalculation
{
private:
	Dice attackDice_One,
		 attackDice_Two,
		 attackDice_Three,

		 defendDice_One,
		 defendDice_Two;

	std::string winnerRound_One,
				winnerRound_Two;

public:
	BattleCalculation();
	~BattleCalculation();

	void calculateBattle(const int& attackCount, Territory& attackerTerr, Territory& defenderTerr);

	void sortDices();

	const std::string& getWinnerRound_One() const;
	const std::string& getWinnerRound_Two() const;
};

#endif // !BATTLECALCULATION_H