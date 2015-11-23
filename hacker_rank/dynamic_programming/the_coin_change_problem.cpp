/*
 * 
 * Problem Statement

How many different ways can you make change for an amount, given a list of coins? In this problem, your code will need to efficiently compute the answer.

Task

Write a program that, given

An amount N and types of infinite available coins M
A list of M coins - C={C1,C2,C3,..,CM}
Prints out how many different ways you can make change from the coins to STDOUT.

The problem can be formally stated:

Given a value N, if we want to make change for N cents, and we have infinite supply of each of C={C1,C2,…,CM} valued coins, how many ways can we make the change? The order of coins doesn’t matter.

Constraints

1≤Ci≤50
1≤N≤250
1≤M≤50
The list of coins will contain distinct integers.
Solving the overlapping subproblems using dynamic programming

You can solve this problem recursively, but not all the tests will pass unless you optimise your solution to eliminate the overlapping subproblems using a dynamic programming solution

Or more specifically;

If you can think of a way to store the checked solutions, then this store can be used to avoid checking the same solution again and again.
Input Format

First line will contain 2 integer N and M respectively. 
Second line contain M integer that represent list of distinct coins that are available in infinite amount.

Output Format

One integer which is the number of ways in which we can get a sum of N from the given infinite supply of M types of coins.
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

long ways_to_make_change(int m, int n, const vector<int>& coins, long** dp)
{
    // if number of coins is 0 or value to make < 0, return 0
    if (m==0 || n<0)
        return 0;
    // if value to make is 0, return 1
    else if (n==0)
        dp[m-1][0] = 1;
    else if (dp[m-1][n]<0)
    {
        dp[m-1][n]=ways_to_make_change(m-1, n, coins, dp) + ways_to_make_change(m, n-coins[m-1], coins, dp);
    }
    else
    {
        //do nothing
    }
    return dp[m-1][n];
}

long ways_to_make_change(int n, vector<int>& coins)
{
    //sort
    sort(coins.begin(), coins.end());
    int m = coins.size();

    //vector to store number of ways to make a particular value 0 to n, size n+1
    long** dp = new long*[m];
    for (int i=0; i<m; ++ i)
    {
        dp[i] = new long[n+1];
        for (long j=0; j<=n; ++j)
            dp[i][j]=-1;
    }

    //size of coins array, value to make, coins, dp
    return ways_to_make_change(m, n, coins, dp); 
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int m=0, n=0;
    cin>>n>>m;
    vector<int> coins(m);

    for(size_t i=0; i<=m; ++i)
        cin>>coins[i];
    long result=ways_to_make_change(n, coins);
    cout<<result<<endl;

    return 0;
}

