/*
 * class        : LinkListBase
 * description  : double linked node based list
 * author       : Raiden
 * date         : 2011-02-23
 * version      : 0.1.0
 */


#include <stdlib.h>
#include "linklistnodebases.h"

#define LinkListNode DoubleLinkedListNodeBase<T>

template <class T>
class LinkListBase
{
public:
	/// construct and deconstruct funs
	LinkListBase(void);

	/// charas
        LinkListNode* getHead();/*< returns the head node of list*/
        LinkListNode* getTail();/*< returns the tail node of list*/
        LinkListNode* getNext();
        LinkListNode* getCurrent();
        LinkListNode* at(int i);
	int count();
	int currentIndex();
	bool atFirst();
	bool atLast();
	bool isEmpty();

	///
	void clear();
	bool removeFirst();
	bool removeLast();

        bool setCurrentNode(LinkListNode* newnode);
        void insertFirst(LinkListNode* node);
        bool insertAt(int index, LinkListNode* node);
        void append(LinkListNode* node);

	bool removeAt(int i);

	int firstIndexOf(const T data);
	int lastindexOf(const T data);

        void moveToNextNode();
        void moveToPriorNode();

protected:
	void freeNode(LinkListNode* node);

private:
	int _count;
	int _index;
	LinkListNode* _head;
	LinkListNode* _tail;
        LinkListNode* _current;
};
