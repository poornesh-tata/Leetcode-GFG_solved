//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        vector<long long> r;
        stack<pair<long long,int>> s;
        r.push_back(-1);
        s.push({arr[n-1],n-1});
        
        for(int i=n-2;i>=0;i--)
        {
            if(s.top().first<arr[i]) r.push_back(s.top().second);
            else
            {
                while(!s.empty() and s.top().first>=arr[i]) s.pop();
                if(s.empty()) r.push_back(-1);
                else r.push_back(s.top().second);
            }
            s.push({arr[i],i});
        }
        reverse(r.begin(),r.end());
        while(!s.empty()) s.pop();
        
        vector<long long> l;
        s.push({arr[0],0});
        l.push_back(-1);
        
        for(int i=1;i<n;i++)
        {
            if(s.top().first<arr[i]) l.push_back(s.top().second);
            else
            {
                while(!s.empty() and s.top().first>=arr[i]) s.pop();
                if(s.empty()) l.push_back(-1);
                else l.push_back(s.top().second);
            }
            s.push({arr[i],i});
        }
        long long max=0;
        long long area=0;
        for(int i=0;i<n;i++)
        {
            if(r[i]==-1 and l[i]==-1) area=(n*arr[i]);
            else if(r[i]==-1) area=(arr[i]*(n-l[i]-1));
            else if(l[i]==-1) area=(arr[i]*(r[i]));
            else area=arr[i]*(r[i]-l[i]-1);
            if(area>max) max=area;
        }
        return max;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends