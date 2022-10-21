#ifndef TWENTYONE_H
#define TWENTYONE_H
#include <iostream>

#include "players.h"
#include "cards.h"
#include <vector>

class Twenty_one{
    private:
    int cards_played=0;
    public:
    int get_cards_played();
    void set_cards_played(int n);
    std::pair<std::pair<int,std::string>,std::pair<int,std::string>> deal_twenty_one();
    std::pair<int,std::string> hit();
    int conversion_card(int card_value);
    int sum_of_21(std::vector<std::pair<int,std::string>> cards);
};
#endif