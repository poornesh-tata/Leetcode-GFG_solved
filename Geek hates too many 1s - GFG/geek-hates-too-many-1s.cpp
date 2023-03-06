//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    int noConseBits(int n) {
        // code here
        int f=0;
        for(int i=32;i>=0;i--)
        {
            if(n&(1<<i))
            {
                f=i;
                break;
            }
        }
        // cout<<f<<endl;
        int c=0;
        while(f>=0)
        {
            // cout<<(1<<f)<<" "<<n<<endl;
            if( (1<<f) & n )
            {
                c++;
            }
            else c=0;
            if(c==3)
            {
                n-=(1<<f);
                c=0;
            }
            f--;
        }
        return n;
    }
};


//{ Driver Code Starts.

int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}

// } Driver Code Ends