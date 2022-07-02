#pragma once
enum class suit
//This is used to assign all possible suits a numeric value
//so that logic can be perfomed on it while also making
//the numeric values readable for the programmer.
{
	HEART = 0,
	DIAMOND,
	SPADE,
	CLUB
};
enum class card_type
{
	ACE = 0,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING
};
struct card_template
{
	suit m_suit = suit::CLUB;//initalizes the variables
	card_type m_type = card_type::ACE;
};