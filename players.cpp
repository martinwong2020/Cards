#include "players.h"
#include <iostream>


void Player::set_card_one(int card_one_value,std::string card_one_symbol){
    this->card_one_value=card_one_value;
    this->card_one_symbol=card_one_symbol;
}
std::pair<int,std::string> Player::get_card_one(){
    return std::make_pair(card_one_value,card_one_symbol);
}
void Player::set_card_two(int card_two_value,std::string card_two_symbol){
    this->card_two_value=card_two_value;
    this->card_two_symbol=card_two_symbol;
}
std::pair<int,std::string> Player::get_card_two(){
    return std::make_pair(card_two_value,card_two_symbol);
}