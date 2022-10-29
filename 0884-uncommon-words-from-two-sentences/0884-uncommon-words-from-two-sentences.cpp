class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> hash;
        string w;
        for(auto it:s1)
        {
            if(it==' ')
            {
                hash[w]++;
                w="";
            }
            else w+=it;
        }
        hash[w]++;
        w="";
        for(auto it:s2)
        {
            if(it==' ')
            {
                hash[w]++;
                w="";
            }
            else w+=it;
        }
        hash[w]++;
        vector<string> ans;
        for(auto it:hash) if(it.second==1) ans.push_back(it.first);
        return ans;
    }
};