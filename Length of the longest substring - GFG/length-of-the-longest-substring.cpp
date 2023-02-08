//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string s){
        //code
        vector<char> v;
        int ans=INT_MIN,size=0;
        
        for(int i=0;i<s.size();i++)
        {
            if(find(v.begin(),v.end(),s[i])==v.end())
            {
                v.push_back(s[i]);
                size=v.size();
                ans=max(ans,size);
            }
            else
            {
                auto it=find(v.begin(),v.end(),s[i]);
                v.erase(v.begin(),it+1);
                size=v.size();
                ans=max(ans,size);
                v.push_back(s[i]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends