/*
 * class        : HashTableBase
 * description  : hash table base class
 * author       : Raiden
 * date         : 2011-03-14
 * version      : 0.1.0
 */
#ifndef HASHTABLEBASE_H
#define HASHTABLEBASE_H

#include <stdlib.h>

inline long  getHash( int n )
{
    return n * 19571113 + 142035;
}

template <typename keyT, typename valueT>
class HashTableBase
{
		class HashPair
		{
				public:
						HashPair(keyT nkey, valueT nvalue, HashPair * pnext) : next(pnext), key(nkey), value(nvalue){};
						HashPair *next;
						keyT key;
						valueT value;
		};

private:
	    int _size;
	    int _count;
	    HashPair **_table;
public:
		HashTableBase( int size )
		{
				if (size < 16 )
						size = 16;
				_table = new HashPair* [ size ];
				memset( _table, 0, sizeof(HashPair*) * size );
				_size = size;
				_count = 0;
		}

		~HashTableBase()
		{
				if ( _table )
				{
						clear();
						delete[] _table;
				}
		}

		int length()
		{
			return _count;
		}

        int size()
		{
			return _size;
		}

		void clear()
		{
			for ( int i = 0; i < _size; ++i )
			{
				HashPair *p = _table[i];
				while (p)
				{
					HashPair *tmp = p;
					p = p->next;
					delete tmp;
					}
			}
			memset( _table, 0, sizeof(HashPair*) *_size );
			_count = 0;
		}

		void resize( int nsize )
		{
				HashPair ** new_table = new HashPair * [ nsize ];
				memset( new_table, 0, sizeof(HashPair*) * nsize );
				for ( int i = 0; i < _size; ++i )
				{
						HashPair *p = _table[i];
						while (p)
						{
								long index = getHash( p->key ) % ( nsize );
								new_table[index] = new HashPair( p->key, p->value, new_table[index] );
								HashPair *tmp = p;
								p = p->next;
								delete tmp;
						}
				}
				if (_table)
						delete[] _table;
				_table = new_table;
				_size = nsize;
		}

		void set( keyT key, valueT value )
		{
			long index = getHash( key ) % ( _size );
			HashPair **p = &_table[index];
			for ( ; *p ;p = &(*p)->next )
			{
				if ( (*p)->key == key )
				{
					(*p)->value = value;
					return;
				}
			}
			if ( _count >= _size )
			{
				resize( _size * 2 );
				index = getHash( key ) % ( _size );
				p = &_table[index];
				for ( ; *p ;p = &(*p)->next )
				{
				}
			}
			*p = new HashPair( key, value, NULL );
			++_count;
		}

		void remove( keyT key )
		{
			long index = getHash( key ) % ( _size );
			HashPair **p = &_table[index];
			for ( ;*p ;p = &(*p)->next )
			{
				if ( (*p)->key == key )
				{
					HashPair *tmp = *p;
					*p = (*p)->next;
					delete tmp;
					--_count;
					return;
				}
			}
		}

		valueT get( keyT key )
		{
			long index = getHash( key ) % ( _size );
			HashPair * p = _table[index];
			for ( ;p ;p = p->next )
			{
				if ( p->key == key )
				{
					return p->value;
				}
			}
			return valueT();
		}

		bool get( keyT key, valueT & res )
		{
			long index = getHash( key ) % ( _size );
			HashPair * p = _table[index];
			for ( ;p ;p = p->next )
			{
				if ( p->key == key )
				{
					res = p->value;
					return true;
				}
			}
			return false;
		}

		class iterator
		{
				friend class HashTableBase;
		public:
				const HashTableBase &_table;
				int _index;
				HashPair *_ptr;
				public:
				iterator( const HashTableBase &table )
						: _table( table ), _index(0), _ptr(NULL)
				{
				}

				iterator( const iterator & v )
						: _table( v._table ), _index(v.index), _ptr(v.ptr)
				{
				}


				HashPair *next()
				{
						if (_index >= _table._size)
								return NULL;
						if (_ptr)
								_ptr = _ptr->next;
						if (!_ptr)
						{
								for ( ; _index < _table._size; )
								{
										_ptr = _table._table[_index++ ];
										if (_ptr)
												return _ptr;
								}
						}
						return _ptr;
				}

		};

		iterator forwardIterator() const
		{
			return iterator(*this);
		}
};

#endif // HASHTABLEBASE_H
