#include <iostream>
#include <list>
#include <string>
using namespace std;

void AddCourses(list<string>& courses)
{
	courses.push_front("cs 250");
	courses.push_front("cs 200");
	courses.push_front("cs 210");

	courses.push_back("cs 235");
	courses.push_back("cs 134");
	courses.push_back("cs 211");
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
	

	cout << "Normal order" << endl;
	AddCourses(courses);
	DisplayCourses(courses);
	cout << endl << "Sorted order" << endl;
	SortList(courses);
	DisplayCourses(courses);
	cout << endl << "Reverse order" << endl;
	ReverseList(courses);
	DisplayCourses(courses);
	cout << endl;

	return 0;
}
