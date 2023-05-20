//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        //Write your code here
        sort(range.begin(),range.end());
        vector<int> v;
        for(int i=0;i<q;i++)
        {
            bool flag=true; int c=0; int prev=INT_MIN; 
            for(auto it:range)
            {
                int start=it[0], end=it[1];
                if(start <= prev)
                {
                    start=prev+1;
                }
                if(queries[i]<=c+end-start+1)
                {
                    v.push_back(queries[i]-c+start-1);
                    flag=false;
                    break;
                }
                c+=end-start+1;
                prev=end;
            }
            if(flag) v.push_back(-1);
        }
        return v;
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
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends