/*

Bit manipulation :  
    As the name suggests is modifying data mostly numbers by modifying their bits. 
    A bit is the smallest unit of data that a computer can manage and store. 
    All data is in bits in its basic form. 
        Decimal System :  0 1 2 3 4 5 6 7 8 9
        Binary System  :  0 1
    Every data for a computer is stored in Binary System using bits (1 and 0).


    DECIMAL TO BINARY : 
        Convereted by dividing the decimal digit by 2 and writing out the remainder aside.
        Examples for Decimal to bits : 	
            1 is 1
            2 is 10
            3 is 11
            4 is 100
            5 is 101
            6 is 110
            7 is 111
            8 is 1000
            9 is 1001
            10 is 1010
            15 is 1111
            20 is 10100
            50 is 110010
            70 is 1000110
            100 is 1100100
        

    BITWISE OPERATORS : 
        &	(and)(+ve if both positve)
        |	(or)(+ve if atleast one positive)
        ^	(xor)(+ve if both different)
        ~   (compliment)(toggle bits)
        <<	(right shift)(shifts bits of a number to right by desired times, each shift *2 the number)
        >>	(left shift)(shifts bits of a number by to left desired times, each shift /2 the number)



*/ 

    int n = 5 << 2;            
    // 101 << 2 = 10100
    // Decimal 5 has become decimal 20.

    int m = 15 >> 1;
    // 1111 >> 1 = 11
    // Decimal 15 becomes decimal 7.

/*
    BASIC FUNCTIONS : 
        1. getBit
        2. setBit
        3. clearBit
        4. toggleBit
        5. updateBit
        All functions use concept of 'masking', a mask is a binary number used to modify other binary number. 
        Both binary numbers undergo bitwise operations.
        Example of masking in setbit : 
            Consider :
                For setBit(20, 2) 
                10100    //  Number 20
            OR  00010    //  Mask (made by 1<<2-1)
            ------------
                10110    // 2 bit set to 1

        Note that : 1 << 0 means decimal 1.
                    1 << 1 means decimal 2
                    1 << 2 means decimal 4. and so on,
                    So we have to do (n-1) to get to the real.
            
*/

    bool getBit(int n, int i){                  // get bit present at i position of n, and return it
        return (n>>i-1) & 1;           
    }

    bool setBit(int n, int i){                  // set bit present at i position of n to 1, and return it
        return n | (1<<i-1)
    }

    bool clearBit(int n, int i){                // set bit present at i position of n by 1, and return it
        return n | (1<<n)
    }   

    bool toggleBit(int n, int i){               // toggle bit present at i position, and return it
        return n & ~(1<<i-1);
    }

    bool updateBit(int n, int i, int u){        // set bit present at 'i' position of 'n' to 'u', and return it
        n = n & ~(1<<i-1);
        return n | (u<<i-1);
    }