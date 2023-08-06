//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void fun(string s,vector<string>& ans,string& str,vector<int>& vis)
    {
        if(str.size()==s.size())
        {
            ans.push_back(str);
            return ;
        }
        for(int i=0;i<s.size();i++)
        {
            if(!vis[i])
            {
                vis[i]=1;
                str+=s[i];
                fun(s,ans,str,vis);
                str.pop_back();
                vis[i]=0;
            }
        }
    }
    vector<string> permutation(string S)
    {
        //Your code here
        string str;     vector<string> ans;
	    vector<int> vis(S.size(),0);
	    fun(S,ans,str,vis);
	    sort(ans.begin(),ans.end());
	    return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends