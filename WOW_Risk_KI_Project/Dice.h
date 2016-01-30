#ifndef DICE_H
#define DICE_H

#include <time.h>
#include <iostream>

class Dice
{
private:
	int value;

public:
	Dice();
	~Dice();

	const int& getDiceValue() const;

	void setDiceValue(const int& newValue);

	friend bool operator<(const Dice& lhs, const Dice& rhs);
	friend bool operator>(const Dice& lhs, const Dice& rhs);
	friend bool operator==(const Dice& lhs, const Dice& rhs);
	friend bool operator<=(const Dice& lhs, const Dice& rhs);
	friend bool operator>=(const Dice& lhs, const Dice& rhs);
};

#endif // !DICE_H