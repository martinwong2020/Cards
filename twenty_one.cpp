#include "twenty_one.h"
#include<iostream>
#include <vector>
int Twenty_one::get_cards_played(){
    return cards_played;
}
void Twenty_one::set_cards_played(int n){
    cards_played=cards_played+n;
}
std::pair<std::pair<int,std::string>,std::pair<int,std::string>> Twenty_one::deal_twenty_one(){
    set_cards_played(2);
    Card card;
    std::vector<std::pair<int,std::string>> card_storage = card.generate_n_cards(2);
    return std::make_pair(card_storage[get_cards_played()-2],card_storage[get_cards_played()-1]);
    // std::vector<std::pair<int,std::string>> deal_cards;
    // for(int i=0;i<2;i++){
    //     deal_cards.push_back(card.get_card());
    // }
    // std::vector<int> storage;
    // srand((unsigned) time(NULL));
    // for (int i=0;i<2;i++){
    //     storage.push_back((1+(rand()%13)));
    // }
    // return std::make_pair(deal_cards[0],deal_cards[1]);
    // return std::make_pair(cardget_card(),card2.get_card());
}

std::pair<int,std::string> Twenty_one::hit(){
    set_cards_played(1);
    Card card;
    return (card.generate_n_cards(get_cards_played()+1))[get_cards_played()-1];
}
