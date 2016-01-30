#include "GameBoard.h"

GameBoard::GameBoard(Player* player_One_Alliance, Player* player_two_Horde)
	:	attack(Attack()),
		playerOne(player_One_Alliance),
		playerTwo(player_two_Horde)
{
	//// INITIALIZE: cards and territories ////
	Faction allianz = player_One_Alliance->getPlayerFaction();
	Faction horde = player_two_Horde->getPlayerFaction();
	Faction neutral = Faction("Neutrales Gebiet");

	// #1 Teldrassil
	// vecCard.push_back(new Card(1, "Teldrassil", 1));
	vecTerr.push_back(new Territory("Teldrassil", 1, allianz, playerOne));
	vecTerr[0]->changeUnitCount(1);
	vecTerr[0]->setNeighborNumber(2);
	
	// #2 Dunkelküste
	// vecCard.push_back(new Card(1, "Dunkelkueste", 2));
	vecTerr.push_back(new Territory("Dunkelkueste", 2, neutral, NULL)); // Für Prototyp_Balanacing
	//vecTerr[1]->changeUnitCount(1); // Für Prototyp_Balanacing
	vecTerr[1]->setNeighborNumber(1);
	vecTerr[1]->setNeighborNumber(4); // Für Prototyp_Balanacing
	vecTerr[1]->setNeighborNumber(7);
	//vecTerr[1]->setNeighborNumber(27); // Für Prototyp_Balanacing

	// #3 Teufelswald
	// vecCard.push_back(new Card(1, "Teufelswald", 3));
	vecTerr.push_back(new Territory("Teufelswald", 3, neutral, NULL));
	vecTerr[2]->setNeighborNumber(4);
	vecTerr[2]->setNeighborNumber(5);
	vecTerr[2]->setNeighborNumber(7);

	// #4 Mondlichtung
	//vecCard.push_back(new Card(1, "Mondlichtung", 4));
	vecTerr.push_back(new Territory("Mondlichtung", 4, neutral, NULL));
	vecTerr[3]->setNeighborNumber(2); // Für Prototyp_Balanacing
	vecTerr[3]->setNeighborNumber(3);
	vecTerr[3]->setNeighborNumber(5); // Für Prototyp_Balanacing

	// #5 Winterquell
	//vecCard.push_back(new Card(1, "Winterquell", 5));
	vecTerr.push_back(new Territory("Winterquell", 5, neutral, NULL));
	vecTerr[4]->setNeighborNumber(3);
	vecTerr[4]->setNeighborNumber(4); // Für Prototyp_Balanacing
	vecTerr[4]->setNeighborNumber(6);

	// #6 Azshara
	//vecCard.push_back(new Card(1, "Azshara", 6));
	vecTerr.push_back(new Territory("Azshara", 6, neutral, NULL));
	vecTerr[5]->setNeighborNumber(5);
	vecTerr[5]->setNeighborNumber(7);

	// #7 Eschental
	//vecCard.push_back(new Card(1, "Eschental", 7));
	vecTerr.push_back(new Territory("Eschental", 7, neutral, NULL));
	vecTerr[6]->setNeighborNumber(2);
	vecTerr[6]->setNeighborNumber(3);
	vecTerr[6]->setNeighborNumber(6);
	vecTerr[6]->setNeighborNumber(8);
	vecTerr[6]->setNeighborNumber(9);

	// #8 Steinkrallengebirge
	//vecCard.push_back(new Card(1, "Steinkrallengebirge", 8));
	vecTerr.push_back(new Territory("Steinkrallengebirge", 8, neutral, NULL));
	vecTerr[7]->setNeighborNumber(7);
	// vecTerr[7]->setNeighborNumber(11); // Für Prototyp_Balanacing

	// #9 Brachland
	//vecCard.push_back(new Card(1, "Brachland", 9));
	vecTerr.push_back(new Territory("Brachland", 9, horde, playerTwo));
	vecTerr[8]->changeUnitCount(1);
	vecTerr[8]->setNeighborNumber(7);
	//vecTerr[8]->setNeighborNumber(10); // Für Prototyp_Balanacing
	//vecTerr[8]->setNeighborNumber(12); // Für Prototyp_Balanacing
	//vecTerr[8]->setNeighborNumber(13); // Für Prototyp_Balanacing
	//vecTerr[8]->setNeighborNumber(39); // Für Prototyp_Balanacing

	// #10 Durotar
	//vecCard.push_back(new Card(1, "Durotar", 10));
	vecTerr.push_back(new Territory("Durotar", 10, neutral, NULL)); // Für Prototyp_Balanacing
	//vecTerr[9]->changeUnitCount(2); // Für Prototyp_Balanacing
	//vecTerr[9]->setNeighborNumber(9); // Für Prototyp_Balanacing
	vecTerr[9]->setNeighborNumber(20);
	vecTerr[9]->setNeighborNumber(39);

	// #11 Desolace
	//vecCard.push_back(new Card(1, "Desolace", 11));
	vecTerr.push_back(new Territory("Desolace", 11, neutral, NULL)); 
	//vecTerr[10]->setNeighborNumber(8); // Für Prototyp_Balanacing
	vecTerr[10]->setNeighborNumber(14);

	// #12 Mulgore
	//vecCard.push_back(new Card(1, "Mulgore", 12));
	vecTerr.push_back(new Territory("Mulgore", 12, neutral, NULL)); // Für Prototyp_Balanacing
	//vecTerr[11]->changeUnitCount(2); // Für Prototyp_Balanacing
	//vecTerr[11]->setNeighborNumber(9); // Für Prototyp_Balanacing

	// #13 Düstermarschen
	//vecCard.push_back(new Card(1, "Duestermarschen", 13));
	vecTerr.push_back(new Territory("Duestermarschen", 13, neutral, NULL));
	//vecTerr[12]->setNeighborNumber(9); // Für Prototyp_Balanacing
	vecTerr[12]->setNeighborNumber(15);
	vecTerr[12]->setNeighborNumber(27);

	// #14 Feralas
	//vecCard.push_back(new Card(1, "Feralas", 14));
	vecTerr.push_back(new Territory("Feralas", 14, neutral, NULL));
	vecTerr[13]->setNeighborNumber(11);
	vecTerr[13]->setNeighborNumber(15);

	// #15 Tausend Nadeln
	//vecCard.push_back(new Card(1, "Tausend Nadeln", 15));
	vecTerr.push_back(new Territory("Tausend Nadeln", 15, neutral, NULL));
	vecTerr[14]->setNeighborNumber(13);
	vecTerr[14]->setNeighborNumber(14);
	vecTerr[14]->setNeighborNumber(18);

	// #16 Silithus
	//vecCard.push_back(new Card(1, "Silithus", 16));
	vecTerr.push_back(new Territory("Silithus", 16, neutral, NULL));
	vecTerr[15]->setNeighborNumber(17);
	vecTerr[15]->setNeighborNumber(19);

	// #17 Krater von Un'Goro
	//vecCard.push_back(new Card(1, "Krater von Un'Goro", 17));
	vecTerr.push_back(new Territory("Krater von Un'Goro", 17, neutral, NULL));
	vecTerr[16]->setNeighborNumber(16);
	vecTerr[16]->setNeighborNumber(18);

	// #18 Tanaris
	//vecCard.push_back(new Card(1, "Tanaris", 18));
	vecTerr.push_back(new Territory("Tanaris", 18, neutral, NULL));
	vecTerr[17]->setNeighborNumber(15);
	vecTerr[17]->setNeighborNumber(17);

	// #19 Ahn'Quiraj
	//vecCard.push_back(new Card(1, "Ahn'Quiraj", 19));
	vecTerr.push_back(new Territory("Ahn'Quiraj", 19, neutral, NULL));
	vecTerr[18]->setNeighborNumber(16);

	// #20 Tirisfal
	//vecCard.push_back(new Card(1, "Tirisfal", 20));
	vecTerr.push_back(new Territory("Tirisfal", 20, neutral, NULL)); // Für Prototyp_Balanacing
	//vecTerr[19]->changeUnitCount(2); // Für Prototyp_Balanacing
	vecTerr[19]->setNeighborNumber(10);
	vecTerr[19]->setNeighborNumber(21);
	vecTerr[19]->setNeighborNumber(23);
	vecTerr[19]->setNeighborNumber(39);

	// #21 Westliche Pestländer
	//vecCard.push_back(new Card(1, "Westliche Pestlaender",21));
	vecTerr.push_back(new Territory("Westliche Pestlaender", 21, neutral, NULL));
	vecTerr[20]->setNeighborNumber(20);
	vecTerr[20]->setNeighborNumber(22);
	vecTerr[20]->setNeighborNumber(24);

	// #22 Östliche Pestländer
	//vecCard.push_back(new Card(1, "Oestliche Pestlaender", 22));
	vecTerr.push_back(new Territory("Oestliche Pestlaender", 22, neutral, NULL));
	vecTerr[21]->setNeighborNumber(21);

	// #23 Silberwald
	//vecCard.push_back(new Card(1, "Silberwald", 23));
	vecTerr.push_back(new Territory("Silberwald", 23, neutral, NULL)); // Für Prototyp_Balanacing
	// vecTerr[22]->changeUnitCount(2); // Für Prototyp_Balanacing
	vecTerr[22]->setNeighborNumber(20);
	vecTerr[22]->setNeighborNumber(24);

	// #24 Vorgebirge des Hügellands
	//vecCard.push_back(new Card(1, "Vorgebirge des Huegellands", 24));
	vecTerr.push_back(new Territory("Vorgebirge des Huegellands", 24, neutral, NULL));
	vecTerr[23]->setNeighborNumber(21);
	vecTerr[23]->setNeighborNumber(23);
	vecTerr[23]->setNeighborNumber(25);
	vecTerr[23]->setNeighborNumber(26);

	// #25 Hinterland
	//vecCard.push_back(new Card(1, "Hinterland", 25));
	vecTerr.push_back(new Territory("Hinterland", 25, neutral, NULL));
	vecTerr[24]->setNeighborNumber(24);

	// #26 Arathihochland
	//vecCard.push_back(new Card(1, "Arathihochland", 26));
	vecTerr.push_back(new Territory("Arathihochland", 26, neutral, NULL));
	vecTerr[25]->setNeighborNumber(24);
	vecTerr[25]->setNeighborNumber(27);

	// #27 Sumpfland
	//vecCard.push_back(new Card(1, "Sumpfland", 27));
	vecTerr.push_back(new Territory("Sumpfland", 27, neutral, NULL)); // Für Prototyp_Balanacing
	//vecTerr[26]->changeUnitCount(1); // Für Prototyp_Balanacing
	//vecTerr[26]->setNeighborNumber(2); // Für Prototyp_Balanacing
	vecTerr[26]->setNeighborNumber(13);
	vecTerr[26]->setNeighborNumber(26);
	vecTerr[26]->setNeighborNumber(29);

	// #28 Dun Morogh
	//vecCard.push_back(new Card(1, "Dun Morogh", 28));
	vecTerr.push_back(new Territory("Dun Morogh", 28, neutral, NULL)); // Für Prototyp_Balanacing
	//vecTerr[27]->changeUnitCount(1); // Für Prototyp_Balanacing
	vecTerr[27]->setNeighborNumber(29);
	vecTerr[27]->setNeighborNumber(32);

	// #29 Loch Modan
	//vecCard.push_back(new Card(1, "Loch Modan", 29));
	vecTerr.push_back(new Territory("Loch Modan", 29, neutral, NULL)); // Für Prototyp_Balanacing
	//vecTerr[28]->changeUnitCount(1); // Für Prototyp_Balanacing
	vecTerr[28]->setNeighborNumber(27);
	vecTerr[28]->setNeighborNumber(28);
	vecTerr[28]->setNeighborNumber(31);
	
	// #30 Sengende Schlucht
	//vecCard.push_back(new Card(1, "Sengende Schlucht", 30));
	vecTerr.push_back(new Territory("Sengende Schlucht", 30, neutral, NULL));
	vecTerr[29]->setNeighborNumber(31);
	vecTerr[29]->setNeighborNumber(33);

	// #31 Ödland
	//vecCard.push_back(new Card(1, "Ödland", 31));
	vecTerr.push_back(new Territory("Ödland", 31, neutral, NULL));
	vecTerr[30]->setNeighborNumber(29);
	vecTerr[30]->setNeighborNumber(30);

	// #32 Wald von Elwynn
	//vecCard.push_back(new Card(1, "Wald von Elwynn", 32));
	vecTerr.push_back(new Territory("Wald von Elwynn", 32, neutral, NULL)); // Für Prototyp_Balanacing
	//vecTerr[31]->changeUnitCount(1); // Für Prototyp_Balanacing
	vecTerr[31]->setNeighborNumber(28);
	vecTerr[31]->setNeighborNumber(34);
	vecTerr[31]->setNeighborNumber(35);
	vecTerr[31]->setNeighborNumber(36);

	// #33 Brennende Steppe
	//vecCard.push_back(new Card(1, "Brennende Steppe", 33));
	vecTerr.push_back(new Territory("Brennende Steppe", 33, neutral, NULL));
	vecTerr[32]->setNeighborNumber(30);
	vecTerr[32]->setNeighborNumber(34);

	// #34 Rotkammgebirge
	//vecCard.push_back(new Card(1, "Rotkommgebirge", 34));
	vecTerr.push_back(new Territory("Rotkammgebirge", 34, neutral, NULL)); // Für Prototyp_Balanacing
	//vecTerr[33]->changeUnitCount(1); // Für Prototyp_Balanacing
	vecTerr[33]->setNeighborNumber(32);
	vecTerr[33]->setNeighborNumber(33);

	// #35 Westfall
	//vecCard.push_back(new Card(1, "Westfall", 35));
	vecTerr.push_back(new Territory("Westfall", 35, neutral, NULL)); // Für Prototyp_Balanacing
	//vecTerr[34]->changeUnitCount(1); // Für Prototyp_Balanacing
	vecTerr[34]->setNeighborNumber(32);
	vecTerr[34]->setNeighborNumber(36);
	
	// #36 Dämmerwald
	//vecCard.push_back(new Card(1, "Dämmerwald", 36));
	vecTerr.push_back(new Territory("Dämmerwald", 36, neutral, NULL)); // Für Prototyp_Balanacing
	//vecTerr[35]->changeUnitCount(1); // Für Prototyp_Balanacing
	vecTerr[35]->setNeighborNumber(32);
	vecTerr[35]->setNeighborNumber(35);
	vecTerr[35]->setNeighborNumber(37);
	vecTerr[35]->setNeighborNumber(39);
	
	// #37 Gebirgspass der Totenwinde
	//vecCard.push_back(new Card(1, "Gebirge von Totenwinde", 37));
	vecTerr.push_back(new Territory("Gebirgspass der Totenwinde", 37, neutral, NULL));
	vecTerr[36]->setNeighborNumber(36);
	vecTerr[36]->setNeighborNumber(38);

	// #38 Sümpfe des Elends
	//vecCard.push_back(new Card(1, "Suempfe des Elends", 38));
	vecTerr.push_back(new Territory("Suempfe des Elends", 38, neutral, NULL));
	vecTerr[37]->setNeighborNumber(37);
	vecTerr[37]->setNeighborNumber(41);

	// #39 Schlingendorntal
	//vecCard.push_back(new Card(1, "Schlingendorntal", 39));
	vecTerr.push_back(new Territory("Schlingendorntal", 39, neutral, NULL));
	//vecTerr[38]->setNeighborNumber(9); // Für Prototyp_Balanacing
	vecTerr[38]->setNeighborNumber(10);
	vecTerr[38]->setNeighborNumber(20);
	vecTerr[38]->setNeighborNumber(36);
	vecTerr[38]->setNeighborNumber(40);

	// #40 Zul'Gurub
	//vecCard.push_back(new Card(1, "Zul Gurub", 40));
	vecTerr.push_back(new Territory("Zul'Gurub", 40, neutral, NULL));
	vecTerr[39]->setNeighborNumber(39);

	// #41 Verwüstete Lande
	//vecCard.push_back(new Card(1, "Verwuestete Lande", 41));
	vecTerr.push_back(new Territory("Verwuestete Lande", 41, neutral, NULL));
	vecTerr[40]->setNeighborNumber(38);

	// Shuffle Cards
	//std::random_shuffle(vecCard.begin(), vecCard.end());
}

GameBoard::~GameBoard()
{

}


// Return Territory #(int)
Territory& GameBoard::getSpecificTerritory(int terrNumber)
{
	return *vecTerr[terrNumber - 1];
}


/*

std::vector<Card*>& GameBoard::getVecCard()
{
	return vecCard;
}

*/


// Initiate attack
void GameBoard::fight(const int& attacker_TerritoryNumber, const int& defender_TerritoryNumber, const int& attackingUnitCount)
{
	attack.attack(vecTerr[attacker_TerritoryNumber - 1]->getTerrOwner(), *vecTerr[attacker_TerritoryNumber - 1], *vecTerr[defender_TerritoryNumber - 1], attackingUnitCount);
}

void GameBoard::moveUnits(const int& unitCount, const int& fromTerrStart, const int& toTerrEnd)
{
	// TO DO: Neighbors?
	std::vector<int>::const_iterator temp_neigborFinder_It = std::find(	vecTerr[fromTerrStart - 1]->getVectorNeighborNumber().begin(), // Terr -> vec_Nr().ANFANG
																		vecTerr[fromTerrStart - 1]->getVectorNeighborNumber().end(),
																		toTerrEnd - 1);

	// If Iterator not at end of the vector, attacker- and defender-territory are neighbors
	if(	temp_neigborFinder_It != vecTerr[fromTerrStart - 1]->getVectorNeighborNumber().end())
	{

		// Is destination_territory friendly or neutral?
		if(	vecTerr[fromTerrStart - 1]->getTerrFaction().getFactionName().compare(vecTerr[toTerrEnd - 1]->getTerrFaction().getFactionName()) == 0 ||
			vecTerr[toTerrEnd - 1]->getTerrFaction().getFactionName().compare("Neutrales Gebiet") == 0)
		{
			vecTerr[fromTerrStart - 1]->changeUnitCount(-unitCount);
			vecTerr[toTerrEnd - 1]->changeUnitCount(unitCount);
		}
	}
	else
	{
		std::cout << "Die Gebiete " << vecTerr[fromTerrStart - 1]->getTerrName() << " und " << vecTerr[toTerrEnd - 1]->getTerrName() << " sind nicht benachbart und/oder unter Ihrer Kontrolle!" << std::endl << std::endl;
	}
}

// Return Player(#)
Player* GameBoard::getPlayer(const int& playerNumber) const
{
	// Alliance
	if(playerNumber == 1)
	{
		return playerOne;
	}

	// Horde
	else
	{
		return playerTwo;
	}
}

const bool GameBoard::checkIfPlayerWonTerrNumber(Player& currentPlayer, int& terrNumber)
{

	if(vecTerr[terrNumber - 1]->getUnitCount() == 0)
	{
		vecTerr[terrNumber - 1]->setTerrFaction(currentPlayer.getPlayerFaction());

		// Set the Faction of the conquered Territory to the Faction of currentPlayer
		if(currentPlayer.getPlayerFaction().getFactionName().compare("Allianz") == 0)
		{
			playerOne->changeOwnsTerrNumber(terrNumber);
			playerTwo->changeOwnsTerrNumber(terrNumber);
		}
		else
		{
			playerTwo->changeOwnsTerrNumber(terrNumber);
			playerOne->changeOwnsTerrNumber(terrNumber);
		}



		// Mark him eligible for drawing a Card this turn because of a conquered Teritory in this turn
		currentPlayer.setNewTerritoryInTurn(true);

		return true;
	}

	else
	{
		return false;
	}
}


/*

void GameBoard::drawCard(Player& currentPlayer)
{
	int cardNumber = (int)(std::rand() % vecCard.size() + 1);
	currentPlayer.setNewCard(cardNumber);

	// ...
}

*/


const bool GameBoard::checkIfPlayersNeighborsHostiles(Player* currentPlayer)
{
	std::string playersFactionName = currentPlayer->getPlayerFaction().getFactionName();

	for(int i = 0; i < (int)vecTerr.size(); i++)
	{
		if(currentPlayer->ownsTerritoryNumber(i + 1))
		{
			for(int j = 0; j < (int)vecTerr[i]->getVectorNeighborNumber().size(); j++)
			{
				std::string neighborFactionName = getSpecificTerritory((vecTerr[i]->getVectorNeighborNumber().at(j)) + 1).getTerrFaction().getFactionName();
			
				if(playersFactionName.compare("Allianz") == 0)
				{
					if(neighborFactionName.compare("Horde") == 0)
					{
						return true;
					}
				}
				if(playersFactionName.compare("Horde") == 0)
				{
					if(neighborFactionName.compare("Allianz") == 0)
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

const bool GameBoard::checkIfPlayerLostAllTerrs(Player* currentPlayer) const
{
	int checkSum = 0;

	for(int i = 1; i <= 9; i++) // 42 Terr_check for the real game! Prototyp_Balancing!
	{
		if(!currentPlayer->ownsTerritoryNumber(i))
		{
			checkSum++;
		}
	}
	
	switch(checkSum)
	{
	case 9:
		{
			return true;
			break;
		}
	default:
		{
			return false;
			break;
		}
	}
}