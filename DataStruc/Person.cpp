#include "Person.h"

//--------------------------------------------------------------------------------//
Person::Person(int id, const string fullName)
{
	setId(id);
	setFullName(fullName);
}
//--------------------------------------------------------------------------------//
void Person::setId(const int id)
{
	this->m_id = id;
}
//--------------------------------------------------------------------------------//
void Person::setFullName(const string fullName)
{
	this->m_fullName = fullName;
}
//--------------------------------------------------------------------------------//
int Person::getId() const
{
	return this->m_id;
}
//--------------------------------------------------------------------------------//
string Person::getFullName() const
{
	return this->m_fullName;
}
//--------------------------------------------------------------------------------//
bool Person::operator<(const Person & other) const
{
	return this->m_id < other.m_id;
}
//--------------------------------------------------------------------------------//
bool Person::operator==(const Person & other) const
{
	return this->m_id == other.m_id;
}
//--------------------------------------------------------------------------------//
bool Person::operator>(const Person & other) const
{
	return (!(*this < other) && !(*this == other));
}
//--------------------------------------------------------------------------------//
const Person & Person::operator=(const Person & other)
{
	if (this != &other)
	{
		this->m_id = other.m_id;
		this->m_fullName = other.m_fullName;
	}

	return *this;
}
//--------------------------------------------------------------------------------//
ostream & operator<<(ostream & os, const Person & person)
{
	os << person.m_id << " " << person.m_fullName;
	return os;
}
