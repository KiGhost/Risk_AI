#ifndef TURN_H
#define TURN_H

#include "GameBoard.h"
#include "Faction.h"
#include "AI.h"
#include "Data.h"

#define O(output) std::cout << output
#define C(input) std::cin >> input
#define E std::endl

class Turn
{
private:
	GameBoard& gameBoard;
	sf::RenderWindow& window;
	Data& data;

	sf::Texture map_tex;
	sf::Sprite map_spr;

	std::vector <sf::Sprite> terrColorVec;

	int currentPhaseNumber;
	int gameDurationCount;
	bool gameEnd;

	bool currentTurn;
	Player* currentPlayer;

public:
	Turn(GameBoard* board, sf::RenderWindow* wind, Data* datas);
	~Turn();

	void phaseOne_PlaceUnits(Player* currentPlayer);
	void phaseTwo_Conquer(Player* currentPlayer);
	void phaseThree_MoveUnits(Player* currentPlayer);
	// void phaseFour_DrawCards(Player& currentPlayer);

	void activateCurrentPhase(bool playersTurn, int phase);

	// void exchangingCards(Player& currentPlayer);

	const int& getCurrentPhaseNumber() const;

	const bool& getGameEnd();

	void setCurrentPhaseNumber(const int& phaseNmbr);

	void updateSpecificTerrColor(const int& terrNumber, const char& color);

	void CheckWinningGameForPlayer(Player* currentPlayer);

	void drawEverything();

};

#endif // !TURN_H