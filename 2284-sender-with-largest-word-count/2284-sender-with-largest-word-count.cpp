class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string,int> hash;
        for(int i=0;i<senders.size();i++)
        {
            hash[senders[i]]+=count(begin(messages[i]),end(messages[i]),' ')+1;
        }
        int max=INT_MIN;
        string ans;
        for(auto it:hash)
        {
            if(it.second>=max)
            {
                max=it.second;
                   ans=it.first;
            }
        }
        
        return ans;
    }
};