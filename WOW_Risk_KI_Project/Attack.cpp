#include "Attack.h"

Attack::Attack()
	: battleCalc(BattleCalculation())
{
	
}

Attack::~Attack()
{

}

// Initialize a fight and get winner of round 1 (and 2)
void Attack::attack(Player& currentPlayer, Territory& terr_Attack, Territory& terr_Defend, int attackingUnitCount)
{
	std::cout << "Die " << currentPlayer.getPlayerFaction().getFactionName() << " greift " << terr_Defend.getTerrName() << " mit " << attackingUnitCount << " Einheiten an!" << std::endl;

	// Get Defender-Count
	int defendingUnitCount = terr_Defend.getUnitCount();

	// Calculate winner of Round 1 (and 2)
	battleCalc.calculateBattle(attackingUnitCount, terr_Attack, terr_Defend);	
	
	if(defendingUnitCount == 1)
	{
		// COUT Winner Round 1
		std::cout << "Das erste Gefecht hat die " << battleCalc.getWinnerRound_One() << " gewonnen!" << std::endl;

		// COUT Winner of this fight
		if(battleCalc.getWinnerRound_One().compare("Allianz") == 0)
		{
			std::cout << "Die Allianz gewann diese Schlacht!" << std::endl;
			std::cout << std::endl;
		}

		if(battleCalc.getWinnerRound_One().compare("Horde") == 0)
		{
			std::cout << "Die Horde gewann diese Schlacht!" << std::endl;
			std::cout << std::endl;
		}
	}

	// More than 1 defender? COUT Winner Round 2
	if(defendingUnitCount > 1)
	{
		std::cout << "Das zweite Gefecht hat die " << battleCalc.getWinnerRound_Two() << " gewonnen!" << std::endl;

		// Cout Winner of this fight
		if(	battleCalc.getWinnerRound_One().compare("Allianz") == 0 &&
			battleCalc.getWinnerRound_Two().compare("Allianz") == 0)
		{
			std::cout << "Die Allianz gewann diese Schlacht!" << std::endl;
			std::cout << std::endl;
		}

		if(	battleCalc.getWinnerRound_One().compare("Horde") == 0 &&
			battleCalc.getWinnerRound_Two().compare("Horde") == 0)
		{
			std::cout << "Die Horde gewann diese Schlacht!" << std::endl;
			std::cout << std::endl;
		}

		else
		{
			std::cout << "Die Verteidiger konnten ihr Territorium unter Verlusten verteidigen!" << std::endl;
			std::cout << std::endl;
		}
	}
}