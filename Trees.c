#include <stdio.h>
#include <stdlib.h>
typedef struct Tree
{
    struct Tree* left;
    int data;
    struct Tree* right;
}Tree;

Tree* createNode(int data)
{
    Tree* newNode=(Tree *)malloc(sizeof(Tree));
    if(!newNode)
    {
        printf("\nMemory Allocation Failed\n");
        exit(1);
    }
    newNode->left=NULL;
    newNode->data=data;
    newNode->right=NULL;
    return newNode;
}