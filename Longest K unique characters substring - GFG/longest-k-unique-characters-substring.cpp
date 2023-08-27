//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        int i =0; int j =0; int ans = INT_MIN; int n = s.size();
        unordered_map<char,int> hash;
        while(j<n)
        {
            hash[s[j]]++;
            if(hash.size()==k)
            {
                ans = max(ans,j-i+1);
            }
            else if(hash.size()>k)
            {
                while(i<n and hash.size()!=k)
                {
                    hash[s[i]]--;
                    if(hash[s[i]]<=0) hash.erase(s[i]);
                    i++;
                }
            }
            j++;
        }
        return ans==INT_MIN?-1:ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends