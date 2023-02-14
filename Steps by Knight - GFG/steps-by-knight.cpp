//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    bool isvalid(int i,int j,int n)
    {
        if(i<0 or j<0 or i>=n or j>=n) return false;
        return true;
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    // Code here
	    int row[8]={-2,-1,1,2,2,1,-1,-2};
	    int col[8]={1,2,2,1,-1,-2,-2,-1};
	    int sx=KnightPos[0],sy=KnightPos[1];
	    int dx=TargetPos[0],dy=TargetPos[1];
	    vector<vector<int>> vis(n,vector<int>(n,0));
	    queue<pair<int,int>> q;
	    q.push({sx,sy});
	    int d=0;
	    
	    while(!q.empty())
	    {
	        int size=q.size();d++;
	        for(int i=0;i<size;i++)
	        {
    	        int x=q.front().first;
    	        int y=q.front().second;
    	        q.pop();
    	        for(int i=0;i<8;i++)
    	        {
    	            int nx=x+row[i];
    	            int ny=y+col[i];
    	            if(nx==dx and ny==dy) return d;
    	            if(isvalid(nx,ny,n) and !vis[nx][ny])
    	            {
    	                q.push({nx,ny});
    	                vis[nx][ny]=1;
    	            }
    	        }
	        }
	    }
	    return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends