

#include "Board.h"

Board::Board(string title)
{
    boardTitle = title;

    vector<post> posts;

}

void Board::addPost(string author)
{
    post p;
    p.postStatus = "�@";
    cout << "��J���D: " << endl;
    cin >> p.title;
    cout << "��J���e: " << endl;
    cin >> p.content;
    p.author = author;
    //time_t now; // �ܼƫŧi
    //time(&now); // ���o�{�b������ɶ�
    //p.time = ctime(&now);
    time_t now = time(0);
    tm* ltm = localtime(&now);
    p.time = to_string(1 + ltm->tm_mon) + "/";
    p.time += to_string(ltm->tm_mday) + "_";
    p.time += to_string(ltm->tm_hour) + ":";
    p.time += to_string(ltm->tm_min);
    posts.push_back(p);
}

// Intent: �s�W�d��
// Pre: 
// Post: �z
void Board::addmessage(int postNum, string username)
{
    message m;
    m.username = username;
    int chooseGood;
    cout << "(1) �� (2) �N" << endl;
    cin >> chooseGood;
    
    if(chooseGood == 1)
    {
        m.good = true;
    }
    else
    {
        m.good = false;
    }
    cout << "��J���e: " << endl;
    cin >> m.leaveMessage;
    
    //time_t now; // �ܼƫŧi
    //time(&now); // ���o�{�b������ɶ�
    //m.time = ctime(&now);

    time_t now = time(0);
    tm* ltm = localtime(&now);
    m.time = to_string(1 + ltm->tm_mon) + "/";
    m.time += to_string(ltm->tm_mday) + "_";
    m.time += to_string(ltm->tm_hour) + ":";
    m.time += to_string(ltm->tm_min);
    posts[postNum].messages.push_back(m);
}

// Intent: �p�G�d���h�L10�h�A�N���A�אּ�z
// Pre: 
// Post: �z
void Board::changePostStatus()
{
    for(int i = 0; i < posts.size(); i++)
    {
        if(posts[i].messages.size() >= 5)
        {
            posts[i].postStatus = "�z";
        }
    }
}

