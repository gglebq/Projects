#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

#include "Item.h"
typedef struct tree *Tree;
typedef void(*perItemFunc) (Item *pItem);

Tree CreateTree(void);
//ptrNode getParentNode(ptrNode root, ptrNode ptrSon);
void traversePreOrder(Tree tree, perItemFunc pFunc);
void traverseInOrder(Tree tree, perItemFunc pFunc);
void traversePostOrder(Tree tree, perItemFunc pFunc);
//static void traversePre(ptrNode root, perItemFunc pFunc);
//static void traverseIn(ptrNode root, perItemFunc pFunc);
//static void traversePost(ptrNode root, perItemFunc pFunc);
void add(Tree tree, Key key, Item item);
int getSizeTree(Tree tree);
//static void display_graphic_tree(ptrNode tree_to_display);
void printTree(Tree tree);
//static void delete_tree(ptrNode tree_to_delete);
void deleteTree(Tree tree_to_delete);

#endif // !_BINARY_TREE_H
