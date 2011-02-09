#include "../include/linerlistbase.h"

template<class T> LinerListBase<T>::LinerListBase(void)
								:_list(NULL),_length(0),_size(0)
{
	this->initList();
}

template<class T> LinerListBase<T>::LinerListBase(const LinerListBase<T>& copy)
{
	this->initList();
	this->_length = copy.length();
	this->_size = copy.size();
	if (_size)
	{
		this->_list = new T[_size];
		for (int i = 0; i < _length; ++ i)
		{
			_list[i] = copy.getElement(i);
		}
	}
	else
	{
		this->_list = NULL;
	}
}

template<class T> LinerListBase<T>::~LinerListBase()
{
	this->clear();
}

template<class T> T* LinerListBase<T>::getList()
{
	return this->_list;
}

template<class T> int LinerListBase<T>::length()
{
	return this->_length;
}

template<class T> int LinerListBase<T>::size()
{
	return this->_size;
}

template<class T> bool LinerListBase<T>::empty()
{
	return (_length == 0);
}

template<class T> bool LinerListBase<T>::isNull()
{
	return (_list == NULL);
}

template<class T> void LinerListBase<T>::clear()
{
	if (this->_list)
	{
		delete this->_list;
		this->_list = NULL;
	}
	this->_length = 0;
	this->_size = 0;
}

template<class T>
T LinerListBase<T>::getElement(int index)
{
	if (index < 0 || index >= _length)
	{
		return NULL;
	}
	return this->_list[index];
}

template <class T>
T& LinerListBase<T>::get(int index)
{
	if (index < 0 || index >= _length)
		return NULL;
	return this->_list[index];
}

template <class T>
T& LinerListBase<T>::at(int index)
{
	return this->get(index);
}

template <class T>
int LinerListBase<T>::locate(const T elem,bool(*compare)(const T elem1,const T elem2))
{
	for (int i = 0; i < _length; ++i)
	{
		if ((*compare)(elem,this->getElement(i)))
			return i;
	}
	return 0;
}

template <class T>
T& LinerListBase<T>::first()
{
	if (_size)
	{
		return _list[0];
	}
	return NULL;
}

template <class T>
T& LinerListBase<T>::last()
{
	if (_size)
	{
		return _list[size];
	}
	return NULL;
}

template <class T>
int LinerListBase<T>::firstLocation(const T elem)
{
	for (int i = 0; i < _length; ++i)
	{
		if (elem == this->getElement(i))
			return i;
	}
	return -1;
}

template <class T>
int LinerListBase<T>::lastLocation(const T elem)
{
	for (int i = _length -1; i == 0; --i)
    {
        if (elem == this->getElement(i))
            return i;
    }
    return -1;
}

template <class T>
void LinerListBase<T>::set(int index, const T elem)
{
	this->reserve(index);
	_list[index] = elem;
}

template <class T>
bool LinerListBase<T>::insert(int pos, const T item)
{
	if (pos < 0)
	{
		return false;
	}
	if ( _length == 0)
		reserve(1);
	if ( pos >= _length )
		reserve(pos);
	for (int i=_length; i > pos; --i)
		_list[i] = _list[i - 1];
	_list[pos] = item;
	++_length;
	return true;
}

template <class T>
void LinerListBase<T>::append(const T elem)
{
	this->insert(_length,elem);
}

template <class T>
void LinerListBase<T>::append(const T* elems, int length)
{
	reserve(_length + length);
	for (int i = 0; i < length; ++i)
		_list[i + length] = elems[i];
	_length += length;
}

template <class T>
void LinerListBase<T>::append(const LinerListBase<T>& list)
{
	reserve(_length + list.length());
	for(int i = 0; i < list.length(); ++i)
		_list[_length + i] = list.getElement(i);
	_length += list.length();
}

template <class T>
void LinerListBase<T>::remove(int pos, int n)
{
	if ( pos < 0 || n <= 0 || pos + n > _length )
		return;
	int i;
    for (i = pos + n; i < _length; ++i)
    {
		_list[i - n] = _list[i];
	}
	_length -= n;
	_size = _length;
}

template <class T>
void LinerListBase<T>::removeAt(int pos)
{
	remove(pos,1);
}

template <class T>
LinerListBase<T>& LinerListBase<T>::operator = (const LinerListBase& list)
{
	this->clear();
	this->_length = list.length();
	this->_size = list.size();
	if (list.size())
	{
		this->_list = new T[_size];
		for (int i = 0; i < _length; ++i)
		{
			_list[i] = list.getElement(i);
		}
	}
	else
	{
		this->_list = NULL;
	}
	return *this;
}

template <class T>
T& LinerListBase<T>::operator [] (int index)
{
	if (index < 0 || index >= _length)
		return NULL;
	return this->_list[index];
}

template <class T>
T LinerListBase<T>::operator [] (int index) const
{
	if (index < 0 || index >= _length)
		return NULL;
	return this->_list[index];
}

template <class T>
void LinerListBase<T>::traverse(int(*visit)(const T&))
{
	for(int i = 0; i < this->length(); ++i)
		(*visit)(this->getElement(i));
}

template <class T>
void LinerListBase<T>::initList()
{
	this->clear();
}

template <class T>
void LinerListBase<T>::reserve(int size)
{
	if ( size > _size )
	{
		T* tmp_list = new T[ size ];
		if ( _list )
		{
			for ( int i = 0; i < _length; ++i )
				tmp_list[i] = _list[i];
			delete [] _list;
		}
		_list = tmp_list;
		_size = size;
	}
}

/// main function for test
#include<stdio.h>
int main()
{
	LinerListBase<int> list;
	list.append(1);
	list.append(2);
	list.append(3);
	list.remove(0,3);
	for (int i = 0; i < list.length(); ++i)
	{
		printf("elem : %d is %d\n",i,list.getElement(i));
	}
	return 0;
}
