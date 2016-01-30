#include "BattleCalculation.h"


BattleCalculation::BattleCalculation()
{
	
}

BattleCalculation::~BattleCalculation()
{

}

void BattleCalculation::calculateBattle(const int& attackCount, Territory& attackerTerr, Territory& defenderTerr)
{
	std::string attackerName = attackerTerr.getTerrName();
	std::string defendername = defenderTerr.getTerrName();

	Player& attacker = attackerTerr.getTerrOwner();
	Player& defender = defenderTerr.getTerrOwner();

	int defendCount = 0;

	if(defenderTerr.getUnitCount() > 1)
	{
		defendCount = 2;
	}
	else
	{
		defendCount = 1;
	}

	// Attack Dices
	attackDice_One = Dice();
	attackDice_Two = Dice();
	attackDice_Three = Dice();

	// Defend Dices
	defendDice_One = Dice();
	defendDice_Two = Dice();

	// Sort all Dices from High to low
	sortDices();

	// 3 or 2 Atacker (lowest roll is not relevant)
	if(attackCount == 3 || attackCount == 2)
	{
		if(defendCount == 2) // 2 vs 2 and 3 vs 2
		{
			// ROUND 1
			if(attackDice_One.getDiceValue() > defendDice_One.getDiceValue())
			{
				winnerRound_One = attackerName;
				
				// Defender - 1 UNIT(1)
				defenderTerr.changeUnitCount(-1);
				defender.pushUnit(1);
			}

			if(attackDice_One.getDiceValue() <= defendDice_One.getDiceValue())
			{
				winnerRound_One = defendername;

				// Attacker - 1 UNIT(1)
				attackerTerr.changeUnitCount(-1);
				attacker.pushUnit(1);
			}

			// ROUND 2
			if(attackDice_Two.getDiceValue() > defendDice_Two.getDiceValue())
			{
				winnerRound_Two = attackerName;

				// Defender - 1 UNIT(2)
				defenderTerr.changeUnitCount(-1);
				defender.pushUnit(1);
			}

			if(attackDice_Two.getDiceValue() <= defendDice_Two.getDiceValue())
			{
				winnerRound_Two = defendername;

				// Attacker - 1 UNIT(2)
				attackerTerr.changeUnitCount(-1);
				attacker.pushUnit(1);
			}

			// COUT battleresults
			if(attackCount == 3)
			{
				std::cout << std::endl;
				std::cout << "   Round   |    Attacker    |   Defender    " << std::endl;
				std::cout << " ----------|----------------|-------------- " << std::endl;
				std::cout << "    #1:    |       " << attackDice_One.getDiceValue() << "        |       " << defendDice_One.getDiceValue() << std::endl;
				std::cout << "    #2:    |       " << attackDice_Two.getDiceValue() << "        |       " << defendDice_Two.getDiceValue() << std::endl;
				std::cout << "    #3:    |       " << attackDice_Three.getDiceValue() << "        |       -" << std::endl;
				std::cout << std::endl;
			}

			if(attackCount == 2)
			{
				std::cout << std::endl;
				std::cout << "   Round   |    Attacker    |   Defender    " << std::endl;
				std::cout << " ----------|----------------|-------------- " << std::endl;
				std::cout << "    #1:    |       " << attackDice_One.getDiceValue() << "        |       " << defendDice_One.getDiceValue() << std::endl;
				std::cout << "    #2:    |       " << attackDice_Two.getDiceValue() << "        |       " << defendDice_Two.getDiceValue() << std::endl;
				std::cout << "    #3:    |       -        |       -" << std::endl;
				std::cout << std::endl;
			}
		}

		if(defendCount == 1) // 2 vs 1 and 3 vs 1
		{
			if(attackDice_One > defendDice_One)
			{
				winnerRound_One = attackerName;

				// Defender - 1 UNIT
				defenderTerr.changeUnitCount(-1);
				defender.pushUnit(1);
			}
			
			if(attackDice_One <= defendDice_One)
			{
				winnerRound_One = defendername;

				// Attacker - 1 UNIT
				attackerTerr.changeUnitCount(-attackCount);
				attacker.pushUnit(attackCount);
			}

			if(attackCount == 3)
			{
				std::cout << std::endl;
				std::cout << "   Round   |    Attacker    |   Defender    " << std::endl;
				std::cout << " ----------|----------------|-------------- " << std::endl;
				std::cout << "    #1:    |       " << attackDice_One.getDiceValue() << "        |       " << defendDice_One.getDiceValue() << std::endl;
				std::cout << "    #2:    |       " << attackDice_Two.getDiceValue() << "        |       -" << std::endl;
				std::cout << "    #3:    |       " << attackDice_Three.getDiceValue() << "        |       -" << std::endl;
				std::cout << std::endl;
			}

			if(attackCount == 2)
			{
				std::cout << std::endl;
				std::cout << "   Round   |    Attacker    |   Defender    " << std::endl;
				std::cout << " ----------|----------------|-------------- " << std::endl;
				std::cout << "    #1:    |       " << attackDice_One.getDiceValue() << "        |       " << defendDice_One.getDiceValue() << std::endl;
				std::cout << "    #2:    |       " << attackDice_Two.getDiceValue() << "        |       -" << std::endl;
				std::cout << "    #3:    |       -        |       -" << std::endl;
				std::cout << std::endl;
			}
		}
	}

	// 1 Attacker
	if(attackCount == 1) // 1 vs 1
	{
		if(attackDice_One > defendDice_One)
		{
			winnerRound_One = attackerName;

			// Defender - 1 UNIT
			defenderTerr.changeUnitCount(-1);
			defender.pushUnit(1);
		}

		if(attackDice_One <= defendDice_One)
		{
			winnerRound_One = defendername;

			// Attacker - 1 UNIT
			attackerTerr.changeUnitCount(-1);
			attacker.pushUnit(1);
		}

		std::cout << std::endl;
		std::cout << "   Round   |    Attacker    |   Defender    " << std::endl;
		std::cout << " ----------|----------------|-------------- " << std::endl;
		std::cout << "    #1:    |       " << attackDice_One.getDiceValue() << "        |       " << defendDice_One.getDiceValue() << std::endl;
		std::cout << "    #2:    |       -        |       -" << std::endl;
		std::cout << "    #3:    |       -        |       -" << std::endl;
		std::cout << std::endl;
	}
}

// Simple Bubblesort
void BattleCalculation::sortDices()
{
	int temp_Value;

	// Dice_3 > Dice_2? true = Tauschen
	if(attackDice_Three > attackDice_Two)
	{
		temp_Value = attackDice_Two.getDiceValue();
		attackDice_Two.setDiceValue(attackDice_Three.getDiceValue());
		attackDice_Three.setDiceValue(temp_Value);
	}

	// Dice_2 > Dice_1? true = Tauschen
	if(attackDice_Two > attackDice_One)
	{
		temp_Value = attackDice_One.getDiceValue();
		attackDice_One.setDiceValue(attackDice_Two.getDiceValue());
		attackDice_Two.setDiceValue(temp_Value);
	}

	// Dice_3 > Dice_2? true = Tauschen
	if(attackDice_Three > attackDice_Two)
	{
		temp_Value = attackDice_Two.getDiceValue();
		attackDice_Two.setDiceValue(attackDice_Three.getDiceValue());
		attackDice_Three.setDiceValue(temp_Value);
	}
}

// Return Winner of Round 1
const std::string& BattleCalculation::getWinnerRound_One() const
{
	return winnerRound_One;
}

// Return Winner of Round 2
const std::string& BattleCalculation::getWinnerRound_Two() const
{
	return winnerRound_Two;
}