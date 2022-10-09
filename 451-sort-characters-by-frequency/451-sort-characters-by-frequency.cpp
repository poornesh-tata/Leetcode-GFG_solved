class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> hash;
        for(auto it:s) hash[it]++;
        vector<pair<int,char>> v;
        for(auto it:hash)
        {
            v.push_back(make_pair(it.second,it.first));
        }
        sort(v.begin(),v.end());
        string res;
        for(auto it:v)
        {
            for(int i=0;i<it.first;i++) res+=it.second;
        }
        reverse(res.begin(),res.end());
        return res;
        }
};