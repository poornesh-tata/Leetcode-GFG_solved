class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> hash={'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int count=0;
        for(int i=0;i<s.size()/2;i++)
        {
            if(hash.find(s[i])!=hash.end()) count++;
        }
        for(int i=s.size()/2;i<s.size();i++)
        {
            if(hash.find(s[i])!=hash.end()) count--;
        }
        if(count==0) return true;
        return false;
    }
};