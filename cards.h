#ifndef CARDS_H
#define CARDS_H

#include <iostream>

class Card{
    private:
        int card_value;
        enum suit {Diamond, Clover, Heart, Spade};
    public:
        suit get_suit();
        int get_card_value(); 
        std::pair<int,suit> get_card();   
};

#endif