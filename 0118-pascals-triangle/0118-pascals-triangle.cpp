class Solution {
public:
    vector<int> f(int n,vector<vector<int>> &ans)
    {
        if(n==1) return {1};
        if(n==2) return {1,1};
        int x=ans.size()-1;
        vector<int> res;
        res.push_back(1);
        for(int i=0;i<ans[x].size()-1;i++)
        {
            res.push_back(ans[x][i]+ans[x][i+1]);
        }
        res.push_back(1);
        return res;
    }
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        for(int i=1;i<=n;i++)
        {
            ans.push_back(f(i,ans));
        }
        return ans;
    }
};