int DivCountSum(int n)
{
    // Example when n==8;
    int sum=0;
    for(int i=1;i<=n;i++) sum+=(n/i); 
    return sum;
    // (8/1) gives the no. of 1 multiples b/w 1 and 8 --> 1,2,3,4,5,6,7,8
    // (8/2) gives the no. of 2 multiples b/2 1 and 8 --> 2,4,6,8
    // (8/3) gives the no. of 3 multiples b/2 1 and 8 --> 3,6 
    // (8/4) gives the no. of 4 multiples b/2 1 and 8 --> 4,8
    // .........
    // Similarly we count for all numbers in 1 and n
}
