#ifndef TWENTYONE_H
#define TWENTYONE_H
#include <iostream>
#include "cards.h"


class Twenty_one{
    private:
    int cards_played=0;
    public:
    int get_cards_played();
    void set_cards_played(int n);
    std::pair<std::pair<int,std::string>,std::pair<int,std::string>> deal_twenty_one();
    std::pair<int,std::string> hit();
};
#endif