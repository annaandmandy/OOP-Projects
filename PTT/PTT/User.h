#include<string>
#include<vector>
#include<iostream>
#include<cstring>
#include<stdio.h>
#include<conio.h>
using namespace std;
#pragma once
class User
{
private:
    vector<int>postID;
    //string account;
    //string password;
    //string user;
public:
    int Permission_level;//Admin=0,member=1,guest=2
    string Personal_name;
    vector<string>member_id;
    vector<string>member_password;
    int p_pos = 0;//member_pw_pos

    User();
    ~User();

    bool identity(string s);
    bool Check_Adimin_id(string a);
    bool Check_Adimin_password(string a);
    bool Check_Member_id(string a);
    bool Check_Member_password(string a);
    string logName();
    int logLevel();
    

};

