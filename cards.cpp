#include <iostream>
#include "cards.h"


int Card::get_card_value(){
    srand((unsigned) time(NULL));
    // std::cout<<1+(rand()%13);
    return (1+(rand()%13));
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