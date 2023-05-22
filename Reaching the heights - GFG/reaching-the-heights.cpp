//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	}
	return 0;
}
// } Driver Code Ends


//User function Template for C++

vector<int> reaching_height(int n, int a[]) {
    // Complete the function
    int val=0;
    sort(a,a+n,greater<int>());
    vector<int> v;
    for(int i=0;i<n/2;i++)
    {
        v.push_back(a[i]);
        val+=a[i];
        v.push_back(a[n-i-1]);
        val-=a[n-i-1];
        if(val==0) return {-1};
    }
    if(n&1)
    {
        v.push_back(a[n/2]);
        val+=a[n/2];
    }
    if(val==0) return {-1};
    return v;
}
