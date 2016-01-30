#ifndef AI_H
#define AI_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "Player.h"
#include "GameBoard.h"

class AI : public Player
{
private:
	GameBoard* gameBoard;

	// chance for choosing a random action (now: 20% chance)
	float randomChoiceValue;

	std::vector<std::vector<float> > q_values;
	std::vector<std::vector<int> > allActions;

	// Wird mit besuchten States + Action gefüllt und zum Schluss bewertet 
	// <action, state> for [i]
	std::vector<std::pair<int, int>> vecTupel_VisitedStates;

	// <Q_Value> for [i]
	std::vector<float> vecNew_Q_Values;

public:
	AI(Faction faction, GameBoard* board);
	~AI();
	
void load();
void store();

void createEmptyTableOfValues();

void setGameBoard(GameBoard* board);

float getQ_Value(const int& action, const int& state);

float calculateQ_Value(const std::string& currentState, const int& actionNumber, const int& phase, const float& old_Q_Value);

virtual const std::string getCurrentState() const;

void makeInput();

virtual std::vector<int> chooseAction(const int& phaseNumber, std::string currentState);

std::vector<int> agentPlaceUnits(std::string currentState);
std::vector<int> agentAttack(std::string currentState);
// int agentMoveUnits(std::string currentState);

std::vector<int> getAllPossibleActions(const int& phaseNumber, std::string state);
int getBestActionNumber(const int phaseNumber, const std::string& currentState);

int binToDec(std::string state_bin);

};

#endif // !AI_H