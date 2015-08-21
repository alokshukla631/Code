#include "stdafx.h"
#include "stdlib.h"


#define N 10
// Splay tree

struct myNode
{
    int data;
    int balFactor;
    struct myNode *leftChild;
    struct myNode *rightChild;
};

//function makeRoot makes temp as root of the tree 
// currently rooted at *root
void makeRoot(struct myNode *temp, struct myNode **root)
{
    int num = temp->data;
    struct myNode *r = *root, *q = NULL, *p = NULL;

    if(num > r->data)
    {
        temp->leftChild = r;

        p = temp;
        q = r;
        while(r)
        {
            // there might be elements in right subtree of root node who might be greater than num
            // find them and move to right subtree of temp
            while(r && r->data < num)
            {
                q = r;
                r = r->rightChild;
            }

            if(r)
            {
                if(p->data < r->data)
                {
                    p->rightChild = r;
                }
                else
                {
                    p->leftChild = r;
                }
                q->rightChild = NULL;
            }
            

            // there might be elements in left subtree of r node who might be less than num
            // find them and move to left subtree of temp
            while(r && r->data > num)
            {
                p = r;
                r = r->leftChild;
            }

            if(r)
            {
                if(q->data < r->data)
                {
                    q->rightChild = r;
                }
                else
                {
                    q->leftChild = r;
                }
                p->leftChild = NULL;
            }
                
            
        }
    }
    else
    {
        temp->rightChild = r;

        p = temp;
        q = r;
        while(r)
        {
            // there might be elements in left subtree of root node who might be less than num
            // find them and move to left subtree of temp
            while(r && r->data > num)
            {
                q = r;
                r = r->leftChild;
            }

            if(r)
            {
                if(p->data < r->data)
                {
                    p->rightChild = r;
                }
                else
                {
                    p->leftChild = r;
                }
                q->leftChild = NULL;
            }
            

            // there might be elements in right subtree of r node who might be greater than num
            // find them and move to right subtree of temp
            while(r && r->data < num)
            {
                p = r;
                r = r->rightChild;
            }

            if(r)
            {
                if(q->data < r->data)
                {
                    q->rightChild = r;
                }
                else
                {
                    q->leftChild = r;
                }
                p->rightChild = NULL;
            }
        }
    }
    *root = temp;
}

void insert(struct myNode **root, int num)
{
    struct myNode *temp = NULL, *r = *root;

    
    temp = (struct myNode *)malloc(sizeof(struct myNode));
    temp->data = num;
    temp->leftChild = NULL;
    temp->rightChild = NULL;

    if(r == NULL)
    {
        *root = temp;
        return;
    }

    makeRoot(temp, root);
}

void inorder(struct myNode *root)
{
    if(root == NULL)
        return;
    inorder(root->leftChild);
    printf("%d,",root->data);
    inorder(root->rightChild);
}

void rightRotate(struct myNode **root)
{
    struct myNode *temp = *root, *r = temp->leftChild, *p = NULL;

    if(r)
    {
        p = r->rightChild;
        r->rightChild = temp;
        temp->leftChild = p;
    }

    *root = r;
}

void leftRotate(struct myNode **root)
{
    struct myNode *temp = *root, *r = temp->rightChild, *p = NULL;

    if(r)
    {
        p = r->leftChild;
        r->leftChild = temp;
        temp->rightChild = p;
    }

    *root = r;
}

int setBalFactor(struct myNode **root)
{
    //printf("root->data = %d\n",root->data);
    int balLeft = 0;
    int balRight = 0;
    struct myNode *temp = *root;

    if(temp == NULL)
    {
        return 0;
    }
    else
    {
        balLeft = setBalFactor(&(temp->leftChild));
        balRight = setBalFactor(&(temp->rightChild));
    }

    temp->balFactor = balRight - balLeft; // if balFactor > 1 means tree is right heavy, if balFactor < -1 means tree is left heavy

    while(temp->balFactor > 1 || temp->balFactor < -1)
    {
        if(temp->balFactor > 1)
        {
            leftRotate(root);
        }
        else if(temp->balFactor < -1)
        {
            rightRotate(root);
        }
        setBalFactor(root); // After rotation calculate balance factor again
    }
    
    return ((balRight >= balLeft) ? (balRight+1) : (balLeft+1));
}

// There can be three cases
// 1. Node to be deleted is leaf node
// 2. Node to delete has only one child
// 3. Node to delete has two childs
void delete1(struct myNode *root, struct myNode *parent)
{
    struct myNode *temp = NULL, *r = NULL;

    if(root == NULL)
    {
        return;
    }
    // 1. Node to be deleted is leaf node
    if(root->leftChild == NULL && root->rightChild == NULL)
    {
        if(parent->leftChild == root)
        {
            parent->leftChild = NULL;
        }
        else
        {
            parent->rightChild = NULL;
        }

        free(root);
        return;
    }

    // 2. Node to delete has only one child
    if((root->leftChild && root->rightChild == NULL) || (root->leftChild == NULL && root->rightChild))
    {
        temp = root->leftChild ? root->leftChild : root->rightChild;
        root->data = temp->data;
        delete1(temp, root);
        return;
    }

    // 3. Node to delete has two childs
    if(root->leftChild && root->rightChild)
    {
        temp = root->leftChild;
        while(temp->rightChild)
        {
            r = temp;
            temp = temp->rightChild;
        }
        root->data = temp->data;
        delete1(temp, r);
        return;
    }
}

void deleteNode(struct myNode *root, int num)
{
    struct myNode *parent = NULL;
    if(root == NULL)
    {
        return;
    }

    while(root && root->data != num)
    {
        parent = root;
        root = num > root->data ? root->rightChild : root->leftChild;
    }

    if(root == NULL)
    {
        // not found
        return;
    }

    delete1(root, parent);
}

int main()
{
    int i = 0;
    int a[] = {3,6,8,10,2,9,5,21,63,54};
    int height = 0;

    struct myNode *root = NULL;

    // build tree
    for(i=0; i<N; i++)
    {
        insert(&root, a[i]);
        inorder(root);
        printf("\n");

        // after every insertion we must set the balancing factor i.e. height of right subtree - height of left subtree
        // value returned here will be hright of tree
        height = setBalFactor(&root);

    }

    // traverse the tree in inorder and print results
    inorder(root);

    // delete the node whose data is 2
    deleteNode(root, 9);

    // balance tree again after deleting
    height = setBalFactor(&root);

    printf("\n");
    // print again
    inorder(root);

    // delete the node whose data is 2
    deleteNode(root, 2);

    // balance tree again after deleting
    height = setBalFactor(&root);

    printf("\n");
    // print again
    inorder(root);

    return 0;
}