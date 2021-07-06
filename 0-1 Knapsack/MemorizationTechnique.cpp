#include <iostream>
using namespace std;
int knapSack(int w, int wt[], int val[], int n, int **dp){
    if(n==0 || w==0)
      return 0;
     if(wt[n-1]<=w){
         return dp[n][w]= max(val[n-1]+knapSack(w-wt[n-1], wt, val, n-1,dp),knapSack(w, wt, val, n-1,dp));
     }
     else
         return dp[n][w] = knapSack(w, wt, val, n-1,dp);
}

int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int w = 50;
    int n = sizeof(val) / sizeof(val[0]);
    int** dp;
    dp = new int*[n];
 
    // loop to create the table dynamically
    for (int i = 0; i < n; i++)
        dp[i] = new int[w + 1];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < w + 1; j++)
            dp[i][j] = -1;
    cout << knapSack(w, wt, val, n-1,dp);
    return 0;
}
/*
Time Complexity: O(N*W). 
Auxiliary Space: O(N*W). 
*/
