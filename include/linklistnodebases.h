/*
 * file	        : LinkedListNodeBases
 * description  : link list node base classes
 * author       : Raiden
 * date         : 2011-02-16
 * version      : 0.1.0
 */

#ifndef LINKLISTNODEBASES_H
#define LINKLISTNODEBASES_H

///
//	class		: SimpleLinkedListNodeBase
//	description	: simple link list node base class consists with data and 'next' ptr
//


#include <stdlib.h>

template <class T>
class SimpleLinkedListNodeBase
{
public:
	/// construct and deconstruct funs
	SimpleLinkedListNodeBase(void);
        SimpleLinkedListNodeBase(T node,SimpleLinkedListNodeBase<T>* next = NULL);
	SimpleLinkedListNodeBase(const SimpleLinkedListNodeBase<T>& copy);
	~SimpleLinkedListNodeBase();

	/// charas
        SimpleLinkedListNodeBase* nextNode();
	T& data();
	T* nodePtr();
        void setNode(T node);

	/// operations
	void setNextNode(SimpleLinkedListNodeBase<T>* next);
        SimpleLinkedListNodeBase& operator = (const SimpleLinkedListNodeBase<T>& node);

private:
        T _node;
        SimpleLinkedListNodeBase* _next;
};

///
//      class           : DoubleLinkedListNodeBase
//      description     : simple 2 ways link list node base class consists with data and 'next' & 'prio'ptr
//

template <class T>
class DoubleLinkedListNodeBase
{
public:
	/// construct and deconstruct funs
        DoubleLinkedListNodeBase();
        DoubleLinkedListNodeBase(T node, DoubleLinkedListNodeBase* next, DoubleLinkedListNodeBase* prior);
        DoubleLinkedListNodeBase(const DoubleLinkedListNodeBase<T>& copy);
        ~DoubleLinkedListNodeBase();

	/// charas
        DoubleLinkedListNodeBase* priorNode();
        DoubleLinkedListNodeBase* nextNode();

	/// operations
        void setPriorNode(DoubleLinkedListNodeBase* prior);
        void setNextNode(DoubleLinkedListNodeBase* next);

        T& data();
        T* nodePtr();
        void setNode(T node);
private:
        DoubleLinkedListNodeBase* _prior;
        DoubleLinkedListNodeBase* _next;
        T _node;
};
//#include "src/linklistnodebases.cpp"
#endif
