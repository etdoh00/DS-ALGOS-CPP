#pragma once
#define LIST_NODE_H

template <typename T>
class ListNode
{
public: 
	ListNode<T>(T nodeItem, ListNode<T>* pPrev, ListNode<T>* pNext);
	T item;
	ListNode<T>* pPrev, pNext;


private:
};
template<typename T>
	ListNode<T>::ListNode(T nodeItem, ListNode<T>* pPrev, ListNode<T>* pNext)
		:item(nodeItem), pPrev(pPrev), pNext(pNext)
{
}



