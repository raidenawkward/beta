/*
 * class        : LinerListBase
 * discript     : base liner table
 * author       : Raiden
 * date         : 2011-02-09
 * version      : 0.1.0
 */

#include<stdlib.h>
#include<unistd.h>

template <class T>
class LinerListBase
{
public:
	/// construct and deconstruct funs
	LinerListBase(void);
	LinerListBase(const LinerListBase<T> &copy);
	~LinerListBase();

	/// get value
	T* getList();
	int length();
	int size();

	/// operations
	void clear();
	T& getElement(int index);
	/// operators
	LinerListBase& operator = (const LinerListBase& list);
protected:
private:
	void initList();
private:
	T* _list;//liner list
	int _length;//list length
	int _size;//list size
};
