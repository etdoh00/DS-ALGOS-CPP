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
	if (pos < 0 || pos > listSize) // check if position is valid
	{
		std::cout << "List element invalid" << std::endl;
	}
	while (p-- > 0) // sets position in list
	{
		pCurrent->pNext // move from current to next on each iteration 
	}
}

template <typename T>
void List<T>::set_first()
{
	pCurrent = pFirst; // current node is now first
}

template <typename T> 
void List<T>::set_last()
{
	pCurrent = pLast; // current node is now last
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
	//create a new listnode object, with item = user item, previous pointer = NULL as it is now first, next pointer is equal to old previous 
	pFirst = new ListNode<T>*(item, NULL, pFirst);
	if (listSize > 0) { pFirst->pNext->pPrev = pFirst; } // if there are other elements in the list, then the first node's next previous element is equal to the first node 

	else 

	{ pLast = pFirst; } // if there are no elements, then the last is the first as there is only one element

	listSize++; // increase size
	return item; // return item added
}

template <typename T> //same logic as insert_front
T List<T>::insert_end(T item)
{
	pLast = new ListNode<T>*(item, pLast, NULL); // difference now is that it is the last, so the nxt pointer is NULL and the previous is now last
	if (listSize > 0) { pLast->pPrev->pNext = pLast; }

	else

	{ insert_front(pLast); } // uses second branch conditional from insert_front

	listSize++;
	return item;
}

template <typename T> //allows the user to insert an element between 0 < pos < listsize
T List<T>::insert(T item, int pos)
{
	if (pos == 0) { insert_front(item); } // front element
	if (pos == listSize) { insert_end(item); } // last element

	setpos(pos); // sets positon to inserrt
	ListNode<T>* pNew = new ListNode<T>*(item, pCurrent->pPrev, pCurrent); // new node that holds the value to be inserted, its previous
	pCurrent->pPrev = pNew;													// value is the current nodes previous and its next is the node it is moving up by 1
	pCurrent->pPrev->pNext = pNew; 
	listSize++; // increase list size
	return item;
}

template <typename T>
T List<T>::remove_front()
{
	if (pFirst != NULL) // checks if there is an element to remove
	{
		T item = pFirst->item; // holds teh value that is going to be removed
		ListNode<T> pValTemp = pFirst->pNext; //holder that holds the value of current +1, which will be the new first
		delete pFirst; // delete old first
		pFirst = pValTemp; // new first is the holder
		if (pFirst != NULL) // if first exists, set the previous pointer to null as it is now first
		{
			pFirst->pPrev = NULL;			
		}
		listSize--; // shrink size
		if (listSize == 0)
		{
			pLast = NULL; // if list = 0, there wil be no last
		}
	}
	return item;
}

template <typename T>
T List<T>::remove_end()
{
	if (listSize == 1) { remove_front(); }

	if (pLast != NULL)// same logic as before only with last
	{
		T item = pLast->item; 
		ListNode<T>* pValTemp = pLast->pPrev;
		delete pLast;
		pLast = pValTemp;
		pLast->pNext = NULL;
		listSize--;

	}
	return item;
}

template <typename T>
T List<T>::remove(int pos)
{
	if (pos == 0) { remove_front(); } // checks postion, faster execution 
	if (pos == listSize) { remove_end(); }

	setpos(p);
	pCurrent->pPrev->pNext = pCurrent->pNext; // the current nodes previous next node, is equal to current node's next node  [PREV] -- [CURRENT] -- [NEXT]
	pCurrent->pNext->pPrev = pCurrent->pPrev; // the current nodes next pervious node, is equal to current node's previous node  [PREV] -- [CURRENT] -- [NEXT]
	T item = pCurrent->item; // holds item
	delete pCurrent; // delete node
	listSize--; // shrink size

	return item;
}

template <typename T>
T List<T>::get(int pos)
{
	setpos(pos); // returns item at given pos
	return pCurrent->item;
}

template <typename T>
T List<T>::get_next()
{
	while (pCurrent != NULL)
	{
		T item = pCurrent->item;
		pCurrent = pCurrent->pNext;
		return item; // returns item for eahc iteration of pcurrent -> pnext
	}
}

template <typename T>
T List<T>::get_prev() //same logic as above
{
	while (pCurrent != NULL)
	{
		T item = pCurrent->item;
		pCurrent = pCurrent->pPrev;
		return item;
	}
}

