//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
            // code here
            for(int i=0;i<s.size();i++)
            {
                if(s[i]=='.' and s[i+1]=='.') return 0;
            }
            int num=0,c=0,flag=0;
            for(auto it:s)
            {
                if(it!='.' and !isdigit(it)) return 0;
                else if(it=='.')
                {
                    c++;
                    if(num<0 or num>255) return 0;
                    num=0;
                    flag=0;
                }
                else
                {
                    if((flag==1 and num==0) or flag>3 or num>255) return 0;
                    num=num*10+(it-'0');
                    flag++;
                }
            }
            if(c!=3 or num<0 or num>255) return 0;
            return 1;
        }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
// } Driver Code Ends