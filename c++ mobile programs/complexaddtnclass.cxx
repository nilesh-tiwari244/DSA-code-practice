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
    addition()
    {real=0;
    complex=0;
    }
    addition operator + (addition obj)
    {addition re;
    re.real=real+obj.real;
    re.complex=complex+ obj.complex;
    return re;   
    }
   void display ()
  { cout<<real<<" + "<<complex<<"j";
  }
};

int main()
{addition ob1(1,2);
addition ob2(3,4);
ob1.display();
cout<<endl;
addition res=ob1+ob2;
res.display();
return 0;
}

    