 #include <iostream>
using namespace std;
int knapSack(int W, int leng[], int price[], int n){
    int i, w;
    int K[n + 1][W + 1];
 
    // Build table K[][] in bottom up manner
    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (leng[i - 1] <= w)
                K[i][w] = max(price[i - 1] + K[i][w - leng[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}

int main()
{
    int price[] = { 60, 100, 120 };
    int leng[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(price) / sizeof(price[0]);
    cout << knapSack(W, leng, price, n);
    return 0;
}
