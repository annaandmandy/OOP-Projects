#pragma once

#include "calculation.h"
#include"Integer.h"
#include <cstdlib>
#include<windows.h>
#include <vector>
#include <iostream>
using namespace std;

bool compare(vector<int> a, vector<int> b)
{
    if (a.size() > b.size())
    {
        return 1;
    }
    else if (a.size() < b.size())
    {
        return 0;
    }
    else
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] > b[i])
            {
                return 1;
            }
            else if (a[i] < b[i])
            {
                return 0;
            }
        }
    }
    return 1;
}

bool comparestring(nextNum a, nextNum b)
{
    if (a.number.size() > b.number.size())
    {
        return 1;
    }
    else if (a.number.size() < b.number.size())
    {
        return 0;
    }
    else
    {
        for (int i = 0; i < a.number.size(); i++)
        {
            if (a.number[i] > b.number[i])
            {
                return 1;
            }
            else if (a.number[i] < b.number[i])
            {
                return 0;
            }
        }
    }
    return 1;
}

bool isnumber(vector<string> vecs)
{
    bool isinteger = false;
    if (vecs.size() == 1)
    {
        int sizeE = vecs[0].size();
        for (int i = 0; i < sizeE; i++)
        {
            if (vecs[0][i] >= '0' && vecs[0][i] <= '9' || vecs[0][i] == '.' || vecs[0][i] == '-')
            {
                isinteger = true;
            }
            else
            {
                isinteger = false;
                break;
            }
        }
    }
    return isinteger;
}

bool stringIsNum(string s)
{
    bool isinteger = false;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9' || s[i] == '.' || s[i] == '-')
        {
            isinteger = true;
        }
        else
        {
            isinteger = false;
            break;
        }
    }
    if (s.size() == 1 && s[0] == '-')
    {
        isinteger = false;
    }
    return isinteger;
}


void formula::setEquation(string s)
{
    this->equ = s;
    string save = "";
    bool count = 0;
    bool countnum = 0;
    /*****************************************************************************************************************/
    for (int i = 0;i < this->equ.size();i++) {
        this->set.push_back(this->equ[i]);
    }

    //為Decimal、Integer重載
    if (this->set[0] = 'S' && this->set[1] == 'e' && this->set[2] == 't') {
        if (this->set[4] == 'I') {
            this->type = "Integer";
        }
        else if (this->set[4] == 'D') {
            this->type = "Decimal";
        }
        
        int pos = 0;
        for (int i = 12;i < this->set.size();i++) {
            if (this->set[i] != ' ') {
                this->name += this->set[i];
            }
            else {
                pos = i;
                break;
            }
        }

        //存數據
        for (int i = pos + 3;i < this->set.size();i++) {
            this->value += this->set[i];
        }
        SetI s;
        //SetI setre;
        s.Setto(this->type,this->name,this->value);
    }
    else {  //純值


        for (int i = 0; i < equ.size(); i++)
        {
            if (equ[i] == '.') {
                include_p = true;
            }

            if (equ[i] >= '0' && equ[i] <= '9' || equ[i] == '.')
            {
                count = 1;
            }
            else
            {
                count = 0;
            }

            if (count == 1)
            {
                save += equ[i];
            }
            else if (count == 0)
            {
                if (save != "")
                {
                    equation.push_back(save);
                }
                save = equ[i];
                equation.push_back(save);
                save = "";
            }
        }
        if (save != "")
        {
            equation.push_back(save);
        }

        for (int i = 0; i < equation.size(); i++)
        {
            if (equation[i] == " ")
            {
                equation.erase(equation.begin() + i);
            }
        }
    }

}

string formula::operator=(nextNum a)
{
    this->ans = a.number;
    return ans;
}

string operator-(nextNum anext, nextNum bnext)
{
    formula f;
    string a = anext.number;
    string b = bnext.number;
    vector<int> numA, numB;
    string c = "";
    bool normal = 1;
    bool minus = 0;
    bool decimalA = 0;
    bool decimalB = 0;
    int decimalPlaceA = 0;
    int decimalPlaceB = 0;
    int decimalPlace = 0;

    // 大數減小數

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '.')
        {
            decimalA = 1;
            decimalPlaceA = i;
        }
        else
        {
            numA.push_back((int)a[i] - 48);
        }
    }

    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] == '.')
        {
            decimalB = 1;
            decimalPlaceB = i;
        }
        else
        {
            numB.push_back((int)b[i] - 48);
        }
    }

    if (decimalA == 1 && decimalB == 0)
    {
        decimalB = 1;
        decimalPlaceB = numB.size();
    }

    if (decimalA == 0 && decimalB == 1)
    {
        decimalA = 1;
        decimalPlaceA = numA.size();
    }

    if (decimalA == 0 && decimalB == 0)
    {
        decimalA = 1;
        decimalPlaceA = numA.size();
        decimalB = 1;
        decimalPlaceB = numB.size();
    }


    if (decimalA == 1 && decimalB == 1)
    {
        if (numA.size() - decimalPlaceA > numB.size() - decimalPlaceB)
        {
            int time1 = numA.size() - decimalPlaceA - numB.size() + decimalPlaceB;
            for (int i = 0; i <time1 ; i++)
            {
                numB.push_back(0);
            }
        }
        else if (numA.size() - decimalPlaceA < numB.size() - decimalPlaceB)
        {
            int time2 = numB.size() - decimalPlaceB - numA.size() + decimalPlaceA;
            for (int i = 0; i < time2; i++)
            {
                numA.push_back(0);
            }
        }
    }

    if (decimalPlaceB > decimalPlaceA || decimalPlaceB == decimalPlaceA && !compare(numA, numB))
    {
        normal = 0;
    }

    // 從後面開始做
    reverse(numA.begin(), numA.end());
    reverse(numB.begin(), numB.end());

    // 用0填滿
    if (numA.size() < numB.size())
    {
        for (int i = 0; i < numB.size() - numA.size(); i++)
        {
            numA.push_back(0);
        }
    }
    else if (numB.size() < numA.size())
    {
        for (int i = 0; i < numA.size() - numB.size(); i++)
        {
            numB.push_back(0);
        }
    }


    if (normal == 1)
    {
        for (int i = 0; i < numA.size(); i++)
        {
            if (numA[i] >= numB[i])
            {
                int num = numA[i] - numB[i];
                c += to_string(num);
            }

            else
            {
                if (numA[i + 1] > 0)
                {
                    numA[i + 1] -= 1;
                    int num = 10 + (int)numA[i] - (int)numB[i];
                    c += to_string(num);
                }
                else if ((int)numA[i + 1] == 0)
                {
                    int notzero = 1;
                    while (numA[i + notzero] != 0)
                    {
                        notzero += 1;
                    }
                    for (int j = i + 1; j < i + notzero; j++)
                    {
                        numA[j] = 9;
                    }
                    numA[i + notzero] -= 1;
                    int num = 10 + (int)numA[i] - (int)numB[i];

                    c += to_string(num);
                }
            }
        }
    }

    else
    {
        for (int i = 0; i < numB.size(); i++)
        {
            if (numB[i] >= numA[i])
            {
                int num = numB[i] - numA[i];
                c += to_string(num);
            }

            else
            {
                if (numB[i + 1] > 0)
                {
                    numB[i + 1] -= 1;
                    int num = 10 + (int)numB[i] - (int)numA[i];
                    c += to_string(num);
                }
                else if ((int)numB[i + 1] == 0)
                {
                    int notzero = 1;
                    while (numB[i + notzero] != 0)
                    {
                        notzero += 1;
                    }
                    for (int j = i + 1; j < i + notzero; j++)
                    {
                        numB[j] = 9;
                    }
                    numB[i + notzero] -= 1;
                    int num = 10 + (int)numB[i] - (int)numA[i];
                    c += to_string(num);
                }
            }
        }
    }

    reverse(c.begin(), c.end());
    if (decimalPlaceA != c.size() && decimalPlaceB != c.size())
    {
        if (decimalPlaceA >= decimalPlaceB)
        {
            c.insert(decimalPlaceA, ".");
            
        }
        else
        {
            c.insert(decimalPlaceB, ".");
            
        }
    }

    while (c[0] == '0' && c[1] != '.')
    {
        c.erase(c.begin());
    }

    bool allzero = 1;
    for (int i = 0; i < c.size(); i++)
    {
        if (c[i] != '0')
        {
            allzero = 0;
            break;
        }
    }

    if (normal == 0)
    {
        if (c == ""  || allzero)
        {
            c = "0";
        }
        else
        {
            c.insert(c.begin(), '-');
        }
    }

    

    f.ans = c;

    return f.ans;
}

string operator+(nextNum anext, nextNum bnext)
{
    formula f;
    string a = anext.number, b = bnext.number;
    string n1 = a;
    string n2 = b;
    //string ans1;
    vector<char>add_ans;
        int point[2] = { 0 };//小數點
        //抓出兩數小數點位置
        int n1len = n1.length();
        int n2len = n2.length();
        bool n1_isInt = true;
        bool n2_isInt = true;
        for (int i = 0;i < n1len;i++) {
            if (n1[i] == '.') {
                point[0] = i;
                //n1_isInt = false;
                for (int j = i+1;j < n1len;j++) {
                    if (n1[j] != '0') {
                        n1_isInt = false;
                        break;
                    }
                }

                break;
            }
            else {
                point[0] = n1.length();
            }
        }
        for (int i = 0;i < n2len;i++) {
            if (n2[i] == '.') {
                point[1] = i;
                //n2_isInt = false;
                for (int j = i + 1;j < n2len;j++) {
                    if (n2[j] != '0') {
                        n2_isInt = false;
                        break;
                    }
                }
                break;
            }
            else {
                point[1] = n2.length();
            }
        }
        bool in = false;//小數是否進位

        //整數相加
        if (n1_isInt == true && n2_isInt == true) {
            string add1;
            string add2;
            bool flag = true;

            for (int i = 0;i < n1len;i++) {
                if (n1[i] >= '0' && n1[i] <= '9')
                {
                    add1.push_back(n1[i]);
                }
                else {
                    break;
                }
            }
            for (int i = 0;i < n2len;i++) {
                if (n2[i] >= '0' && n2[i] <= '9') {
                    add2.push_back(n2[i]);
                }
                else {
                    break;
                }
            }

            reverse(add1.begin(), add1.end());
            reverse(add2.begin(), add2.end());
            unsigned n = max(add1.length(), add2.length());
            string c(n + 1, 0);
            for (int i = 0;i < (int)n;i++) {
                int add1n = 0;
                if (i < (int)add1.length()) {
                    add1n = add1[i] - '0';
                }
                int add2n = 0;
                if (i < (int)add2.length()) {
                    add2n = add2[i] - '0';
                }
                int sum = c[i] + add1n + add2n;
                c[i] = sum % 10;
                c[i + 1] += sum / 10;

            }
            if (c[n]) {
                add_ans.push_back(char(c[n] + '0'));
            }
            for (int i = n - 1;i >= 0;i--) {
                add_ans.push_back(char(c[i] + '0'));

            }

        }

        //有小數點相加
        else {
            string n1_int;
            string n1_dec;
            string n2_int;
            string n2_dec;

            for (int i = 0;i < (int)n1.length();i++) {
                if (n1[i] >= '0' && n1[i] <= '9') {
                    n1_int += n1[i];
                }
                else if (n1[i] == '.') {
                    break;
                }
            }
            for (int j = point[0] + 1;j < (int)n1.length();j++) {
                if (n1[j] >= '0' && n1[j] <= '9') {
                    n1_dec += n1[j];
                }
            }

            for (int i = 0;i < (int)n2.length();i++) {
                if (n2[i] >= '0' && n2[i] <= '9') {
                    n2_int += n2[i];
                }
                else if (n2[i] == '.') {
                    break;
                }
            }
            for (int j = point[1] + 1;j < (int)n2.length();j++) {
                if (n2[j] >= '0' && n2[j] <= '9') {
                    n2_dec += n2[j];
                }
            }

            //n1_int 跟 n2_int相加
            reverse(n1_int.begin(), n1_int.end());
            reverse(n2_int.begin(), n2_int.end());

            unsigned n = max(n1_int.length(), n2_int.length());
            string c(n + 1, 0);
            for (int i = 0;i < (int)n;i++) {
                int n1_intN = 0;
                if (i < (int)n1_int.length()) {
                    n1_intN = n1_int[i] - '0';
                }
                int n2_intN = 0;
                if (i < n2_int.length()) {
                    n2_intN = n2_int[i] - '0';
                }
                int sum = c[i] + n1_intN + n2_intN;
                c[i] = sum % 10;
                c[i + 1] += sum / 10;
            }

            if (c[n]) {
                add_ans.push_back(char(c[n] + '0'));
            }
            for (int i = n - 1;i >= 0;i--) {
                add_ans.push_back(char(c[i] + '0'));
            }

            /***********/
            add_ans.push_back('.');
            /***********/

            //n1_dec和n2_dec相加
            /*****************************************************/
            if (n1_dec[0] + n2_dec[0] - '0' - '0' >= 10) {
                in = true;
            }
            int count = 0;//進ans次數
            unsigned n3 = max(n1_dec.length(), n2_dec.length());

            while (n1_dec.length() != n3) {
                n1_dec += '0';
            }
            while (n2_dec.length() != n3) {
                n2_dec += '0';
            }
            reverse(n1_dec.begin(), n1_dec.end());
            reverse(n2_dec.begin(), n2_dec.end());


            string c3(n3 + 1, 0);
            for (int i = 0;i < n3;i++) {
                int n1_decN = 0;
                if (i < n1_dec.length()) {
                    n1_decN = n1_dec[i] - '0';
                }
                int n2_decN = 0;
                if (i < n2_dec.length()) {
                    n2_decN = n2_dec[i] - '0';
                }
                int sum = c3[i] + n1_decN + n2_decN;
                c3[i] = sum % 10;
                c3[i + 1] += sum / 10;
            }

            if (c3[n3]) {
                add_ans.push_back(char(c3[n3] + '0'));
                count += 1;
            }
            for (int i = n3 - 1;i >= 0;i--) {
                add_ans.push_back(char(c3[i] + '0'));
                count += 1;
            }

            if (count > (n1_dec.length() + n2_dec.length())/2) {
                in = true;//進整數位
            }
            vector<char>ans2;

            //處理小數進位整數
            if (in == true) {
                int point = 0;//小數點位置
                string n_1;
                for (int i = 0;i < add_ans.size();i++) {
                    if (add_ans[i] == '.') {
                        point = i;

                        n_1 = add_ans[i + 1];
                        add_ans.erase(add_ans.begin() + i + 1);//刪掉point+1位
                        break;
                    }
                }

                string n_2;
                for (int i = 0;i < point;i++) {
                    //做整數+進位數
                    n_2 += add_ans[i];
                }
                add_ans.erase(add_ans.begin(), add_ans.begin() + point);

                reverse(add_ans.begin(), add_ans.end());//xxx.

                reverse(n_1.begin(), n_1.end());
                reverse(n_2.begin(), n_2.end());
                unsigned n = max(n_1.length(), n_2.length());
                string c(n + 1, 0);

                for (int i = 0;i < n;i++) {
                    int n_1_N = 0;
                    if (i < n_1.length()) {
                        n_1_N = n_1[i] - '0';
                    }
                    int n_2_N = 0;
                    if (i < n_2.length()) {
                        n_2_N = n_2[i] - '0';
                    }
                    int sum = c[i] + n_1_N + n_2_N;
                    c[i] = sum % 10;
                    c[i + 1] = sum / 10;

                }

                if (c[n]) {
                    ans2.push_back(char(c[n] + '0'));
                }
                for (int i = n - 1;i >= 0;i--) {
                    ans2.push_back(char(c[i] + '0'));
                }

            }
            reverse(ans2.begin(), ans2.end());

            if (ans2.size() != 0) {
                for (int i = 0;i < ans2.size();i++) {
                    add_ans.push_back(ans2[i]);
                }
            }
            vector<char>().swap(ans2);

            reverse(add_ans.begin(), add_ans.end());//turn1
            //處理整數前面是0
            for (int i = add_ans.size() - 1;i >= 0;i--) {
                if (add_ans[i] != '0') {
                    if (add_ans[i] == '.') {
                        add_ans.push_back('0');
                        break;
                    }
                    break;
                }
                else if (add_ans[i] == '0') {
                    if (add_ans[i - 1] != '.') {
                        add_ans.pop_back();
                    }
                    else if(add_ans[i - 1] == '.') {
                        break;
                    }
                }

            }

            //和<=1
            for (int i = 0;i < add_ans.size();i++) {
                if (add_ans[i] == '.') {
                    if (add_ans[i - 1] == '1') {
                        reverse(add_ans.begin(), add_ans.end());
                        break;
                    }
                    break;
                }
            }

            //處理掉小數尾巴是0

            for (int i = 0;i < add_ans.size();i++) {
                if (add_ans[i] == '.') {
                    for (int j = add_ans.size() - 1;j >= i;j--) {
                        if (add_ans[j] == '0') {
                            add_ans.pop_back();
                        }
                        else {
                            break;
                        }
                    
                    }
                    if (i == add_ans.size() - 1) {
                        add_ans.pop_back();
                    }
                    break;
                }
            
            }
            reverse(add_ans.begin(), add_ans.end());//turn3


        }

    /***************************************************************/
    /*答案*/
    for (int i = 0; i < add_ans.size(); i++) {
        f.ans += add_ans[i];
    }


    return f.ans;



}

string operator*(nextNum anext, nextNum bnext) {
    formula f;

    string a = anext.number, b = bnext.number;
    string mul1 = a;
    string mul2 = b;

    
    string mul_ans;
    vector<char>c;

    //乘數有0
    bool check = false;
    if (mul1 == "0" || mul2 == "0") {
        check = true;
    }

    //檢查正負號
    bool sign1 = true;
    bool sign2 = true;
        
    bool flag = false;
    int point[2] = { 0,0 };//小數點位置
    int mul1_pointCount = 0;
    int mul2_pointCount = 0;
    for (int i = 0;i < mul1.length();i++) {
        if (mul1[i] == '.') {
            flag = true;
            break;
        }
    }
    for (int i = 0;i < mul2.length();i++) {
        if (mul2[i] == '.') {
            flag = true;
            break;
        }
    }

        

    //整數乘法
    if (flag == false) {
        int sum[20000] = { NULL };
        string m1;
        string m2;

        for (int i = 0;i < mul1.length();i++) {
            if (mul1[i] >= '0' && mul1[i] <= '9') {
                m1 += mul1[i];
            }
        }
        for (int i = 0;i < mul2.length();i++) {
            if (mul2[i] >= '0' && mul2[i] <= '9') {
                m2 += mul2[i];
            }
        }


        for (int i = m1.length() - 1;i >= 0;i--) {
            for (int j = m2.length() - 1;j >= 0;j--) {
                sum[i + j + 1] += ((m1[i] - '0') * (m2[j] - '0'));
            }
        }
        for (int i = m1.length() + m2.length() - 1;i >= 1;i--) {
            sum[i - 1] += sum[i] / 10;
            sum[i] %= 10;
        }
        for (int i = m1.length() + m2.length() - 1;i >= 0;i--) {
            c.push_back(sum[i] + '0');
        }
        reverse(c.begin(), c.end());

        int zero = 0;//紀錄前面第幾位不是0的位數
        for (int i = 0;i < c.size();i++) {
            if (c[i] != '0') {
                zero = i;
                break;
            }

        }
        vector<char>ans2;
        //從非0開始存
        for (int i = zero;i < c.size();i++) {
            mul_ans += c[i];//?
        }

    }

    //含小數乘法
    else if (flag == true) {
        string m1;
        string m2;
        //處理尾數0
        int count_m1 = 0;
        for (int i = mul1.length();i >= 0;i--) {
            if (mul1[i] != '0') {
                for (int j = i - 1;j >= 0;j--) {
                    if (mul1[j] >= '0' && mul1[j] <= '9') {
                        m1 += mul1[j];
                        count_m1 += 1;
                    }
                    if (mul1[j] == '.') {
                        point[0] = count_m1;
                    }

                }
                break;
            }
        }
        int count_m2 = 0;
        for (int i = mul2.length();i >= 0;i--) {
            if (mul2[i] != '0') {
                for (int j = i - 1;j >= 0;j--) {
                    if (mul2[j] >= '0' && mul2[j] <= '9') {
                        m2 += mul2[j];
                        count_m2 += 1;
                    }
                    if (mul2[j] == '.') {
                        point[1] = count_m2;
                    }


                }
                break;
            }
        }
        reverse(m1.begin(), m1.end());
        reverse(m2.begin(), m2.end());

        int sum[20000] = { NULL };
        for (int i = m1.length() - 1;i >= 0;i--) {
            for (int j = m2.length() - 1;j >= 0;j--) {
                sum[i + j + 1] += ((m1[i] - '0') * (m2[j] - '0'));
            }
        }
        for (int i = m1.length() + m2.length() - 1;i >= 1;i--) {
            sum[i - 1] += sum[i] / 10;
            sum[i] %= 10;
        }
        for (int i = m1.length() + m2.length() - 1;i >= 0;i--) {
            c.push_back(sum[i] + '0');
        }
        reverse(c.begin(), c.end());

        int zero = 0;//紀錄前面第幾位不是0的位數
        for (int i = 0;i < c.size();i++) {
            if (c[i] != '0') {
                zero = i;
                break;
            }

        }
        //從非0開始存
        for (int i = zero;i < c.size();i++) {
            mul_ans += c[i];//?
        }
    }

    //點
    int count = 0;//位數

    int pos = 0;
    pos = point[0] + point[1];
    if (flag) {
        while (pos >= mul_ans.length()) {
            mul_ans.insert(mul_ans.begin(), '0');
        }
        mul_ans.insert(mul_ans.end() - pos, '.');
            
    }

     

/***答案*************************************/
    
    if (check == true) {
        f.ans += "0";
    }
    else {
        for (int i = 0; i < mul_ans.size(); i++) {
            f.ans += mul_ans[i];
        }

    }
    vector<char>().swap(c);
    return f.ans;
}

string operator/(nextNum anext, nextNum bnext)
{
    formula f;
    string a = anext.number;
    string b = bnext.number;
    vector<int> numA, numB;
    string c = "";
    bool normal = 1;
    bool minus = 0;
    bool decimalA = 0;
    bool decimalB = 0;
    int decimalPlaceA = 0;
    int decimalPlaceB = 0;
    int decimalPlace = 0;

    // 大數減小數

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '.')
        {
            decimalA = 1;
            decimalPlaceA = i;
        }
        else
        {
            numA.push_back((int)a[i] - 48);
        }
    }

    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] == '.')
        {
            decimalB = 1;
            decimalPlaceB = i;
        }
        else
        {
            numB.push_back((int)b[i] - 48);
        }
    }

    if (decimalA == 1 && decimalB == 0)
    {
        decimalB = 1;
        decimalPlaceB = numB.size();
    }

    if (decimalA == 0 && decimalB == 1)
    {
        decimalA = 1;
        decimalPlaceA = numA.size();
    }

    if (decimalA == 0 && decimalB == 0)
    {
        decimalA = 1;
        decimalPlaceA = numA.size();
        decimalB = 1;
        decimalPlaceB = numB.size();
    }

    if (decimalPlaceB > decimalPlaceA || decimalPlaceB == decimalPlaceA && numB[0] > numA[0])
    {
        normal = 0;
    }

    if (decimalA == 1 && decimalB == 1)
    {
        if (numA.size() - decimalPlaceA > numB.size() - decimalPlaceB)
        {
            int time1 = numA.size() - decimalPlaceA - numB.size() + decimalPlaceB;
            for (int i = 0; i < time1; i++)
            {
                numB.push_back(0);
            }
        }
        else if (numA.size() - decimalPlaceA < numB.size() - decimalPlaceB)
        {
            int time2 = numB.size() - decimalPlaceB - numA.size() + decimalPlaceA;
            for (int i = 0; i < time2; i++)
            {
                numA.push_back(0);
            }
        }
    }

    while (numA[0] == 0)
    {
        numA.erase(numA.begin());
    }

    while (numB[0] == 0)
    {
        numB.erase(numB.begin());
    }

    while (numA[numA.size() - 1] == 0 && numB[numB.size() - 1] == 0)
    {
        numA.pop_back();
        numB.pop_back();
    }

    bool decimalpoint = 0;
    string answer;
    nextNum anum, bnum;
    for (int i = 0; i < numB.size(); i++)
    {
        bnum.number += to_string(numB[i]);
    }

    int onehundred = 0;
    while (c.size() - onehundred < 100 && !numA.empty() || numA.size() == 1 && numA[0] == 0)
    {
        int num;
        bool allzero = 1;
        for (int i = 0; i < numA.size(); i++)
        {
            if (numA[i] != 0)
            {
                allzero = 0;
                break;
            }
        }
        if (allzero == 1)
        {
            for (int i = 0; i < numA.size(); i++)
            {
                c += "0";
            }
            vector<int>().swap(numA);
        }
        if (numA.empty() == 1)
        {
            break;
        }
        if (numA.size() < numB.size() || numA.size() == numB.size() && !compare(numA, numB))
        {
            if (decimalpoint == 0)
            {
                if (c.size() == 0)
                {
                    c += "0";
                }
                c += ".";
                onehundred = c.size();
                decimalpoint = 1;
            }
            numA.push_back(0);
            while (!compare(numA, numB))
            {
                c += "0";
                numA.push_back(0);
            }
        }

        else
        {
            anum.number = "";
            // 用減法
            for (int i = 0; i < numB.size(); i++)
            {
                anum.number += to_string(numA[i]);
            }
            if (!comparestring(anum, bnum))
            {
                anum.number += to_string(numA[numB.size()]);
            }

            if (numB.size() + 1 - numA.size() == 1)
            {
                vector<int>().swap(numA);
            }
            else
            {
                numA.erase(numA.begin(), numA.begin() + anum.number.size());
            }
            
            int count = 0;

            while (comparestring(anum, bnum))
            {
                string ans1 = anum - bnum;
                anum.number = ans1;
                count += 1;
            }
            c += to_string(count);
            if (anum.number != "0")
            {
                int count1 = 0;
                if (!numA.empty())
                {
                    for (int i = 0; i < anum.number.size(); i++)
                    {
                        numA.insert(numA.begin() + count1, anum.number[i] - 48);
                        count1 += 1;
                    }
                }
                else
                {
                    for (int i = 0; i < anum.number.size(); i++)
                    {
                        numA.push_back(anum.number[i] - 48);
                    }
                }
                
            }

        }
    }

    f.ans = c;
    return f.ans;
}

string operator/(nextNum anext, string b)
{
    formula f;
    string a = anext.number;
    vector<int> numA, numB;
    string c = "";
    bool normal = 1;
    bool minus = 0;
    bool decimalA = 0;
    bool decimalB = 0;
    int decimalPlaceA = 0;
    int decimalPlaceB = 0;
    int decimalPlace = 0;

    // 大數減小數

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '.')
        {
            decimalA = 1;
            decimalPlaceA = i;
        }
        else
        {
            numA.push_back((int)a[i] - 48);
        }
    }

    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] == '.')
        {
            decimalB = 1;
            decimalPlaceB = i;
        }
        else
        {
            numB.push_back((int)b[i] - 48);
        }
    }

    if (decimalA == 1 && decimalB == 0)
    {
        decimalB = 1;
        decimalPlaceB = numB.size();
    }

    if (decimalA == 0 && decimalB == 1)
    {
        decimalA = 1;
        decimalPlaceA = numA.size();
    }

    if (decimalA == 0 && decimalB == 0)
    {
        decimalA = 1;
        decimalPlaceA = numA.size();
        decimalB = 1;
        decimalPlaceB = numB.size();
    }

    if (decimalPlaceB > decimalPlaceA || decimalPlaceB == decimalPlaceA && numB[0] > numA[0])
    {
        normal = 0;
    }

    if (decimalA == 1 && decimalB == 1)
    {
        if (numA.size() - decimalPlaceA > numB.size() - decimalPlaceB)
        {
            int time1 = numA.size() - decimalPlaceA - numB.size() + decimalPlaceB;
            for (int i = 0; i < time1; i++)
            {
                numB.push_back(0);
            }
        }
        else if (numA.size() - decimalPlaceA < numB.size() - decimalPlaceB)
        {
            int time2 = numB.size() - decimalPlaceB - numA.size() + decimalPlaceA;
            for (int i = 0; i < time2; i++)
            {
                numA.push_back(0);
            }
        }
    }

    while (numA[0] == 0)
    {
        numA.erase(numA.begin());
    }

    while (numB[0] == 0)
    {
        numB.erase(numB.begin());
    }

    while (numA[numA.size() - 1] == 0 && numB[numB.size() - 1] == 0)
    {
        numA.pop_back();
        numB.pop_back();
    }

    bool decimalpoint = 0;
    string answer;
    nextNum anum, bnum;
    for (int i = 0; i < numB.size(); i++)
    {
        bnum.number += to_string(numB[i]);
    }

    int onehundred = 0;
    while (c.size() - onehundred < 100 && !numA.empty() || numA.size() == 1 && numA[0] == 0)
    {
        int num;
        bool allzero = 1;
        for (int i = 0; i < numA.size(); i++)
        {
            if (numA[i] != 0)
            {
                allzero = 0;
                break;
            }
        }
        if (allzero == 1)
        {
            for (int i = 0; i < numA.size(); i++)
            {
                c += "0";
            }
            vector<int>().swap(numA);
        }
        if (numA.empty() == 1)
        {
            break;
        }
        if (numA.size() < numB.size() || numA.size() == numB.size() && !compare(numA, numB))
        {
            vector<int>().swap(numA);
        }

        else
        {
            anum.number = "";
            // 用減法
            for (int i = 0; i < numB.size(); i++)
            {
                anum.number += to_string(numA[i]);
            }
            if (!comparestring(anum, bnum))
            {
                anum.number += to_string(numA[numB.size()]);
            }

            if (numB.size() + 1 - numA.size() == 1)
            {
                vector<int>().swap(numA);
            }
            else
            {
                numA.erase(numA.begin(), numA.begin() + anum.number.size());
            }

            int count = 0;

            while (comparestring(anum, bnum))
            {
                string ans1 = anum - bnum;
                anum.number = ans1;
                count += 1;
            }
            c += to_string(count);
            if (anum.number != "0")
            {
                int count1 = 0;
                if (!numA.empty())
                {
                    for (int i = 0; i < anum.number.size(); i++)
                    {
                        numA.insert(numA.begin() + count1, anum.number[i] - 48);
                        count1 += 1;
                    }
                }
                else
                {
                    for (int i = 0; i < anum.number.size(); i++)
                    {
                        numA.push_back(anum.number[i] - 48);
                    }
                }

            }

        }
    }

    if (c == "")
    {
        c = "0";
    }

    f.ans = c;
    return f.ans;
}

string operator^(nextNum anext, nextNum bnext)
{
   
    formula f;
    string power_ans;
    vector<char>c;
    //power(power1,power2) = power1 ^ power2

    string power1 = anext.number;
    string power2 = bnext.number;
    

    int point = 0;

        bool is_zero = false;
        //檢查次方是否是0
        if (power2 == "0") {
            is_zero = true;

        }

        bool num_int = true;
        //檢查power1底數是否為整數
        for (int i = power1.length();i >= 0 ;i--) {
            if (power1[i] == '.') {
                num_int = false;
                point = i + 1;
                break;
            }
        }

        //檢查power2是否是0.5的倍數
        bool is_int = true;
        for (int i = 0;i < power2.length();i++) {
            if (power2[i] == '.') {
                is_int = false;
                break;
            }
        }

        /****************************************************************************/
        /*運算*/

        //非零數的0次方
        if (is_zero == true) {
            power_ans += "1";
        }
        //0^0?


        //power1連乘pow次
        //整數次方
        else if (is_int == true) {

            string p1;
            string p2;
            int pow = 0;
            for (int i = 0;i < power1.length();i++) {
                if (power1[i] >= '0' && power1[i] <= '9') {
                    p1 += power1[i];
                }
            }
            for (int i = 0;i < power2.length();i++) {
                if (power2[i] >= '0' && power2[i] <= '9') {
                    p2 += power2[i];
                }
            }
            pow = stoi(p2);

            //p1^p2
            string shortage = p1;//shortage不動

            for (int i = 0;i < pow - 1; i++) {
                int sum[500] = { NULL };//處理500位數乘法

                //做p1*shortage
                for (int i = p1.length() - 1;i >= 0;i--) {
                    for (int j = shortage.length() - 1;j >= 0;j--) {
                        sum[i + j + 1] += ((p1[i] - '0') * (shortage[j] - '0'));
                    }
                }
                for (int i = p1.length() + shortage.length() - 1;i >= 1;i--) {
                    sum[i - 1] += sum[i] / 10;
                    sum[i] %= 10;
                }

                for (int i = p1.length() + shortage.length() - 1;i >= 0;i--) {
                    c.push_back(sum[i] + '0');
                }

                for (int i = c.size() - 1;i >= 0;i--) {
                    if (c[i] == '0') {
                        c.pop_back();
                    }
                    else {
                        break;
                    }
                }

                std::reverse(c.begin(), c.end());

                //答案給p1
                string p3;
                for (int i = 0;i < c.size();i++) {
                    p3 += c[i];
                }
                p1 = p3;
                vector<char>().swap(c);
            }
            int zero = 0;//紀錄前面第幾位不是0的位數
            for (int i = 0;i < p1.size();i++) {
                if (p1[i] != '0') {
                    zero = i;
                    break;
                }
            }
            
            //從非0開始存
            for (int i = zero;i < p1.size();i++) {
                power_ans += p1[i];//?
            }

        }


        //直式開方
        else if (is_int == false) {

            string p1 = power1;
            string int_part;
            string dec_part;
            for (int i = 0;i < power2.length();i++) {
                if (power2[i] != '.') {
                    int_part += power2[i];
                }
                else {
                    for (int j = i + 1;j < power2.length();j++) {
                        dec_part += power2[j];//==5
                    }
                    break;
                }
            }


            /***************************************************/
            int pow = 0;

            pow = stoi(int_part);

            //p1^p2
            string shortage = p1;//shortage不動

            for (int i = 0;i < pow - 1; i++) {
                int sum[500] = { NULL };//處理500位數乘法

                //做p1*shortage
                for (int i = p1.length() - 1;i >= 0;i--) {
                    for (int j = shortage.length() - 1;j >= 0;j--) {
                        sum[i + j + 1] += ((p1[i] - '0') * (shortage[j] - '0'));
                    }
                }
                for (int i = p1.length() + shortage.length() - 1;i >= 1;i--) {
                    sum[i - 1] += sum[i] / 10;
                    sum[i] %= 10;
                }

                for (int i = p1.length() + shortage.length() - 1;i >= 0;i--) {
                    c.push_back(sum[i] + '0');
                }

                for (int i = c.size() - 1;i >= 0;i--) {
                    if (c[i] == '0') {
                        c.pop_back();
                    }
                    else {
                        break;
                    }
                }

                std::reverse(c.begin(), c.end());

                //答案給p1
                string p3;
                for (int i = 0;i < c.size();i++) {
                    p3 += c[i];
                }
                p1 = p3;
                vector<char>().swap(c);
            }

            int zero = 0;//紀錄前面第幾位不是0的位數
            for (int i = 0;i < p1.size();i++) {
                if (p1[i] != '0') {
                    zero = i;
                    break;
                }
            }

            /********************************************************************************************************************/
            //乘法
            string mul;
            long double mul0 = stoi(power1);
            
            mul0 = sqrt(mul0);
            mul = to_string(mul0);
            /********************************************************************************************************************/
            if (int_part != "0") {
                string mul1 = mul;//小數
                string mul2 = p1;
                string mul_ans;
                vector<char>c;

                //檢查是否有小數點
                bool flag = false;
                int point[2] = { 0,0 };//小數點位置
                int mul1_pointCount = 0;
                int mul2_pointCount = 0;
                for (int i = 0;i < mul1.length();i++) {
                    if (mul1[i] == '.') {
                        flag = true;
                        break;
                    }
                }

                for (int i = 0;i < mul2.length();i++) {
                    if (mul2[i] == '.') {
                        flag = true;
                        break;
                    }
                }
                //含小數乘法
                if (flag == true) {
                    string m1;
                    string m2;
                    //處理尾數0
                    int count_m1 = 0;
                    for (int i = mul1.length();i >= 0;i--) {
                        if (mul1[i] != '0') {
                            for (int j = i - 1;j >= 0;j--) {
                                if (mul1[j] >= '0' && mul1[j] <= '9') {
                                    m1 += mul1[j];
                                    count_m1 += 1;
                                }
                                if (mul1[j] == '.') {
                                    point[0] = count_m1;
                                }

                            }
                            break;
                        }
                    }
                    int count_m2 = 0;
                    for (int i = mul2.length();i >= 0;i--) {
                        if (mul2[i] != '0') {
                            for (int j = i - 1;j >= 0;j--) {
                                if (mul2[j] >= '0' && mul2[j] <= '9') {
                                    m2 += mul2[j];
                                    count_m2 += 1;
                                }
                                if (mul2[j] == '.') {
                                    point[1] = count_m2;
                                }


                            }
                            break;
                        }
                    }
                    std::reverse(m1.begin(), m1.end());
                    std::reverse(m2.begin(), m2.end());

                    int sum[100] = { NULL };//處理100位數乘法
                    for (int i = m1.length() - 1;i >= 0;i--) {
                        for (int j = m2.length() - 1;j >= 0;j--) {
                            sum[i + j + 1] += ((m1[i] - '0') * (m2[j] - '0'));
                        }
                    }
                    for (int i = m1.length() + m2.length() - 1;i >= 1;i--) {
                        sum[i - 1] += sum[i] / 10;
                        sum[i] %= 10;
                    }
                    for (int i = m1.length() + m2.length() - 1;i >= 0;i--) {
                        c.push_back(sum[i] + '0');
                    }
                    std::reverse(c.begin(), c.end());

                    int zero = 0;//紀錄前面第幾位不是0的位數
                    for (int i = 0;i < c.size();i++) {
                        if (c[i] != '0') {
                            zero = i;
                            break;
                        }

                    }
                    //從非0開始存
                    for (int i = zero;i < c.size();i++) {
                        mul_ans += c[i];//?
                    }
                }

                //點
                int pos = 0;
                pos = point[0] + point[1];
                if (flag) {
                    while (pos >= mul_ans.length()) {
                        mul_ans.insert(mul_ans.begin(), '0');
                    }
                    mul_ans.insert(mul_ans.end() - pos, '.');


                    /******(可不用)******/
                        //檢查小數點後是否有沒用的0
                    for (int i = mul_ans.length() - 1;i >= 0;i--) {
                        if (mul_ans[i] == '0') {
                            mul_ans.pop_back();
                        }
                        else {
                            break;
                        }
                    }
                    /***************************/
                }
                int ans_lastchar = 0;
                ans_lastchar = mul_ans.length() - 1;
                if (mul_ans[ans_lastchar] == '.') {
                    mul_ans.pop_back();
                }

                /******************************/

                    for (int i = 0;i < mul_ans.size();i++) {
                        power_ans += mul_ans[i];
                    }

                    vector<char>().swap(c);

            }
            
            else {
                for (int i = 0;i < mul.length();i++) {
                    power_ans += mul[i];
                }
            }

        }


        /***********************************************************************************************************************/
        if (num_int == false) {
            string p1 = power1;
            string p2 = power2;
            string int_part;
            string dec_part;
            int declen = 0;

            for (int i = 0;i < p1.length();i++) {
                if (p1[i] != '.') {
                    int_part += p1[i];
                }
                else {     
                    declen = p1.length() - i - 1;
                    break;
                }
            }
            

            /***************************************************/
            int pow = 0;

            pow = int(stoi(p2));

            //p1^p2
            string shortage = int_part;//shortage不動

            point = declen;

            for (int i = 1;i < pow; i++) {
                point += declen;
            }

            power_ans.insert(power_ans.end() - point , '.');
        }

        //答案
       /* for (int i = 0;i < power_ans.size();i++) {
            cout << power_ans[i];
        }
        cout << endl;
        power_ans = { NULL };
        vector<char>().swap(c);*/

    

    string answ = "";
    //答案
    for (int i = 0;i < power_ans.size();i++) {
        //cout << power_ans[i];
        answ += power_ans[i];
    }
    //cout << endl;
    power_ans = { NULL };
    vector<char>().swap(c);
    f.ans = answ;

    return f.ans;
    
}

// 看正負號
void formula::minusplusEqu(vector<string> s)
{
    if (s.size() != 2 || s.size() != 2 && s[1] != "!")
    {
        int place = 0;
        while (place < s.size())
        {
            if (stringIsNum(s[place]))
            {
                place += 1;
            }
            else if (!stringIsNum(s[place]))
            {
                if (place == 0)
                {
                    if (stringIsNum(s[place + 1]))
                    {
                        if (s[place] == "-")
                        {
                            s.erase(s.begin());
                            if (s[place][0] == '-')
                            {
                                s[0].erase(s[0].begin());
                            }
                            else
                            {
                                s[0] = "-" + s[0];
                            }
                        }
                        else if (s[place] == "+")
                        {
                            s.erase(s.begin());
                        }
                    }
                }
                else if (place + 1 != s.size() && stringIsNum(s[place + 1]) || s[place] == "!")
                {
                    place += 1;
                }
                else if (place + 1 != s.size() && s[place] == "*" && s[place + 1] == "/" || place + 1 != s.size() && s[place] == "*" && s[place + 1] == "*" || place + 1 != s.size() && s[place] == "/" && s[place + 1] == "/" || place + 1 != s.size() && s[place] == "/" && s[place + 1] == "*")
                {
                    cout << "wrong" << endl;
                    vector<string>().swap(equation);
                    vector<string>().swap(calculateOperator);
                    break;
                }
                else
                {
                    int newplace = place + 1;
                    string newNum;
                    while (!stringIsNum(s[newplace]))
                    {
                        if (stringIsNum(s[newplace + 1]) && s[newplace] == "-")
                        {
                            s.erase(s.begin() + newplace);
                            if (s[place + 1][0] == '-')
                            {
                                s[newplace].erase(s[newplace].begin());
                            }
                            else
                            {
                                s[newplace] = "-" + string(s[newplace]);
                            }

                        }
                        else if (s[newplace] == "+")
                        {
                            s.erase(s.begin() + newplace);
                        }
                        else if (s[newplace] == "-" && s[newplace + 1] == "-")
                        {
                            s.erase(s.begin() + newplace);
                            s[newplace] = "+";
                        }
                        else if (s[newplace + 1] == "+" && s[newplace] == "-")
                        {
                            s.erase(s.begin() + newplace);
                            s[newplace] = "-";
                        }
                    }
                }
            }
        }

        vector<string>().swap(equation);
        for (int i = 0; i < s.size(); i++)
        {
            equation.push_back(s[i]);
        }
    }
    else if (s.size() == 2 && s[1] == "+")
    {
        cout << "wrong" << endl;
        vector<string>().swap(equation);
    }
    
}

void formula::minusplusCal(vector<string> s)
{
    if (s.size() != 2 || s.size() != 2 && s[1] != "!")
    {
        int place = 0;
        while (place < s.size())
        {
            if (stringIsNum(s[place]))
            {
                place += 1;
            }
            else if (!stringIsNum(s[place]))
            {
                if (place == 0)
                {
                    if (stringIsNum(s[place + 1]))
                    {
                        if (s[place] == "-")
                        {
                            s.erase(s.begin());
                            if (s[place][0] == '-')
                            {
                                s[0].erase(s[0].begin());
                            }
                            else
                            {
                                s[0] = "-" + s[0];
                            }
                        }
                        else if (s[place] == "+")
                        {
                            s.erase(s.begin());
                        }
                    }
                }
                else if (place + 1 != s.size() && stringIsNum(s[place + 1]) || s[place] == "!")
                {
                    place += 1;
                }
                /********************/
                else if (place + 1 != s.size() && s[place] == "*" && s[place + 1] == "/" || place + 1 != s.size() && s[place] == "*" && s[place + 1] == "*" || place + 1 != s.size() && s[place] == "/" && s[place + 1] == "/" || place + 1 != s.size() && s[place] == "/" && s[place + 1] == "*")
                {
                    cout << "wrong" << endl;
                    vector<string>().swap(equation);
                    vector<string>().swap(calculateOperator);
                    break;
                }
                else
                {
                    int newplace = place + 1;
                    string newNum;
                    while (!stringIsNum(s[newplace]))
                    {
                        if (stringIsNum(s[newplace + 1]) && s[newplace] == "-")
                        {
                            s.erase(s.begin() + newplace);
                            if (s[place + 1][0] == '-')
                            {
                                s[newplace].erase(s[newplace].begin());
                            }
                            else
                            {
                                s[newplace] = "-" + string(s[newplace]);
                            }
                        }
                        else if (s[newplace] == "+")
                        {
                            s.erase(s.begin() + newplace);
                        }
                        else if (s[newplace] == "-" && s[newplace + 1] == "-")
                        {
                            s.erase(s.begin() + newplace);
                            s[newplace] = "+";
                        }
                        else if (s[newplace + 1] == "+" && s[newplace] == "-")
                        {
                            s.erase(s.begin() + newplace);
                            s[newplace] = "-";
                        }
                        
                    }
                }
            }
        }
        vector<string>().swap(calculateOperator);
        for (int i = 0; i < s.size(); i++)
        {
            calculateOperator.push_back(s[i]);
        }
    }
    else if (s.size() == 2 && s[1] == "+")
    {
        cout << "wrong" << endl;
        vector<string>().swap(equation);
        vector<string>().swap(calculateOperator);
    }
    

}


int formula::priority(char c)
{
    int priority;
    switch (c)
    {
    case '(':
        priority = 1;
    case ')':
        priority = 1;
    case '/':
        priority = 2;
    case '*':
        priority = 2;
    case '+':
        priority = 3;
    case '-':
        priority = 3;
    case '^':
        priority = 3;
    case '!':
        priority = 3;
    }

    return priority;
}

void formula::process(vector<string> s)
{
    int prior = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (stringIsNum(s[i]))
        {
            number.push_back(s[i]);
        }
        else
        {
            // +
            if (s[i] == "+")
            {
                if (stack.empty() || !stack.empty() && prior > 3)
                {
                    stack.push_back("+");
                    prior = 3;
                }
                else
                {
                    for (int j = stack.size() - 1; j >= 0; j--)
                    {
                        number.push_back(stack[j]);
                        deci.push_back(stack[j]);
                    }
                    vector<string>().swap(stack);
                    stack.push_back("+");
                    prior = 3;
                }
            }
            // -
            else if (s[i] == "-")
            {
                if (stack.empty() || !stack.empty() && prior > 3)
                {
                    stack.push_back("-");
                    prior = 3;
                }
                else
                {
                    for (int j = stack.size() - 1; j >= 0; j--)
                    {
                        number.push_back(stack[j]);
                        deci.push_back(stack[j]);
                    }
                    vector<string>().swap(stack);
                    stack.push_back("-");
                    prior = 3;
                }
            }
            // *
            else if (s[i] == "*")
            {
                if (stack.empty() || !stack.empty() && prior > 2)
                {
                    stack.push_back("*");
                    prior = 2;
                }
                else
                {
                    for (int j = stack.size() - 1; j >= 0; j--)
                    {
                        number.push_back(stack[j]);
                        deci.push_back(stack[j]);
                    }
                    vector<string>().swap(stack);
                    stack.push_back("*");
                    prior = 2;
                }
            }
            // /
            else if (s[i] == "/")
            {
                if (stack.empty() || !stack.empty() && prior > 2)
                {
                    stack.push_back("/");
                    prior = 2;
                }
                else
                {
                    for (int j = stack.size() - 1; j >= 0; j--)
                    {
                        number.push_back(stack[j]);
                        deci.push_back(stack[j]);
                    }
                    vector<string>().swap(stack);
                    stack.push_back("/");
                    prior = 2;
                }
            }
            // ^
            else if (s[i] == "^")
            {
                if (stack.empty()|| !stack.empty() && prior > 3 || stack[stack.size() - 1] == "^")
                {
                    stack.push_back("^");
                    prior = 3;
                }
                else
                {
                    for (int j = stack.size() - 1; j >= 0; j--)
                    {
                        number.push_back(stack[j]);
                        deci.push_back(stack[j]);
                    }
                    vector<string>().swap(stack);
                    stack.push_back("^");
                    prior = 3;
                }
            }

            else if (s[i] == "!")
            {
                if (stack.empty() || !stack.empty() && prior > 3)
                {
                    stack.push_back("!");
                    prior = 3;
                }
                else
                {
                    for (int j = stack.size() - 1; j >= 0; j--)
                    {
                        number.push_back(stack[j]);
                        deci.push_back(stack[j]);
                    }
                    vector<string>().swap(stack);
                    stack.push_back("!");
                    prior = 3;
                }
            }
        }
    }
    if (!stack.empty())
    {
        for (int j = stack.size() - 1; j >= 0; j--)
        {
            number.push_back(stack[j]);
        }
        vector<string>().swap(stack);
    }

    /*
    for (int i = 0; i < deci.size(); i++)
    {

    }

    for (int i = 0; i < number.size(); i++)
    {
        cout << number[i] << endl;
    }*/
}

void formula::calculate(vector<string> s)
{
    if (number.size() == 1)
    {
        ans = number[0];
    }
    else if (number.size() == 2 && number[1] == "-" || number.size() == 2 && number[1] == "+")
    {
        if (number[1] == "-")
        {
            if (number[0][0] == '-')
            {
                number.erase(number.begin() + 1);
                number[0].erase(number[0].begin());
                ans = number[0];
            }
            else
            {
                number.erase(number.begin() + 1);
                number[0] = "-" + number[0];
                ans = number[0];
            }
        }
        else if (number[1] == "+")
        {
            number.erase(number.begin() + 1);
            ans = number[0];
        }
    }

    else
    {
        while (number.size() != 1)
        {

            string sign;
            int i = 0;
            while (i < number.size())
            {
                placeFront = i - 2;
                placeBack = i - 1;
                if (!stringIsNum(number[i]))
                {
                    if (number[i] == "+")
                    {

                        if (number[placeFront][0] == '-' && number[placeBack][0] == '-')
                        {
                            number[placeFront].erase(number[placeFront].begin());
                            number[placeBack].erase(number[placeBack].begin());
                            nextNum a, b;
                            a.number = number[placeFront];
                            b.number = number[placeBack];
                            number[placeFront] = a + b;

                            if (number[placeFront][0] == '-')
                            {
                                number[placeFront] = a + b;
                            }
                            else
                            {
                                number[placeFront] = "-" + number[placeFront];
                            }
                            number.erase(number.begin() + placeBack, number.begin() + i + 1);
                            i = 0;
                        }
                        else if (number[placeFront][0] == '-' && number[placeBack][0] != '-')
                        {
                            number[placeFront].erase(number[placeFront].begin());
                            nextNum a, b;
                            a.number = number[placeFront];
                            b.number = number[placeBack];
                            number[placeFront] = b - a;
                            number.erase(number.begin() + placeBack, number.begin() + i + 1);
                            i = 0;
                        }
                        else if (number[placeFront][0] != '-' && number[placeBack][0] == '-')
                        {
                            number[placeBack].erase(number[placeBack].begin());
                            nextNum a, b;
                            a.number = number[placeFront];
                            b.number = number[placeBack];
                            number[placeFront] = a - b;
                            number.erase(number.begin() + placeBack, number.begin() + i + 1);
                            i = 0;
                        }
                        else
                        {
                            nextNum a, b;
                            a.number = number[placeFront];
                            b.number = number[placeBack];
                            number[placeFront] = a + b;
                            number.erase(number.begin() + placeBack, number.begin() + i + 1);
                            i = 0;
                        }
                    }
                    else if (number[i] == "-")
                    {
                        if (number[placeFront][0] == '-' && number[placeBack][0] == '-')
                        {
                            number[placeFront].erase(number[placeFront].begin());
                            number[placeBack].erase(number[placeBack].begin());
                            nextNum a, b;
                            a.number = number[placeFront];
                            b.number = number[placeBack];
                            number[placeFront] = b - a;
                            number.erase(number.begin() + placeBack, number.begin() + i + 1);
                            i = 0;
                        }
                        else if (number[placeFront][0] == '-' && number[placeBack][0] != '-')
                        {
                            number[placeFront].erase(number[placeFront].begin());
                            nextNum a, b;
                            a.number = number[placeFront];
                            b.number = number[placeBack];
                            number[placeFront] = a + b;
                            number[placeFront] = "-" + number[placeFront];
                            number.erase(number.begin() + placeBack, number.begin() + i + 1);
                            i = 0;
                        }
                        else if (number[placeFront][0] != '-' && number[placeBack][0] == '-')
                        {
                            number[placeBack].erase(number[placeBack].begin());
                            nextNum a, b;
                            a.number = number[placeFront];
                            b.number = number[placeBack];
                            number[placeFront] = a + b;
                            number.erase(number.begin() + placeBack, number.begin() + i + 1);
                            i = 0;
                        }
                        else
                        {

                            nextNum a, b;
                            a.number = number[placeFront];
                            b.number = number[placeBack];
                            number[placeFront] = a - b;
                            number.erase(number.begin() + placeBack, number.begin() + i + 1);
                            i = 0;
                        }
                    }
                    else if (number[i] == "*")
                    {
                        if (number[placeFront][0] == '-' && number[placeBack][0] == '-')
                        {
                            number[placeFront].erase(number[placeFront].begin());
                            number[placeBack].erase(number[placeBack].begin());
                            nextNum a, b;
                            a.number = number[placeFront];
                            b.number = number[placeBack];
                            number[placeFront] = a * b;
                            number.erase(number.begin() + placeBack, number.begin() + i + 1);
                            i = 0;
                        }
               
                        else if (number[placeFront][0] != '-' && number[placeBack][0] == '-')
                        {
                            number[placeBack].erase(number[placeBack].begin());
                            nextNum a, b;
                            a.number = number[placeFront];
                            b.number = number[placeBack];
                            number[placeFront] = a * b;
                            number[placeFront] = "-" + number[placeFront];
                            number.erase(number.begin() + placeBack, number.begin() + i + 1);
                            i = 0;
                        }
                        else if (number[placeFront][0] == '-' && number[placeBack][0] != '-')
                        {
                            number[placeFront].erase(number[placeFront].begin());
                            nextNum a, b;
                            a.number = number[placeFront];
                            b.number = number[placeBack];
                            number[placeFront] = a * b;
                            number[placeFront] = "-" + number[placeFront];
                            number.erase(number.begin() + placeBack, number.begin() + i + 1);
                            i = 0;
                        }
                        else
                        {
                            nextNum a, b;
                            a.number = number[placeFront];
                            b.number = number[placeBack];
                            number[placeFront] = a * b;
                            number.erase(number.begin() + placeBack, number.begin() + i + 1);
                            i = 0;
                        }
                    }
                    else if (number[i] == "/")
                    {

                    if (include_p == 1)
                    {
                        if (number[placeFront][0] == '-' && number[placeBack][0] == '-')
                        {
                            number[placeFront].erase(number[placeFront].begin());
                            number[placeBack].erase(number[placeBack].begin());

                            // 不能除0

                            if (number[placeBack] == "0")
                            {
                                cout << "no zero!!!" << endl;
                                number.erase(number.begin() + placeBack, number.begin() + i + 1);
                                i = 0;
                            }

                            else
                            {
                                nextNum a, b;
                                a.number = number[placeFront];
                                b.number = number[placeBack];
                                number[placeFront] = a / b;
                                number.erase(number.begin() + placeBack, number.begin() + i + 1);
                                i = 0;
                            }
                        }
                        else if (number[placeFront][0] == '-' && number[placeBack][0] != '-')
                        {
                            number[placeFront].erase(number[placeFront].begin());

                            // 不能除0

                            if (number[placeBack] == "0")
                            {
                                cout << "no zero!!!" << endl;
                                number.erase(number.begin() + placeBack, number.begin() + i + 1);
                                i = 0;
                            }
                            else
                            {
                                nextNum a, b;
                                a.number = number[placeFront];
                                b.number = number[placeBack];
                                number[placeFront] = a / b;
                                number[placeFront] = "-" + number[placeFront];
                                number.erase(number.begin() + placeBack, number.begin() + i + 1);
                                i = 0;
                            }

                        }
                        else if (number[placeFront][0] != '-' && number[placeBack][0] == '-')
                        {
                            number[placeBack].erase(number[placeBack].begin());

                            // 不能除0

                            if (number[placeBack] == "0")
                            {
                                cout << "no zero!!!" << endl;
                                number.erase(number.begin() + placeBack, number.begin() + i + 1);
                                i = 0;
                            }
                            else
                            {
                                nextNum a, b;
                                a.number = number[placeFront];
                                b.number = number[placeBack];
                                number[placeFront] = a / b;
                                number[placeFront] = "-" + number[placeFront];
                                number.erase(number.begin() + placeBack, number.begin() + i + 1);
                                i = 0;
                            }

                        }
                        else
                        {
                            // 不能除0

                            if (number[placeBack] == "0")
                            {
                                cout << "no zero!!!" << endl;
                                number.erase(number.begin() + placeBack, number.begin() + i + 1);
                                i = 0;
                            }
                            else
                            {
                                nextNum a, b;
                                a.number = number[placeFront];
                                b.number = number[placeBack];
                                number[placeFront] = a / b;
                                number.erase(number.begin() + placeBack, number.begin() + i + 1);
                                i = 0;
                            }

                        }
                    }
                    else
                    {
                        if (number[placeFront][0] == '-' && number[placeBack][0] == '-')
                        {
                            number[placeFront].erase(number[placeFront].begin());
                            number[placeBack].erase(number[placeBack].begin());

                            // 不能除0

                            if (number[placeBack] == "0")
                            {
                                cout << "no zero!!!" << endl;
                                number.erase(number.begin() + placeBack, number.begin() + i + 1);
                                i = 0;
                            }

                            else
                            {
                                nextNum a, b;
                                a.number = number[placeFront];
                                number[placeFront] = a / number[placeBack];
                                number.erase(number.begin() + placeBack, number.begin() + i + 1);
                                i = 0;
                            }
                        }
                        else if (number[placeFront][0] == '-' && number[placeBack][0] != '-')
                        {
                            number[placeFront].erase(number[placeFront].begin());

                            // 不能除0

                            if (number[placeBack] == "0")
                            {
                                cout << "no zero!!!" << endl;
                                number.erase(number.begin() + placeBack, number.begin() + i + 1);
                                i = 0;
                            }
                            else
                            {
                                nextNum a, b;
                                a.number = number[placeFront];
                                number[placeFront] = a / number[placeBack];
                                number[placeFront] = "-" + number[placeFront];
                                number.erase(number.begin() + placeBack, number.begin() + i + 1);
                                i = 0;
                            }

                        }
                        else if (number[placeFront][0] != '-' && number[placeBack][0] == '-')
                        {
                            number[placeBack].erase(number[placeBack].begin());

                            // 不能除0

                            if (number[placeBack] == "0")
                            {
                                cout << "no zero!!!" << endl;
                                number.erase(number.begin() + placeBack, number.begin() + i + 1);
                                i = 0;
                            }
                            else
                            {
                                nextNum a, b;
                                a.number = number[placeFront];
                                number[placeFront] = a / number[placeBack];
                                number[placeFront] = "-" + number[placeFront];
                                number.erase(number.begin() + placeBack, number.begin() + i + 1);
                                i = 0;
                            }

                        }
                        else
                        {
                            // 不能除0

                            if (number[placeBack] == "0")
                            {
                                cout << "no zero!!!" << endl;
                                number.erase(number.begin() + placeBack, number.begin() + i + 1);
                                i = 0;
                            }
                            else
                            {
                                nextNum a, b;
                                a.number = number[placeFront];
                                number[placeFront] = a / number[placeBack];
                                number.erase(number.begin() + placeBack, number.begin() + i + 1);
                                i = 0;
                            }

                        }
                    }

                    }

                    // ^
                    else if (number[i] == "^")
                    {


                    bool deci = 0;
                    int deciplace = 0;
                    for (int i = 0; i < number[placeBack].size(); i++)
                    {
                        if (number[placeBack][i] == '.')
                        {
                            deci = 1;
                            deciplace = i;
                        }
                    }

                    if (deci == 1)
                    {
                        bool all9 = 1;
                        for (int i = deciplace + 1; i < number[placeBack].size() - 3; i++)
                        {
                            if (number[placeBack][i] != '9')
                            {
                                all9 = 0;
                            }
                        }

                        if (all9 == 1 && number[placeBack].size() - deciplace - 1 > 80)
                        {
                            number[placeBack].erase(number[placeBack].begin() + deciplace, number[placeBack].end());

                            if (number[placeBack][0] == '-')
                            {
                                number[placeBack].erase(number[placeBack].begin());
                                nextNum eq;
                                nextNum one;
                                eq.number = number[placeBack];
                                one.number = "1";
                                number[placeBack] = eq + one;
                                number[placeBack] = "-" + number[placeBack];
                            }
                            else
                            {
                                nextNum eq;
                                nextNum one;
                                eq.number = number[placeBack];
                                one.number = "1";
                                number[placeBack] = eq + one;
                            }
                        }
                    }

                    // 一定要是0.5的倍數
                    nextNum back, point5;
                    back.number = number[placeBack];
                    point5.number = "0.5";
                    string try1 = back / point5;

                    if (number[placeBack][0] == '-')
                    {
                        cout << "不能是負的喔喔喔";
                        number.erase(number.begin() + placeBack, number.begin() + i + 1);
                    }

                    int decipoint = 0;
                    bool de = 0;
                    for (int j = 0; j < try1.size(); j++)
                    {
                        if (try1[j] == '.')
                        {
                            decipoint = j;
                            de = 1;
                        }
                    }
                    bool wrong = 0;
                    if (de == 1)
                    {
                        for (int j = decipoint + 1; j < try1.size(); j++)
                        {
                            if (try1[j] != '0')
                            {
                                wrong = 1;
                                break;
                            }
                        }
                    }


                    bool dec1 = 0, dec2 = 0;
                    for (int j = 0; j < number[placeFront].size(); j++)
                    {
                        if (number[placeFront][j] == '.')
                            dec1 = 1;
                    }

                    if (dec1 == 1)
                    {
                        while (number[placeFront][number[placeFront].size() - 1] == '0')
                        {
                            number[placeFront].pop_back();
                            if (number[placeFront][number[placeFront].size() - 1] == '.')
                            {
                                number[placeFront].pop_back();
                                break;
                            }
                        }
                    }

                    for (int j = 0; j < number[placeBack].size(); j++)
                    {
                        if (number[placeBack][j] == '.')
                            dec2 = 1;
                    }

                    if (dec2 == 1)
                    {
                        while (number[placeBack][number[placeBack].size() - 1] == '0')
                        {
                            number[placeBack].pop_back();
                            if (number[placeBack][number[placeBack].size() - 1] == '.')
                            {
                                number[placeBack].pop_back();
                                break;
                            }
                        }
                    }

                    // 一定要是0.5的倍數
                    if (wrong == 1)
                    {
                        cout << "一定要是0.5的倍數";
                        number.erase(number.begin() + placeBack, number.begin() + i + 1);
                    }

                    else if (number[placeFront][0] == '-')
                    {
                        number[placeFront].erase(number[placeFront].begin());
                        nextNum a, b;
                        a.number = number[placeFront];
                        b.number = number[placeBack];
                        number[placeFront] = a ^ b;
                        number[placeFront] = "-" + number[placeFront];
                        number.erase(number.begin() + placeBack, number.begin() + i + 1);
                        i = 0;
                    }
                    else
                    {
                        nextNum a, b;
                        a.number = number[placeFront];
                        b.number = number[placeBack];
                        number[placeFront] = a ^ b;
                        number.erase(number.begin() + placeBack, number.begin() + i + 1);
                        i = 0;
                    }

                    }

                    // !
                    else if (number[i] == "!")
                    {
                    // 整數
                    bool dec2 = 0;
                    for (int j = 0; j < number[placeBack].size(); j++)
                    {
                        if (number[placeBack][j] == '.')
                            dec2 = 1;
                    }

                    if (dec2 == 1)
                    {
                        while (number[placeBack][number[placeBack].size() - 1] == '0')
                        {
                            number[placeBack].pop_back();
                            if (number[placeFront][number[placeFront].size() - 1] == '.')
                            {
                                number[placeFront].pop_back();
                                break;
                            }
                        }
                    }

                    bool deci = 0;
                    int deciplace = 0;
                    for (int i = 0; i < number[placeBack].size(); i++)
                    {
                        if (number[placeBack][i] == '.')
                        {
                            deci = 1;
                            deciplace = i;
                        }
                    }

                    if (deci == 1)
                    {
                        bool all9 = 1;
                        for (int i = deciplace + 1; i < number[placeBack].size() - 3; i++)
                        {
                            if (number[placeBack][i] != '9')
                            {
                                all9 = 0;
                            }
                        }

                        if (all9 == 1 && number[placeBack].size() - deciplace - 1 > 80)
                        {
                            number[placeBack].erase(number[placeBack].begin() + deciplace, number[placeBack].end());

                            if (number[placeBack][0] == '-')
                            {
                                number[placeBack].erase(number[placeBack].begin());
                                nextNum eq;
                                nextNum one;
                                eq.number = number[placeBack];
                                one.number = "1";
                                number[placeBack] = eq + one;
                                number[placeBack] = "-" + number[placeBack];
                            }
                            else
                            {
                                nextNum eq;
                                nextNum one;
                                eq.number = number[placeBack];
                                one.number = "1";
                                number[placeBack] = eq + one;
                            }
                        }
                    }
                    bool wrong2 = 0;
                    for (int j = 0; j < number[placeBack].size(); j++)
                    {
                        if (number[placeBack][j] == '.')
                            wrong2 = 1;
                    }

                    if (number[placeBack][0] == '-' || wrong2 == 1)
                    {
                        cout << "一定要是正整數喔喔";
                        number.erase(number.begin() + i + 1);
                        i = 0;
                    }

                    else
                    {
                        nextNum a;
                        a.number = number[placeBack];

                        nextNum n;
                        nextNum an;
                        nextNum count;
                        count.number = "1";
                        n.number = "1";
                        an.number = "1";
                        while (n.number != number[placeBack])
                        {
                            an.number = an * n;
                            n.number = n + count;
                        }
                        an.number = an * a;
                        number[placeBack] = an.number;
                        number.erase(number.begin() + i);
                        i = 0;
                    }
                         
                    }
                }
                else
                {
                     i += 1;
                }
            }
        }
        ans = number[0];
        
    }

}

void SetColor(int f = 7, int b = 0)
{
    unsigned short ForeColor = f + 16 * b;
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon, ForeColor);
}


void formula::print()
{
    bool deci = 0;
    int deciplace = 0;
    for (int i = 0; i < equation[0].size(); i++)
    {
        if (equation[0][i] == '.')
        {
            deci = 1;
            deciplace = i;
        }
    }

    if (deci == 1)
    {
        bool all9 = 1;
        for (int i = deciplace + 1; i < equation[0].size() - 10; i++)
        {
            if (equation[0][i] != '9')
            {
                all9 = 0;
            }
        }

        if (all9 == 1 && equation[0].size() - deciplace - 1 > 80)
        {
            equation[0].erase(equation[0].begin() + deciplace, equation[0].end());

            if (equation[0][0] == '-')
            {
                equation[0].erase(equation[0].begin());
                nextNum eq;
                nextNum one;
                eq.number = equation[0];
                one.number = "1";
                equation[0] = eq + one;
                equation[0] = "-" + equation[0];
                /****************************/
                if (include_p == true) {
                    equation[0] += '.';
                    for (int i = 0;i < 100;i++) {
                        equation[0] += '0';
                    }
                }
                
            }
            else
            {
                nextNum eq;
                nextNum one;
                eq.number = equation[0];
                one.number = "1";
                equation[0] = eq + one;
                /***********************/
                /*equation[0] += '.';
                for (int i = 0;i < 100;i++) {
                    equation[0] += '0';
                }*/
            }
        }
        else
        {
            while (equation[0].size() - deciplace - 1 < 100)
            {
                equation[0].push_back('0');
            }
        }
    }
    else if (deci == false && include_p == true) {
        
        equation[0].push_back('.');
            for (int i = 0;i < 100;i++) {
                equation[0].push_back('0');
            }
        
    }

    if (deci == true && include_p == false) {
        equation[0].erase(equation[0].begin() + deciplace, equation[0].end());
    }

    if (equation[0] == "-0") {
        equation[0].erase(equation[0].begin());
    }
    system("color 3");
    
    cout << this->equ << " = ";
    for (int i = 0; i < equation.size(); i++)
    {
        std::cout << equation[i] << endl;
    }
    cout << "----------------------------------------------------------------\n";
}

void formula::reset()
{
    vector<string>().swap(equation);
    vector<string>().swap(calculateOperator);
    parenthesePlace = 0;
    parentheseErase = 0;
    include_p = false;
}

