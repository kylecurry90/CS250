//@author Kyle Curry

#include <iostream>
#include <list>
#include <string>
using namespace std;

void AddCourses(list<string>& courses)
{
	courses.push_front("CS 250");
	courses.push_front("CS 200");
	courses.push_front("CS 210");
	courses.push_front("CS 235");
	courses.push_front("CS 134");
	courses.push_front("CS 211");
}

void SortList(list<string>& courses)
{
	courses.sort();
}

void ReverseList(list<string>& courses)
{
	courses.reverse();
}

void DisplayCourses(list<string>& courses)
{
	int counter = 0;
	//This is how we have to iterate thru a list.
	for (list<string>::iterator it = courses.begin();
		it != courses.end(); it++)
	{
		if (counter != 0) { cout << ", "; }
		cout << counter++ << ". " << (*it);
	}
}

int main()
{
	list<string> courses;
	AddCourses(courses);
	DisplayCourses(courses);

	SortList(courses);
	DisplayCourses(courses);

	ReverseList(courses);
	DisplayCourses(courses);

	return 0;
}