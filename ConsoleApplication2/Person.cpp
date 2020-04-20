#pragma once
#include "Person.h"
#include <iostream>

using namespace std;

Person::Person() : firstname(""), lastname(""), arbitraryNumber(-1)
{
}

Person::Person(std :: string first, std::string last, int arbitrary) :
	firstname(first), lastname(last), arbitraryNumber(arbitrary)
{
	if (arbitraryNumber == 0)
	{
		throw invalid_argument("Arbitrary number for a person cannot be zero.");
	}
}

Person::~Person()
{	
}

string Person::GetName() const
{
	return firstname + " " + lastname;
}

//void Person::AddResource()
//{
//	pResource.reset();
//	pResource = std::make_shared<Resource>("Resource for " + GetName());
//}
//
//bool Person:: operator<(Person const& p) const
//{
//	return arbitraryNumber < p.arbitraryNumber;
//}
//
//bool Person::operator<(int i) const
//{
//	return arbitraryNumber < i;
//}
//
//bool operator<(int i, Person const& p)
//{
//	return i < p.GetNumber();
//}