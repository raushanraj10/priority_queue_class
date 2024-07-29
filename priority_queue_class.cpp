#include<iostream>
using namespace std;
class Node
{
public:
    int item;
    int pno;
    Node *next;
};
class priorityqueue
{
private:
    Node *start;
public:
    priorityqueue()
    {
        start=NULL;
    }
    void insertdata(int,int);
    void display();
    void delete1stp();
    ~priorityqueue();
};
void priorityqueue::insertdata(int p,int data)
{
    Node *n;
    n=new Node;
    n->item=data;
    n->pno=p;
    n->next=NULL;
    if(start==NULL)
        start=n;
    else
    {
        Node *r,*t;
        r=NULL;
        t=start;
        while(t!=NULL)
        {
            if(t->pno<=n->pno)
                break;
            else
            {
                r=t;
                t=t->next;
            }
        }
        if(r==NULL)
            {n->next=start;
            start=n;}
        else
        {
            if(t==NULL)
                r->next=n;
            else
            {
                n->next=r->next;
                r->next=n;

            }
        }

    }
}
void priorityqueue::display()
{
    if(start==NULL)
        cout<<" no data ";
    else
    {
        Node *t;
        t=start;
        while(t!=NULL)
        {
            cout<<" "<<"#"<<t->pno<<" - "<<t->item<<" , ";
            t=t->next;
        }
        cout<<endl;
    }
}

void priorityqueue::delete1stp()
{
    if(start!=NULL)
    {
        Node *n;
        n=start;
        start=n->next;
        delete n;
    }

}
priorityqueue::~priorityqueue()
{
    Node *t,*r;
    t=start;
    r=start;
    if(start!=NULL){
    while(t!=NULL)
    {
        t=t->next;
        delete r;
        r=t;

    }
                   }
}
