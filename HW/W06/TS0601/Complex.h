#include <iostream>
#include <sstream>

using namespace std;

class Complex
{
public:
	double realValue, imaginaryValue;

	Complex();
	//~Complex();
	Complex(double r);
	//~Complex(double r);
	Complex(double r, double i);
	//~Complex(double r, double i);
	double real();
	double imag();
	double norm();
	friend double real(Complex c);
	friend double imag(Complex c);
	friend double norm(Complex c);	
	Complex operator+(Complex c);
	Complex operator-(Complex c);
	Complex operator*(Complex c);
	Complex operator/(Complex c);
	friend Complex operator+(double d, Complex c);
	friend Complex operator-(double d, Complex c);
	friend Complex operator*(double d, Complex c);
	friend Complex operator/(double d, Complex c);
	friend bool operator==(Complex c1, Complex c2);	
	friend ostream& operator<<(ostream &strm, const Complex &c);
	friend istream& operator>>(istream &strm,Complex &c);
};

// 初始化值為0
// post : realValue, imaginaryValue
Complex::Complex()
{
	this->realValue = 0;
	this->imaginaryValue = 0;
}

// 初始化realvalue為r
// Pre : r
// Post : realValue, imaginaryValue
Complex::Complex(double r)
{
	this->realValue = r;
	this->imaginaryValue = 0;
}

// 初始化realvalue為r, imaginaryvalue為i
// Pre : r, i
// Post : realValue, imaginaryValue
Complex::Complex(double r, double i)
{
	this->realValue = r;
	this->imaginaryValue = i;
}

// 回傳realvalue
// Pre : realValue
// Post : realValue
double Complex::real()
{
	return this->realValue;
}

// 回傳imaginaryValue
// Pre : imaginaryValue
// Post : imaginaryValue
double Complex::imag()
{
	return this->imaginaryValue;
}

// 回傳值
// Pre : imaginaryValue, realValue
// Post : num
double Complex::norm()
{
	double num;
	num = pow(this->realValue, 2) + pow(this->imaginaryValue, 2);
	num = pow(num, 1 / 2);
	return num;
}

double real(Complex c)
{
	return c.realValue;
}

double imag(Complex c)
{
	return c.imaginaryValue;
}

double norm(Complex c)
{
	double num;
	num = pow(c.realValue, 2) + pow(c.imaginaryValue, 2);
	num = pow(num, 1 / 2);
	return num;
}

Complex Complex::operator+(Complex c)
{
	this->realValue = this->realValue + c.realValue;
	this->imaginaryValue = this->imaginaryValue + c.imaginaryValue;
	return *this;
}
Complex Complex::operator-(Complex c)
{
	this->realValue = this->realValue + c.realValue;
	this->imaginaryValue = this->imaginaryValue + c.imaginaryValue;
	return *this;
}
Complex Complex::operator*(Complex c)
{
	this->realValue = this->realValue * c.realValue;
	this->realValue -= this->imaginaryValue * c.imaginaryValue;
	this->imaginaryValue = this->realValue * c.imaginaryValue;
	this->imaginaryValue += this->imaginaryValue * c.realValue;
	return *this;
}
Complex Complex::operator/(Complex c)
{
	double de;
	this->realValue = this->realValue * c.realValue;
	this->realValue -= this->imaginaryValue * -c.imaginaryValue;
	this->imaginaryValue = this->realValue * -c.imaginaryValue;
	this->imaginaryValue += this->imaginaryValue * c.realValue;
	de = pow(c.realValue, 2) + pow(c.imaginaryValue, 2);
	this->imaginaryValue = this->imaginaryValue / de;
	this->realValue = this->imaginaryValue / de;
	return *this;
}

Complex operator+(double d, Complex c)
{
	c.realValue += d;
	return c;
}

Complex operator-(double d, Complex c)
{
	c.realValue -= d;
	return c;
}
Complex operator*(double d, Complex c)
{
	c.realValue *= d;
	c.imaginaryValue *= d;
	return c;
}
Complex operator/(double d, Complex c)
{
	c.realValue /= d;
	c.imaginaryValue /= d;
	return c;
}
bool operator==(Complex c1, Complex c2)
{
	if (c1.imaginaryValue == c2.imaginaryValue && c1.realValue == c2.realValue)
		return true;
	else
		return false;
}
ostream& operator<<(ostream& strm, const Complex& c)
{
	strm << c.realValue << " + " << c.imaginaryValue << "*i" << endl;
	return strm;
}
istream& operator>>(istream& strm, Complex& c)
{
	string input;
	cin >> input;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == 'x' || input[i] == '=' || input[i] == '+' || input[i] == '*' || input[i] == 'i' || input[i] == 'y' || input[i] == 'z')
		{
			cout << input[i] << endl;
			input[i] = ' ';
		}
	}
	cout << input;
	istringstream is(input);
	double num;
	int count = 0;
	while (is >> num)
	{
		if (count == 0)
		{
			c.realValue = num;
			strm >> num;
			count += 1;
		}
		else
		{
			c.imaginaryValue = num;
			strm >> num;
			count = 0;
		}
	}
	return strm;
}