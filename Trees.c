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

Tree *insertChild(Tree *root,int data)
{
    Tree* newNode=createNode(data);
    Tree* temp=root; 
    Tree* tail=NULL;
    if(!root)
    {
        root=newNode;
    }
    else
    {
        while(temp)
        {
            tail=temp;
            if(newNode->data < temp->data)
            {
                
                temp=temp->left;
            }
            else if(newNode->data > temp->data)
            {
                
                temp=temp->right;
            }
            else
            {
                break;
            }
        }
        if(newNode->data < tail->data)
        {
            tail->left=newNode;
        }
        else if(newNode->data > tail->data)
        {
            tail->right=newNode;
        }
        else
        {
            printf("\nCan't insert duplicate values\n");
            return root;
        }
    }
    return root;
}

void inOrder(Tree* root)
{
    if(root)
    {
        inOrder(root->left);
        printf("[%d] ",root->data);
        inOrder(root->right);
    }
}

void preOrder(Tree* root)
{
    if(root)
    {
        printf("[%d] ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Tree* root)
{
    if(root)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("[%d] ",root->data);
    }
}