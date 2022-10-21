#include "twenty_one.h"
#include "players.h"
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
    std::vector<std::pair<int,std::string>> card_storage = card.generate_n_cards(get_cards_played());   
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
    std::pair<int,std::string> new_card=(card.generate_n_cards(get_cards_played()))[get_cards_played()-1];
    // std::cout<<"hit: "<<new_card.first<<std::endl;
    return new_card;
}
int Twenty_one::conversion_card(int card_value){
    if(card_value==11||card_value==12||card_value==13){
        return 10;
    }
    else if(card_value==1){
        return 11;
    }
    return card_value;
}

int Twenty_one::sum_of_21(std::vector<std::pair<int,std::string>> cards){
    int sum_of_cards=0;
    //calculates sum with J, Q, and K being 10 and A being 11.
    for(int i=0;i<int(cards.size());i++){
        sum_of_cards=sum_of_cards+conversion_card((cards[i]).first);
    }
    //accounts for A's being 1 or 11
    if(sum_of_cards>21){
        for(int i=0;i<int(cards.size());i++){
            if((cards[i]).first==1){
                sum_of_cards=sum_of_cards-10;
            }
        }
    }
    return sum_of_cards;
}
