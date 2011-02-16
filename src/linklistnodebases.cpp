#include "../include/linklistnodebases.h"

/////////////////////////  for class SimpleLinkedListNodeBase //////////////////

template <class T>
SimpleLinkedListNodeBase<T>::SimpleLinkedListNodeBase()
			:_node(NULL),
			_next(NULL)
{

}

template <class T>
SimpleLinkedListNodeBase<T>::SimpleLinkedListNodeBase(T& node, SimpleLinkedListNodeBase<T>* next)
{
	_node = &node;
	_next = next;
}

template <class T>
SimpleLinkedListNodeBase<T>::SimpleLinkedListNodeBase(const SimpleLinkedListNodeBase<T>& copy)
{
	_node = copy.nodePtr();
	_next = copy.nextNode();
}

template <class T>
SimpleLinkedListNodeBase<T>::~SimpleLinkedListNodeBase()
{
	_node = NULL;
	_next = NULL;
}

template <class T>
SimpleLinkedListNodeBase<T>* SimpleLinkedListNodeBase<T>::nextNode()
{
	return _next;
}

template <class T>
T& SimpleLinkedListNodeBase<T>::data()
{
	return *_node;
}

template <class T>
T* SimpleLinkedListNodeBase<T>::nodePtr()
{
	return _node;
}

template <class T>
void SimpleLinkedListNodeBase<T>::setNextNode(SimpleLinkedListNodeBase<T>* next)
{
	_next = next;
}

template <class T>
SimpleLinkedListNodeBase<T> SimpleLinkedListNodeBase<T>::operator = (const SimpleLinkedListNodeBase<T>& node)
{
	return SimpleLinkedListNodeBase<T>(node);
}


/////////////////////////  for class DoubleLinkedListNodeBase //////////////////

template <class T>
DoubleLinkedListNodeBase<T>::DoubleLinkedListNodeBase()
						:SimpleLinkedListNodeBase<T>(),
						_prior(NULL)
{

};

template <class T>
DoubleLinkedListNodeBase<T>::DoubleLinkedListNodeBase(T& node, DoubleLinkedListNodeBase<T>* next, DoubleLinkedListNodeBase<T>* prior)
					: SimpleLinkedListNodeBase<T>(node,next),
					  _prior(prior)
{

}

template <class T>
DoubleLinkedListNodeBase<T>::DoubleLinkedListNodeBase(const DoubleLinkedListNodeBase<T>& copy)
						:SimpleLinkedListNodeBase<T>(copy)
{
	_prior = copy.priorNode();
}

template <class T>
DoubleLinkedListNodeBase<T>* DoubleLinkedListNodeBase<T>::priorNode()
{
	return _prior;
}

template <class T>
void DoubleLinkedListNodeBase<T>::setPriorNode(DoubleLinkedListNodeBase<T>* prior)
{
	_prior = prior;
}


/// main function for test

#include <stdio.h>

int main(int argc, char** argv)
{
	int data = 12530;
	SimpleLinkedListNodeBase<int> node(data);
	printf("node data : %d\n",node.data());
}

