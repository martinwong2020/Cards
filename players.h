#ifndef PLAYERS_H
#define PLAYERS_H
#include <iostream>

class Player{
    private:
        int card_one_value;
        std::string card_one_symbol;
        int card_two_value;
        std::string card_two_symbol;
    public:
        void set_card_one(int card_one_value,std::string card_one_symbol);
        std::pair<int,std::string> get_card_one();
        void set_card_two(int card_two_value,std::string card_two_symbol);
        std::pair<int,std::string> get_card_two();
};
#endif