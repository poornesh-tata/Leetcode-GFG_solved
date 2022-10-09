class Solution {
public:
    int percentageLetter(string s, char letter) {
        int c =0;
        for(auto it:s)
        {
            if(it==letter) c++;
        }
        if(c==0) return 0;
        int ans=(c*100/s.length());
        return ans;
    }
};