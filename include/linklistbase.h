/*
 * class        : LinkListBase
 * description  : double linked node based list
 * author       : Raiden
 * date         : 2011-02-23
 * version      : 0.1.0
 */

#ifndef LINKLISTBASE_H
#define LINKLISTBASE_H

#include <stdlib.h>
#include "linklistnodebases.h"

#define __LinkListNode DoubleLinkedListNodeBase<T>
#define LinkListNode DoubleLinkedListNodeBase

template <class T>
class LinkListBase
{
public:
	/// construct and deconstruct funs
	LinkListBase(void);

	/// charas
        __LinkListNode* getHead();/*!< returns the head node of list*/
        __LinkListNode* getTail();/*!< returns the tail node of list*/
        __LinkListNode* getNext();
        __LinkListNode* getCurrent();
        __LinkListNode* at(int i);
	int count();
	int currentIndex();
	bool atFirst();
	bool atLast();
	bool isEmpty();

	///
	void clear();
	bool removeFirst();
	bool removeLast();

        bool setCurrentNode(__LinkListNode* newnode);
        void insertFirst(__LinkListNode* node);
        bool insertAt(int index, __LinkListNode* node);
        void append(__LinkListNode* node);

	bool removeAt(int i);

	int firstIndexOf(const T data);
	int lastindexOf(const T data);

        void moveToNextNode();
        void moveToPriorNode();

protected:
        void freeNode(__LinkListNode* node);
        void traverse();
private:
	int _count;
	int _index;
        __LinkListNode* _head;
        __LinkListNode* _tail;
        __LinkListNode* _current;
};
#endif
