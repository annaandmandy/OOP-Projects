#include "User.h"
User::User() {

}

User::~User() {

}

bool User::identity(string s) {
    //�w�]2��member�b��
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
        cout << "��J�޲z�̱b���G";
        if (Check_Adimin_id(Adimin_id) == true) {
            string password = "54088"; //Adimin' s�K�X
            cout << "��J�K�X�G";
            if (Check_Adimin_password(password) != true) {
                cout << "�n�J����!";
                system("pause");
            }
            else {
                cout << "�n�J���\!";
                Permission_level = 0;//Adimin = 0
                system("pause");
            }
        }
    }
    else if (id == "Member") {
        string Member_id;
        cout << "��J�ϥΪ̱b���G";

        while (cin >> Member_id) {
            for (int i = 0; i < member_id.size(); i++) {
                if (Check_Member_id(Member_id) == true) {
                    int j = p_pos;
                    string Member_password;
                    cout << "��J�K�X�G";
                    if (Check_Member_password(member_password[j]) != true) {
                        cout << "�n�J����!";
                        system("pause");
                        return 0;
                        break;
                    }
                    else {
                        Personal_name = Member_id;
                        Permission_level = 1;//member=1
                        cout << "�n�J���\!";
                        system("pause");
                        return 1;
                        break;
                    }
                }
                else {
                    if (i == member_id.size() - 1) {
                        cout << "�d�L���b��, �Э��s��J: ";
                    }
                }
            }
        }
    }
    else if (id == "Guest") {
        Personal_name = "Guest123";
        Permission_level = 2;
        cout << "�A�w�ϥ�" << Personal_name << "�n�J";
        return 1;
    }
    else if (id == "new") {
        string new_id;
        string new_pw;
        cout << "�п�J�����U���b��: ";
        while (cin >> new_id) {
            for (int i = 0; i < member_id.size(); i++) {
                if (new_id == member_id[i]) {
                    cout << "�w�����Ʊb��!�Э��s��J: ";
                    break;
                }
                else {
                    if (i == member_id.size() - 1) {
                        member_id.push_back(new_id);
                        cout << "�п�J�K�X: ";
                        cin >> new_pw;
                        member_password.push_back(new_pw);
                        Personal_name = new_pw;
                        Permission_level = 1;//member=1
                        cout << "���U���\!�w�۰ʵn�J!";
                        system("pause");
                        return 1;


                    }
                }
            }

        }

    }
    else {
        cout << "�A��?";
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
            if (ch == '\b' && i > 0)//�h��
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
            cout << "��J���~!�ЦA��J�@���G";
            times++;
        }
        else
        {
            //cout << "��J���T!" << endl << endl;
            judge = true;
            return judge;
        }
    }
    //�b���O�_�n�]�m��J����?
    /*if (times == 4) {
        return judge;
    }
    return judge;*/
}

bool User::Check_Adimin_password(string a)/*��J�K�X,���T�����|*/
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
            if (ch == '\b' && i > 0)//�h��
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
                cout << "��J���~!�Ѿl" << (3 - times) << "�����|�G";
            times++;
        }
        else
        {
            //cout << "��J���T!" << endl << endl;
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

bool User::Check_Member_password(string b)/*��J�K�X,���T�����|*/
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
            if (ch == '\b' && i > 0)//�h��
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
                cout << "��J���~!�Ѿl" << (3 - times) << "�����|�G";
            times++;
        }
        else
        {
            //cout << "��J���T!" << endl << endl;
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

