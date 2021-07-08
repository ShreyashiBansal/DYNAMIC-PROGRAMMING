#include <iostream>
using namespace std;
int LCS(string x, string y, int n, int m){
    if(n==0 || m==0)
      return 0;
    if(x[n-1]==y[m-1])
      return  1+LCS(x,y,n-1,m-1);
    else
      return max(LCS(x,y,n,m-1),LCS(x,y,n-1,m));
}

int main()
{
    string x;
    string y;
    cin>>x>>y;
    cout << LCS(x,y,x.length(),y.length());
    return 0;
}
//Happy coding
/*
Time complexity: O(2^n) in worst case and worst case happens when all characters of X and Y mismatch i.e., length of LCS is 0.
LCS Problem Statement : Given two sequences, find the length of longest subsequence present in both of them.
                       A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.
                       For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”.
*/
