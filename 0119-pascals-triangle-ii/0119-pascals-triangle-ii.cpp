class Solution {
public:
    vector<int> f(int n)
    {
        if(n==1) return {1};
        if(n==2) return {1,1};
        vector<int> x=f(n-1);
        vector<int> res;
        res.push_back(1);
        for(int i=0;i<x.size()-1;i++)
        {
            res.push_back(x[i]+x[i+1]);
        }
        res.push_back(1);
        return res;

    }
    vector<int> getRow(int n) {
        return f(n+1);
    }
};