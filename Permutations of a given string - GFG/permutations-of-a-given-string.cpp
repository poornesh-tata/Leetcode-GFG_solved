//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void fun(string s,set<string>& hash,string& str,vector<int>& vis)
        {
            if(str.size()==s.size())
            {
                hash.insert(str);
                return ;
            }
            for(int i=0;i<s.size();i++)
            {
                if(!vis[i])
                {
                    vis[i]=1;
                    str+=s[i];
                    fun(s,hash,str,vis);
                    str.pop_back();
                    vis[i]=0;
                }
            }
        }
    	vector<string>find_permutation(string S)
		{
		    // Code here there
		    string str;     vector<string> ans;
		    set<string> hash;   vector<int> vis(S.size(),0);
		    fun(S,hash,str,vis);
		    for(auto it:hash)
		    {
		        ans.push_back(it);
		    }
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends