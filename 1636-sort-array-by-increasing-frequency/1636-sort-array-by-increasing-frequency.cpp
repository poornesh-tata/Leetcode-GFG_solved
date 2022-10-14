class Solution {
public:
    static bool comp(pair<int,int> a,pair<int,int> b)
    {
        if(a.first==b.first)
            return a.second>b.second;
        return a.first<b.first;
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> hash;
        for(auto it:nums) hash[it]++;
        vector<pair<int,int>> v;
        for(auto it:hash)
        {
            v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end(),comp);
        vector<int> ans;
        for(auto it:v)
        {
            for(int i=0;i<it.first;i++) ans.push_back(it.second);
        }
        return ans;
    }
};