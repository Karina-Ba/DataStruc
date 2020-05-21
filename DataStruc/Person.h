#ifndef __PERSON_
#define __PERSON_

#include "Utils.h"

class Person
{
private:
	string m_fullName;
	int   m_id;

public:
	//C'tors
	Person(int id, const string fullName);
	Person(const Person& other) = delete;
	Person(Person&& other) = delete;
	~Person() = default;

	//Set functions
	void setId(const int id);
	void setFullName(const string fullName);

	//Get functions
	int   getId() const;
	string getFullName() const;

	//Operators
	bool operator <  (const Person& other)const;
	bool operator == (const Person& other)const;
	bool operator >  (const Person& other)const;
	bool operator >=  (const Person& other)const;
	const Person& operator=(const Person& other);
	friend ostream& operator << (ostream& os, const Person& person);

};

#endif //!__PERSON_

