#include<iostream>
#include <bits/stdc++.h>
#include<vector>
using namespace std;
int LCS(string x, string y, int n, int m){
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
    //CREATED THE LCS TABLE
    return t[n][m];
}

int main()
{
    string x;
    string y;
    cin>>x>>y;
    int lcs = LCS(x,y,x.size(),y.size());
    int n=x.size();
    int m=y.size();
    cout<<"Minimum Number of Deletion "<< n-lcs <<endl;
    cout<<"Minimum Number of Insertion "<< m-lcs <<endl;
    return 0;
}
/*
Input:
heap 
pea

Output: 
Minimum Number of Deletion 2
Minimum Number of Insertion 1

*/
