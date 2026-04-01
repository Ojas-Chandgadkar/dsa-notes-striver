// Given an infinite supply of Indian currency i.e. [1, 2, 5, 10, 20, 50, 100, 500, 1000] valued coins and an amount 'N'.
// Find the minimum coins needed to make the sum equal to 'N'. 
// You have to return the list containing the value of coins required in decreasing order.



vector<int> MinimumCoins(int n)
{

    vector<int> res;
    vector<int> coins = {1,2,5,10,20,50,100,500,1000};
    int i = 8; 

    while(n!=0){
        if(n-coins[i] >= 0){
            n -= coins[i];
            res.push_back(coins[i]);
        }
        else{
            i--;
        }
    }


    return res;
    
}