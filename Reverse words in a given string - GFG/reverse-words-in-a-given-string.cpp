//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        string res =""; string str = "";
        for(int i=0;i<S.size();i++)
        {
            str+=S[i];
            if(S[i]=='.')
            {
                res=str+res;
                str = "";
            }
        }
        res ='.'+res;
        res=str+res;
        
        res.pop_back();
        return res;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends