#include<iostream>
#include<vector>
using namespace std;

bool rowcheck(vector<vector<char> > &b,int pp,int qq){
    int i,j,k;
            for(k=0;k<9;k++){
                if ((k!=qq)&&(b[pp][qq]==b[pp][k]))
                return false;
            }
            for(k=0;k<9;k++){
                if ((k!=pp)&&(b[pp][qq]==b[k][qq]))
                return false;
            }
    return true;
}
bool chbo(vector<vector<char> > &b,int i,int j){
    int r=i/3;
    int c=j/3;
    r=r*3;
    c=c*3;
    int u,y,fl=0;
    for (u=r;u<r+3;u++){
        for (y=c;y<c+3;y++){
            if (b[i][j]==b[u][y])
            fl++;
            if (fl==2)
            return false;
        }
    }
    return true;
}
bool boxcheck(vector<vector<char> > &b,int pp,int qq){
    int i,j,k;
    if (!chbo(b,i,j))
        return false;
    return true;
}
bool check (vector<vector<char> > &b,int pp,int qq){
    if (b[pp][qq]=='.')
    return true;
    if (!rowcheck(b,pp,qq))
    return false;
    if (!boxcheck(b,pp,qq))
    return false;
    return true;
}
bool solve(vector<vector<char> > &b,int pp,int qq){
    if (!check(b,pp,qq))
    return false;
    vector<vector<char> > v=b;
    int i,j,k;
    char p='0';
    int fl=0;
    for (i=0;i<9;i++){
        for (j=0;j<9;j++){
            p='0';
            fl=0;
            if (b[i][j]=='.'){
                for (k=1;k<10;k++){
                    v[i][j]==p+k;
                    if (solve (v,i,j))
                        {b=v;
                        return true;
                        }
                    else
                    v=b;
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<char> > b=A;
    bool k=solve(b,0,0);
    if (k)
    A=b;
    else
    A[0][0]='9';
    return;
}
int main(){
	//vector<vector<char> > v={{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'}, {'.','9','8','.','.','','.','6','.'}, {'8','.','.','.','6','.','.','.','3'},{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'}, {'.','9','8','.','.','','.','6','.'}, {'8','.','.','.','6','.','.','.','3'}};
	vector<vector<char> > v;
	int i,j;
					char ch;
	cout<<"enter sudoku"<<endl;
		for (i=0;i<9;i++){
			for (j=0;j<9;j++){

				cin>>ch;
				v[i][j]=ch;
			}
				cout<<"2nd row"<<endl;
		}
	cout<<"hello sudoku"<<endl;
	solveSudoku(v);
	for (i=0;i<9;i++){
		for (j=0;j<9;j++){
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}


/*
5 3 . . 7 . . . . 6 . . 1 9 5 . . . . 9 8 . . . . 6 . 8 . . . 6 . . . 3 4 . . 8 . 3 . . 1 7 . . . 2 . . . 6 . 6 . . . . 2 8 . . . . 4 1 9 . . 5 . . . . 8 . . 7 9
53..7....6..195....98....6.8...6...34..8.3..17...2...6.6....28....419..5....8..79







*/
