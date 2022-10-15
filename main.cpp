#include <iostream>
#include "cards.h"
using namespace std;
int main(){
    cout<<"hi"<<endl;
    Card c;
    c.get_card_value();
    pair<int,string> card=c.get_card();
    cout<<card.first<<card.second<<endl;
    c.draw_card(card);
}