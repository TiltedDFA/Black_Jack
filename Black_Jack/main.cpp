
#include "card_functions.h"
int main()
{
    std::vector<card_template> deck, computer_cards,user_cards;
	Game::set_up_deck(deck);//shuffles and initalizes values for deck 
   
    user_cards.push_back(Game::deal_card(deck));
    user_cards.push_back(Game::deal_card(deck));//adds two cards to the user's collection

    bool is_user_turn = true;
    std::string u_input;
    while (true)
    {
        if(is_user_turn)
        {
            if (Game::get_card_total(user_cards) > 21)
            {
                std::cout << "Your cards are: " << std::endl;
                Game::display_all_cards(user_cards);
                std::cout << "Oh no! you've gone bust. The Dealer wins!.\n";
                break;
            }
	        std::cout << "Your cards are: " << std::endl;
        	Game::display_all_cards(user_cards);
            std::cout << "Would you like to hit(1) or stay(2)?\n";
            std::cin >> u_input;            
        	if(u_input == "1")
            {
                user_cards.push_back(Game::deal_card(deck));
            }
            else
            {
                is_user_turn = false;
            }
        }
        else
        {
            std::cout << "Now it's the computer's turn.\n";
            std::cout << "The computer's cards are: \n";
            Game::deal_computer_cards(computer_cards,deck);
            Game::display_all_cards(computer_cards);
            if(Game::get_card_total(computer_cards) > 21)
            {
                std::cout << "The computer's gone bust! You win\n";
                break;
            }
            if(Game::get_card_total(computer_cards) > Game::get_card_total(user_cards))
            {
                std::cout << "The dealer's total is: " << Game::get_card_total(computer_cards) << ", while yours is: " << Game::get_card_total(user_cards) << std::endl;
                std::cout << "Therefore, the computer wins!\n";
                break;
            }
            if(Game::get_card_total(computer_cards) == Game::get_card_total(user_cards))
            {
                std::cout << "The dealer's total is: " << Game::get_card_total(computer_cards) << ", while yours is: " << Game::get_card_total(user_cards) << std::endl;
                std::cout << "Therefore, the computer wins!\n";
                break;
            }
            std::cout << "The dealer's total is: " << Game::get_card_total(computer_cards) << ", while yours is: " << Game::get_card_total(user_cards) << std::endl;
            std::cout << "Therefore, you win!\n";
            break;
        }        
    }
    return 0;
}