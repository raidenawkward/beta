#include "include/linkstackbase.h"
#include "linklistbase.cpp"
template<class T>
LinkStackBase<T>::LinkStackBase()
    :LinkListBase<T>()
{
}

template<class T>
LinkStackBase<T>::~LinkStackBase()
{
    this->clear();
}

template<class T>
void LinkStackBase<T>::push(T elem)
{
    DoubleLinkedListNodeBase<T>* node = new DoubleLinkedListNodeBase<T>(elem,NULL,NULL);
    this->append(node);
}

template<class T>
T& LinkStackBase<T>::pop()
{
    T ret = this->getTail()->data();
    this->removeLast();
    return ret;
}

template<class T>
T& LinkStackBase<T>::getTop()
{
    return this->getTail()->data();
}

template<class T>
int LinkStackBase<T>::length()
{
    return this->count();
}

template<class T>
void LinkStackBase<T>::clear()
{
    LinkListBase<T>::clear();
}


/// main function for test
//#define TEST_LINKSTACK
#ifdef TEST_LINKSTACK
#include <stdio.h>
#include <string.h>
int main()
{
    int i = 0;
    LinkStackBase<int> stack;
    while (i < 10)
    {
        printf("push : %d : %d\n",i,i);
        stack.push(i++);
    }
    while(stack.length())
        printf("pop : %d : %d\n",stack.length(), stack.pop());
    return 0;
}
#endif
