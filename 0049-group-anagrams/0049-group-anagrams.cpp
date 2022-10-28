class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<int>> hash;
        
        for(int i=0;i<strs.size();i++)
        {
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            hash[temp].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto it:hash)
        {
            vector<string> v;
            for(auto itt:it.second)
            {
                v.push_back(strs[itt]);
            }
            ans.push_back(v);
            v.clear();
        }
        return ans;
    }
};