

#include "Board.h"

Board::Board(string title)
{
    boardTitle = title;

    vector<post> posts;

}

void Board::addPost(string author)
{
    post p;
    p.postStatus = "　";
    cout << "輸入標題: " << endl;
    cin >> p.title;
    cout << "輸入內容: " << endl;
    cin >> p.content;
    p.author = author;
    //time_t now; // 變數宣告
    //time(&now); // 取得現在的日期時間
    //p.time = ctime(&now);
    time_t now = time(0);
    tm* ltm = localtime(&now);
    p.time = to_string(1 + ltm->tm_mon) + "/";
    p.time += to_string(ltm->tm_mday) + "_";
    p.time += to_string(ltm->tm_hour) + ":";
    p.time += to_string(ltm->tm_min);
    posts.push_back(p);
}

// Intent: 新增留言
// Pre: 
// Post: 爆
void Board::addmessage(int postNum, string username)
{
    message m;
    m.username = username;
    int chooseGood;
    cout << "(1) 推 (2) 噓" << endl;
    cin >> chooseGood;
    
    if(chooseGood == 1)
    {
        m.good = true;
    }
    else
    {
        m.good = false;
    }
    cout << "輸入內容: " << endl;
    cin >> m.leaveMessage;
    
    //time_t now; // 變數宣告
    //time(&now); // 取得現在的日期時間
    //m.time = ctime(&now);

    time_t now = time(0);
    tm* ltm = localtime(&now);
    m.time = to_string(1 + ltm->tm_mon) + "/";
    m.time += to_string(ltm->tm_mday) + "_";
    m.time += to_string(ltm->tm_hour) + ":";
    m.time += to_string(ltm->tm_min);
    posts[postNum].messages.push_back(m);
}

// Intent: 如果留言多過10則，將狀態改為爆
// Pre: 
// Post: 爆
void Board::changePostStatus()
{
    for(int i = 0; i < posts.size(); i++)
    {
        if(posts[i].messages.size() >= 5)
        {
            posts[i].postStatus = "爆";
        }
    }
}

