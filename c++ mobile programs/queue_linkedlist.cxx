#include<iostream>
using namespace std;
class node{
   public:
    int data;
    node* next;
    node(int a)
    {data=a;
    next=NULL;
    }     
};
class queue{
    public:
    node* front;
    node* back;
    queue()
    {
       front=NULL;
       back=NULL;
    }
    void enqueue(int a)
    {if (front==NULL)
   {front=new node(a);
   back=front;
   return;
    }
    back->next=new node(a);
    back=back->next;
    return;
    }
    
    void dequeue()
    {if (front==NULL)
    {cout<<"empty queue";
    return;
    }
    node* todel=front;
    front=front->next;
    delete todel;
    return;
    }
    
    int peek()
    {if (front==NULL)
    {cout<<"queue empty";
    return -1;
    }
        return front->data;
    }
    
    bool empty()
    {if (front==NULL)
    return 1;
    else
    return 0;
    }
    
    void display()
    {if (front==NULL)
    {cout<<endl<<"empty";
    return;
    }
    cout<<endl;
    node* gg=front;
        while (gg!=back->next)
        {cout<<gg->data<<" ";
        gg=gg->next;
        }
        return;
    }
};
int main()
{queue a;
a.enqueue (1);
a.enqueue(2);
a.enqueue(3);
a.display();
cout<<endl;
a.dequeue();
cout<<"yaha se suru";
cout<<endl<<a.peek()<<endl;
a.display();
queue b;
b.enqueue(5);
cout<<endl<<a.peek()<<endl;
cout<<endl<<b.peek()<<endl;
return 0;
}