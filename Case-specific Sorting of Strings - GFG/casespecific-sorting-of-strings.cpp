//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        string temp=str;
        sort(str.begin(),str.end());
        int x=0,y=-1;
        for(int i=0;i<n;i++)
        {
            if(islower(str[i]))
            {
                y=i;
                break;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(isupper(temp[i]))
            {
                temp[i]=str[x];
                x++;
            }
            else
            {
                temp[i]=str[y];
                y++;
            }
        }
        return temp;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends