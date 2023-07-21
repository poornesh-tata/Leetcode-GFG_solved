//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    struct Node
	    {
	        int data;
	        Node* left;
	        Node* right;
	        Node(int val)
	        {
	            data = val;
	            left=NULL;
	            right = NULL;
	        }
	    };
	    struct cmp
	    {
	        bool operator()(Node* l,Node* r)
	        {
	            return l->data > r->data;
	        }
	    };
	    void fun(Node* root,string& str,vector<string>& res)
	    {
	        if(root->left==NULL and root->right==NULL)
	        {
	            res.push_back(str);
	            return ;
	        }
	        str+='0';
	        fun(root->left,str,res);
	        str.pop_back();
	        str+='1';
	        fun(root->right,str,res);
	        str.pop_back();
	    }
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    priority_queue< Node*, vector<Node*>, cmp > pq;
		    for(int i=0;i<N;i++)
		    {
		        Node* newnode = new Node(f[i]);
		        pq.push(newnode);
		    }
		    
		    while(!pq.empty())
		    {
		        if(pq.size()<=1) break;
		        
		        Node* x = pq.top();
		        pq.pop();
		        Node* y = pq.top();
		        pq.pop();
		        
		        Node* newnode = new Node(x->data+y->data);
		        newnode->left = x;
		        newnode->right = y;
		        
		        pq.push(newnode);
		    }
		    Node* root = pq.top();
		    pq.pop();
		    
		    string str =""; vector<string> res;
		    fun(root,str,res);
		    
		    return res;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends