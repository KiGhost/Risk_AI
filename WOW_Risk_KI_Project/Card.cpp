#include "Card.h"

Card::Card(int value, std::string name, int terrNumber)
	:	cardName(name),
		cardValue(value),
		cardNumber(terrNumber)
{

}

Card::~Card()
{

}

const int& Card::getCardValue() const
{
	return cardValue;
}

const std::string& Card::getCardName() const
{
	return cardName;
}

const int& Card::getCardNumber() const
{
	return cardNumber;
}