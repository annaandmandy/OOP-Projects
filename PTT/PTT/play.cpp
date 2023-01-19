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
    cout << "\n1 - �׷��K�X\n2 - �g���D\n3 - �ŤM���Y��\n";
    cout << "�п�ܹC��: ";
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
    cout << "�п�J����0~10���Ʀr: ";
    int code = 0;
    int count = 0;
    while (cin >> code) {
        count += 1;
        if (code == x) {
            cout << "Bingo!!!";
            cout << "�A�`�@�ϥ�" << count << "������";
            break;
        }
        else if (code > x) {
            cout << "�Ӥj�F!�A��J�@��: ";
        }
        else if (code < x) {
            cout << "�Ӥp�F!�A��J�@��: ";
        }

    }
    return;
}

void play::snake()
{
    system("cls");
    //system("mode con cols=100 lines=40"); //�]�w�}�ҵ����j�p
    //ystem("color 7C"); //�]�w�I����M�e����
    //system("title �g�Y�D v1.0"); //�]�w�������D
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
        cout << "�п�J(R - Rock / P - Paper / S - Scissors)�ο�Jq�h�X�C��: ";
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
                cout << "����!";
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
                cout << "����!";
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
                cout << "����!";
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

