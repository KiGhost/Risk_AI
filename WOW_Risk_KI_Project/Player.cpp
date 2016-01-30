#include "Player.h"

Player::Player(Faction faction, bool agent)
	:	playerFaction(faction),
		isAgent(agent),
		isOnTurn(false),
		activateExchangeCards(false),
		unitsOnBoard(0),
		unitsToPlaceOnBoard(0),
		territoryCount(0),
		cardCount(0),
		exchangedCardsInUnitsValue(0),
		conqueredNorthEasternKingdoms(false),
		conqueredSouthEasternKingdoms(false),
		conqueredNorthKalimdor(false),
		conqueredSouthKalimdor(false),
		newTerritoryInTurn(false)
{
	// Initialize 45 Units (maximum per player)
	for(int i = 0; i < 45; i++)
	{
		playerUnitStack.push(new Unit(faction));
	}
	
	// Initialize the Card- and Territory-Vector of Player with false
	for(int i = 0; i < 42; i++)
	{
		playerTerrVec.push_back(false);
		playerCardVec.push_back(false);
	}
	
	// Set the Start-Territorys of the specific faction true in the Territory-Vector
	if(playerFaction.getFactionName().compare("Allianz") == 0)
	{
		playerTerrVec.at(0) = true;
		//playerTerrVec.at(1) = true; // Für Prototyp_Balanacing
		//playerTerrVec.at(26) = true; // Für Prototyp_Balanacing
		//playerTerrVec.at(27) = true; // Für Prototyp_Balanacing
		//playerTerrVec.at(28) = true; // Für Prototyp_Balanacing
		//playerTerrVec.at(31) = true; // Für Prototyp_Balanacing
		//playerTerrVec.at(33) = true; // Für Prototyp_Balanacing
		//playerTerrVec.at(34) = true; // Für Prototyp_Balanacing
		//playerTerrVec.at(35) = true; // Für Prototyp_Balanacing
	}

	if(playerFaction.getFactionName().compare("Horde") == 0)
	{
		playerTerrVec.at(8) = true;
		//playerTerrVec.at(9) = true; // Für Prototyp_Balanacing
		//playerTerrVec.at(11) = true; // Für Prototyp_Balanacing
		//playerTerrVec.at(19) = true; // Für Prototyp_Balanacing
		//playerTerrVec.at(22) = true; // Für Prototyp_Balanacing
	}
}

Player::~Player()
{

}

bool Player::getIsAgent()
{
	return isAgent;
}

const std::string Player::getCurrentState() const
{
	return std::string("Something went wrong! Im not a derived_Object");
}

// If Baseclass method! -> Something went wrong!
std::vector<int> Player::chooseAction(const int& phaseNumber, std::string currentState)
{
	std::cerr << "Player::chooseAction. Something went wrong -> no AI-Method!" << std::endl;
	return std::vector<int>();
}

// Push i Units on UnitStack of Player
void Player::pushUnit(const int& unitCount)
{
	if(playerUnitStack.size() != 44)
	{
		for(int i = 0; i < unitCount; i++)
		{
			playerUnitStack.push(new Unit(playerFaction));
		}
	}
	if(playerUnitStack.size() == 45)
	{
		std::cout << "UnitStack von der " << playerFaction.getFactionName() << " ist voll! FEHLER!" << std::endl;
	}
}

// Pop i Units off the UnitStack of Player
void Player::popUnit(const int& unitCount)
{
	if(playerUnitStack.size() != 0)
	{
		for(int i = 0; i < unitCount; i++)
		{
			playerUnitStack.pop();
		}
	}
	if(playerUnitStack.size() == 0)
	{
		std::cout << "UnitStack von der " << playerFaction.getFactionName() << " ist leer! FEHLER!" << std::endl;
	}
}

const Faction& Player::getPlayerFaction() const
{
	return playerFaction;
}

// Return counter of conquered Territories
const int& Player::getTerritoryCount()
{
	int temp_terrCount = 0;
	for(unsigned i = 0; i < playerCardVec.size(); i++)
	{
		if(playerCardVec.at(i))
		{
			temp_terrCount++;
		}
	}
	territoryCount = temp_terrCount;
	return territoryCount;
}

/*
const int& Player::getCardCount()
{
	int temp_cardCount = 0;
	for(unsigned i = 0; i < playerCardVec.size(); i++)
	{
		if(playerCardVec.at(i))
		{
			cardCount++;
		}
	}
	cardCount = temp_cardCount;
	return cardCount;
}
*/

const int& Player::getUnitsOnBoard() const
{
	return unitsOnBoard;
}

const int& Player::getUnitsToPlaceOnBoard() const
{
	return unitsToPlaceOnBoard;
}

// Return true if player is at turn
const bool& Player::getIsOnTurn() const
{
	return isOnTurn;
}

/*
const bool& Player::isExchangeCardsActive() const
{
	return activateExchangeCards;
}
*/

// Return true if player got a new Territory in this Round
const bool& Player::getNewTerritoryInTurn() const
{
	return newTerritoryInTurn;
}

// Return true if a player owns every Territory of the specific Continent (North/South)
const bool& Player::getConqueredNorthEasternKingdoms() const
{
	return conqueredNorthEasternKingdoms;
}

const bool& Player::getConqueredSouthEasternKingdoms() const
{
	return conqueredSouthEasternKingdoms;
}

const bool& Player::getConqueredNorthKalimdor() const
{
	return conqueredNorthKalimdor;
}

const bool& Player::getConqueredSouthKalimdor() const
{
	return conqueredSouthKalimdor;
}

// Check if player owns a Territory
const bool Player::ownsTerritoryNumber(const int& number)
{
	return playerTerrVec[number - 1];
}

/*
// Check if player owns a Card
const bool Player::ownsCardNumber(const int& number)
{
	return playerCardVec[number - 1];
}
*/

void Player::changeUnitsToPlaceOnBoard(const int& count)
{
	unitsToPlaceOnBoard += count;
}

/*

// Set the specific Territory-Card true in the Player's Card-Vector
// True = owns the Card now
void Player::setNewCard(const int& cardNumber)
{
	playerCardVec[cardNumber - 1] = true;
}


// Delete the specific Territory-Card from the Player's Card-Vector
// False = player doesn't own it anymore
void Player::deleteCard(const int& cardNumber)
{
	playerCardVec[cardNumber - 1] = false;
}


// Exchange Cards for Units and delete the specific Cards from the Game

const int& Player::unitsForExchangeCards()
{
	if(getCardCount() > 0)
	{
		int sum_exchangedCardValues = 0;

		std::cout << "Bitte geben Sie die Kartennummer ein, die Sie gegen Verstaerkung umtauschen moechten." << std::endl;
		std::cout << "Moechten Sie keine weiteren Karten mehr eintauschen, geben sie eine 0 ein, um Ihre Auswahl zu bestaetigen." << std::endl;

		for(int i = 0; i != 1024; i++)
		{
			int temp_terrNumber;
			std::cout << i << ". Gebietskarte die Sie eintauschen moechten: ";
			std::cin >> temp_terrNumber;
			std::cout << std::endl << std::endl;

			// 0 stops exchanging Cards
			if( temp_terrNumber == 0)
			{
				break;
			}
						
			if(playerCardVec.at(temp_terrNumber - 1))
			{
				sum_exchangedCardValues += 1;
				deleteCard(temp_terrNumber);
				break;
			}
			if(!(playerCardVec.at(temp_terrNumber - 1)))
			{
				std::cout << "Diese Gebietskarte besitzen Sie nicht!" << std::endl;
				i--;
			}
		}

		switch(sum_exchangedCardValues)
		{
		case 1:
			{
				exchangedCardsInUnitsValue = 1;
				activateExchangeCards = false;
				return exchangedCardsInUnitsValue;
			}
		case 2:
			{
				exchangedCardsInUnitsValue = 2;
				activateExchangeCards = false;
				return exchangedCardsInUnitsValue;
			}
		case 3:
			{
				exchangedCardsInUnitsValue = 4;
				activateExchangeCards = false;
				return exchangedCardsInUnitsValue;
			}
		case 4:
			{
				exchangedCardsInUnitsValue = 7;
				activateExchangeCards = false;
				return exchangedCardsInUnitsValue;
			}
		case 5:
			{
				exchangedCardsInUnitsValue = 10;
				activateExchangeCards = false;
				return exchangedCardsInUnitsValue;
			}
		case 6:
			{
				exchangedCardsInUnitsValue = 13;
				activateExchangeCards = false;
				return exchangedCardsInUnitsValue;
			}
		case 7:
			{
				exchangedCardsInUnitsValue = 17;
				activateExchangeCards = false;
				return exchangedCardsInUnitsValue;
			}
		case 8:
			{
				exchangedCardsInUnitsValue = 21;
				activateExchangeCards = false;
				return exchangedCardsInUnitsValue;
			}
		case 9:
			{
				exchangedCardsInUnitsValue = 25;
				activateExchangeCards = false;
				return exchangedCardsInUnitsValue;
			}
		case 10:
			{
				exchangedCardsInUnitsValue = 30;
				activateExchangeCards = false;
				return exchangedCardsInUnitsValue;
			}
		default:
			{
				std::cout << "ERROR at CARD_EXCHANGE!" << std::endl;
				exchangedCardsInUnitsValue = 0;
				activateExchangeCards = false;
				return exchangedCardsInUnitsValue;
			}
		}
	}
	else
	{
		std::cout << "Sie benoetigen insgesamt mindestens 2 Sterne um Verstaerkung zu erhalten!" << std::endl;
		exchangedCardsInUnitsValue = 0;
		activateExchangeCards = false;
		return exchangedCardsInUnitsValue;
	}
	
	std::cout << "Sie haben keine Gebietskarten, die Sie eintauschen koennten!" << std::endl;
	exchangedCardsInUnitsValue = 0;
	activateExchangeCards = false;
	return exchangedCardsInUnitsValue;
}
*/

void Player::changeOwnsTerrNumber(const int& terrNumber)
{
	playerTerrVec[terrNumber - 1] = !(playerTerrVec[terrNumber - 1]);

	// check if North Kalimdor is conquered
	if(	playerTerrVec.at(0) &&
		playerTerrVec.at(1) &&
		playerTerrVec.at(2) &&
		playerTerrVec.at(3) &&
		playerTerrVec.at(4) &&
		playerTerrVec.at(5) &&
		playerTerrVec.at(6) &&
		playerTerrVec.at(7) &&
		playerTerrVec.at(9) &&
		playerTerrVec.at(10))
	{
		conqueredNorthKalimdor = true;
	}
	else
	{
		conqueredNorthKalimdor = false;
	}

	// check if South Kalimdor is conquered
	if(	playerTerrVec.at(8) &&
		playerTerrVec.at(11) &&
		playerTerrVec.at(12) &&
		playerTerrVec.at(13) &&
		playerTerrVec.at(14) &&
		playerTerrVec.at(15) &&
		playerTerrVec.at(16) &&
		playerTerrVec.at(17) &&
		playerTerrVec.at(18))
	{
		conqueredSouthKalimdor = true;
	}
	else
	{
		conqueredSouthKalimdor = false;
	}

	// check if North Eastern Kingdoms is conquered
	if(	playerTerrVec.at(19) &&
		playerTerrVec.at(20) &&
		playerTerrVec.at(21) &&
		playerTerrVec.at(22) &&
		playerTerrVec.at(23) &&
		playerTerrVec.at(24) &&
		playerTerrVec.at(25) &&
		playerTerrVec.at(26) &&
		playerTerrVec.at(27) &&
		playerTerrVec.at(28) &&
		playerTerrVec.at(29))
	{
		conqueredNorthEasternKingdoms = true;
	}
	else
	{
		conqueredNorthEasternKingdoms = false;
	}

	// check if South Eastern Kingdoms is conquered
	if(	playerTerrVec.at(30) &&
		playerTerrVec.at(31) &&
		playerTerrVec.at(32) &&
		playerTerrVec.at(33) &&
		playerTerrVec.at(34) &&
		playerTerrVec.at(35) &&
		playerTerrVec.at(36) &&
		playerTerrVec.at(37) &&
		playerTerrVec.at(38) &&
		playerTerrVec.at(39) &&
		playerTerrVec.at(40))
	{
		conqueredSouthEasternKingdoms = true;
	}
	else
	{
		conqueredSouthEasternKingdoms = false;
	}
}

void Player::setIsOnTurn(const bool& b)
{
	isOnTurn = b;
}

/*
void Player::setActivateExchangeCards(const bool& b)
{
	activateExchangeCards = b;
}
*/

// Set true if a player owns every Territory of the specific Continent (North/South Kalimdor/Eastern Kingdoms)
void Player::setConqueredNorthEasternKingdoms(const bool& b)
{
	conqueredNorthEasternKingdoms = b;
}

void Player::setConqueredSouthEasternKingdoms(const bool& b)
{
	conqueredSouthEasternKingdoms = b;
}

void Player::setConqueredNorthKalimdor(const bool& b)
{
	conqueredNorthKalimdor = b;
}

void Player::setConqueredSouthKalimdor(const bool& b)
{
	conqueredSouthKalimdor = b;
}


// True for a new territory in this Round
void Player::setNewTerritoryInTurn(const bool& b)
{
	newTerritoryInTurn = b;
}