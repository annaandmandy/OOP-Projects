#include"BoardManager.h"

struct numberPlace
{
    int boardNum;
    int postNum;
    int commentNum;
};

struct postpost
{
    int boardNum;
    int postNum;
};

void BoardManager::update(bool key[])
{
    for (int i = 0; i < boards.size(); i++)
    {
        boards[i].changePostStatus();
    }


    system("CLS");
    bool hasInput = false;
    if (key[BoardState::MENU])
    {
        std::cout << "即將前往MENU" << std::endl;
        system("pause");
        hasInput = true;
    }
    else if (key[BoardState::SELECT_BOARD])
    {
        std::cout << "即將前往看板選單" << std::endl;
        system("pause");
        viewer.viewSelectBoard(boards);
        if (viewer.askaddmessage == true)
        {
            string commend;
            cout << "是否要留言?" << endl;
            cin >> commend;
            if (commend == "yes")
            {
                string message;
                cout << "輸入留言: " << endl;
                boards[viewer.Boardplace].addmessage(viewer.PostPalce, viewer.userName);
                viewer.printPost(boards);
            }
        }

        if (viewer.asksendmail == true)
        {
            system("cls");
            cout << "1-寄信, 2-收信, 3-返回";
            int option;
            cin >> option;
            if (option == 1) {
                gmail.sendMail(viewer.userName);
            }
            else if (option == 2) {
                gmail.inBox(viewer.userName);
            }
        }

        if (viewer.changePostorMessage == true)
        {

            int choose;
            std::cout << "(1) 檢視貼文 (2) 檢視留言" << std::endl;
            cin >> choose;
            if (choose == 1)
            {
                vector<postpost> post;
                for (int i = 0; i < boards.size(); i++)
                {
                    for (int j = 0; j < boards[i].posts.size(); j++)
                    {
                        if (boards[i].posts[j].author == viewer.userName)
                        {
                            postpost p;
                            p.boardNum = i;
                            p.postNum = j;
                            post.push_back(p);
                            std::cout << post.size() - 1 << boards[i].posts[j].title << endl;
                        }
                    }
                }
                std::cout << "選擇要編輯的貼文" << std::endl;
                std::cin >> choose;
                if (choose < post.size())
                {
                    int dowhat;
                    std::cout << "(1) 編輯內容 (2)刪除" << std::endl;
                    std::cin >> dowhat;
                    if (dowhat == 1)
                    {
                        std::cout << "新標題: " << endl;
                        std::cin >> boards[post[choose].boardNum].posts[post[choose].postNum].title;
                        std::cout << "新內容: " << endl;
                        std:: cin >> boards[post[choose].boardNum].posts[post[choose].postNum].content;
                    }
                    else if (dowhat == 2)
                    {
                        boards[post[choose].boardNum].posts.erase(boards[post[choose].boardNum].posts.begin() + post[choose].postNum);
                    }
                    
                }
            }
            else if (choose == 2)
            {
                vector<numberPlace> comment;
                for (int i = 0; i < boards.size(); i++)
                {
                    for (int j = 0; j < boards[i].posts.size(); j++)
                    {
                        for (int m = 0; m < boards[i].posts[j].messages.size(); m++)
                        {
                            if (boards[i].posts[j].messages[m].username == viewer.userName)
                            {
                                numberPlace numP;
                                numP.boardNum = i;
                                numP.postNum = j;
                                numP.commentNum = m;
                                comment.push_back(numP);
                                std::cout << comment.size() - 1 << boards[i].posts[j].messages[m].leaveMessage << endl;
                            }
                        }
                    }
                }
                std::cout << "選擇要編輯的留言" << std::endl;
                std::cin >> choose;
                if (choose < comment.size())
                {
                    int dowhat;
                    std::cout << "(1) 編輯內容 (2)刪除" << std::endl;
                    std::cin >> dowhat;
                    if (dowhat == 1)
                    {
                        std::cout << "新內容: " << endl;
                        std::cin >> boards[comment[choose].boardNum].posts[comment[choose].postNum].messages[comment[choose].commentNum].leaveMessage;
                    }
                    else if (dowhat == 2)
                    {
                        boards[comment[choose].boardNum].posts[comment[choose].postNum].messages.erase(boards[comment[choose].boardNum].posts[comment[choose].postNum].messages.begin() + comment[choose].commentNum);
                    }
                }
            }

        }

        if (viewer.addBoard == true)
        {
            if (user.logLevel() == 0)
            {
                std::cout << "要新增看板嗎? (1) 新增 (2) 刪除 (3) 不做" << std::endl;
                int dowhat;
                std::cin >> dowhat;
                if (dowhat == 1)
                {
                    string boardtitle;
                    std::cout << "看板名稱: " << std::endl;
                    std::cin >> boardtitle;
                    boards.push_back(boardtitle);
                }
                else if (dowhat == 2)
                {
                    string boardtitle;
                    std::cout << "看板名稱: " << std::endl;
                    std::cin >> boardtitle;
                    int boardnum;
                    for (int b = 0; b < boards.size(); b++)
                    {
                        if (boards[b].boardTitle == boardtitle)
                        {
                            boards.erase(boards.begin() + b);
                            break;
                        }
                    }
                }
            }
            else
            {
                std::cout << "你沒有權限" << std::endl;
                system("pause");
            }
        }

        hasInput = true;
    }
    else if (key[BoardState::POST])
    {
        std::cout << "新增貼文" << std::endl;
        system("pause");
        viewer.viewBoard(boards);
        boards[viewer.Boardplace].addPost(viewer.userName);
        viewer.PostPalce = boards[viewer.Boardplace].posts.size() - 1;
        viewer.printPost(boards);
        hasInput = true;
    }
    else if (key[BoardState::BOARD])
    {
        std::cout << "即將前往看板" << std::endl;
        system("pause");
        viewer.viewBoard(boards);
        if (viewer.Boardplace < boards.size())
        {
            viewer.viewPost(boards);
            if (PostPalce < boards[viewer.Boardplace].posts.size())
            {
                viewer.printPost(boards);
                viewer.askaddmessage = true;
            }
            else
            {
                cout << "請問要新增貼文嗎?" << endl;
            }
        }
        else
        {

        }
        if (viewer.askaddmessage == true)
        {
            string commend;
            cout << "是否要留言?" << endl;
            cin >> commend;
            if (commend == "yes")
            {
                string message;
                cout << "輸入留言: " << endl;
                boards[viewer.Boardplace].addmessage(viewer.PostPalce, viewer.userName);
                viewer.printPost(boards);
            }
        }

        
    }
    else
    {
        
    }

}

void BoardManager::keyUpdate(bool key[])
{
    
    for (int i = 0; i < BoardState::INVALID; i++) {
        key[i] = false;
    }

    char input = _getch();
    string commend;

    switch (input)
    {
    case 'm':
        key[BoardState::MENU] = true;
        break;
    case 's':
        key[BoardState::SELECT_BOARD] = true;
        break;
    case 'b':
        key[BoardState::BOARD] = true;
        break;
    case 'p':
        key[BoardState::POST] = true;
        break;
    case 27:
        key[BoardState::EESC] = true;
        break;
    default:
        break;
    }
}



