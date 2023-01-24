//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long a[], int len)
{
    // Your code goes here
    int i=0,j=len-1,max=0,area=0;
    while(i<j)
    {
        int dist=j-i;
        area=min(a[i],a[j])*dist;
        if(area>max) max=area;
        if(a[i]<=a[j]) i++;
        else j--;
    }
    return max;
}


//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends