#include <stdio.h>
#include <stdlib.h>

struct employee
{
    char name[30];
    int id;
    int salary;
};

struct Node
{
    struct employee emp;
   struct Node *left;
    struct Node *right;
};

struct Node *root=NULL;


struct Node *create (struct employee  e)
{
   struct Node* New=(struct Node *)malloc(1*sizeof(struct Node));
    New->emp=e;

    New->right=New->left=NULL;
}


void Add (struct Node * pnew)
{
    if(root==NULL)
    {
        root=pnew;
    }
    else
    {
      struct Node *pcurrent =root;
       struct Node *parent;
       while(pcurrent != NULL)
       {
           parent=pcurrent;

                        if(pnew->emp.id>pcurrent->emp.id)
                      {
                           pcurrent=pcurrent->right;
                      }
                      else
                      {
                          pcurrent=pcurrent->left;
                      }

       }
       if (pnew ->emp.id > parent->emp.id)
       {
           parent->right=pnew;
       }
       else
       {
           parent->left=pnew;
       }
    }
}

struct Node *search (int id )
{
   struct Node *psearch=root;
    while (psearch  != NULL)
    {
        if(psearch->emp.id== id)
        {
            return psearch;
        }
        else if(psearch->emp.id<id)
        {
            psearch=psearch->right;
        }
        else
        {
            psearch=psearch->left;
        }
    }
    return NULL;
}

struct Node* getparent(struct Node* pchild)
{
    struct Node *parent=root;
    while(parent != NULL)
    {
        if((parent ->left== pchild)||(parent->right=pchild))
        {
            return parent;
        }
        else if (pchild->emp.id > pchild->emp.id)
        {
            parent=parent->right;
        }
        else
        {
            parent=parent->left;
        }
    }
    return NULL;
}

void delete (struct Node * pdelete)
{
    struct Node *pcurrent=NULL;
    struct Node *parent=NULL;
    if(pdelete == root)
    {
        if((root->left==NULL)||(root->right==NULL))
        {
            root==NULL;
        }
        else if(root->right==NULL)
        {
            root=root->right;
        }
        else if(root->left=NULL)
        {
            root=root->left;
        }
        else
        {
             pcurrent=root->left;
            while(pcurrent->right !=NULL)
            {
                pcurrent=pcurrent->right;
            }
            pcurrent->right=root->right;
   root=root->left;
        }
    }

    else
    {
        parent=getparent(pdelete);
        if((pdelete->left==NULL)&&(pdelete->right=NULL))
        {
            if(parent->left==  pdelete)
            {
                parent->left=NULL;
            }
            else
            {
                parent->right=NULL;
            }
        }
        else if(pdelete->right == NULL)
        {
            if(parent->left==pdelete)
            {
                parent->left=pdelete->left;
            }
            else
            {
                parent->right=pdelete->left;
            }
        }
        else if(pdelete->left==NULL)
        {
            if(parent->left==pdelete)
            {
                parent->left=pdelete->right;
            }
            else
            {
                parent->right=pdelete->right;
            }
        }
        else
        {
            pcurrent=pdelete->left;
            while(pcurrent->right !=NULL)
            {
                pcurrent=pcurrent->right;
            }
            pcurrent->right=pdelete->right;
            if(parent->left==pdelete)
            {
                parent->left=pdelete->left;
            }
            else{
                parent->right=pdelete->left;
            }
        }
    }
    free(pdelete);
}


void display(struct Node *pNode)
{
    if(pNode!=NULL)
    {
        display(pNode->left);
        printf("%s\n",pNode->emp.name);
        printf("%d\n",pNode->emp.id);
        printf("%d\n",pNode->emp.salary);
        display(pNode->right);
    }
}


int main()
{
    struct Node *khaled=NULL;
    int n;
    struct employee emp;
  struct    Node *ptr;
     printf("enter the first name\n");
    scanf("%s",emp.name);
    printf("enter the id\n");
    scanf("%d",&emp.id);
    printf("enter the salary\n");
    scanf("%d",&emp.salary);

   ptr= create(emp);
    Add(ptr);

    printf("enter the first name\n");
    scanf("%s",emp.name);
    printf("enter the id\n");
    scanf("%d",&emp.id);
    printf("enter the salary\n");
    scanf("%d",&emp.salary);

    ptr=create(emp);
    Add(ptr);

      printf("enter the first name\n");
    scanf("%s",ptr->emp.name);
    printf("enter the id\n");
    scanf("%d",&emp.id);
    printf("enter the salary\n");
    scanf("%d",&emp.salary);
    ptr=create(emp);
    Add(ptr);



    display(root);
printf("enter the id to delete\n");
    scanf("%d",&n);
  khaled= search(n);
  delete(khaled);
   display(root);

