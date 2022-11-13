#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Trie{
    public:
    class node{
        public: 
        node* next[2];
        node(){
            next[0]=NULL;
            next[1]=NULL;
        }
    }; 
    node* trie;
    Trie(){
        trie=new node();
    }
    
    void insert(vector<int> a){
        int i=0,n;
        node* it=trie;
        while (i<32){
            if (it->next[a[i]]==NULL)
            it->next[a[i]]=new node();
            it=it->next[a[i]];
            i++;
        }
        return;
        }
        
    int maxi(vector<int> b){
            int maxi=0;
            int i=0,j,p,n;
            node *it1=trie;
            while (i<32){
       if ((it1->next[1]==NULL) && (b[i]==0)){
                 it1=it1->next[0];
                 i++;
                }
                else
                break;
            }
            int zz;
            while(i<32){
                zz=b[i] xor 1;
                if (it1->next[zz]!=NULL){
                p=31-i;
                maxi+= pow(2,p);
                 it1=it1->next[zz];
                }
                else
                 it1=it1->next[b[i]];
                i++;   
            }
            return maxi;
        }
};

vector<int> tobits(int a){
    int i,jj=0;
     vector<int> x(32);
     stack<int> s;
    while (a>0){
        s.push(a%2);
        a=a/2;
    }
     for (i=s.size();i<32;i++)
    s.push(0);  
   while (!s.empty())
   {x[jj]=(s.top());
   jj++;
   s.pop();
   }
    return x;
}
int main(){
    Trie *dict=new Trie();
    int i,maxi=0,n;
    cin>>n;
    vector<vector<int>> b(n);
   vector<int> a(n); 
    for (i=0;i<n;i++){
        cin>>a[i];
        b[i]=(tobits(a[i]));
        dict->insert(b[i]);
    }
    int cc=0;
    for (i=0;i<n;i++){
        cc=dict->maxi(b[i]);
        maxi=max(maxi,cc);
    }
    cout<<maxi;
    return 0;
}

/*

5
3 10 5 15 2

*/