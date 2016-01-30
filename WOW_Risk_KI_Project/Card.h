#ifndef CARD_H
#define CARD_H

#include <string>

class Card
{
private:
	int cardValue;
	std::string cardName;
	int cardNumber;

public:
	Card(int value, std::string name, int terrNumber);
	~Card();

	const int& getCardValue() const;
	const std::string& getCardName() const;
	const int& getCardNumber() const;

};

#endif // !CARD_H