#pragma once
enum class suit
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
	suit m_suit = suit::CLUB;
	card_type m_type = card_type::ACE;
};