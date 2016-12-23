#include <stdlib.h> //for malloc
#include "BinaryTree.h"
#include <stdio.h>

typedef struct Node {
	Item item;
	Key key;
	struct Node *left; //if left == NULL , it means it has no left son
	struct Node *right; // if right == NULL , it means it has no right son
}*ptrNode;

struct tree {
	ptrNode root;
	int size;
};

//helper functions
static void traversePre(ptrNode subtree, perItemFunc pFunc);
static void traverseIn(ptrNode subtree, perItemFunc pFunc);
static void traversePost(ptrNode subtree, perItemFunc pFunc);

Tree CreateTree(void) {
	struct tree *t;
	t = calloc(1, sizeof(struct tree));
	t->size = 0;
	return t;
}

static ptrNode getParentNode(ptrNode root, ptrNode ptrSon) {
	if (root) {
		if (ptrSon == root->left || ptrSon == root->right) return root;
		else {
			if (root->left ) return getParentNode(root->left , ptrSon);
			if (root->right) return getParentNode(root->right, ptrSon);
		}
	}
	else return NULL;
}

void traversePreOrder(Tree tree, perItemFunc pFunc) {
	traversePre(tree->root, pFunc);
}

void traverseInOrder(Tree tree, perItemFunc pFunc) {
	traverseIn(tree->root, pFunc);
}

void traversePostOrder(Tree tree, perItemFunc pFunc) {
	traversePost(tree->root, pFunc);
}

static void traversePre(ptrNode root, perItemFunc pFunc) {
	if (root) { //if ptr is not NULL (i.e.,there is a node)
		pFunc(&root->item);
		traversePre(root->left , pFunc);
		traversePre(root->right, pFunc);
	}
}

static void traverseIn(ptrNode root, perItemFunc pFunc) {
	if (root) { //if ptr is not NULL (i.e., there is a node)
		traverseIn(root->left , pFunc);
		pFunc(&root->item);
		traverseIn(root->right, pFunc);
	}
}

static void traversePost(ptrNode root, perItemFunc pFunc) {
	if (root) { //if ptr is not NULL (i.e., there is a node)
		traversePost(root->left , pFunc);
		traversePost(root->right, pFunc);
		pFunc(&root->item);
	}
}

void add(Tree tree, Key key, Item item) {
	ptrNode subtree;
	//create new Node
	ptrNode newNode = malloc(sizeof(struct Node));
	if (!newNode) {
		ERROR();
		return;
	}
	//fill it with data
	newNode->key = key;
	newNode->item = item;
	newNode->left = newNode->right = NULL;

	subtree = tree->root; //start from beginning
	if (!tree->root) {	  // is it an empty tree?
		tree->root = newNode;
		tree->size++;
		return;
	} 
	while (1) {
		if (EQ(key, subtree->key) < 0) { //add to left sub-tree
			if (subtree->left == NULL) {
				subtree->left = newNode;
				tree->size++;
				return;
			}
			subtree = subtree->left;
		}
		else {							 //add to right sub-tree
			if (subtree->right == NULL) {
				subtree->right = newNode;
				tree->size++;
				return;
			}
			subtree = subtree->right;
		}
	}
}

int getSizeTree(Tree tree) {
	return tree->size;
}

static void display_graphic_tree(ptrNode tree_to_display) {
	static int i = 1;
	int j;
	if (tree_to_display != NULL) {
		i++;
		display_graphic_tree(tree_to_display->right);
		for (j = 0; j < i; j++)printf("  ");

		printf("%d", tree_to_display->key);
		printf("\n");

		display_graphic_tree(tree_to_display->left);
		i--;
	}
}

void printTree(Tree tree) {
	display_graphic_tree(tree->root);
}

static void delete_tree(ptrNode tree_to_delete) {
	if (tree_to_delete == NULL) return;
	delete_tree(tree_to_delete->left);
	delete_tree(tree_to_delete->right);

	free(tree_to_delete);
}

void deleteTree(Tree tree_to_delete) {
	delete_tree(tree_to_delete->root);
	//tree_to_delete->size = 0;
	free(tree_to_delete);
	tree_to_delete = NULL;
}