#include<iostream>
#include <bits/stdc++.h>
#include<vector>
using namespace std;
int LENGTHSCS(string x, string y, int n, int m){
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
    vector<char> v;
    int i=n,j=m;
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
            v.push_back(x[i-1]);
          i--; j--;
        }
        else{
            if(t[i-1][j]>t[i][j-1]){
                v.push_back(x[i-1]);
                i--;
            }
            else{
                v.push_back(y[j-1]);
              j--;
            }
        }
    }
            while(i>0){
                v.push_back(x[i-1]);
                i--;
            }
            while(j>0){
                v.push_back(y[j-1]);
                j--;
            }
            string s;
            reverse(v.begin(), v.end());
            for(int i=0;i<v.size();i++)
            s.push_back(v[i]);
            
    cout << "SCS of " << x << " and " << y << " is " << s << endl;
    
    return t[n][m];
}

int main()
{
    string x;
    string y;
    cin>>x>>y;
    int lcs = LENGTHSCS(x,y,x.size(),y.size());
    int n=x.size();
    int m=y.size();
    int lengthofscs = m + n - lcs;
    cout<<lengthofscs;
    return 0;
}
/*
OUTPUT: SCS of AGGTAB and GXTXAYB is AGGXTXAYB
9
*/
