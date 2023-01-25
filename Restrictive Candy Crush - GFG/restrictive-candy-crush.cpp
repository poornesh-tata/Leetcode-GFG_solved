//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    string Reduced_String(int k,string s){
        // Your code goes here
        stack<pair<char,int>> st;
        for(auto it:s)
        {
            if(st.empty())
            {
                st.push({it,1});
            }
            else if(st.top().first==it)
            {
                int x=st.top().second;
                st.pop();
                st.push({it,++x});
            }
            else
            {
                st.push({it,1});
            }
            if(st.top().second==k) st.pop();
        }
        string ans;
        while(!st.empty())
        {
            int x=st.top().second;
            while(x--)
            {
                ans+=st.top().first;
            }
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }


};

//{ Driver Code Starts.

int main() {
    
    
    int t;cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.Reduced_String(k,s)<<"\n";
        
    }
    
	return 0;
}
// } Driver Code Ends