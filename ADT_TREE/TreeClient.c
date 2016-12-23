#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "BinaryTree.h"

//in the traversals - for each item we invoke 'job'
void job(Item *item) {
	printf("%d ", item->num);
}

//prints details about the Record
void printWorker(workerRec *worker) {
	printf("\nThe record's details are: num = %d name = ""%s", worker->num, worker->name);
}
//buildTreeFromVec creates a tree from the workers-
//vectors and it uses the add function for all of the items and returns the new tree.

Tree buidTreeFromVec(workerRec *workersArr, int vecsize) {
	int i;
	Tree theTree = CreateTree();

	//add data to the tree.
	for (i = 0; i < vecsize; ++i) {
		add(theTree, workersArr[i].num, workersArr[i]);
	}
	return theTree;
}

void main() {
	Tree theTree;
	Item *pItem;

	workerRec workersArr[] = {
		{5,"Mickey Mouse" },
		{7,"Buggs Bunny"  },
		{3,"Donald Duck"  },
		{6,"Duffy Duck"   },
		{2,"Yogi Bear"    },
		{9,"Olive Oil"    },
		{0,"Silvester Cat"},
		{4,"Goofy Long"   },
		{8,"Garfield Fat" },
		{1,"Pluto Doggy"  }
	};

	printf("\n\nBeginning of binary tree program");
	theTree = buidTreeFromVec(workersArr, sizeof(workersArr) / sizeof(workersArr[0]));

	printf("\n\nThe keys of the records in the tree in PRE_ORDER :\n");
	traversePreOrder(theTree, job);

	printf("\n\nThe keys of the records in the tree in IN_ORDER :\n");
	traverseInOrder(theTree, job);

	printf("\n\nThe keys of the records in the tree in POST_ORDER :\n");
	traversePostOrder(theTree, job);

	printf("\nNumber of nodes is %d\n", getSizeTree(theTree));
	printTree(theTree);
	printf("\nDeleting the records in the tree by key");
	_getch();
	printf("\n\nThe keys of the records in the tree in IN_ORDER :\n");
	traverseInOrder(theTree, job);
	printf("\n\n\n");
	printTree(theTree);
	printf("\nNumber of nodes is %d", getSizeTree(theTree));

	deleteTree(theTree);
	if (theTree = NULL) ERROR();
	printf("\n\nEnd of the program \n");
}