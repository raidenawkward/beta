#include "../include/hashtablebase.h"


#define TEST_HASHTABLE
#ifdef TEST_HASHTABLE
#include <stdio.h>
#include <string.h>
int main()
{
		HashTableBase<int,const char*> table(4);
		table.set(3,"test 3");
		table.set(10,"test 10");
		table.remove(3);
		//table.clear();
		printf("get 3 : %s\n",table.get(3));
		printf("get 10 : %s\n",table.get(10));
		return 0;
}
#endif
