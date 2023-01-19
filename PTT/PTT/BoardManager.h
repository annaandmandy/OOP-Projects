#include<vector>
#include "Viewer.h"
#include "Mail.h"
#include <iostream>
using namespace std;

// ¿ï¾Ü¶µ¥Ø
enum BoardState
{
    MENU = 0,
    SELECT_BOARD = 1,
    BOARD = 2,
    POST = 3,
    EESC = 4,
    INVALID,
};

class BoardManager : public Viewer
{
public:

    std::vector <Board> boards;

    int current_user;

    User user;
    BoardState state;
    Viewer viewer;
    Board board;
    Mail gmail;

    void update(bool key[]);
    void keyUpdate(bool key[]);
    
};
