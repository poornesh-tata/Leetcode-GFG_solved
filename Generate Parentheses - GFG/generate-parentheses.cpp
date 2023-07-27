//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void fun(int left, int right, vector<string>& ans, string str)
    {
        if(left==0 and right==0)
        {
            ans.push_back(str);
            return ;
        }
        if(left == right)
        {
            fun(left-1,right,ans,str+'(');
        }
        else
        {
            if(left>0) 
            {
                fun(left-1,right,ans,str+'(');
            }
            if(right>0)
            {
                fun(left,right-1,ans,str+')');
            }
        }
        
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string> ans;
        fun(n,n,ans,"");
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
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends