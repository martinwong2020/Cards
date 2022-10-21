#include <iostream>
#include "cards.h"
#include <vector>

#include "players.h"
int Card::get_card_value(){
    srand((unsigned) time(NULL));
    // std::cout<<1+(rand()%13);
    return (1+(rand()%13));
}
std::vector<std::pair<int,std::string>> Card::generate_n_cards(int n){
    std::vector<std::pair<int,std::string>> cards;
    srand((unsigned) time(NULL));
    for(int i=0;i<n;i++){
        cards.push_back(std::make_pair((1+(rand()%13)),Card::suit[(rand()%4)]));
    }
    return cards;
}
std::string Card::get_suit(){
    srand((unsigned) time(NULL));
    int index=(rand()%4);
    std::string sign=Card::suit[index];
    return sign;
}

std::pair<int,std::string> Card::get_card(){
    Card c;
    return std::make_pair(c.get_card_value(),c.get_suit());
}

void Card::draw_card(std::pair<int,std::string> card){
    std::cout<<card.first<<std::endl;
    std::cout<<card.second<<std::endl;
    for(int i=0;i<25;i++){
        std::cout<<"-";
    }
    std::cout<<std::endl;
    int num=2;
    switch(num){
        case 1:
        std::cout<<"|           /\\          |"<<std::endl;
        std::cout<<"|          /  \\         |"<<std::endl;
        std::cout<<"|         ------        |"<<std::endl;
        std::cout<<"|        /      \\       |"<<std::endl;
        case 2:
        std::cout<<"|         ----          |"<<std::endl;
        std::cout<<"|            |          |"<<std::endl;
        std::cout<<"|         ----          |"<<std::endl;
        std::cout<<"|         |             |"<<std::endl;
        std::cout<<"|         ----          |"<<std::endl;
        // case 3:
        
    }
    if(card.second=="Heart"){
        std::cout<<"/\\/\\"<<std::endl;
        std::cout<<"\\  /"<<std::endl;
        std::cout<<" \\/ "<<std::endl;
    }
    else if(card.second=="Clover"){
        std::cout<<"  () "<<std::endl;
        std::cout<<"()  ()"<<std::endl;
        std::cout<<"  /\\"<<std::endl;
    }
    else if(card.second=="Diamond"){
        std::cout<<" /\\ "<<std::endl;
        std::cout<<"/  \\"<<std::endl;
        std::cout<<"\\  /"<<std::endl;
        std::cout<<" \\/  "<<std::endl;
    }
    else if(card.second=="Spade"){
        std::cout<<" /\\ "<<std::endl;
        std::cout<<"/  \\"<<std::endl;
        std::cout<<"U  U"<<std::endl;
        std::cout<<" /\\ "<<std::endl;
    }
}