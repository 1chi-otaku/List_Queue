#include <iostream>
#include "QueueList.h"
using namespace std;


int main() {
	List<int> lt;

	lt.Fill(10);

	lt.Print();


	List<int> l2;


	l2 = lt;

	l2.Print();




	return 0;
}