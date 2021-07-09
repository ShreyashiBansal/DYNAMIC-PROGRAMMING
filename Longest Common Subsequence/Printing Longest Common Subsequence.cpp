#include<iostream>
#include<vector>
using namespace std;
void PRINTLCS(string x, string y, int n, int m){
    int t[n+1][m+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 || j==0)
              t[i][j]=0;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(x[i-1]==y[j-1])
              t[i][j] = t[i-1][j-1] + 1 ;
            else 
              t[i][j] = max(t[i-1][j],t[i][j-1]);
        }
    }
    int index = t[n][m];
    char lcs[index+1];
    lcs[index] = '\0';
    int i=n,j=m;
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
          lcs[index-1] = x[i-1];
          i--; j--; 
          index--; 
        }
        else{
            if(t[i-1][j]>t[i][j-1])
              i--;
            else
              j--;
        }
    }
    cout << "LCS of " << x << " and " << y << " is " << lcs;
}

int main()
{
    string x;
    string y;
    cin>>x>>y;
    PRINTLCS(x,y,x.size(),y.size());
    return 0;
}
/*
output: LCS of AGGTAB and GXTXAYB is GTAB
*/
