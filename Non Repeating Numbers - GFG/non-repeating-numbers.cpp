//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int x=0;
        for(auto it:nums) x=x^it;
        
        int a=1;
        while(!(x&a))
        {
            a=a<<1;
        }
        vector<int> ans;
        int l=0,r=0;
        for(auto it:nums)
        {
            if(it&a)
            {
                l=l^it;
            }
            else
            {
                r=r^it;
            }
        }
        return {min(l,r),max(l,r)};
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends