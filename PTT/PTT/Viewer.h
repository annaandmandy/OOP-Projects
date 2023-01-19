#pragma once
#include "Board.h"
#include "play.h"
class Viewer : public Board
{
public:
    
    string userName;
    int Boardplace;
    int PostPalce;
    bool viewpost;
    bool viewcomment;
    int selectBoardNum;
    int boardNum;
    int postNum;
    bool askaddmessage = false;
    bool asksendmail = false;
    bool changePostorMessage;
    bool addBoard;

    void viewSelectBoard(vector<Board> boards);
    void viewBoard(vector<Board> boards);
    void viewPost(vector<Board> boards);
    void selectBoard(char choose, vector<Board> boards);
    void printPost(vector<Board> boards);
};

