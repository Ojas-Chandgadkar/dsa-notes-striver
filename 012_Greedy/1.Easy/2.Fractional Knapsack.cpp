// You have been given weights and values of ‘N’ items. 
// You are also given a knapsack of size ‘W’.

// Your task is to put the items in the knapsack such that the total value of items in the knapsack is maximum.

// Note:
// You are allowed to break the items.
// Example:
// If 'N = 4' and 'W = 10'. The weights and values of items are weights = [6, 1, 5, 3] and values = [3, 6, 1, 4]. 
// Then the best way to fill the knapsack is to choose items with weight 6, 1 and  3. The total value of knapsack = 3 + 6 + 4 = 13.00   




#include <bits/stdc++.h> 
// ITEMS contains {weight, value} pairs.

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    double MAX_V = 0;

    map<pair<double,int>, int> effRatio;                                     // map<{itemEfficienvy, itemIndex} itemIndex>, a pair is added to make key unique when two items share same efficiency.
    for(int i=0; i<n; i++){
        double eff = (double)items[i].second/items[i].first;
        effRatio[{eff,i}] = i;
    }

    int bagFilled = 0;
    for(auto mpIt=effRatio.rbegin(); mpIt!=effRatio.rend(); ++mpIt){          // since keys(eff) in map are arranged in ascending order  
        int itemIndex = mpIt->second;
        double itemEff = mpIt->first.first;

        int val = items[itemIndex].second;
        int wt = items[itemIndex].first;

        if(bagFilled + wt <= w){                                               // take whole
            bagFilled += wt;
            MAX_V += val;
            if(bagFilled == w) break;
        }
        else if(bagFilled+wt > w){                                              // take fractional
            double spaceLeft = w - bagFilled;
            bagFilled += spaceLeft;
            MAX_V += spaceLeft*itemEff;
            break;
        }
        
    }
    

    return MAX_V;
    
}