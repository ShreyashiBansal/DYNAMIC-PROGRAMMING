#include <iostream>
using namespace std;
int knapSack(int w, int wt[], int val[], int n){
    if(n==0 || w==0)
      return 0;
     if(wt[n-1]<=w){
         return max(val[n-1]+knapSack(w-wt[n-1], wt, val, n-1),knapSack(w, wt, val, n-1));
     }
     else
         return knapSack(w, wt, val, n-1);
}

int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapSack(W, wt, val, n);
    return 0;
}
/*
Time Complexity:O(2^n)
Space Complexity: O(1)
*/
