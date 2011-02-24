/*
 * file	        : LinkedListNodeBases
 * description  : link list node base classes
 * author       : Raiden
 * date         : 2011-02-16
 * version      : 0.1.0
 */



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
	SimpleLinkedListNodeBase(T& node,SimpleLinkedListNodeBase<T>* next = NULL);
	SimpleLinkedListNodeBase(const SimpleLinkedListNodeBase<T>& copy);
	~SimpleLinkedListNodeBase();

	/// charas
	SimpleLinkedListNodeBase<T>* nextNode();
	T& data();
	T* nodePtr();

	/// operations
	void setNextNode(SimpleLinkedListNodeBase<T>* next);
	SimpleLinkedListNodeBase<T> operator = (const SimpleLinkedListNodeBase<T>& node);

private:
	T* _node;
	SimpleLinkedListNodeBase<T>* _next;
};

///
//      class           : DoubleLinkedListNodeBase
//      description     : simple 2 ways link list node base class consists with data and 'next' & 'prio'ptr
//

template <class T>
class DoubleLinkedListNodeBase : public SimpleLinkedListNodeBase<T>
{
public:
	/// construct and deconstruct funs
	DoubleLinkedListNodeBase(void);
	DoubleLinkedListNodeBase(T& node, DoubleLinkedListNodeBase<T>* next, DoubleLinkedListNodeBase<T>* prior);
	DoubleLinkedListNodeBase(const DoubleLinkedListNodeBase<T>& copy);

	/// charas
	DoubleLinkedListNodeBase<T>* priorNode();
        DoubleLinkedListNodeBase<T>* nextNode();

	/// operations
	void setPriorNode(DoubleLinkedListNodeBase<T>* prior);
        void setNextNode(DoubleLinkedListNodeBase<T>* next);
private:
	DoubleLinkedListNodeBase<T>* _prior;
        SimpleLinkedListNodeBase<T>* _next;
};
