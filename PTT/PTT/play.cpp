#include "play.h"
#include"snake.h"
play::play()
{
}

play::~play()
{
}

void play::choose()
{
    system("cls");
    wcout << R"(
           .'\   /`.
         .'.-.`-'.-.`.
    ..._:   .-. .-.   :_...
  .'    '-.(o ) (o ).-'    `.
 :  _    _ _`~(_)~`_ _    _  :
:  /:   ' .-=_   _=-. `   ;\  :
:   :|-.._  '     `  _..-|:   :
 :   `:| |`:-:-.-:-:'| |:'   :
  `.   `.| | | | | | |.'   .'
    `.   `-:_| | |_:-'   .'
      `-._   ````    _.-'
          ``-------''
)";
    cout << "\n1 - 終極密碼\n2 - 貪食蛇\n3 - 剪刀石頭布\n";
    cout << "請選擇遊戲: ";
    int choose = 0;
    cin >> choose;
    if (choose == 1) {
        number();
        return;
    }
    else if (choose == 2) {
        snake();
        return;

    }
    else if (choose == 3) {
        rock();
        return;

    }
}

void play::number()
{
    system("cls");
    srand(time(NULL));
    int min = 0;
    int max = 10;
    int x = rand() % (max - min + 1) + min;
    cout << "請輸入介於0~10的數字: ";
    int code = 0;
    int count = 0;
    while (cin >> code) {
        count += 1;
        if (code == x) {
            cout << "Bingo!!!";
            cout << "你總共使用" << count << "次答對";
            break;
        }
        else if (code > x) {
            cout << "太大了!再輸入一次: ";
        }
        else if (code < x) {
            cout << "太小了!再輸入一次: ";
        }

    }
    return;
}

void play::snake()
{
    system("cls");
    //system("mode con cols=100 lines=40"); //設定開啟視窗大小
    //ystem("color 7C"); //設定背景色和前景色
    //system("title 貪吃蛇 v1.0"); //設定視窗標題
    Game game;
    gotoxy(0, 17);
    cout << "Game over!" << endl;
    return;
}

void play::rock()
{
    system("cls");
    srand(time(NULL));
    int min = 1;
    int max = 3;
    //R=1,P=2,S=3
    int x = rand() % (max - min + 1) + min;
    char code = 0;
    int count = 0;
    while (1) {
        x = rand() % (max - min + 1) + min;
        cout << "請輸入(R - Rock / P - Paper / S - Scissors)或輸入q退出遊戲: ";
        cin >> code;
        if (code == 'R') {
            system("cls");
            wcout << R"(
    _______
---'   ____)
      (_____)
      (_____)
      (____)
---.__(___)
'''
)";
            if (x == 1) {
                cout << "平手!";
            }
            else if (x == 2) {
                cout << "loser!!";
            }
            else if (x == 3) {
                cout << "win!!";
            }
        }
        else if (code == 'P') {
            system("cls");

            wcout << R"(
    _______
---'   ____)____
          ______)
          _______)
         _______)
---.__________)
'''
)";
            if (x == 1) {
                cout << "win!!";
            }
            else if (x == 2) {
                cout << "平手!";
            }
            else if (x == 3) {
                cout << "loser!!";
            }

        }
        else if (code == 'S') {
            system("cls");

            wcout << R"(
    _______
---'   ____)____
          ______)
       __________)
      (____)
---.__(___)
'''
)";
            if (x == 1) {
                cout << "平手!";
            }
            else if (x == 2) {
                cout << "loser!!";
            }
            else if (x == 3) {
                cout << "win!!";
            }

        }
        else if (code == 'q') {
            return;
        }
        else {
            system("cls");
            cout << "input invaild!";
        }
    }

}

