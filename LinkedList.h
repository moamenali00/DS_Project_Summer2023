#pragma once


#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
class LinkedList
{
private:
	Node<T>* Head;
public:


	LinkedList();
	~LinkedList();

	void PrintList()	const;
	void PrintKth(int k);
	

	Node<T>* RemoveMin();
	void InsertBeg(const T& data);
	void InsertEnd(const T& data);

	void DeleteAll();
	void DeleteFirst();
	bool DeleteNode(const T& data);

};

