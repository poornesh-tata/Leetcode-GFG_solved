//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        // code here
        int five=0; int ten=0;
        for(auto it:bills)
        {
            if(it==5) five++;
            else if(it==10)
            {
                if(five<1) return false;
                else
                {
                    five--;
                    ten++;
                }
            }
            else 
            {
                if(ten<1)
                {
                    if(five<3) return false;
                    else
                    {
                        five-=3;
                    }
                }
                else
                {
                    if(five<1) return false;
                    else
                    {
                        ten--;
                        five--;
                    }
                }
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends