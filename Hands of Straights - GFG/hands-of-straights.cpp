//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        // code here
        if(N % groupSize!=0) return false;
        
        unordered_map<int,int> hash;
        for(auto it:hand) hash[it]++;
        sort(hand.begin(),hand.end());
        
        int temp=groupSize; int c=0;
        for(int i=0;i<N;i++)
        {
            if(hash[hand[i]]<=0) continue;
            int val = hand[i];
            for(int i=0;i<groupSize;i++)
            {
                if(hash.find(val)==hash.end())
                {
                    return false;
                }
                hash[val]--;
                val++;
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
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends