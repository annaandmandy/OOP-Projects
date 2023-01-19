#include "User.h"
User::User() {

}

User::~User() {

}

bool User::identity(string s) {
    //預設2個member帳號
    /*
    member_id.push_back("B10801019");
    member_id.push_back("B10801032");
    member_password.push_back("coco");
    member_password.push_back("tommy");
*/

    string id = s;
    //Adimin
    //id = anna
    //pw = 54088
    if (id == "Adimin") {
        string Adimin_id = "anna";
        cout << "輸入管理者帳號：";
        if (Check_Adimin_id(Adimin_id) == true) {
            string password = "54088"; //Adimin' s密碼
            cout << "輸入密碼：";
            if (Check_Adimin_password(password) != true) {
                cout << "登入失敗!";
                system("pause");
            }
            else {
                cout << "登入成功!";
                Permission_level = 0;//Adimin = 0
                system("pause");
            }
        }
    }
    else if (id == "Member") {
        string Member_id;
        cout << "輸入使用者帳號：";

        while (cin >> Member_id) {
            for (int i = 0; i < member_id.size(); i++) {
                if (Check_Member_id(Member_id) == true) {
                    int j = p_pos;
                    string Member_password;
                    cout << "輸入密碼：";
                    if (Check_Member_password(member_password[j]) != true) {
                        cout << "登入失敗!";
                        system("pause");
                        return 0;
                        break;
                    }
                    else {
                        Personal_name = Member_id;
                        Permission_level = 1;//member=1
                        cout << "登入成功!";
                        system("pause");
                        return 1;
                        break;
                    }
                }
                else {
                    if (i == member_id.size() - 1) {
                        cout << "查無此帳號, 請重新輸入: ";
                    }
                }
            }
        }
    }
    else if (id == "Guest") {
        Personal_name = "Guest123";
        Permission_level = 2;
        cout << "你已使用" << Personal_name << "登入";
        return 1;
    }
    else if (id == "new") {
        string new_id;
        string new_pw;
        cout << "請輸入欲註冊的帳號: ";
        while (cin >> new_id) {
            for (int i = 0; i < member_id.size(); i++) {
                if (new_id == member_id[i]) {
                    cout << "已有重複帳戶!請重新輸入: ";
                    break;
                }
                else {
                    if (i == member_id.size() - 1) {
                        member_id.push_back(new_id);
                        cout << "請輸入密碼: ";
                        cin >> new_pw;
                        member_password.push_back(new_pw);
                        Personal_name = new_pw;
                        Permission_level = 1;//member=1
                        cout << "註冊成功!已自動登入!";
                        system("pause");
                        return 1;


                    }
                }
            }

        }

    }
    else {
        cout << "你誰?";
        return 0;
    }

}

bool User::Check_Adimin_id(string a) {
    bool judge = false;
    int i = 0;
    int times = 1;
    string s;
    char ch;
    char pw[50];
    while (1)
    {
        i = 0;
        while ((ch = _getch()) != '\r')
        {
            if (ch == '\b' && i > 0)//退格
            {
                printf("\b \b");
                i--;
            }
            else
            {
                pw[i++] = ch;
                cout << ch;
            }
        }
        pw[i] = '\0';
        cout << endl;
        if (a.compare(pw) != 0)
        {
            cout << "輸入錯誤!請再輸入一次：";
            times++;
        }
        else
        {
            //cout << "輸入正確!" << endl << endl;
            judge = true;
            return judge;
        }
    }
    //帳號是否要設置輸入次數?
    /*if (times == 4) {
        return judge;
    }
    return judge;*/
}

bool User::Check_Adimin_password(string a)/*輸入密碼,有三次機會*/
{
    bool judge = false;
    int i = 0;
    int times = 1;
    string s;
    char ch;
    char pw[50];
    while (times <= 3)
    {
        i = 0;
        while ((ch = _getch()) != '\r')
        {
            if (ch == '\b' && i > 0)//退格
            {
                printf("\b \b");
                i--;
            }
            else
            {
                pw[i++] = ch;
                cout << '*';
            }
        }
        pw[i] = '\0';
        cout << endl;
        if (a.compare(pw) != 0)
        {
            if (times == 3)
                cout << endl;
            else
                cout << "輸入錯誤!剩餘" << (3 - times) << "次機會：";
            times++;
        }
        else
        {
            //cout << "輸入正確!" << endl << endl;
            judge = true;
            return judge;
        }
    }
    if (times == 4)
        return judge;
    return judge;
}


bool User::Check_Member_id(string a) {

    bool judge = false;
    int t = 0;
    while (1) {
        for (int i = 0; i < member_id.size(); i++) {
            if (a != member_id[i]) {
                t += 1;
                if (t == member_id.size()) {
                    return false;
                }
            }
            else {
                judge = true;
                p_pos = i;
                return judge;
            }
        }
        break;
    }

}

bool User::Check_Member_password(string b)/*輸入密碼,有三次機會*/
{
    bool judge = false;
    int i = 0;
    int times = 1;
    string s;
    char ch;
    char pw[50];
    while (times <= 3)
    {
        i = 0;
        while ((ch = _getch()) != '\r')
        {
            if (ch == '\b' && i > 0)//退格
            {
                printf("\b \b");
                i--;
            }
            else
            {
                pw[i++] = ch;
                cout << '*';
            }
        }
        pw[i] = '\0';
        cout << endl;
        if (b.compare(pw) != 0)
        {
            if (times == 3)
                cout << endl;
            else
                cout << "輸入錯誤!剩餘" << (3 - times) << "次機會：";
            times++;
        }
        else
        {
            //cout << "輸入正確!" << endl << endl;
            judge = true;
            return judge;
        }
    }
    if (times == 4)
        return judge;
    return judge;
}

string User::logName()
{
    return this->Personal_name;
}

int User::logLevel()
{
    return this->Permission_level;
}

