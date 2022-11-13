#include<iostream>
#include<stack>
using namespace std;
void reversesentence(string s)
{stack <string> st;
int i=0;
string ss;
while(s[i]!='\0')
    {ss.clear();
        while((s[i]!=' ')&&(s[i]!='\0'))
        {ss+=s[i];
        i++;
        }
        st.push(ss);
        i++; 
    }  
    cout<<endl;
    while(!st.empty())
    {cout<<st.top()<<" ";
    st.pop();
    }
    return;  
}

int main()
{
    string s;
    getline(cin,s);
    reversesentence(s);
    return 0;
}