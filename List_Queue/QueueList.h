#pragma once
using namespace std;
#include <iostream>

template <typename T>
struct Node
{
	T data;
	Node* next, * prev;
};

template <typename T>
class QueueList
{
	Node<T>* Head, * Tail;
	int Count;

public:
	QueueList();
	void Del();				//Deletes the first element in the queue
	void DelAll();			//Deletes all queue
	void AddTail(T);		//Adds a new element in the queue
	void Random();			//Random function.
	void Fill(int numbers); //Creates and fills the specific amount of queue elements using Random() function.
	void Print() const;		//Prints all the queue
	int GetCount()const;	//Returns count of elements.
	bool IsEmpty()const;	//Checks if the queue is empty
	T GetFirst()const;		//Returns first element in the queue
	
	QueueList<T>& operator=(const  QueueList<T> &oldList) {
		if (this == &oldList)			
			return *this;

		this->~QueueList<T>();				//Deleting current List data.

		Node<T>* temp = oldList.Head;	//Creating temp that saves oldList.Head pointer
		while (temp!=0)					//While there are elemets in oldList
		{
			AddTail(temp->data);		//Adding new elements to the current list and filling them with temp->data
			temp = temp->next;			//Moving forward with temp.
		}

		return *this;
	}
	~QueueList();
};

template<typename T>
QueueList<T>::QueueList() {
	Head = Tail = NULL;
	Count = 0;
}


template<typename T>
void  QueueList<T>::Del()
{
	if (GetCount() == 1) Head = Tail = 0; Count = 0;//If there is only one node left, will just delete node completely.
	if (Head == NULL)return;					//If head pointer is NULL, returns.
	Node<T>* temp = Head;						//Creating temp for saving Head pointer to delete it later
	Node<T>* AfterDel = temp->next;				//Creating AfterDel to save pointer to the next element after head.
	Head = AfterDel;							//Assign Head pointer with AfterDel. Now Head pointer is the next element.
	delete temp;								//Deleting the first element.
	Count--;
}



template<typename T>
void  QueueList<T>::DelAll()
{
	while (Count!= 0)
	{
		Del();
	}
}

template<typename T>
void  QueueList<T>::AddTail(T data)
{
	Node<T>* temp = new Node<T>;				

	temp->next = NULL;
	temp->data = data;
	temp->prev = Tail;

	if (Tail != 0)
		Tail->next = temp;

	if (Count == 0)
		Head = Tail = temp;
	else
		Tail = temp;

	Count++;
}

template<typename T>
void  QueueList<T>::Random()
{
	Node<T>* temp = Head;

	while (temp!=0)
	{
		temp->data = (rand() % 256) / 1.6;
	}
}

template<typename T>
void  QueueList<T>::Fill(int numbers)
{
	for (int i = 0; i < numbers; i++)
	{
		AddTail((rand() % 256) / 1.6);
	}
}

template<typename T>
void  QueueList<T>::Print()const
{
	Node<T>* temp = Head;
	while (temp != 0)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;

}

template<typename T>
int  QueueList<T>::GetCount() const
{
	return Count;
}

template<typename T>
bool  QueueList<T>::IsEmpty() const
{
	if (GetCount() == 0) return 1;
	else return 0;
}

template<typename T>
T QueueList<T>::GetFirst() const
{
	return Head->data;
}

template<typename T>
QueueList<T>::~QueueList() {
	DelAll();
}