class Solution {
public:
    int wc(string s)
    {
        int c=0;
        for(auto it:s)
        {
            if(it==' ') c++;
        }
        return c+1;
    }
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string,int> hash;
        for(int i=0;i<senders.size();i++)
        {
            hash[senders[i]]+=wc(messages[i]);
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