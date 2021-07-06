# DYNAMIC-PROGRAMMING
Implementation of Dynamic Programming.
Dynamic Programming: Dynamic Programming (DP) is an algorithmic technique for solving an optimization problem by breaking it down into simpler subproblems and utilizing the fact that the optimal solution to the overall problem depends upon the optimal solution to its subproblems.

# Dynamic Programming Method
   1. **Top-down with Memoization**  -  
        In this approach, we try to solve the bigger problem by recursively finding the solution to smaller sub-problems. Whenever we solve a sub-problem, we cache its result so           that we don’t end up solving it repeatedly if it’s called multiple times. Instead, we can just return the saved result. This technique of storing the results of already           solved subproblems is called Memoization.
        
   2. **Bottom-up with Tabulation**  -  
        Tabulation is the opposite of the top-down approach and avoids recursion. In this approach, we solve the problem “bottom-up” (i.e. by solving all the related sub-problems         first). This is typically done by filling up an n-dimensional table. Based on the results in the table, the solution to the top/original problem is then computed.
        
  # Patterns of Dynamic programming  -  
  1) 0/1 knapsack
  2) Unbounded knapsack
  3) LCS(Longest Common Sequence)
  4) Kadane's Algorithm
  5) Matrix Chain Multiplication
  6) DP on Tree 
  7) DP on Grid
