#include "Viewer.h"
#include"Mail.h"


void Viewer::viewSelectBoard(vector<Board> boards)
{
    std::system("CLS");
    std::wcout << R"(
                             .                                   
                          ,''`.         _                        
                     ,.,'''  '`--- ._,,'|                        
                   ,'                   /                        
              __.-'                    |                         
           ''                ___   ___ |                         
         ,'                  \(|\ /|)/ |                         
        ,'                 _     _     `._                       
       /     ,.......-\    `.      __     `-.                    
      /     ,' :  .:''`|    `:`.../:.`` ._   `._                 
  ,..,'  _/' .: :'     |     |      '.    \.    \                
 /      ,'  :'.:  / \  |     | / \   ':.  . \    \               
|      /  .: :' ,'  _)  ".._,;'  _)    :. :. \    |              
 |     | :'.:  /   |   .,   /   |       :  :  |   |              
 |     |:' :  /____|  /  \ /____|       :  :  |  ,'              
  |   /    '         /    \            :'   : |,/                
   \ |  '_          /______\              , : |                  
  _/ |  \'`--`.    _            ,_   ,-'''  :.|         __       
 /   |   \..   ` ./ `.   _,_  ,'  ``'  /'   :'|      _,''/       
/   /'. :   \.   _    [_]   `[_]  .__,,|   _....,--=/'  /:       
|   \_| :    `.-' `.    _.._     /     . ,'  :. ':/'  /'  `.     
`.   '`'`.         `. ,.'   ` .,'     :'/ ':..':.    |  .:' `.   
  \.      \          '               :' |    ''''      ''     `. 
    `''.   `|        ':     .      .:' ,|         .  ..':.      |
      /'   / '"-..._  :   .:'    _;:.,'  \.     .:'   :. ''.    |
     (._,.'        '`''''''''''''          \.._.:      ':  ':   /
________                                      '`- ._    ,:__,,-' 
                                                    ``''
)";
    char choose;
    std::cout << "選擇你要前往的地方: " << endl;
    std::cout << "(A)ddBoard     【　新 增 看板　】" << std::endl;
    std::cout << "(F)avorite     【　我 的 最愛　】" << std::endl;
    std::cout << "(C)lass        【　分組討論區　】" << std::endl;
    std::cout << "(M)ail         【　私人信件區　】" << std::endl;
    std::cout << "(T)alk         【　休閒聊天區　】" << std::endl;
    std::cout << "(U)ser         【　個人設定區　】" << std::endl;
    std::cout << "(X)yz          【　系統資訊區　】" << std::endl;
    std::cout << "(P)lay         【　娛樂休閒區　】" << std::endl;
    std::cout << "(N)amelist     【　編特別名單　】" << std::endl;
    std::cout << "(G)oodbye          離開，再見    " << std::endl;
    std::cin >> choose;

    selectBoard(choose, boards);
}

void Viewer::viewBoard(vector<Board> boards)
{
    std::system("CLS");
    std::wcout << R"(
 _._     _,-'""`-._
(,-.`._,'(       |\`-/|
    `-.-' \ )-`( , o o)
          `-    \`_`"'-
)";

    
    std::cout << "選擇你要前往的看板: " << endl;
    for (int i = 0; i < boards.size(); i++)
    {
        std::cout << "(" << i << ")" << " " << boards[i].boardTitle << endl;
    }
    std::cin >> Boardplace;
    
}





void Viewer::viewPost(vector<Board> boards)
{
    std::system("CLS");
    std::wcout << R"(
      /";;:;;"\
    (:;/\,-,/\;;)
   (:;{  d b  }:;)
    (:;\__Y__/;;)-----------,,_
     ,..\  ,..\      ___/___)__`\
    (,,,)~(,,,)`-._##____________)
)";


    std::cout << "選擇你要看的貼文: " << endl;
    for (int i = 0; i < boards[Boardplace].posts.size(); i++)
    {
        if (boards[Boardplace].posts[i].postStatus == "爆")
        {
            std::cout << "爆　";
        }
        std::cout << "(" << i << ")" << " " << boards[Boardplace].posts[i].title << endl;
    }
    cin >> PostPalce;
}

void Viewer::printPost(vector<Board> boards)
{
    std::system("CLS");
    std::cout << "標題: " << boards[Boardplace].posts[PostPalce].title << endl;
    std::cout << "作者: " << boards[Boardplace].posts[PostPalce].author << endl;
    std::cout << "時間: " << boards[Boardplace].posts[PostPalce].time << endl;
    std::cout << "內容: " << boards[Boardplace].posts[PostPalce].content << endl;

    vector<string>userlist;
    for (int i = 0; i < boards[Boardplace].posts[PostPalce].messages.size(); i++)
    {
        string status;
        
        bool yes = false;
        for (int j = 0; j < userlist.size(); j++)
        {
            if (boards[Boardplace].posts[PostPalce].messages[i].username == userlist[j])
            {
                yes = true;
            }
        }
        if (yes == false)
        {
            userlist.push_back(boards[Boardplace].posts[PostPalce].messages[i].username);
            if (boards[Boardplace].posts[PostPalce].messages[i].good == true)
            {
                status = "推";
            }
            else
            {
                status = "噓";
            }
        }
        else
        {
            status = "->";
        }
        
        std::cout << status << "\t"
            << boards[Boardplace].posts[PostPalce].messages[i].username << "\t"
            << boards[Boardplace].posts[PostPalce].messages[i].leaveMessage << "\t"
            << boards[Boardplace].posts[PostPalce].messages[i].time
            << endl;
    }
    
}

void Viewer::selectBoard(char choose, vector<Board> boards)
{
    play p;
    string name;
    askaddmessage = false;
    asksendmail = false; 
    changePostorMessage = false;
    switch (choose)
    {
    case 'a':
        addBoard = true;
        break;
    case 'f':
        break;
    case 'c':
        viewBoard(boards);
        if (Boardplace < boards.size())
        {
            viewPost(boards);
            if (PostPalce < boards[Boardplace].posts.size())
            {
                printPost(boards);
                askaddmessage = true;
            }
            else
            {
                std::cout << "請問要新增貼文嗎?" << endl;
            }
        }
        else
        {
            
        }
        
        break;
    case 'm':
        asksendmail = true;
        std::cout << "即將前往私人信件區...\n";
        std::system("pause");
        break;
    case 't':
        break;
    case 'u':
        std::cout << "即將前往個人設定區...\n";
        changePostorMessage = true;
        break;
    case 'x':
        break;
    case 'p':
        
        p.choose();
        break;
    case 'n':
        std::cout << "感謝B10801019黃湘宜\n";
        std::cout << "感謝B10801032黃詠筑\n";
        break;
    case 'g':
        break;
    }
}