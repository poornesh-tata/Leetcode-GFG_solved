//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    vector<string> f(string &str,vector<string> &ans)
    {
        vector<string> a;
        for(int i=0;i<ans.size();i++)
        {
            for(int j=0;j<str.size();j++)
            {
                string temp="";
                temp+=ans[i];
                temp+=str[j];
                a.push_back(temp);
            }
        }
        return a;
    }
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int digits[], int N)
    {
        //Your code here
        map<int,string> hash;
        hash[2]="abc";hash[3]="def";hash[4]="ghi";hash[5]="jkl";
        hash[6]="mno";hash[7]="pqrs";hash[8]="tuv";hash[9]="wxyz";
        string s;
        vector<string> ans;
        int size=N;
        if(size==0) return {};
        if(size>=1)
        {
            for(auto it:hash[digits[0]])
            {
                string t="";
                t+=it;
                ans.push_back(t);
            }
            if(size==1) return ans;
        }
        for(int i=1;i<size;i++)
        {
            ans=f(hash[digits[i]],ans);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends