class Solution {
public:
    static bool cmp(pair<string,int> a,pair<string,int> b)
    {
        return a.second>b.second;
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> ans;
        vector<pair<string,int>> v;
        for(int i=0;i<names.size();i++)
        {
            v.push_back({names[i],heights[i]});
        }
        sort(v.begin(),v.end(),cmp);
        for(auto it:v) ans.push_back(it.first);
        return ans;
    }
};