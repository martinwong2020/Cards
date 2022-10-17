#ifndef BOARD_H
#define BOARD_H


class Board{
    public:
        void draw_board();
        void draw_score(int score);
        void score_counter(int& score,bool win_state,int bet);
    private:
};
#endif