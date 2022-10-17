#include <iostream>
#include "board.h"
void Board::score_counter(int& score,bool win_state,int bet){
    if (win_state==true){
        score=score+bet*2;
    }
    else{
        score=score-bet;
    }
}
void Board::draw_score(int score){
    std::cout<<"Score: "<<score<<std::endl;
}
void Board::draw_board(){

}
