
class PrimeNumber {
public:
	int value;
	int get();
	PrimeNumber();
	PrimeNumber(int _value);
	PrimeNumber & operator++();
	PrimeNumber operator++(int);
	PrimeNumber & operator--();
	PrimeNumber operator--(int);

};

// �]�w��l��
PrimeNumber::PrimeNumber()
{
	this->value = 1;
}

// �]�w��l�Ȭ� _value
PrimeNumber::PrimeNumber(int _value)
{
	this->value = _value;
}

int PrimeNumber::get()
{
	return this->value;
}

PrimeNumber& PrimeNumber::operator++()
{
	int count = 0;
	this->value += 1;
	while (this->value < 10000)
	{
		for (int i = 2; i < this->value; i++)
		{
			if (this->value % i != 0)
				count += 1;
		}
		if (count == 0)
			return *this;
		else
			this->value += 1;
	}
}
PrimeNumber PrimeNumber::operator++(int)
{
	int count = 0;
	this->value += 1;
	while (this->value < 10000)
	{
		for (int i = 2; i < this->value; i++)
		{
			if (this->value % i != 0)
				count += 1;
		}
		if (count == 0)
			return *this;
		else
			this->value += 1;
	}
}
PrimeNumber& PrimeNumber::operator--()
{
	int count = 0;
	this->value -= 1;
	while (this->value > -10000)
	{
		for (int i = 2; i < this->value; i++)
		{
			if (this->value % i != 0)
				count += 1;
		}
		if (count == 0)
			return *this;
		else
			this->value -= 1;
	}
}
PrimeNumber PrimeNumber::operator--(int)
{
	int count = 0;
	this->value -= 1;
	while (this->value > -10000)
	{
		for (int i = 2; i < this->value; i++)
		{
			if (this->value % i != 0)
				count += 1;
		}
		if (count == 0)
			return *this;
		else
			this->value -= 1;
	}
}