#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "GameBoard.h"
#include "Faction.h"
#include "Turn.h"
#include "Player.h"
#include "AI.h"
#include "Data.h"

int main()
{
	sf::RenderWindow window;
	sf::ContextSettings antiAliasing;

	// DATA INITIALIZATION
	// seed rand() with std::time
	srand((unsigned int) time(NULL));

	// Initialize data
	Faction alliance("Allianz");
	Faction horde("Horde");

	// Initialize first player
	Player* player_Alliance = new Player(alliance, false);

	// Initialize Agent and load previously stored Q_Value_Table
	AI* agent_Horde = new AI(horde, NULL);
	
	//agent_Horde->createEmptyTableOfValues();
	agent_Horde->load();

	Data dat = Data();

	GameBoard gameBoard = GameBoard(player_Alliance, agent_Horde);
	agent_Horde->setGameBoard(&gameBoard);

	// Initialize the Turns
	Turn gameTurn = Turn(&gameBoard, &window, &dat);

	// true for Player One's Turn
	// false for Player Two's/AI's Turn
	bool playerIsAtTurn = true;;



	antiAliasing.antialiasingLevel = 8;

	// Create a window (1920 x 1080)
	window.create(sf::VideoMode(1220, 1080), "KI_Projekt_-_World_of_Warcraft_Risiko_Prototyp", sf::Style::None, antiAliasing);
	window.setPosition(sf::Vector2i(0, 0));
	
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
			// Game Loop

			// If agent or player won: update brain.txt with new Q_Values
			if(gameTurn.getGameEnd())
			{
				agent_Horde->store();
			}

			// Check whos at turn and get his Game-Phase
			if(playerIsAtTurn)
			{
				gameTurn.activateCurrentPhase(playerIsAtTurn, gameTurn.getCurrentPhaseNumber());

				// End of turn? -> Next player
				if(gameTurn.getCurrentPhaseNumber() == 4)
				{
					playerIsAtTurn = !playerIsAtTurn;
					gameTurn.setCurrentPhaseNumber(1);
				}
			}
			if(!playerIsAtTurn)
			{
				gameTurn.activateCurrentPhase(playerIsAtTurn ,gameTurn.getCurrentPhaseNumber());

				// End of turn? -> Next player
				if(gameTurn.getCurrentPhaseNumber() == 4)
				{
					playerIsAtTurn = !playerIsAtTurn;
					gameTurn.setCurrentPhaseNumber(1);
				}
			}
        }

	// update in turn integrieeren!


    }

    return 0;
}