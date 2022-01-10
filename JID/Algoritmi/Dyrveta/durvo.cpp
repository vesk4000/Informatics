#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *l, *r, *p;
};


Node *root;

void Preorder(Node *t)
{
    if(t)
    {
        cout << t->key << " ";
        Preorder(t->l);
        Preorder(t->r);
    }
}
void Inorder(Node *t)
{
    if(t)
    {
        Inorder(t->l);
        cout << t->key << " ";
        Inorder(t->r);
    }
}
void Postorder(Node *t)
{
    if(t)
    {
        Postorder(t->l);
        Postorder(t->r);
        cout << t->key << " ";
    }
}

 void Add(int k)
 {
     Node *t, *q;
     t = root;
     while(true)
     {
         if( k < t-> key)
         {
             if(t->l==NULL)
             {
                 q = new Node;
                 q->key=k;
                 q->l=q->r=NULL;
                 q->p=t;
                 t->l=q;
                 break;
             }
             else
             t=t->l;
         }
        else
        {
             if(t->r==NULL)
             {
                 q=new Node;
                 q->key=k;
                 q->l=q->r=NULL;
                 q->p=t;
                 t->r=q;
                 break;
             }
             else t=t->r;

       }
     }
 }

void Search( int k, Node *t, Node &q)
{
    if(t->key==k)
    {
        q=t;
    }
    else
    {
        if(k< t->key)
        Search(k,t->l,q);
        else
        Search(k,t->r,q);
    }
}
void Delete(int k)
{
    Node *t, *q;
    Search(k,root,t);
    if(t)
    {
        if(t->l==NULL&&t->r==NULL)
        {
            if(k>t->p->key)
            t->p->r=NULL;
            else
            t->p->l=NULL;
        }
    }
}
int main()
{
    root= new Node;
    root->key=20;
    root->l=NULL;
    root->r=NULL;
    root->p=NULL;
    //root->l=root->r=root->p=NULL;
    Add(10);
    Add(30);
    Add(8);
    Add(18);
    Add(15);
    Add(25);
    Add(40);
    Add(6);
    Add(9);
    Add(13);
    Add(18);
    Add(4);
    Add(7);
    Add(11);
    Add(19);
    /*//Preorder(root);
    cout << endl;
    //Inorder(root);
    //cout << endl;
    Postorder(root);*/
    Node *q=new Node;
    q=NULL;
    cout << endl;
    Search(20,root,q);
    cout << q << endl;
    Delete(9);
    Preorder(root);
    return 0;
}
