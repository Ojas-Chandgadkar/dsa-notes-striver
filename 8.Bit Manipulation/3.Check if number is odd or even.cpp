string oddEven(int N){
    return ((N&1)==0)? "even" : "odd";
}



// Even numbers have their rightmost bit set to 0;
// Odd numbers have their rightmost bit set to 1.
// Using this property we can create a mask like,.
//          1010101         (Any random number)
//        & 0000001         (Mask)
//         ---------- 
//          0000001         (0:even | 1:odd)