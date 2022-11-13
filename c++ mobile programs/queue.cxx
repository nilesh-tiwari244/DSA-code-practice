#include<iostream>
using namespace std;
class queue{
    private:
    int front;
    int back;
    public:
    int * arr=new int[100];
    queue()
    {front=-1;
    back=-1;
    }
    void enqueue(int a)
    {front++;
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
        return arr[back];
    }
    bool empty()
    {return (back==-1);
    }
    void display()
    {if ((front==back)&&(front==-1))
    {cout<<endl<<"empty";
    return;
    }cout<<endl;
        while (back<=front)
        {cout<<arr[back]<<" ";
        back++;
        }
        return;
    }
};
int main()
{queue a;
a.enqueue (1);
a.enqueue(2);
a enqueue(3);
a.dequeue();
cout<<endl<<a.peek()<<endl;
a.display();
return 0;
}