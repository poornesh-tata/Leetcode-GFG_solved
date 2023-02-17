//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int N, int K, vector<long long> GeekNum) {
        // code here
        vector<long long> v; int n=GeekNum.size(); long long sum=0;
        for(auto it:GeekNum)
        {
           v.push_back(it);
           sum+=it;
        } 
        sum-=GeekNum.back();
        
        for(int i=n;i<N;i++)
        {
            sum+=v[i-1];
            v.push_back(sum);
            sum=sum-v[i-K];
        }

        return v.back();
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends