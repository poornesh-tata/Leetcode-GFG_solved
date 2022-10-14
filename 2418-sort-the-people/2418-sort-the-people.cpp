class Solution {
public:
    static bool cmp(pair<int,string>a,pair<int,string> b)
    {
        return a.first>b.first;
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> ans;
        vector<pair<int,string>> v;
        for(int i=0;i<names.size();i++)
        {
            v.push_back({heights[i],names[i]});
        }
        sort(v.begin(),v.end(),cmp);
        for(auto it:v) ans.push_back(it.second);
        return ans;
    }
};