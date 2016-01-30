#include "Dice.h"


Dice::Dice()
{
	// generate RNG-Value(1-6)
	value = (std::rand() % 6) + 1;
}

Dice::~Dice()
{

}

// Return value of rolled Dice
const int& Dice::getDiceValue() const
{
	return value;
}


// set new value for Dice
void Dice::setDiceValue(const int& newValue)
{
	value = newValue;
}


// overloaded comparison-operators for Dices
bool operator<(const Dice& lhs, const Dice& rhs)
{ 
	return (lhs.getDiceValue() < rhs.getDiceValue());
}

bool operator>(const Dice& lhs, const Dice& rhs)
{ 
	return (lhs.getDiceValue() > rhs.getDiceValue());
}

bool operator==(const Dice& lhs, const Dice& rhs)
{ 
	return (lhs.getDiceValue() == rhs.getDiceValue());
}

bool operator<=(const Dice& lhs, const Dice& rhs)
{ 
	return (lhs < rhs || lhs == rhs);
}

bool operator>=(const Dice& lhs, const Dice& rhs)
{ 
	return (lhs > rhs || lhs == rhs);
}