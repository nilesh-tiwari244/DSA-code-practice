#include<iostream>
using namespace std;
class addition{
    public:
    int real;
    int complex;
    
    addition(int a,int b)
    {real=a;
    complex=b;
    }
    addition operator + (addition obj)
    {addition re;
    re.real=real+obj.real;
    re.complex=complex+ obj.complex;
    return re;   
    }
   void display (addition ob)
   cout<<ob.real<<" + "<<ob.complex<<"j";
};

int main()
{addition ob1(1,2);
addition ob2(3,4);
addition res=ob1+ob2;
display(res);
return 0;
}

    