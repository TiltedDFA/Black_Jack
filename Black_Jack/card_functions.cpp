#include "card_functions.h"
void Game::set_up_deck(std::vector<card_template>& deck)
{
	for (int j = 0; j < 13; ++j)
	{
		for(int i = 0; i < 4; ++i)
		{
			card_template temp1;
			temp1.m_suit = static_cast<suit>(i);
			temp1.m_type = static_cast<card_type>(j);
			deck.push_back(temp1);
		}
	}
	std::random_device rd;
	auto rng = std::default_random_engine{ rd() };
	std::shuffle(deck.begin(), deck.end(), rng);
}
card_template Game::deal_card(std::vector<card_template>& deck)
{
	const card_template chosen_card = deck[deck.size()-1];
	deck.erase(std::next(deck.begin(), deck.size()-1));
	return chosen_card;
}
std::string Game::card_to_string(const card_template& card)
{
	std::string temp{};
	switch (card.m_type)
	{
	case card_type::ACE:
		temp += "Ace of ";
		break;
	case card_type::TWO:
		temp += "Two of ";
		break;
	case card_type::THREE:
		temp += "Three of ";
		break;
	case card_type::FOUR:
		temp += "Four of ";
		break;
	case card_type::FIVE:
		temp += "Five of ";
		break;
	case card_type::SIX:
		temp += "Six of ";
		break;
	case card_type::SEVEN:
		temp += "Seven of ";
		break;
	case card_type::EIGHT:
		temp += "Eight of ";
		break;
	case card_type::NINE:
		temp += "Nine of ";
		break;
	case card_type::TEN:
		temp += "Ten of ";
		break;
	case card_type::JACK:
		temp += "Jack of ";
		break;
	case card_type::QUEEN:
		temp += "Queen of ";
		break;
	case card_type::KING:
		temp += "King of ";
		break;
	}
	switch (card.m_suit)
	{
	case suit::CLUB:
		temp += "Clubs";
		break;
	case suit::DIAMOND:
		temp += "Diamonds";
		break;
	case suit::SPADE:
		temp += "Spades";
		break;
	case suit::HEART:
		temp += "Hearts";
		break;
	}
	return temp;
}
void Game::display_all_cards(const std::vector<card_template>& cards)
{
	for(auto i = cards.cbegin(); i < cards.cend(); ++i)
	{
		std::cout << (i-cards.cbegin()+1) << ". " << card_to_string(*i) << std::endl;
	}
}
int Game::get_card_total(std::vector<card_template>cards)
{
	std::sort(cards.begin(), cards.end(),
		[&](const card_template card1,const card_template card2)	{
			return (static_cast<int>(card1.m_type) > static_cast<int>(card2.m_type));
	});
	int r_total = 0;
	for(auto i = cards.cbegin(); i < cards.cend(); ++i)
	{
		if(static_cast<int>(i->m_type) < 10 && static_cast<int>(i->m_type) != 0)
		{
			r_total += static_cast<int>(i->m_type)+1;
		}
		else if(static_cast<int>(i->m_type)!= 0)
		{
			r_total += 10;
		}
		else
		{
			if(r_total + 11 > 21)
			{
				r_total += 1;
			}
			else
			{
				r_total += 11;
			}
		}
	}
	return r_total;
}
void Game::deal_computer_cards(std::vector<card_template>& cards, std::vector<card_template>& deck)
{
	while(get_card_total(cards) < 17)
	{
		cards.push_back(deal_card(deck));
	}	
}