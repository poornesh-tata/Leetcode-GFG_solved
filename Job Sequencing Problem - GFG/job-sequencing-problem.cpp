//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<pair<int,int>> v; int max_deadline = 0;
        for(int i=0;i<n;i++)
        {
            v.push_back({arr[i].profit,arr[i].dead}); // {profit and deadline};
            if(arr[i].dead>max_deadline) max_deadline = arr[i].dead;
        }
        sort(v.begin(),v.end());
        
        int profit = 0; int count = 0;
        vector<int> deadline(max_deadline+1,0);
        
        for(int i=n-1;i>=0;i--)
        {
            int j = v[i].second;
            while(j>0)
            {
                if(deadline[j]==0)
                {
                    count++;
                    profit+=v[i].first;
                    deadline[j]=1;
                    break;
                }
                else j--;
            }
        }
        return {count,profit};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends