#include "../include/linklistbase.h"

template <class T>
LinkListBase<T>::LinkListBase()
    :_count(0),
    _index(0),
    _head(NULL),
    _tail(NULL),
    _current(NULL)
{

}

template <class T>
LinkListNode* LinkListBase<T>::getHead()
{
    return this->_head;
}

template <class T>
LinkListNode* LinkListBase<T>::getTail()
{
    return this->_tail;
}

template <class T>
LinkListNode* LinkListBase<T>::getNext()
{
    return this->_current->nextNode();
}

template <class T>
LinkListNode* LinkListBase<T>::getCurrent()
{
    return this->_current;
}

template <class T>
LinkListNode* LinkListBase<T>::at(int i)
{
    if (i < 0 || i > _count -1)
        return NULL;

    if (i < _count/2)
    {
        int index = 0;
        LinkListNode* tmp_node = _head;

        while (i != index)
        {
            tmp_node = tmp_node->nextNode();
            ++index;
        }
        return tmp_node;
    }
    else
    {
        int index = _count;
        LinkListNode* tmp_node = _tail;
        while (i != _count - index)
        {
            tmp_node = tmp_node->priorNode();
            ++index;
        }
        return tmp_node;
    }
}

template <class T>
int LinkListBase<T>::count()
{
    return this->_count;
}

template <class T>
int LinkListBase<T>::currentIndex()
{
    return this->_index;
}

template <class T>
bool LinkListBase<T>::atFirst()
{
    return this->_current == this->_head;
}

template <class T>
bool LinkListBase<T>::atLast()
{
    return this->_current == this->_tail;
}

template <class T>
bool LinkListBase<T>::isEmpty()
{
    return this->_count == 0;
}

template <class T>
void LinkListBase<T>::clear()
{
    _current = _head;
    do
    {
        if (_current)
        {
            _current = _current->nextNode();
            freeNode(_current->priorNode());
        }
    }
    while (_current != _tail);
    freeNode(_tail);
    this->_head = NULL;
    this->_tail = _head;
    this->_current = _head;
    this->_index = 0;
    this->_count = 0;
}

template <class T>
bool LinkListBase<T>::removeFirst()
{
    if (this->isEmpty())
        return false;
    if (this->count() == 1)
        clear();
    else
    {
        _head = _head->nextNode();
        freeNode(_head->priorNode());
    }
    return true;
}

template <class T>
bool LinkListBase<T>::removeLast()
{
    if (this->isEmpty())
        return false;
    if (this->count() == 1)
        clear();
    else
    {
        _tail = _tail->priorNode();
        freeNode(_tail->nextNode());
    }
    return true;
}

template <class T>
bool LinkListBase<T>::setCurrentNode(LinkListNode* newnode)
{
    if (!newnode)
        return false;
    newnode->setNextNode(_current->nextNode());
    newnode->setPriorNode(_current->priorNode());
    freeNode(_current);
    _current = newnode;
    return true;
}

template <class T>
void LinkListBase<T>::insertFirst(LinkListNode* node)
{
    ++count;
    _head->setPriorNode(node);
    _head = _head->priorNode();
}

template <class T>
bool LinkListBase<T>::insertAt(int index, LinkListNode* node)
{
    if (index < 0 || index >= _count)
        return false;

    LinkListNode* tmp_node = this->at(index);
    node->setNextNode(tmp_node);
    node->setPriorNode(tmp_node->priorNode());
    tmp_node->setPriorNode(node);
    return true;
}

template <class T>
void LinkListBase<T>::append(LinkListNode* node)
{
    ++count;
    _tail->setNextNode(node);
    _tail = _tail->nextNode();
}

template <class T>
bool LinkListBase<T>::removeAt(int i)
{
    if (i < 0 || i > _count -1)
        return false;
    LinkListNode* tmp_node = this->at(i);
    tmp_node->nextNode()->setPriorNode(tmp_node->priorNode());
    tmp_node->priorNode()->setNextNode(tmp_node->nextNode());
    freeNode(tmp_node);
    --_count;
    return true;
}

template <class T>
int LinkListBase<T>::firstIndexOf(const T data)
{
    int ret = 0;
    if (this->isEmpty())
        return -1;
    LinkListNode* tmp_node = _head;
    while (ret < _count)
    {
        if (tmp_node->data() == data)
            return ret;
        ++ ret;
    }
    return -1;
}

template <class T>
int LinkListBase<T>::lastindexOf(const T data)
{
    int ret = _count;
    if (this->isEmpty())
        return -1;
    LinkListNode* tmp_node = _tail;
    while (ret >= 0)
    {
        if (tmp_node->data() == data)
            return ret;
        -- ret;
    }
    return -1;
}

template <class T>
void LinkListBase<T>::moveToNextNode()
{
    if (_index == _count -1)
        return;
    ++_index;
    _current = _current->nextNode();
}

template <class T>
void LinkListBase<T>::moveToPriorNode()
{
    if (_index == 0)
        return;
    --_index;
    _current = _current->priorNode();
}

template <class T>
void LinkListBase<T>::freeNode(LinkListNode* node)
{
    if (!node)
        return;
    delete node;
}

/// main function for test
#define TEST_LINKLIST
#ifdef TEST_LINKLIST
#include <stdio.h>

int main()
{
    return 0;
}
#endif
