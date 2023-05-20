//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        // code here
        if(N % groupSize!=0) return false; 
        if(groupSize==1)return true; map<int,int>mp; int ans=0;
        
        for(int i=0;i<N;i++)mp[hand[i]]++;
        
        for(auto it:mp)
        {
            int a=it.first; int c=1;
            while(mp.find(a)!=mp.end() and c<=groupSize)
            {
                mp[a]--;
                if(mp[a]==0){
                    mp.erase(a);
                }
                a++; c++;
            }
            if(c>groupSize)
            {
                ans++;
            }
        }
        return ans*groupSize==N;
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