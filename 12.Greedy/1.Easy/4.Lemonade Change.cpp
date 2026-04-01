
// At a lemonade stand, each lemonade costs $5. 
// Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). 
// Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. 
// You must provide the correct change to each customer so that the net transaction is that the customer pays $5.

// Note that you do not have any change in hand at first.

// Given an integer array bills where bills[i] is the bill the ith customer pays, 
// return true if you can provide every customer with the correct change, or false otherwise.




class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        int cntr_5bills = 0;
        int cntr_10bills = 0;
        int n = bills.size();

        for(int i=0; i<n; i++){
            if(bills[i] == 5){
                cntr_5bills++;
            }
            else if(bills[i]==10 && cntr_5bills >= 1){
                cntr_5bills--;
                cntr_10bills++;
            }
            else if(bills[i]==20 && cntr_10bills>=1 && cntr_5bills>=1){
                cntr_10bills--;
                cntr_5bills--;
            }
            else if(bills[i]==20 && cntr_5bills>=3){
                cntr_5bills -= 3;
            }
            else{
                return false;
            }
        }

        return true;
    }
};