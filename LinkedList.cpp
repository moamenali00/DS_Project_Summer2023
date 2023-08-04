#include"LinkedList.h"

template<typename T>
LinkedList<T>::LinkedList() {
	Head = nullptr;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
	DeleteAll();
}

template<typename T>
void LinkedList<T>::PrintList()	const
{
	cout << "\nprinting list contents:\n\n";
	Node<T>* p = Head;

	while (p)
	{
		cout << "[ " << p->getItem() << " ]";
		cout << "--->";
		p = p->getNext();
	}
	cout << "*\n";
}

template<typename T>
void LinkedList<T>::PrintKth(int k)
{
	Node<T>* p = Head;
	for (int i = 1; i < k; i++)
	{
		while (p)
		{
			p = p->getNext();
		}
	}
	if (p == nullptr) {
		cout << "Beyond List Length";
		return;
	}
	cout << "the data stored in the node number " << k << " is " << p->getItem();
}

template<typename T>
Node<T>* LinkedList<T>::RemoveMin()
{
	T min = Head->getItem();
	Node<T>* minPtr = Head;
	Node<T>* p = Head;
	while (p) {
		p = p->getNext();
		if (min > p->getItem()) {
			min = p->getItem();
			minPtr = p;
		}
	}
	Node<T>* new = minPtr;
	minPtr = minPtr->getNext();
	return minPtr;
}

template<typename T>
void LinkedList<T>::InsertBeg(const T& data)
{
	Node<T>* R = new Node<T>(data);
	R->setNext(Head);
	Head = R;
}

template<typename T>
void LinkedList<T>::InsertEnd(const T& data)
{
	Node<T>* R = new Node<T>(data);
	Node<T>* p = Head;
	while (p->getNext() != nullptr)
	{
		p = p->getNext();
	}
	p->setNext(R);
}

template<typename T>
void LinkedList<T>::DeleteAll()
{
	Node<T>* P = Head;
	while (Head)
	{
		P = Head->getNext();
		delete Head;
		Head = P;
	}
}

template<typename T>
void LinkedList<T>::DeleteFirst()
{
	Node<T>* P = Head;
	P = Head->getNext();
	delete Head;
	Head = P;
}


template<typename T>
bool LinkedList<T>::DeleteNode(const T& data)
{
	Node<T>* p = Head;
	while (p) {
		if (p->getItem() == data)
		{
			delete p;
			return true;
		}
	}
	return false;
}
