#ifndef ATTACK_H
#define ATTACK_H

#include "BattleCalculation.h"
#include "Player.h"
#include "Territory.h"

class Attack
{
private:
	BattleCalculation battleCalc;

public:
	Attack();
	~Attack();

	void attack(Player& currentPlayer, Territory& terr_Attack, Territory& terr_Defend, int attackingUnitCount);
};

#endif // !ATTACK_H