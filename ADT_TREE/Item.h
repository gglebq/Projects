#include <stdio.h>

#ifndef ITEM_H
#define ITEM_H

typedef struct {
	int num;
	char name[30];
}workerRec;

typedef workerRec Item;
typedef int Key;

#define EQ(key1, key2) (((key1) > (key2)) - ((key1) < (key2)))
#define ERROR() fprintf(stderr, "\nError: The tree is not deleting!\n");
#endif // !ITEM_H
