#pragma once
#include "card.h"
#include <vector>
#include <random>
#include <string>
#include <iostream>
#include <algorithm>
namespace Game
{
	
	void set_up_deck(std::vector<card_template>& deck);
	card_template deal_card(std::vector<card_template>& deck);
	std::string card_to_string(const card_template& card);
	void display_all_cards(const std::vector<card_template>& cards);
	bool compare_card_type(const card_template& card1, const card_template& card2);
	int get_card_total(std::vector<card_template>cards);
	void deal_computer_cards(std::vector<card_template>& cards, std::vector<card_template>& deck);
}

