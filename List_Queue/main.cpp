#include <iostream>
#include "QueueList.h"
#include <windows.h>
using namespace std;


int main() {
	QueueList<int> lt;

	lt.Fill(9); 
	cout << "   --Creating.." << endl;;
	lt.Print();
	lt.AddTail(15);
	cout << "   --Adding.." << endl;;
	lt.Print(); 
	lt.Del();
	cout << "   --Substracting.." << endl;
	lt.Print(); 

	QueueList<int> lt2;
	lt2 = lt;

	cout << "   -Assignmenting.." << endl;
	lt2.Print();
	cout << endl;
	system("pause");


	for (int i = 0; i < 9; i++)
	{
		Sleep(100);
		lt.Print();
		lt.Del();
	}


	return 0;
}