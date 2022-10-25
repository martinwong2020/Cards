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
    int player_total=0;
    Board board;
    board.draw_score(score);
    Twenty_one TO;
    Player p1;
    std::pair<std::pair<int,std::string>,std::pair<int,std::string>> dealt_card=TO.deal_twenty_one();
    
    p1.set_card_one(dealt_card.first.first,dealt_card.first.second);
    p1.set_card_two(dealt_card.second.first,dealt_card.second.second);
    cout<<p1.get_card_one().first<<p1.get_card_one().second<<endl;
    cout<<p1.get_card_two().first<<p1.get_card_two().second<<endl;
    // cout<<p1.get_all_cards()[0].first;
    bool hit_or_stand=true;
    while(hit_or_stand){
        
        // int sum_of_cards=0;
        string user_hit_or_stand;
        cout<< "Do you hit or stand?"<<endl;
        cin>>user_hit_or_stand;
        if(user_hit_or_stand=="hit"){
            pair<int,string> hit_card=TO.hit();
            p1.set_all_cards(hit_card);
            vector<std::pair<int,std::string>> p1_cards=p1.get_all_cards();
            // cout<<"round"<<TO.sum_of_21(p1_cards)<<endl;
            cout<< "hit card: "<<hit_card.first<<hit_card.second<<endl;
            player_total=TO.sum_of_21(p1_cards);
            if(player_total>21){
                hit_or_stand=false;
            }
            cout<<"Sum: "<<player_total<<endl;
        }
        else if(user_hit_or_stand=="stand"){ 
            vector<std::pair<int,std::string>> p1_cards=p1.get_all_cards();
            player_total=TO.sum_of_21(p1_cards);   
            cout<<"Sum: "<<player_total<<endl;
            hit_or_stand=false;
        }
        else{
            cout<<"Invalid choice."<<endl;
        }      
    }
    Player AI;
    std::pair<std::pair<int,std::string>,std::pair<int,std::string>> AI_card=TO.deal_twenty_one();
    AI.set_card_one(AI_card.first.first,AI_card.first.second);
    AI.set_card_two(AI_card.second.first,AI_card.second.second);
    cout<<AI.get_card_one().first<<AI.get_card_one().second<<endl;
    cout<<AI.get_card_two().first<<AI.get_card_two().second<<endl;
    bool AI_status=true;
    do{
        int AI_sum=0;
        std::vector<std::pair<int,std::string>> AI_hand=AI.get_all_cards();
        AI_sum=TO.sum_of_21(AI_hand);
        if(AI_sum<player_total&& AI_sum<21 && player_total<=21){
            pair<int,string> hit_card=TO.hit();
            AI.set_all_cards(hit_card);
            AI_sum+=hit_card.first;
            cout<<"Dealer hit card: "<<hit_card.first<<endl;
        }
        cout<<"Deal sum"<<AI_sum<<endl;
        if(((AI_sum>player_total)&&(AI_sum<=21))){
            board.score_counter(score,false,wagered);
            cout<<"2"<<"Dealer Sum: "<<AI_sum<<endl;
            board.draw_score(score);
            AI_status=false;
            
        }
        else if(((AI_sum>player_total)&&(AI_sum>21))|| (AI_sum==player_total)){
            board.score_counter(score,true,wagered);
            cout<<"3"<<"Dealer Sum: "<<AI_sum<<endl;
            board.draw_score(score);
            
            AI_status=false;
        }
    }
    while(AI_status);
}
int main(){
    int score=100;
    string user_input;
    cout<<"Hello! Welcome to the world of card games."<<endl;
    cout<<"We will start you off with 100 points. You can try increasing by playing the offered games."<<endl;
    cout<<"The games we have are 21(Blackjack)[P21],"<<endl;
    cout<<"Please type the game code you wish to play.(The values inside []):"<<endl;
    bool run=true;
    bool play_again=true;
    while(run){
        cin>>user_input;
        if(user_input=="P21"){
            string user_choice;
            while(play_again){
                play_twenty_one(score);
                if(score<26){
                    cout<<"Insufficient points to continue. Game over."<<endl;
                    break;
                }
                cout<<"do you want to play 21 again?[Y/N]";
                cin>>user_choice;
                if(user_choice=="N"){
                    play_again=false;
                }
                else if(user_choice=="Y"){
                    
                }
                else{
                    cout<<"Invalid response. Try typing Y for yes or N for no. Captilized."<<endl;
                }
            }
            

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