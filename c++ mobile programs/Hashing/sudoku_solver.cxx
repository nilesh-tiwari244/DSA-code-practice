#include<iostream>
#include<vector>
#include<map>
using namespace std;

bool checkrow(vector<vector<char>> a){
    int i,j;
    map<char,int> mp;
    for (i=0;i<9;i++){
        for (j=0;j<9;j++){
            if (a[i][j]!='.'){
                mp[a[i][j]]++;
                if (mp[a[i][j]]>1)
                return false;
            }
        }
        mp.clear();     
    }
  return true;  
}

bool checkcol(vector<vector<char>> a){
 int i,j;
    map<char,int> mp;
    for (j=0;j<9;j++){
        for (i=0;i<9;i++){
                if (a[i][j]!='.'){
                mp[a[i][j]]++;
                if (mp[a[i][j]]>1)
                return false;
            }
        }
        mp.clear();     
    }
  return true;     
    
    
}

bool checkcube(vector<vector<char>> a){
  int k,i,j,il,ih,jl,jh; 
  map<char,int> mp;
    for (k=1;k<=9;k++){
        
        if (k<4)
        il=0;
        else if (k<7)
            il=3;
        else
            il=6;
            ih=il+2;
            
       if(k%3==1)
       jl=0;
       else if(k%3==2)
       jl=3;
       else
       jl=6;
       jh=jl+2;
       
    for (j=jl;j<=jh;j++){
        for (i=il;i<=ih;i++){
                if (a[i][j]!='.'){
                mp[a[i][j]]++;
                if (mp[a[i][j]]>1)
                return false;
            }}}
        mp.clear();           
    }
    return true;
}

bool check(vector<vector<char>> a){    if((checkrow(a))&&(checkcol(a))&&(checkcube(a)))
return true;
return false;    
}

bool sudokusolver(vector<vector<char>> & A){
   if (!check(A)) 
   return false;
   
   vector<vector<char>> b;
   int i,j;
   char k;
   for (i=0;i<9;i++){
    for(j=0;j<9;j++){
        if (A[i][j]=='.'){
            for (k='1';k<='9';k++){
                b=A;
                b[i][j]=k;
                if (sudokusolver(b))
                {A=b;
                break;
                }
            }
            if (A[i][j]=='.')
            return false;
        }
    }
   }
     return true;
}

int main(){
   int i,j,n=9;
   vector<vector<char>> a;
   a={{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    for (i=0;i<n;i++){
        for(j=0;j<n;j++)
            cout<<a[i][j]<<"  ";
            cout<<endl;
    } 
    cout<<endl;
  if(sudokusolver(a))
    {cout<<"below is solution"<<endl<<endl;
       for (i=0;i<n;i++){
        for(j=0;j<n;j++)
            cout<<a[i][j]<<"  ";
            cout<<endl;
    }
    }
    else
    cout<<"not possible";   
    return 0;
}