#include <bits/stdc++.h>
using namespace std;
// int BE(int base,int exp)
// {
//     // Iterative way of calculating 
//     int ans=1;
//     while(exp)
//     {
//         if(exp%2==0)
//         {
//             base=base*base;
//             exp/=2;
//         }
//         else
//         {
//             ans=ans*base;
//             exp--;
//         }
//     }
//     return ans;
// }
int BE(int base,int exp)
{
  // Recursive way of binary exponentiation
    if(exp==0) return 1;
    int ans=BE(base,exp/2);
    if(exp%2==0) return ans*ans;
    else return ans*ans*base;
}
int main() {
    int base,exp;
    cin>>base>>exp;
    cout<<BE(base,exp);
    
}
