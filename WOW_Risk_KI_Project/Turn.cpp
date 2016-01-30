#include "Turn.h"

Turn::Turn(GameBoard* board, sf::RenderWindow* wind, Data* datas)
	:	gameBoard(*board),
		window(*wind),
		data(*datas),
		currentPhaseNumber(1),
		gameDurationCount(1),
		gameEnd(false),
		currentPlayer(gameBoard.getPlayer(1))
{
	if(!map_tex.loadFromFile("data/prototyp_map_complete.png"))
	{
		O ("FAILED TO LOAD MAP!");
	}

	map_spr.setTexture(map_tex);

	for(int i = 1; i < 42; i++)
	{
		terrColorVec.push_back(sf::Sprite());

		if(gameBoard.getPlayer(1)->ownsTerritoryNumber(i))
		{
			updateSpecificTerrColor(i, 'b');
		}
		if(gameBoard.getPlayer(2)->ownsTerritoryNumber(i))
		{
			updateSpecificTerrColor(i, 'r');
		}
		if( !gameBoard.getPlayer(1)->ownsTerritoryNumber(i) &&
			!gameBoard.getPlayer(2)->ownsTerritoryNumber(i))
		{
			updateSpecificTerrColor(i, 'y');
		}
	}
}

Turn::~Turn()
{

}

// Phase 1: Calculate new units and place them
void Turn::phaseOne_PlaceUnits(Player* currentPlayer)
{
	drawEverything();

	O ("Die " << currentPlayer->getPlayerFaction().getFactionName() << " ist am Zug!" << E);

	O (E);
	O ("//////////////////////////////////////////" << E);
	O ("///// Phase 1: Einheiten platzieren! /////" << E);
	O ("//////////////////////////////////////////" << E);
	O (E);

	// Counter for Units to place on Board in this Turn
	// Always 3 Units per Turn from UnitStack
	currentPlayer->popUnit(3);
	currentPlayer->changeUnitsToPlaceOnBoard(3);

	// 1 Unit for a NEW conquered Territory in THIS turn
	if(currentPlayer->getNewTerritoryInTurn())
	{
		currentPlayer->popUnit(1);
		currentPlayer->changeUnitsToPlaceOnBoard(1);
	}

	// 2 Units for a COMPLETLY owned Continent (North/South Eastern Kingdoms/Kalimdor)
	if( currentPlayer->getConqueredNorthEasternKingdoms())
	{
		currentPlayer->popUnit(2);
		currentPlayer->changeUnitsToPlaceOnBoard(2);
	}
	if( currentPlayer->getConqueredSouthEasternKingdoms())
	{
		currentPlayer->popUnit(2);
		currentPlayer->changeUnitsToPlaceOnBoard(2);
	}
	if( currentPlayer->getConqueredNorthKalimdor())
	{
		currentPlayer->popUnit(2);
		currentPlayer->changeUnitsToPlaceOnBoard(2);
	}
	if( currentPlayer->getConqueredSouthKalimdor())
	{
		currentPlayer->popUnit(2);
		currentPlayer->changeUnitsToPlaceOnBoard(2);
	}

	int temp_terrCount = currentPlayer->getTerritoryCount();
	
	// Units for owned Territories
	if( temp_terrCount == 12 ||
		temp_terrCount == 13 ||
		temp_terrCount == 14)
	{
		currentPlayer->changeUnitsToPlaceOnBoard(1);
	}
	if( temp_terrCount == 15 ||
		temp_terrCount == 16 ||
		temp_terrCount == 17)
	{
		currentPlayer->changeUnitsToPlaceOnBoard(2);
	}
	if( temp_terrCount == 18 ||
		temp_terrCount == 19 ||
		temp_terrCount == 20)
	{
		currentPlayer->changeUnitsToPlaceOnBoard(3);
	}
	if( temp_terrCount == 21 ||
		temp_terrCount == 22 ||
		temp_terrCount == 23)
	{
		currentPlayer->changeUnitsToPlaceOnBoard(4);
	}
	if( temp_terrCount == 24 ||
		temp_terrCount == 25 ||
		temp_terrCount == 26)
	{
		currentPlayer->changeUnitsToPlaceOnBoard(5);
	}
	if( temp_terrCount == 27 ||
		temp_terrCount == 28 ||
		temp_terrCount == 29)
	{
		currentPlayer->changeUnitsToPlaceOnBoard(6);
	}
	if( temp_terrCount == 30 ||
		temp_terrCount == 31 ||
		temp_terrCount == 32)
	{
		currentPlayer->changeUnitsToPlaceOnBoard(7);
	}
	if( temp_terrCount == 33 ||
		temp_terrCount == 34 ||
		temp_terrCount == 35)
	{
		currentPlayer->changeUnitsToPlaceOnBoard(8);
	}
	if( temp_terrCount == 36 ||
		temp_terrCount == 37 ||
		temp_terrCount == 38 ||
		temp_terrCount == 39)
	{
		currentPlayer->changeUnitsToPlaceOnBoard(9);
	}
	if( temp_terrCount == 40 ||
		temp_terrCount == 41 ||
		temp_terrCount == 42)
	{
		currentPlayer->changeUnitsToPlaceOnBoard(10);
	}

	// Territory to Place Units
	int temp_territory_number;

	// UnitCount to Place at temp_territory_number
	int temp_unitsToPlace;

	O ("Grundverstaerkung und Verstaerkung durch territoriale Vorteile ergeben" << E);
	O ("eine Gesamtverstaerkung von " << currentPlayer->getUnitsToPlaceOnBoard() << " Einheiten." << E);
	O (E);

	while(currentPlayer->getUnitsToPlaceOnBoard() > 0)
	{
		if(currentPlayer->getIsAgent())
		{
			std::vector<int> temp_Vec = currentPlayer->chooseAction(1, currentPlayer->getCurrentState());

			temp_territory_number = temp_Vec.at(1);
			temp_unitsToPlace = temp_Vec.at(2);
		}

		O ("Ihnen verbleiben " << currentPlayer->getUnitsToPlaceOnBoard() << " Einheiten, um Ihre Gebiete zu verstaerken." << E << E);
		O ("Welches Ihrer Gebiete moechten Sie verstaerken?" << E);
		O ("Gebietsnummer: ");

		if(!currentPlayer->getIsAgent())
		{
			// Player choice
			C (temp_territory_number);
		}
		else
		{
			// Agent choice
			O (temp_territory_number);
		}
		O (E << E);

		if(currentPlayer->ownsTerritoryNumber(temp_territory_number))
		{
			O ("Wieviele Einheiten moechten Sie auf " << gameBoard.getSpecificTerritory(temp_territory_number).getTerrName() << " platzieren: ");
			
			if(!currentPlayer->getIsAgent())
			{
				// Player choice
				C (temp_unitsToPlace);
			}
			else
			{
				// Agent choice
				O (temp_unitsToPlace);
			}
			O (E);
						
			if(currentPlayer->getUnitsToPlaceOnBoard() - temp_unitsToPlace >= 0)
			{
				currentPlayer->changeUnitsToPlaceOnBoard(-temp_unitsToPlace);

				gameBoard.getSpecificTerritory(temp_territory_number).changeUnitCount(temp_unitsToPlace);
				drawEverything();
			}
			else
			{
				O ("Soviel Verstaerkung steht Ihnen nicht zur Verfuegung!" << E);
				O (E);
			}
		}
		else
		{
			O ("Dieses Gebiet ist nicht unter Ihrer Kontrolle!" << E);
			O (E);
		}
	}
}

// Phase 2: Attack enemy-territories or conquer neutral terretories
void Turn::phaseTwo_Conquer(Player* currentPlayer)
{
	int temp_attackTerrNumber;
	int temp_defenderTerrNumber;
	int temp_attackCount;

	char temp_Yes_No_One;
	char temp_Yes_No_Two;

	bool temp_isAttacking_One = true;
	bool temp_isAttacking_Two = true;

	O ("Die " << currentPlayer->getPlayerFaction().getFactionName() << " ist am Zug!" << E);

	O ("//////////////////////////////////////////" << E);
	O ("///// Phase 2: Territorien erobern!  /////" << E);
	O ("//////////////////////////////////////////" << E);
	O (E);

	// Check if there are hostile territories around the current players territories
	if(gameBoard.checkIfPlayersNeighborsHostiles(currentPlayer))
	{
		while(temp_isAttacking_One)
		{
			if(currentPlayer->getIsAgent())
			{
				std::vector<int> temp_Vec = currentPlayer->chooseAction(2, currentPlayer->getCurrentState());

				if(temp_Vec.at(1) == 1)
				{
					temp_Yes_No_One = 'J';
					temp_attackTerrNumber = temp_Vec.at(2);
					temp_defenderTerrNumber = temp_Vec.at(3);
				}
				else
				{
					temp_Yes_No_One = 'N';
				}
			}

			O ("Moechten Sie in diesem Zug ein gegnerisches Territorium angreifen?" << E);
			O (" [J]a oder [N]ein: ");

			if(!currentPlayer->getIsAgent())
			{
				// Player choice
				C (temp_Yes_No_One);
			}
			else
			{
				// Agent choice
				O (temp_Yes_No_One);
			}
			O (E << E);

			switch(temp_Yes_No_One)
			{
				case 'j':
				case 'J':
				{
					while(temp_isAttacking_Two)
					{
						O ("Von welchem Gebiet aus moechten Sie eine Offensive auf den Feind starten?" << E);
						O ("Gebietsnummer: ");

						if(!currentPlayer->getIsAgent())
						{
							// Player choice
							C (temp_attackTerrNumber);
						}
						else
						{
							// Agent choice
							O (temp_attackTerrNumber);
						}
						O (E << E);

						int unitCountAttTerr = gameBoard.getSpecificTerritory(temp_attackTerrNumber).getUnitCount();

						if(currentPlayer->ownsTerritoryNumber(temp_attackTerrNumber))
						{
							if(unitCountAttTerr > 1)
							{
								O ("Welches Territorium moechten Sie angreifen?" << E);
								O ("Gebietsnummer: ");

								if(!currentPlayer->getIsAgent())
								{
									// Player choice
									C (temp_defenderTerrNumber);
								}
								else
								{
									// Agent choice
									O (temp_defenderTerrNumber);
								}
								O (E << E);

								// Trys to find if attacker- and defender-territory are neighbors
								std::vector<int>::const_iterator temp_neigborFinder_It = std::find(	gameBoard.getSpecificTerritory(temp_attackTerrNumber).getVectorNeighborNumber().begin(), // Terr -> vec_Nr().ANFANG
																									gameBoard.getSpecificTerritory(temp_attackTerrNumber).getVectorNeighborNumber().end(),
																									temp_defenderTerrNumber - 1);

								// If Iterator not at end of the vector, attacker- and defender-territory are neighbors
								if(temp_neigborFinder_It != gameBoard.getSpecificTerritory(temp_attackTerrNumber).getVectorNeighborNumber().end())
								{
									bool temp_isAttackingTerrain = true;

									// Exception: Cant attack friendly Territories
									if(currentPlayer->ownsTerritoryNumber(temp_defenderTerrNumber))
									{
										O (gameBoard.getSpecificTerritory(temp_defenderTerrNumber).getTerrName() << " ist unter Ihrer Kontrolle und kann nicht angegriffen werden!" << E);
										O (E);

										temp_isAttackingTerrain = false;
									}

									// Exception: Cant attack neutral Territories
									if(gameBoard.getSpecificTerritory(temp_defenderTerrNumber).getTerrFaction().getFactionName().compare("Neutrales Gebiet") == 0)
									{		
										O (gameBoard.getSpecificTerritory(temp_defenderTerrNumber).getTerrName() << " ist ein neutrales Gebiet und kann nicht angegriffen werden!" << E);
										O ("Sie koennen es jedoch in der Truppenbewegungsphase einnehmen!" << E);
										O (E);

										temp_isAttackingTerrain = false;
									}

									while(temp_isAttackingTerrain)
									{
										if(!(currentPlayer->ownsTerritoryNumber(temp_defenderTerrNumber)))
										{
											if(gameBoard.getSpecificTerritory(temp_defenderTerrNumber).getUnitCount() != 0)
											{
												O ("Sie besitzen " << gameBoard.getSpecificTerritory(temp_attackTerrNumber).getUnitCount() << " Einheiten auf " << gameBoard.getSpecificTerritory(temp_attackTerrNumber).getTerrName() << "." << E);
												O (gameBoard.getSpecificTerritory(temp_defenderTerrNumber).getTerrName() << " besitzt " << gameBoard.getSpecificTerritory(temp_defenderTerrNumber).getUnitCount() << " verteidigende Einheiten." << E << E);
												O ("Mit wievielen Einheiten wollen Sie " << gameBoard.getSpecificTerritory(temp_defenderTerrNumber).getTerrName() << " angreifen?" << E);
												O ("Einheitenanzahl: ");

												if(!currentPlayer->getIsAgent())
												{
													// Player choice
													C (temp_attackCount);
												}
												else
												{
													// Agent choice
													if(gameBoard.getSpecificTerritory(temp_attackTerrNumber).getUnitCount() > 3)
													{
														temp_attackCount = 3;
													}
													if(gameBoard.getSpecificTerritory(temp_attackTerrNumber).getUnitCount() == 3)
													{
														temp_attackCount = 2;
													}
													if(gameBoard.getSpecificTerritory(temp_attackTerrNumber).getUnitCount() == 2)
													{
														temp_attackCount = 1;
													}
													O (temp_attackCount);
												}
												O (E << E);

												if(	temp_attackCount == 1 && unitCountAttTerr > 1 ||
													temp_attackCount == 2 && unitCountAttTerr > 2 ||
													temp_attackCount == 3 && unitCountAttTerr > 3)
												{
													// Calculate the battle
													gameBoard.fight(temp_attackTerrNumber, temp_defenderTerrNumber, temp_attackCount);
													drawEverything();

													if(gameBoard.checkIfPlayerWonTerrNumber(*currentPlayer, temp_defenderTerrNumber))
													{
														// Move attackers to the conquered Territory
														gameBoard.moveUnits(temp_attackCount, temp_attackTerrNumber, temp_defenderTerrNumber);
														gameBoard.getSpecificTerritory(temp_defenderTerrNumber).setTerrFaction(currentPlayer->getPlayerFaction().getFactionName());
														gameBoard.getSpecificTerritory(temp_defenderTerrNumber).setNewTerrOwner(currentPlayer);

														if(currentPlayer->getPlayerFaction().getFactionName().compare("Allianz") == 0)
														{
															updateSpecificTerrColor(temp_defenderTerrNumber, 'b');
														}
														if(currentPlayer->getPlayerFaction().getFactionName().compare("Horde") == 0)
														{
															updateSpecificTerrColor(temp_defenderTerrNumber, 'r');
														}

														drawEverything();
														
														// Check if currentPlayer won the Game
														CheckWinningGameForPlayer(currentPlayer);

														O ( gameBoard.getSpecificTerritory(temp_defenderTerrNumber).getTerrName() << " ist nun unter der Kontrolle der " << currentPlayer->getPlayerFaction().getFactionName() << "!" << E << E);
														
														
														if( gameBoard.getSpecificTerritory(temp_attackTerrNumber).getUnitCount() > 1)
														{
															char temp_Yes_No_One_moveUnits;

															O ("Moechten Sie weitere Einheiten aus " << gameBoard.getSpecificTerritory(temp_attackTerrNumber).getTerrName() << " nachruecken lassen?" << E);
															O ("Sie besitzen dort " << gameBoard.getSpecificTerritory(temp_attackTerrNumber).getUnitCount() << " Einheiten." << E << E);
															O (" [J]a oder [N]ein: ");
															
															if(!currentPlayer->getIsAgent())
															{
																// Player choice
																C (temp_Yes_No_One_moveUnits);
															}
															else
															{
																// Agent choice
																temp_Yes_No_One_moveUnits = 'J';
																O (temp_Yes_No_One_moveUnits);
															}

															bool wrongKey = true;

															while(wrongKey)
															{
																switch(temp_Yes_No_One_moveUnits)
																{
																	case 'j':
																	case 'J':
																	{
																		int temp_movingUnits = 0;
																	
																		O ("Wieviele Einheiten wollen Sie nachruecken lassen: ");

																		if(!currentPlayer->getIsAgent())
																		{
																			// Player choice
																			C (temp_movingUnits);
																		}
																		else
																		{
																			// Agent choice
																			temp_movingUnits = (int)gameBoard.getSpecificTerritory(temp_attackTerrNumber).getUnitCount() / 2;
																			O (temp_movingUnits);
																		}

																		bool wrongKey_movingUnits = true;

																		while(wrongKey_movingUnits)
																		{
																			if(	gameBoard.getSpecificTerritory(temp_attackTerrNumber).getUnitCount() + 1 >= temp_movingUnits &&
																				temp_movingUnits > 0 &&
																				gameBoard.getSpecificTerritory(temp_attackTerrNumber).getUnitCount() - temp_movingUnits	>= 1)
																			{
																				gameBoard.moveUnits(temp_movingUnits, temp_attackTerrNumber, temp_defenderTerrNumber);
																				drawEverything();

																				wrongKey_movingUnits = false;
																			}
																			else
																			{
																				O ("Bitte geben Sie eine Einheitenzahl zwischen 1 und " << gameBoard.getSpecificTerritory(temp_attackTerrNumber).getUnitCount() - 1 << " an: " << E);
																				C (temp_movingUnits);
																				O (E << E);
																			}
																		}

																		wrongKey = false;
																		break;
																	}

																	case 'n':
																	case 'N':
																	{
																		wrongKey = false;
																		break;
																	}

																	default:
																	{
																		O ("Bitte druecken Sie die Taste [J] für Ja oder [N] fuer Nein!" << E);
																		O (E);
																		break;
																	}
																}
															}
														}									
													}

													temp_isAttackingTerrain = false;
												}

												if(	temp_attackCount == 1 && unitCountAttTerr == 1 ||
													temp_attackCount == 2 && unitCountAttTerr == 2 ||
													temp_attackCount == 3 && unitCountAttTerr == 3)
												{
													O ("Sie muessen immer mindestens 1 Einheit zur Verteidigung auf ihren Gebieten zuruecklassen!" << E);
													O (E);
												}

												if(temp_attackCount > 3)
												{
													O ("Sie können nur mit maximal 3 Einheiten angreifen!" << E);
													O (E);
												}

												if(temp_attackCount < 1)
												{
													O ("Sie müssen mindestens 1 Einheit auswählen!" << E);
												}
											}
										}
									}
								}

								// Exception: Not a neighbor (attacking is not possible)
								else
								{
									O (gameBoard.getSpecificTerritory(temp_attackTerrNumber).getTerrName() << " kann " << gameBoard.getSpecificTerritory(temp_defenderTerrNumber).getTerrName() << " nicht angreifen! Kein Zugang!" << E);
									O (E);
								}
							}

							if(unitCountAttTerr == 1)
							{
								O ("Sie muessen immer mindestens 1 Einheit zur Verteidigung auf ihren Gebieten zuruecklassen!" << E);
								O (E);
							}
						}

						else
						{
							O ("Dieses Gebiet ist nicht unter Ihrer Kontrolle!" << E);
							O (E);
						}

						O ("Moechten Sie ein weiteres gegnerisches Territorium angreifen?" << E);
						O (" [J]a oder [N]ein: ");

						if(!currentPlayer->getIsAgent())
						{
							// Player choice
							C (temp_Yes_No_Two);
						}
						else
						{
							std::vector<int> temp_Vec = currentPlayer->chooseAction(2, currentPlayer->getCurrentState());

							if(temp_Vec.at(1) == 1)
							{
								temp_Yes_No_Two = 'J';
								temp_attackTerrNumber = temp_Vec.at(2);
								temp_defenderTerrNumber = temp_Vec.at(3);
							}
							else
							{
								temp_Yes_No_Two = 'N';
							}
							O (temp_Yes_No_Two);
						}
						O (E << E);

						switch(temp_Yes_No_Two)
						{
							case 'n':
							case 'N':
							{
								temp_isAttacking_Two = false;
								break;
							}
							case 'j':
							case 'J':
							{
								break;
							}
							default:
							{
								O ("Bitte druecken Sie die Taste [J] für Ja oder [N] fuer Nein!" << E);
								O (E);
								break;
							}
						} // Switch-Ende zweite Abfrage fight Ja/Nein
					}

					temp_isAttacking_One = false;
					break;
				}

				case 'n':
				case 'N':
				{
					temp_isAttacking_One = false;
					break;
				}

				default:
				{
					O ("Bitte druecken Sie die Taste [J] für Ja oder [N] fuer Nein!" << E);
					O (E);
					break;
				}
			}
		}
	}

	else
	{
		O ("Es grenzen keine feindlichen Gebiete an der Ihren!" << E);
		O (E);
	}

	///////////////////////////////////// TO DO! /////////////////////////////////////////////////////////
	//
	// Gegner: letztes Gebiet verloren? -> GAME WIN! 
	//
	//////////////////////////////////////////////////////////////////////////////////////////////////////
}

// Phase 3: Move units from neighbored, friendly territories to neighbored, friendly territories
void Turn::phaseThree_MoveUnits(Player* currentPlayer)
{
	drawEverything();

	O ("Die " << currentPlayer->getPlayerFaction().getFactionName() << " ist am Zug!" << E);

	O ("//////////////////////////////////////////" << E);
	O ("/////  Phase 3: Truppenbewegungen!   /////" << E);
	O ("//////////////////////////////////////////" << E);
	O (E);

	bool movingUnits = true;

	char temp_Yes_No_One;

	while(movingUnits)
	{
		O ("Wollen Sie Truppenbewegungen in ein freundliches/neutrales, benachbartes Gebiet ausfuehren?" << E);
		O (" [J]a oder [N]ein: ");

		if(!currentPlayer->getIsAgent())
		{
			// Player choice
			C (temp_Yes_No_One);
		}
		else
		{
			// Agent choice

			// AI::agentMovingUnits() macht Kenntnis über den Zustand der eigenen Territorien (UnitCount) keinen Sinn
			// da die Aktion immer wahllos bleibt -> Mehr States nötig -> ~45^42 States
			// Default: NO MOVEMENT -> Defensive KI (Da bei Angriff, der Verteidiger einen Vorteil hat)

			temp_Yes_No_One = 'N';
			O (temp_Yes_No_One);
		}
		O (E << E);

		switch(temp_Yes_No_One)
		{
		case 'n':
		case 'N':
			{
				movingUnits = false;
				break;
			}
		case 'j':
		case 'J':
			{
				int temp_startMoveTerrNumber = 0;
				
				O ("Von welchem Gebiet wollen Sie Einheiten abziehen?" << E);
				O ("Gebietsnummer:" << E);

				C (temp_startMoveTerrNumber);
				O (E << E);

				if(currentPlayer->ownsTerritoryNumber(temp_startMoveTerrNumber))
				{
					O ("Sie besitzen " << gameBoard.getSpecificTerritory(temp_startMoveTerrNumber).getUnitCount() << " Einheiten auf " << gameBoard.getSpecificTerritory(temp_startMoveTerrNumber).getTerrName() << "." << E << E);


					int movingUnitCount = 0;

					if(	gameBoard.getSpecificTerritory(temp_startMoveTerrNumber).getTerrFaction().getFactionName().compare(currentPlayer->getPlayerFaction().getFactionName()) == 0 &&
						gameBoard.getSpecificTerritory(temp_startMoveTerrNumber).getUnitCount() > 1)
					{
						O ("Wieviele Einheiten wollen Sie bewegen: ");
						C (movingUnitCount);
						O (E << E);

						if(movingUnitCount >= gameBoard.getSpecificTerritory(temp_startMoveTerrNumber).getUnitCount())
						{
							O ("Sie muessen mindestens 1 Einheit zur Verteidigung zuruecklassen!" << E << E);
						}
						if(movingUnitCount <= 0)
						{
							O ("Bitte geben Sie eine Einheitenzahl zwischen 1 und " << gameBoard.getSpecificTerritory(temp_startMoveTerrNumber).getUnitCount() - 1 << " an: ");
						}
						if(	gameBoard.getSpecificTerritory(temp_startMoveTerrNumber).getUnitCount() + 1 >= movingUnitCount &&
							movingUnitCount > 0 &&
							gameBoard.getSpecificTerritory(temp_startMoveTerrNumber).getUnitCount() - movingUnitCount >= 1)
						{
							int temp_endMoveTerrNumber = 0;
				
							O ("In welchem Gebiet wollen Sie Einheiten postieren?" << E);
							O ("Gebietsnummer:" << E);

							C (temp_endMoveTerrNumber);
							O (E << E);

							gameBoard.moveUnits(movingUnitCount, temp_startMoveTerrNumber, temp_endMoveTerrNumber);
							if(gameBoard.getSpecificTerritory(temp_endMoveTerrNumber).getTerrFaction().getFactionName().compare("Neutrales Gebiet") == 0)
							{
								gameBoard.getSpecificTerritory(temp_endMoveTerrNumber).setNewTerrOwner(currentPlayer);
								gameBoard.getSpecificTerritory(temp_endMoveTerrNumber).setTerrFaction(currentPlayer->getPlayerFaction().getFactionName());

								currentPlayer->changeOwnsTerrNumber(temp_endMoveTerrNumber);
							}

							// Update Territory-Color
							if(currentPlayer->getPlayerFaction().getFactionName().compare("Allianz") == 0)
							{
								updateSpecificTerrColor(temp_endMoveTerrNumber, 'b');
							}
							if(currentPlayer->getPlayerFaction().getFactionName().compare("Horde") == 0)
							{
								updateSpecificTerrColor(temp_endMoveTerrNumber, 'r');
							}

							drawEverything();
						}
					}
				}
				else
				{
					O ("Dieses Gebiet ist nicht unter ihrer Kontrolle!" << E << E);
				}
				break;
			}
		default:
			{
				break;
			}
		}
	}
}

// conquered more than 1 territory? : Draw a card
// TO DO: PHASE 4
/*

void Turn::phaseFour_DrawCards(Player& currentPlayer)
{
	O ("//////////////////////////////////////////" << E);
	O ("///// Phase 4: Gebietskarte ziehen!  /////" << E);
	O ("//////////////////////////////////////////" << E);
	O (E);

	// im Zug mind. 1 Gebiet erobert? -> 1 Karte ziehen!

	// if conquered one or more territories in this turn
	if(currentPlayer.getNewTerritoryInTurn())
	{
		

		
		// Pick a random Card from the CardStack


		void Player::drawCard(const Card& newCard)
		{
			int i = std::rand() % playerCardVec.size() + 1;
			currentPlayer.setNewCard(cardNumber);
		}


		
	}
	else
	{
		O ("In dieser Runde haben Sie keine erfolgreichen Gebietseroberungen durchgeführt und erhalten keine Karte!" << E << E);
	}
}

*/

// Abfrage am Ende des Turns: friendly Gebiete >= 42? -> GAME WIN!


// Activates the function for phase #(int)
void Turn::activateCurrentPhase(bool playersTurn, int phase)
{
	switch(phase)
	{
	case 1:
		{
			// true = Allance is at turn
			if(playersTurn)
			{
				phaseOne_PlaceUnits(gameBoard.getPlayer(1));
				currentPhaseNumber++;
			}
			// !false = Horde is at turn
			if(!playersTurn)
			{
				phaseOne_PlaceUnits(gameBoard.getPlayer(2));
				currentPhaseNumber++;
			}
			break;
		}
	case 2:
		{
			// true = Allance is at turn
			if(playersTurn)
			{
				phaseTwo_Conquer(gameBoard.getPlayer(1));
				currentPhaseNumber++;
			}
			// !false = Horde is at turn
			if(!playersTurn)
			{
				phaseTwo_Conquer(gameBoard.getPlayer(2));
				currentPhaseNumber++;
			}
			break;
		}
	case 3:
		{
			// true = Allance is at turn
			if(playersTurn)
			{
				phaseThree_MoveUnits(gameBoard.getPlayer(1));
				currentPhaseNumber++;
				gameDurationCount++;
			}
			// !false = Horde is at turn
			if(!playersTurn)
			{
				phaseThree_MoveUnits(gameBoard.getPlayer(2));
				currentPhaseNumber++;
			}
			break;
		}

		/*
	case 4:
		{
			phaseFour_DrawCards(currentPlayer);
			currentPhaseNumber = 1;
		}
		break;
		*/
	default:
		break;
	}
}

/*
//
// Exchanging Cards for Units
void Turn::exchangingCards(Player& currentPlayer)
{
	if(currentPlayer.isExchangeCardsActive())
	{
		int temp_unitsToPlaceFromCardExchange = currentPlayer.unitsForExchangeCards();

		currentPlayer.changeUnitsToPlaceOnBoard(temp_unitsToPlaceFromCardExchange);

		currentPlayer.setActivateExchangeCards(false);
	}
}

//
*/ // CARD EXCHANGE

// Returns the current Phase in int
const int& Turn::getCurrentPhaseNumber() const
{
	return currentPhaseNumber;
}

const bool& Turn::getGameEnd()
{
	return gameEnd;
}

void Turn::setCurrentPhaseNumber(const int& phaseNmbr)
{
	currentPhaseNumber = phaseNmbr;
}

// Update the specific Territory with the color
void Turn::updateSpecificTerrColor(const int& terrNumber, const char& color)
{
	terrColorVec.at(terrNumber - 1) = data.getSpecificTerrSpriteColor(terrNumber - 1, color);
}

// Check if Player has won the game by checking if enemey has no Territoties anymore
void Turn::CheckWinningGameForPlayer(Player* currentPlayer)
{
	if(currentPlayer->getPlayerFaction().getFactionName().compare("Allianz") == 0)
	{
		if(gameBoard.checkIfPlayerLostAllTerrs(gameBoard.getPlayer(2))) // check agent_territories: true if all lost
		{
			O ("Herzlichen Glückwunsch! Sie haben den Computer in " << gameDurationCount << " Runden besiegt!" << E);
			gameEnd = true;
			std::cin.ignore();
			std::cin.get();
		}
	}
	else
	{
		if(gameBoard.checkIfPlayerLostAllTerrs(gameBoard.getPlayer(1))) // check player_territories: true if all lost
		{
			O ("Sie haben gegen den Computer in " << gameDurationCount << " Runden verloren. Versuchen Sie es erneut!" << E);
			gameEnd = true;
			std::cin.ignore();
			std::cin.get();
		}
	}
}

// Update every displayed UnitCount/Territory-Color and draw it
void Turn::drawEverything()
{
	window.clear();

	for(int i = 0; i < 41; ++i)
	{
		window.draw(terrColorVec.at(i));

		data.text_updateUnitCount(i + 1, gameBoard.getSpecificTerritory(i + 1).getUnitCount());
		window.draw(data.getText_UnitCountVec().at(i));
	}

	window.draw(map_spr);

	window.display();
}