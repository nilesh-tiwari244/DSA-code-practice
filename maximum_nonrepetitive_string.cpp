#include<iostream>
#include<string>
using namespace std;

int maxstring(string a) // max substring size with no repeatation
{   int i,lo,k,fl=0,aar=0,hi=1,n=a.size();
    for (i=0;i<n;i++)
    {   lo=i;
        while (hi<n)  
        {   cout<<endl<<"lo and hi are="<<lo<<" and "<<hi<<endl;
             for(k=i;k<hi;k++)
                {if (a[k]==a[hi])
                    {fl=hi-i;
                    i=k;
                     break;
                    }
                    fl=hi-i+1; 
                }
            aar=max(aar,fl);
            cout<<endl<<"      "<<aar<<endl;
            if (k<hi)
                break;
            hi++;
        }
        if(hi==n)
            break;
    }
    return aar;
}

int main()
{string a="mynammeisnilesh";
cout<<endl<<maxstring(a);
    return 0;
}