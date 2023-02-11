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
    void f(vector<string>&ans,int digits[],string s,int i,int n,map<int,string> &hash)
    {
        if(i>=n)
        {
            ans.push_back(s);
            return ;
        }
        string temp=hash[digits[i]];
        for(int j=0;j<temp.size();j++)
        {
            s+=temp[j];
            f(ans,digits,s,i+1,n,hash);
            s.pop_back();
        }
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
        f(ans,digits,s,0,size,hash);
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