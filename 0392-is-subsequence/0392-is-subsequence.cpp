class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j=0,i=0;
        for(i=0;i<s.size() and j<t.size();j++)
        {
            if(s[i]==t[j]) i++;
        }
        if(i==s.length()) return true;
        return false;
    }
};