#include<iostream>
#include<fstream>
using namespace std;
int main(){
    string data;
    cout<<"hello world"<<endl;

    ofstream MyFile;
    MyFile.open("C://Users//niles//Desktop//copy_movies.txt"); //is used to make and open a text file
   // MyFile<<"Files can be tricky, but it is fun enough!"<<endl<<"line changed";
   // MyFile.close(); //to clean up unnecessary memory spaces
   
    ifstream infile; 
    infile.open("C:\\Users\\niles\\Desktop\\zzzz.txt"); 
    int i,j,k;
    string pp,gg,hh;
    while (getline (infile, data)) {
        gg.clear();
        hh.clear();
        for(i=0;i<data.size();i++){
            if (data[i]==' '){
                while(i<data.size() && data[i]==' ')
                    i++;
                break;
            }
                
        }
        if (i<data.size()){
            pp=data.substr(i,data.size()-i);
            
            j=i;
            for(i=0;i<pp.size();i++){
                gg+=pp[i];
                if (pp[i]=='('){
                    k=gg.size()-2;
                    while (k>=0 && gg[k]==' '){
                        k--;
                    }
                    gg=gg.substr(0,k+1);
                    while(i<pp.size() && pp[i]!=')')
                        i++;
                    if (i+1<pp.size()){
                        hh=pp.substr(i+1,pp.size()-i-1);
                    }
                    pp=gg+hh;
                    break;
                }  
            }
            i=j;
            k=pp.size()-1;
            while(k>=0 && pp[k]==' '){
                k--;
            }
            pp=pp.substr(0,k+1);
        }
            
        else{
            pp=data;
        }
        data=pp;
        
        //data=data + ",1980,3";
        MyFile<<data<<endl;
        //cout<<data<<endl;
    }
    MyFile.close();
    infile.close();
    return 0;
}
