#pragma once
using namespace std;
#include <string>

class Item
{
public:
	Item(string name, int age, int idNumber);
	~Item();
	string getName() { return name; }
	int getAge() { return age; }
	int getIDNumber() { return idNumber; }

	friend bool operator< (const Item& left, const Item& right) { return left.age < right.age;}
	friend bool operator> (const Item& left, const Item& right) { return right < left; }
	friend bool operator<=(const Item& left, const Item& right) { return !(left > right); }
	friend bool operator>=(const Item& left, const Item& right) { return !(left < right); }

	friend ostream& operator<<(ostream& out, const Item& item);

private:
	string name;
	int age;
	int idNumber;
};

