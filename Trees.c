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

int searchNode(Tree* root, int data)
{
    Tree* temp=root;
    if (root)
    {
        if(root->data == data)
        {
            return 1;
        }
        else if(data < root->data)
        {
            return searchNode(root->left,data);
        }
        else 
        {
            return searchNode(root->right,data);
        }
    }
    return 0;
}

Tree* findMin(Tree* root)
{
    Tree* temp=root;
    if(!root)
    {
        return NULL;
    }
        
    while(temp->left)
    {
        temp=temp->left;
    }
    return temp;
}

Tree* findMax(Tree* root)
{
    Tree* temp=root;
    if(!root)
    {
        return NULL;
    }
        
    while(temp->right)
    {
        temp=temp->right;
    }
    return temp;
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