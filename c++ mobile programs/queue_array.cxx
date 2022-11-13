#include<iostream>
using namespace std;
# define n 100
class queue{
    private:
    int front;
    int back;
    public:
    int * arr=new int[n];
    queue()
    {front=-1;
    back=-1;
    }
    void enqueue(int a)
    {if (front==n-1)
   { cout<<"queue is full";
    return;
    }front++;
    if (back==-1)
    back++;
    arr[front]=a;
    return;
    }
    
    void dequeue()
    {if (back==-1)
    {cout<<"empty queue";
    return;
    }
    back++;
    return;
    }
    
    int peek()
    {if (back==-1)
    {cout<<"queue empty";
    return -1;
    }
        return arr[back];
    }
    
    bool empty()
    {if ((back==-1)||(back>front))
    return 1;
    else
    return 0;
    }
    
    void display()
    {if ((front<back)||(back==-1))
    {cout<<endl<<"empty";
    return;
    }
    cout<<endl;
    int gg=back;
        while (gg<=front)
        {cout<<arr[gg]<<" ";
        gg++;
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
cout<<endl<<b.pee-k()<<endl;
return 0;
}