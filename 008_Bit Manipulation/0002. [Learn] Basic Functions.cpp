// You have a 32-bit unsigned integer called 'num' and another integer called 'i'.
// You need to perform the following operations on the 'num' integer based on the value of 'i':

// 1. Get the bit value at the "i"th position of "num".
// 2. Set the bit at the "i"th position of "num".
// 3. Clear the bit at the "i"th position of "num".
// We are starting bits from 1 instead of 0. (1-based)



vector<int> bitManipulation(int num, int i){
    
    vector<int> res;

    res.push_back((num>>i-1)&1);
    res.push_back(num|(1<<i-1));
    res.push_back(num&~(1<<i-1));

    return res;
}