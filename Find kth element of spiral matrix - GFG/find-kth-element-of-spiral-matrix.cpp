//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int matrix[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		int left =0, top =0, bottom = n-1, right = m-1;
        while(top<=bottom and left<=right)
        {
            for(int i=left;i<=right;i++)
            {
                k--;
                if(k==0) return matrix[top][i];
            }
            top++;
            for(int i=top;i<=bottom;i++)
            {
                k--;
                if(k==0) return matrix[i][right];
            }
            right--;
            if(top<=bottom)
            {
                for(int i=right;i>=left;i--)
                {
                    k--;
                    if(k==0) return matrix[bottom][i];
                }
                bottom--;
            }
            if(left<=right)
            {
                for(int i=bottom;i>=top;i--)
                {
                    k--;
                    if(k==0) return matrix[i][left];
                }
                left++;
            }
        }
        return -1;
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends