//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here   
        int i=0,j=0,count=0,ans=INT_MAX;
        unordered_map<int,int> hash,temp;
        for(auto it:str) hash[it]++;
        count=hash.size();
        
        for(int i=0;i<str.size();i++)
        {
            temp[str[i]]++;
            if(temp.size()==count)
            {
                ans=min(ans,i-j+1);
            }
            while(temp.size()==count)
            {
                temp[str[j]]--;
                if(temp[str[j]]==0) temp.erase(str[j]);
                ans=min(ans,i-j+1);
                j++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends