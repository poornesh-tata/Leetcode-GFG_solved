//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int arr[], int n, int X)
    {
        //Your Code Here
        sort(arr,arr+n);
        for(int i=0;i<n-1;i++)
        {
            if(i>0 and arr[i]==arr[i-1]) continue;
            int left=i+1;
            int right=n-1;
            while(left<right)
            {
                if((arr[i]+arr[left]+arr[right])==X) return true;
                else if((arr[i]+arr[left]+arr[right])>X) right--;
                else left++;
            }
        }
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends