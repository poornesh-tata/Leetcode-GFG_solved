//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
bool valid(string str);
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        cout<<valid(str)<<endl;
    }
    return 0;
}
// } Driver Code Ends


bool valid(string st)
{
    // code here
    stack<char> s;
    for(auto it:st)
    {
        if(it=='(' or it=='{' or it=='[') s.push(it);
        else 
        {
            if(s.empty()) return false;
            if( it==')' and s.top()=='(') s.pop();
            else if( it==']' and s.top()=='[') s.pop();
            else if(it=='}' and s.top()=='{') s.pop();
            else return false;
        }
    }
    if(s.size()!=0) return false;
    return true;
}