#include <iostream>
#include "cards.h"
#include "board.h"

#include "twenty_one.h"
#include "players.h"
#include <vector>
using namespace std;
int score_wager_prompt(int& score){
    int wagered;
    cout<<"To start, you would lose 25 score for card fees everytime you play."<<endl;
    
    cout<<"How much of your point do you want to wager?"<<endl;
    cin>>wagered;
    cout<<"You have wagered: "<<wagered<<endl;
    score=score-25-wagered;
    return wagered;
}
void play_twenty_one(int& score){
    vector<pair<int,std::string>> played_cards;
    int wagered=score_wager_prompt(score);
    Board board;
    board.draw_score(score);
    Twenty_one TO;
    Player p1;
    std::pair<std::pair<int,std::string>,std::pair<int,std::string>> dealt_card=TO.deal_twenty_one();
    
    p1.set_card_one(dealt_card.first.first,dealt_card.first.second);
    p1.set_card_two(dealt_card.second.first,dealt_card.second.second);
    cout<<p1.get_card_one().first<<p1.get_card_one().second<<endl;
    cout<<p1.get_card_two().first<<p1.get_card_two().second<<endl;
    board.score_counter(score,true,wagered);
    board.draw_score(score);

    cout<<TO.hit().first<<endl;
    cout<<TO.hit().first<<endl;
}
int main(){
    // cout<<"hi"<<endl;
    // Card c;
    // // c.get_card_value();
    // pair<int,string> card=c.get_card();
    // c.draw_card(card);
    // // cout<<card.first<<card.second<<endl;
    // // c.draw_card(card);
    int score=100;
    // Twenty_one TO;
    // cout<<TO.deal_twenty_one().first.first; 
    string user_input;
    cout<<"Hello! Welcome to the world of card games."<<endl;
    cout<<"We will start you off with 100 points. You can try increasing by playing the offered games."<<endl;
    cout<<"The games we have are 21(Blackjack)[P21],"<<endl;
    cout<<"Please type the game code you wish to play.(The values inside []):"<<endl;
    bool run=true;
    while(run){
        cin>>user_input;
        if(user_input=="P21"){
            play_twenty_one(score);
            
            run=false;
        }
        else{
            cout<<"Incorrect code format. Try P21 for blackjack."<<endl;
            cout<<"Please type the game code you wish to play.(The values inside []):"<<endl;
        }
    }
    // Board board;
    // cout<<"SCORE: ";
    // board.draw_score(score);   
    
}