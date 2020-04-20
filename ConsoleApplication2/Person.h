#pragma once
#include <string>
#include "Resource.h"
#include <memory>

class Person
{
private:
	std::string firstname;
	std::string lastname;
	int arbitraryNumber;
	//std::shared_ptr<Resource> pResource;

public:

	Person();
	virtual ~Person();
	
	Person(std::string first, std::string last, int arbitrary);
	virtual std::string GetName() const;
	int GetNumber() const { return arbitraryNumber; }
	void SetNumber(int number) { arbitraryNumber = number; }
	void SetFirstName(std::string first) { firstname = first; }
	
	//void AddResource();
	/*std::string GetResourceName() const
	{
		return pResource ? pResource->GetName() : "";
	}*/


	//bool operator<(Person const& p) const;
	//bool operator<(int i) const;

};

////free frunction
//bool operator<(int i, Person const& p);