#include <stdio.h>
#include <stdlib.h>
#define TEST
#ifndef TEST
int main(int argc, char** argv)
{z
	for (int i = 0; i < argc; ++i)
	{
		printf("inputed : %s\n",argv[i]);
	}
}
#endif
