//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string S, string T) {
        // code here
        int j=0;
        for(int i=0;i<T.size(),j<S.size();i++)
        {
            if(!isdigit(T[i]))
            {
                if(S[j]!=T[i]) return 0;
                j++;
            }
            else
            {
                int num=0;
                while(i<T.size() and isdigit(T[i]))
                {
                    num=num*10+(T[i]-'0');
                    i++;
                }
                i--;
                j+=num;
            }
        }
        if(j>S.size()) return 0;
        return 1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends