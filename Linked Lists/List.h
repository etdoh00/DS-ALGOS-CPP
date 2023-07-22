#pragma once
#define LIST_H
#include "ListNode.h"
#include <iostream>

template<typename T> 
class List
{
public:
	List(); // constructor initalising the pointers
	~List(); // deconstructor to free memory after list is no longer used

	T insert_front(T item); // insert an element at the front, no poistion needed due to set function
	T insert_end(T item); // same as insert_front, only it inserts at the end
	T insert(T item, int pos); // insert element at any point using pos 

	T remove_front(); // functions are the same as insert functions, only with no function parameters - nothing is added so not needed
	T remove_end(); // includes delete 
	T remove(int pos); // remove element at position pos

	T get(int p); // get element at position p 
	T get_next(); // return current node and increment to pCurrent -> pNext
	T get_prev();// return current node and decrement to pCurrent -> pPrev

	void setpos(int pos); // set the position in linked list using pos
	void set_first(); // set pCurrent = pFirst
	void set_last(); // set pCurrent = pLast

	int size() {
		return listSize;
	}

private:
	ListNode<T>* pCurrent, * pFirst, * pLast;
	int listSize; 
};

template < typename T>
void List<T>::setpos(int pos)
{
	if (pos < 0 || pos > listSize)
	{
		std::cout << "List element invalid" << std::endl;
	}
	while (p-- > 0)
	{
		pCurrent->pNext
	}
}

template <typename T>
void List<T>::set_first()
{
	pCurrent = pFirst;
}

template <typename T> 
void List<T>::set_last()
{
	pCurrent = pLast;
}
template < typename T>
List<T>::List() //simple construction of list object, all pointers are set to NULL as the ListNode will have three poitners (NULL)<--ListNode(NULL)-->(NULL)
{
	pCurrent = pLast = pFirst = NULL;
	listSize = 0; 

}
template <typename T>
List<T>::~List() //using traversal from beginning, as list object is created with two null pointers in either direction, incremenet the list until a NULL pointer is met
{
	pCurrent = pFirst; //start incrementing from the first list element
	while (pCurrent != NULL) // incremenet until the end
	{
		ListNode<T>* pNew = pCurrent->pNext; // pNew will be pCurrent + 1, so will represent the next node
		delete pCurrent; // delete the current node
		pCurrent = pNew; // new current node = current node + 1, then iterate 

	}
}

template <typename T>
T List<T>::insert_front(T item)
{

	pFirst = new ListNode<T>*(item, NULL, pFirst);
	if (listSize > 0) { pFirst->pNext->pPrev = pFirst; }

	else 

	{ pLast = pFirst; }

	listSize++;
	return item;
}

template <typename T>
T List<T>::insert_end(T item)
{
	pLast = new ListNode<T>*(item, pLast, NULL);
	if (listSize > 0) { pLast->pPrev->pNext = pLast; }

	else

	{ insert_front(pLast); }

	listSize++;
	return item;
}

template <typename T>
T List<T>::insert(T item, int pos)
{
	if (pos == 0) { insert_front(item); }
	if (pos == listSize) { insert_end(item); }

	setpos(pos);
	pNew = new ListNode<T>*(item, pCurrent->pPrev, pCurrent);
	pCurrent->pPrev = pNew;
	pCurrent->pPrev->pNext = pNew; 
	listSize++;
	return item;
}

template <typename T>
T List<T>::remove_front()
{
	if (pFirst != NULL)
	{
		T item = pFirst->item;
		 
		delete pFirst;
		pFirst = 
	}

}







