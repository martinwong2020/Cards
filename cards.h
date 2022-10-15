#ifndef CARDS_H
#define CARDS_H

#include <iostream>

class Card{
    private:
        int card_value;
        // enum suit {Diamond, Clover, Heart, Spade};
        std::string suit[4]={"Diamond","Clover","Heart","Spade"};
    public:
        // suit get_suit();
        std::string get_suit();
        int get_card_value(); 
        std::pair<int,std::string> get_card();   
        void draw_card(std::pair<int,std::string> card);
};

#endif