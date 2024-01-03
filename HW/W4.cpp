#include <iostream>
#include <algorithm>
using namespace std;

int function(int n) {
	int count = 1;
	while (n != 1) 
	{
		if (n % 2 == 0) 
		{
			n = n / 2;
		}
		else
		{
			n = n * 3 + 1;
		}
		count += 1;
	}
	return count;
}

int main() {
	int a, b;
	int bigNum, smallNum;
	int outPut = 0;
	while (cin >> a >> b) {
		outPut = 0;
		if (a > b) {
			bigNum = a;
			smallNum = b;
		}
		else {
			bigNum = b;
			smallNum = a;
		}
		for (int i = smallNum; i < bigNum + 1; i++) {
			if (function(i) > outPut)
			{
				outPut = function(i);
			}
		}
		cout << a << " " << b << " " << outPut << endl;
	}
	
}