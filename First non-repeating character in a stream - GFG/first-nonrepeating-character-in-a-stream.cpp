//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    unordered_map<char,int> hash;
		    queue<char> q; string ans = "";
		    for(auto it:A)
		    {
		        hash[it]++;
		        if(hash[it]==1) q.push(it);
		        while(!q.empty())
		        {
		            if(hash[q.front()]>1) q.pop();
		            else break;
		        }
		        if(!q.empty()) ans+=q.front();
		        else ans+='#';
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends