#ifndef LINKSTACKBASE_H
#define LINKSTACKBASE_H

///
///	class		: LinkStackBase
///	description	: simple link stack
///


#include <stdlib.h>
#include "include/linklistbase.h"

template<class T>
class LinkStackBase : private LinkListBase<T>
{
public:
    LinkStackBase();
    ~LinkStackBase();

    void push(T elem);
    T& pop();
    T& getTop();
    int length();
    void clear();
protected:
    void traverse();
};

#endif // LINKSTACKBASE_H
