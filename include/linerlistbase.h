/*
 * class        : LinerListBase
 * discript     : base liner table
 * author       : Raiden
 * date         : 2011-02-09
 * version      : 1.1.1
 */

#include<stdlib.h>

template <class T>
class LinerListBase
{
public:
	/// construct and deconstruct funs
	LinerListBase(void);
	LinerListBase(const LinerListBase<T>& copy);
	~LinerListBase();

	/// get charas
	T* getList();
	int length();
	int size();
	bool empty();
	bool isNull();

	/// operations
	void clear();
	T getElement(int index);
	T& get(int index);
	T& at(int index);
	int locate(const T elem,bool(*compare)(const T elem1,const T elem2));//return the location of elem according to compare
	T& first();
	T& last();
	int firstLocation(const T elem);
	int lastLocation(const T elem);
	void set(int index, const T elem);
	bool insert(int position, const T elem);
	void append(const T elem);
	void append(const T* elems, int length);
	void append(const LinerListBase<T>& list);
	void remove(int position, int n);
	void removeAt(int position);

	/// operators
	LinerListBase& operator = (const LinerListBase& list);
	T& operator [] (int index);
	T operator [] (int index) const;
protected:
	virtual void traverse(int(*visit)(const T&));
private:
	void initList();
	void reserve(int size);//ensures that size of list is not less than specified value
private:
	/// sq list data
	T* _list;//liner list
	int _length;//list length
	int _size;//list size
};
