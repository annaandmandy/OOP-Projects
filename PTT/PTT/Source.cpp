#include<iostream>
#include "BoardManager.h"
#include <fstream>
#pragma warning(disable : 4996)
using namespace std;

BoardManager bm;

int main()
{
    //讀檔 - board
    ifstream ifsBoard;
    ifsBoard.open("saveBoard.txt");
    string read;
    while (ifsBoard >> read)
    {
        Board b(read);
        bm.boards.push_back(b);
    }
    ifsBoard.close();

    //讀檔 - post
    string Boardtitle;
    string postTitle;
    string postAuthor;
    string postTime;
    string postContent;
    int postCountTime;
    ifstream ifsPost;
    ifsPost.open("savePost.txt");
    while (ifsPost >> Boardtitle >> postTitle >> postAuthor >> postTime >> postCountTime >> postContent)
    {
        int boardPlace;
        for (int i = 0; i < bm.boards.size(); i++)
        {
            if (bm.boards[i].boardTitle == Boardtitle)
            {
                boardPlace = i;
                break;
            }
        }
        post p;
        p.title = postTitle;
        p.author = postAuthor;
        p.time = postTime;
        p.countTime = postCountTime;
        p.content = postContent;
        bm.boards[boardPlace].posts.push_back(p);
    }


    // 讀檔 - comment
    bool messageGood;
    string messageUser;
    string messageM;
    string messageTime;
    ifstream ifsComment;
    ifsComment.open("saveComment.txt");
    while (ifsComment >> Boardtitle >> postTitle >> messageGood >> messageUser >> messageM >> messageTime)
    {
        int boardPlace;
        for (int i = 0; i < bm.boards.size(); i++)
        {
            if (bm.boards[i].boardTitle == Boardtitle)
            {
                boardPlace = i;
                break;
            }
        }
        int postPlace;
        for (int i = 0; i < bm.boards[boardPlace].posts.size(); i++)
        {
            if (bm.boards[boardPlace].posts[i].title == postTitle)
            {
                postPlace = i;
                break;
            }
        }

        message m;
        m.good = messageGood;
        m.username = messageUser;
        m.leaveMessage = messageM;
        m.time = messageTime;
        bm.boards[boardPlace].posts[postPlace].messages.push_back(m);
    }
    ifsComment.close();

    string mailTitle;
    string mailArticle;
    string mailSender;
    string mailRecipient;
    ifstream ifsMail;
    ifsMail.open("saveMessage.txt");
    while (ifsMail >> mailSender >> mailRecipient >> mailTitle >> mailArticle)
    {
        mail m;
        m.sender = mailSender;
        m.Recipient = mailRecipient;
        m.title = mailTitle;
        m.article = mailArticle;
        bm.gmail.MailBox.push_back(m);
    }
    ifsMail.close();

    string userMemberId;
    string userPassword;
    ifstream ifsUser;
    ifsUser.open("saveUser.txt");
    while (ifsUser >> userMemberId >> userPassword)
    {
        bm.user.member_id.push_back(userMemberId);
        bm.user.member_password.push_back(userPassword);
    }
    ifsUser.close();

BEGIN:

    // menu
    bool gKeyState[6];
    string id;
    

    cout << "請輸入登入身分(Adimin/Member/Guest), 或輸入new以建立新帳號:";
    cin >> id;

    if (bm.user.identity(id) == true) {
        cout << "正在準備...\n";
        bm.viewer.userName = bm.user.logName();
        system("pause");
    }
    // 暫時

    cout << "(m) 前往MENU (s) 前往功能表 (b) 前往看板 (p) 前往貼文" << endl;
    bm.keyUpdate(gKeyState);
    system("CLS");

    while (!gKeyState[BoardState::EESC])
    {
        // Compute the time lap

        // Execute the game loop
        cout << "(m) 前往MENU (s) 前往功能表 (b) 前往看板 (p) 前往貼文" << endl;
        system("pause");
        bm.update(gKeyState);

        // Update the key
        bm.keyUpdate(gKeyState);

        if (gKeyState[BoardState::MENU])
        {
            goto BEGIN;
        }

    }

    // 存檔
    fstream ofsBoard;
    ofsBoard.open("saveBoard.txt", ios::out);
    for (int i = 0; i < bm.boards.size(); i++)
    {
        ofsBoard << bm.boards[i].boardTitle << endl;
    }
    ofsBoard.close();
    // post
    fstream ofsPost;
    ofsPost.open("savePost.txt", ios::out);
    for (int i = 0; i < bm.boards.size(); i++)
    {
        for (int j = 0; j < bm.boards[i].posts.size(); j++)
        {
            ofsPost << bm.boards[i].boardTitle << " "
                << bm.boards[i].posts[j].title << " "
                << bm.boards[i].posts[j].author << " "
                << bm.boards[i].posts[j].time << " "
                << bm.boards[i].posts[j].countTime << " "
                << bm.boards[i].posts[j].content << endl;
        }
    }
    ofsPost.close();

    // message
    fstream ofsComment;
    ofsComment.open("saveComment.txt", ios::out);
    for (int i = 0; i < bm.boards.size(); i++)
    {
        for (int j = 0; j < bm.boards[i].posts.size(); j++)
        {
            for (int p = 0; p < bm.boards[i].posts[j].messages.size(); p++)
            {
                ofsComment << bm.boards[i].boardTitle << " "
                    << bm.boards[i].posts[j].title << " "
                    << bm.boards[i].posts[j].messages[p].good << " "
                    << bm.boards[i].posts[j].messages[p].username << " "
                    << bm.boards[i].posts[j].messages[p].leaveMessage << " "
                    << bm.boards[i].posts[j].messages[p].time << endl;
            }
            
        }
    }
    ofsComment.close();

    // mail
    fstream ofsMail;
    ofsMail.open("saveMessage.txt", ios::out);
    for (int i = 0; i < bm.gmail.MailBox.size(); i++)
    {
        ofsMail << bm.gmail.MailBox[i].sender << " "
            << bm.gmail.MailBox[i].Recipient << " "
            << bm.gmail.MailBox[i].title << " "
            << bm.gmail.MailBox[i].article << endl;
    }

    fstream ofsUser;
    ofsUser.open("saveUser.txt",ios::out);
    for (int i = 0; i < bm.user.member_id.size(); i++)
    {
        ofsUser << bm.user.member_id[i] << " "
            << bm.user.member_password[i] << endl;
    }

    return 0;
}

