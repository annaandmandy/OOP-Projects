
#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <stdio.h>
#include "User.h"
using namespace std;

struct message
{
    bool good;
    string username;
    string leaveMessage;
    string time;
};

struct post
{
    string postStatus;
    string author;
    string title;
    string time;
    string content;
    int countTime = 0;
    vector<message> messages;
};


class Board : public User
{

public:  

    Board()
    {

    }

    Board(string title);

    // 看板
    string boardTitle;
    // 裡面很多post
    vector<post> posts;
    // 可以按推或噓

    // 增加貼文
    void addPost(string author);

    // 推爆噓
    void changePostStatus();

    // 增加留言
    void addmessage(int postNum, string username);

};