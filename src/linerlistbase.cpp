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
T& LinerListBase<T>::getElement(int index)
{
	if (index < 0 || index >= _length)
	{
		return NULL;
	}
	return this->_list[index];
}

template<class T>
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
void LinerListBase<T>::initList()
{
	this->clear();
}

/// main function for test
int main(int argc , char** argv)
{
	LinerListBase<int>();
	return 0;
}
