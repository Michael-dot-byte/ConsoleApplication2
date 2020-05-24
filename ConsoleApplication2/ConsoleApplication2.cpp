#pragma once
#include "Resource.h"
#include <vector>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include "Person.h"
#include <fstream>
#include <ostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <random>
#include "Employee.h"
#include <numeric>
#include "Person.h"
#include <set>
#include "Point2D.h"
#include <map>
#include <cassert>

using namespace std;
using std::vector;
using std::cout;

//operator overload
/*ostream& operator<<(ostream& os, const vector<int>& v)
{
	os << "[ ";
	for (auto x : v)
	{
		os << x << ' ';
	}
	os << ']';

	return os;
}*/

//maps
/*use find for maps
void PrintC64Memory(map<string, int> const& memory) {
	auto it = memory.find("C64");
	//assert(it != memory.end());
	
	cout << "The C64 has " << it->second;
}

//used for maps
struct Airport
{
	string Name{};
	string City{};
	string Country{};
	double Latitude{};
	double Longitude{};
	int AltitudeFeet{};

	Airport() = default;
	Airport(string const& name, string const& city, string const& country,
		double latitude, double longitude, int altitudeFeet) :
		Name(name), City(city), Country(country), Latitude(latitude),
		Longitude(longitude), AltitudeFeet(altitudeFeet){}

};*/

//Interfaces
/*class MyAbstractClass {
public:
	virtual void print() = 0;
};

class MyDerivedClass : public MyAbstractClass {
public:
	void print() override {
		cout << "OK";
	}
};*/

//Arrays
/*//4.Klasse f�r Fehlerhandling
class IndexOutOfBoundsException {};

//Arrays
class IntArray {
private:
	int* m_ptr{ nullptr };	//Pointer towards memory location of defined elements 
							//- defined in constructor
	int m_size{ 0 };
public:
	IntArray() = default;

	explicit IntArray(int size) {
		if (size != 0)
		{
			//Allocating memory on heap
			m_ptr = new int[size] {};
			m_size = size;
		}
	}

	//1.Destructor needed to avoid memory leaks
	~IntArray() {
		delete[] m_ptr;
	}

	//2.Operator overload to access elements of array even when m_ptr is private
	//write access (by ref)
	int& operator[](int index) {
		if (! IsValidIndex(index))
		{
			throw IndexOutOfBoundsException{};
		}
		//return element at index
		return m_ptr[index];		
	}

	//read access by value
	int operator[](int index) const {
		if (!IsValidIndex(index))
		{
			throw IndexOutOfBoundsException();
		}
		return m_ptr[index];
	}

	//don't change values in the class -> const
	int Size() const {
		return m_size;
	}

	bool IsEmpty() const {
		return (m_size == 0);
	}

	//3.Bounds Checking
	bool IsValidIndex(int index) const {
		return (index >= 0) && (index < m_size);
	}
};

inline bool operator<(const Point2D pointA, const Point2D pointB)
{	
	return pointA.Length() < pointB.Length();
}
*/

//Binary searching
int BinarySearch(int element, const int* v, int size) {
	int left = 0;
	int right = size - 1;
	int kNotFound = -1;

	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (v[middle] == element)
		{
			return middle;
		}
		else if (v[middle] < element)
		{
			left = middle + 1;		
		}
		else if (v[middle] > element)
		{
			right = middle - 1;
		}
	}
	return kNotFound;
}

int main()
{
	//Array
	/*IntArray a{};
	int aSize = a.Size();
	//wenn Ergebnis in IsEmpty == true l�uft Programm weiter, sonst Abbruch
	assert(a.IsEmpty());

	IntArray b{ 10 };
	for (int i = 0; i < b.Size(); i++)
	{
		b[i] = i + 1;
	}
	
	int bSize = b.Size();
	assert(!b.IsEmpty());
	int testVal = b[4];*/
	
	//Interfaces and virtual
	/*//Instanziierung der reinen virtual (abstract) class not allowed
	//MyAbstractClass a;

	//Die erbende Klasse muss die virtual Function implementieren
	MyDerivedClass d;
	d.print();*/
	
	//Initial Commit
	#pragma region Initial commit

		/*Accum<int> integers(0);
		integers += 3;
		integers += 7;

		cout << integers.GetTotal() << endl;

		Accum<string> strings("");
		strings += "hello";
		strings += " world";
		cout << strings.GetTotal() << endl;
		
		Accum<Person> people(0);	
		Person p1("Michael", "Ploessner", 123);
		Person p2("Someone", "Else", 456);
	
		people += p1;
		people += p2;
		cout << people.GetTotal() << endl;

		{
			Person Mike("Mike", "PL", 111);
			Mike.AddResource();
		}*/
	
		//Person Kate("Kate", "Gregory", 456);
		//Person& rKate = Kate;
		//Person* pKate = &Kate;

		//Tweeter KateGregcons("Kate", "Gregory", 567, "@gregcons");
		//Person* pKateGregcons = &KateGregcons;
		//Person& rpKateGregcons = KateGregcons;
		//Tweeter& rtKateGregcons = KateGregcons;

		//cout << rKate.GetName() << endl;
		//cout << pKate->GetName() << endl;
		//cout << KateGregcons.GetName() << endl;
		//cout << rpKateGregcons.GetName() << endl;
		//cout << rtKateGregcons.GetName() << endl;
		//cout << pKateGregcons->GetName() << endl;
	
		/*vector<int> numbers{ 0,1,2 };
		numbers.push_back(-2);
		numbers[0] = 3;
		int num = numbers[2];

		for (int i:numbers)
		{
			cout << i << '\n';
		}

		Resource r("local");
		{
			cout << "----------------------" << "\n";
			vector<Resource> resources;
			resources.push_back(r);
			cout << "----------------------" << "\n";
			resources.push_back(Resource("first"));
			cout << "----------------------" << "\n";
			resources.push_back(Resource("second"));
			cout << "----------------------" << "\n";

		}*/

		/*
		auto isOdd = [](int candidate) {return candidate % 2 != 0; };

		bool is3Odd = isOdd(3);
		bool is4Odd = isOdd(4);

		vector<int> nums{ 2,3,4,-1,1 };

		int odds = std::count_if(begin(nums), end(nums), isOdd);

		int evens = std::count_if(begin(nums), end(nums),
			[](int candidate) {return candidate % 2 == 0; });

		//capturing by value and ref explicitly [x,y,&message]
		int x = 3;
		int y = 7;

		string message = "elements between ";
		message += std::to_string(x) + " and	" + std::to_string(y) + " inclusive :";
		for_each(begin(nums), end(nums),
			[x, y, &message](int n)
			{
				if (n >= x && n <= y)
					message += " " + std::to_string(n);
			});

		vector<int> v;

		for (int i = 0; i < 5; i++)
		{
			v.push_back(i);
		}

		for (int i = 0; i < 5; )
		{
			v.push_back(i++);
		}

		int i = 0;
		std::generate_n(std::back_inserter(v), 5, [&]() {return i++; });

		auto endv4 = std::remove_if(begin(v), end(v),
			[](int elem) {return (elem == 3); });
		v.erase(endv4, end(v));
		*/

		/*vector<int> v;
		v.push_back(1);
		try
		{
			Person Mike("Mike", "Pl", 0);
			int j = v.at(99);

		}
		catch (out_of_range& e)
		{
			cout << " out of range exeption " << e.what();
		}
		catch (exception & e)
		{
			cout << e.what();
		}*/

		/*vector<string> lines{};

		std::ifstream inputFile{ "Debug/data.txt" };
		string line{};

		while (getline(inputFile,line))
		{
			lines.push_back(line);
		}

		std::sort(begin(lines), end(lines));
		std::sort(begin(lines), end(lines),
			[](auto const& a, auto const& b)
			{return a.length() < b.length(); });

		for (const auto& line : lines)
		{
			std::cout << line << '\n';
		}*/

		/*vector<Person> persons {
			{"Mike", "PL", 23},
			{ "Tim", "hen", 55 },
			{ "Test", "Test", 44 }
		};

		persons.reserve(10);

		persons.push_back(Person{ "John", "Meayer", 99 });

		for (const auto& p: persons)
		{
			cout << p.GetName() << p.GetNumber() << endl;
		}

		cout << persons.capacity() << endl;
		cout << persons.size() << endl;*/

		/*vector<int> v{ 11,22,33,44,55,66 };
		cout << " Initial vecotr: " << v << "\n\n";
	
		cout << " Insterting a single element (99): \n";
		v.insert(begin(v) + 1, 99);
		cout << "    " << v << "\n\n";

		cout << " Inserting 3 copies of 100: \n";
		v.insert(begin(v) + 2, 3, 100);
		cout << "      " << v << "\n\n";

		vector<int> source{ +11,+22,+33 };
		cout << " Inserting values form source range: \n";
		v.insert(begin(v) + 1, begin(source), end(source));
		cout << "    " << v << "\n\n";

		cout << " Inserting values from initializer list: \n";
		v.insert(begin(v) + 4, { 111,222,333 });
		cout << "    " << v << "\n\n";*/
	
		/*v.erase(std::remove_if(begin(v), end(v),
			[](auto const& a)
			{return a % 2 != 0; }), end(v));
	
		cout << "Removed: " << endl << v << endl;*/

		/*auto pos = std::find(begin(lines), end(lines), "57");
		if (pos == end(lines))
		{
			cout << "Object not found";
		}
		else
		{
			cout << "object found";
		}*/

		/*int twos = 0;
		int odds = 0;
		int const target = 2;

		twos = count(begin(v), end(v), target);
		odds = count_if(begin(v), end(v),
			[](auto elem)
			{ return elem % 2 == 1; });

		map<int, int> monthlengths{ {1,31},{2,28},{3,31},{4,30},
			{5,31},{6,30},{7,31},{8,30},{9,31},{10,30},{11,31},{12,30} };

		int longmonths = count_if(begin(monthlengths), end(monthlengths),
			[](auto elem) { return elem.second == 31; });

		auto result = find(begin(v), end(v), 0);
		int weLookedFor = *result;

		result = find(result, end(v), 2);

		result = find_if(begin(v), end(v),
			[](auto elem)
			{ return elem % 2 != 0; });
		weLookedFor = *result;

		vector<int> subsequence{ 0,19 };
		result = search(begin(v), end(v), begin(subsequence), end(subsequence));
		weLookedFor = *result;

		string s = "I am a sentence!";
		string am = "am";

		auto letter = search(begin(s), end(s), begin(am), end(am));
		char a = *letter;

		result = search_n(begin(v), end(v), 2, 4);
		int test = *--result;*/

		/*vector<int> v{ 2,-5,4,4,-6,1,6,2,-2,4,0,-19,2,7,4,4,6,1,6,2 };
		auto v2 = v;

		int high = *(max_element(begin(v2), end(v2)));
		int low = *(min_element(begin(v2), end(v2)));
		sort(begin(v2), end(v2));

		random_device randomDevice;
		mt19937 generator(randomDevice());

		shuffle(begin(v2), end(v2), generator);

		low = *begin(v2);
		high = *(end(v2) - 1);
		int positiv = *upper_bound(begin(v2), end(v2), 0);

		partial_sort(begin(v2), find(begin(v2), end(v2), 4), end(v2));

		vector<int> v3(3);
		partial_sort_copy(begin(v), end(v), begin(v3), end(v3));

		v2 = { 1,5,4,2,9,7,3,8,2 };
		int i = *(begin(v2) + 4);
		nth_element(begin(v2), begin(v2) + 4, end(v2));
		i = *(begin(v2) + 4);

		sort(begin(v2), end(v2),
			[](int elem1, int elem2) { return elem1 > elem2; });
		sort(begin(v2), end(v2),
			[](int elem1, int elem2) { return abs(elem1) > abs(elem2); });

		std::vector<Employee> staff{
			{"Kate","Gregory",1000},
			{"Obvious","Artificial",2000},
			{"Fake","Name",1000},
			{"Alan","Turing",2000},
			{"Grace","Hopper",2000},
			{"Anita","Borg",2000}
		};*/

		//sort(begin(staff), end(staff),
		//	[](Employee e1, Employee e2)
		//	{return e1.getSalary() < e2.getSalary(); });

		/*sort(begin(staff), end(staff), [](Employee e1, Employee e2)
			{ return e1.getSortingName() < e2.getSortingName(); });

		auto p = lower_bound(begin(staff), end(staff), "Gregory, Kate",
			[](Employee e1, string n) { return e1.getSortingName() < n; });
		int sal = p->getSalary();

		std::stable_sort(begin(staff), end(staff), [](Employee e1, Employee e2)
			{return e1.getSalary() < e2.getSalary(); });

		auto sorted = is_sorted(begin(v2), end(v2));
		sorted = is_sorted(begin(v2), end(v2), [](int elem1, int elem2)
			{return abs(elem1) > abs(elem2); });*/

		/*vector<int> a{ 1,2,3,4,5 };
		vector<int> b{ 1,2,0,4,5 };

		bool same = equal(begin(a), end(a), begin(b), end(b));

		auto misPair = mismatch(begin(a), end(a), begin(b));

		int aValue = *(misPair.first);
		int bValue = *(misPair.second);

		int total = 0;
		total = accumulate(begin(a), end(a), 0);
		total = accumulate(begin(a), end(a), 0,
			[](int total, int i) { if (i % 2 == 0) return total + i; return total; });

		vector<string> words{ "one","two","three" };
		auto allwords = accumulate(begin(words), end(words), string{},
			[](const string& total, string s) { return total + " " + s; });*/

		/*vector<int> source{ 3,6,1,0,-2,5 };
		vector<int> v2(source.size());

		copy(begin(source), end(source), begin(v2));

		auto v3 = source;

		auto position = find(begin(source), end(source), 1);
		vector<int> v4(source.size());
		copy(begin(source), position, begin(v4));

		vector<int> v5(source.size());
		//copy_if(begin(source), end(source), begin(v5),
		//	[](int elem) {return elem%2==0;	});
	
		copy_n(begin(v5), 3, begin(v2));
		copy_backward(begin(v3), end(v3), end(source));

		auto newEnd = remove(begin(source), end(source), 3);
		int s = source.size();
		int logicalSize = newEnd - begin(source);
		source.erase(newEnd, end(source));

		source = v3;
		source.erase(remove(begin(source), end(source), 3), end(source));

	
		vector<int> v6(10);
		fill(begin(v6), end(v6), 1);
		fill_n(begin(v6), 6, 2);
		iota(begin(v6), end(v6), 1);

		int index = 10;
		generate(begin(v6), end(v6), [&index]() {return --index;  });

		index = 1;
		generate_n(begin(v6), 7,
			[&index]() {return index *= 2; });


		replace(begin(v6), end(v6), 2, 7);
		replace_if(begin(v6), end(v6), [](int elem) {return elem < 16; }, 7);

		iota(begin(source), end(source), 1);
		transform(begin(source), end(source), begin(source), [](int elem)
			{ return elem * 2; });
		transform(begin(source), end(source) - 1, begin(source) + 1, begin(v6),
			[](int elem1, int elem2) {return elem2 - elem1; });

		iota(begin(v6), end(v6), 1);
		iota(begin(source), end(source), 2);
		vector<int> v7(10);
		transform(begin(source), end(source), begin(v6), begin(v7),
		[](int elem1, int elem2) {return elem1 + elem2; });

		unique(begin(v2), end(v2));
		v2[3] = -2;
		auto v8 = v2;
		v2.erase(unique(begin(v2), end(v2)), end(v2));
		unique_copy(begin(v8), end(v8), begin(v7));

		string sentence = "Hello World!";
		reverse(begin(sentence), end(sentence));

		iter_swap(begin(v7), end(v7) - 1);

		string orig = "                  ";
		reverse_copy(begin(sentence), end(sentence), begin(orig));*/

	#pragma endregion

	//read from file (string)
	/*std::vector<string> lines{};

	std::ifstream inputFile{ "C:\\Users\\ploes\\Desktop\\05_Lebensstil\\06_Weiterbildung\\05_Programmierung\\C++\\ConsoleApplication2\\data.txt.txt" };
	//int n{};
	string line{};
	while (getline(inputFile, line))
	{
		lines.push_back(line);
	}
	for (const auto& x:lines)
	{
		cout << x << endl;
	}*/

	//Vector of own classes
	/*vector<Person> persons{ {"Conni", "Klaus", 30},
		{"Mike", "PL", 28},{"Peter", "Mehr", 40} };

	persons.push_back(Person{ "John","Oliver",55 });
	for (const auto& p:persons)
	{
		cout << p.GetName() << endl;
	}
	
	return 0;*/

	//storing unique objects with set
	/*//in sorted order (no duplicates allowed)
	set<string> colors{ "red","yellow","red", "blue" };
	colors.insert("green");
	colors.insert("green");
	colors.erase("red");
	auto it = colors.find("blue");

	//set with custom classes
	set<Point2D> points{ {20,30},{22,33},{2,3} };
	points.insert(Point2D{ 10,20 });*/

	//std::map; sorted order of key-value pair
	/*map<int, string> numbers{
		{1,"one"},{2,"two"},
		{30,"thirty"},{41,"fourtyone"}, 
		{4,"four"},{5,"five"}
	};
	numbers[2] = "modifiedTwo";
	for (const auto& [key, value] : numbers) {
		std::cout << key << " has value " << value << std::endl;
	}

	for (const auto& kv : numbers) {
		std::cout << kv.first << " has value " << kv.second << std::endl;
	}

	map<string, int> computerMemoryKB{};
	computerMemoryKB["C64"] = 64;
	computerMemoryKB["Amiga 500"] = 512;
	PrintC64Memory(computerMemoryKB);

	std::map<string, string> dictonary{
		{"hello", "ciao"},
		{"good morning", "buon giorno"},
		{"good eventing", "buona sera"},
		{"church", "chiesa"},
		{"ice cream", "gelato"}
	};

	dictonary.insert({ "museum", "museo" });
	dictonary.insert({ "how much?", "quanto" });

	for (auto const& kv : dictonary)
	{
		cout << kv.first << " = " << kv.second << endl;
	};

	map<string, Airport> airportDatabase{
		{"SEA",
			{"Seattle International", "Seattle", "United States", 47.449,
			-122.300, 433}},
		{"LAX",
			{"Los Angeles International", "LA", "United States",
			33.9425, -118, 125}},
		{"FCO",
			{"Leonardo da Vinci", "Rome", "Italy",
			41.800, 12.45324, 13}}
	};

	cout << "Enter Code" << endl;
	string code{};
	cin >> code;

	auto it = airportDatabase.find(code);
	if (it != end(airportDatabase))
	{
		Airport const& airport = it->second;
		cout << airport.Name << '\n';
		cout << airport.City << '\n';
		cout << airport.AltitudeFeet << '\n';
	}*/

	//Efficient searching
	//Binary searching ; O(log(N))
	vector<int> v{ 11,22,33,44,55,66 };
	int pos = BinarySearch(55, v.data(), v.size());

	
	return 0;
}

