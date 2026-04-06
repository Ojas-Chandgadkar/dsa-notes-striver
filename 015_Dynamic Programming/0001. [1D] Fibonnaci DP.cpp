/*
Fibonnaci series is : 
Series    : 0 1 1 2 3 5 8 13 21 ......
Position  : 0 1 2 3 4 5 6  7  8 

You have to write a program that prints the series upto 'n'th position.
*/


// Plain Recursion : ----------------------------------------------------------
// (already done in recursion)
#include<bits/stdc++.h>
using namespace std;

int fib(int n){
  if(n==0 || n==1) return n;
  return fib(n-1) + fib(n-2);
}

int main(){
  
  int n;
  cin >> n;
  
  cout << fib(8);
  return 0;
}


// MEMOIZATION : ----------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;

int fib(int n, vector<int> &dp){

        if(n==0 || n==1) return n;

        if(dp[n]!=-1) return dp[n];
        return dp[n] = fib(n-1, dp) + fib(n-2, dp);
}

int main()
{
        int n;
        cin >> n;

        vector<int> dp(n+1, -1);
        cout << fib(n, dp);
}


// TABULATION : ----------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;

int main()
{
        int n; 
        cin >> n;
        
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;

        for(int i=2; i<=n; i++){
                dp[i] = dp[i-1] + dp[i-2];
        }

        cout << dp[n];       
}

// TABULATION (using less space) : ----------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;

int main()
{
        int n;
        cin >> n;

        int last = 1;
        int secondLast = 0;
        int curr = 1;

        for(int i=2; i<=n; i++){
                curr = last + secondLast;
                secondLast = last;
                last = curr;
        }

        cout << curr;
        return 0;
}



/*
The aprroaches get better, as,
        0. Plain Recursion                              --> We recompute the same subproblem again and again.
        1. Memoization (Recursion)                      --> Better than plain recurssion without dp, still uses call stack which takes storage 
        2. Tabulation (Iterative)                       --> Better than Memoization, as no recursive stack, but still array is used
        3. Tabulation without array (Iterative)         --> Better than tabulation with array, as not even an array is used.
*/