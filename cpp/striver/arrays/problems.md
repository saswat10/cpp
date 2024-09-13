1. put all zeroes at the end
   
   > brute force - pick all the non zero numbers and put them in a temporary array. Then put the zeroes at the end.

   > Optimal Soln - 2 pointer approach - run till you get a zero, then start the loop from where you get zero... after that start swapping whenever you get zero..

2. Missing number
    > double loop
    
    > hashing
    
    > summation and difference

    > xor operation (for bigger data types)
    ```cpp
    int xor1 = 0, xor2 = 0;
    int n = N-1;
    for(int i =0; i<n; i++){
        xor2 = xor2 ^ a[i];
        xor1 = xor1 ^ (i+1);
    }
    xor1 = xor1 ^ N;
    return xor1 ^ xor2;
    ```