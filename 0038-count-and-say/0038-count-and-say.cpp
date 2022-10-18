class Solution {
public:
    string cas(string s)
    { 
        int count=1;
        char temp=s[0];
        string t="";

        for(int i=1;i<s.size();i++)
        {
            if(s[i]==temp)
            {
                count++;
            }
            else
            {
                t+=to_string(count);
                t+=temp;
                count=1;
                temp=s[i];
            }
        }
        if(count!=0)
        {
            t+=to_string(count);
            t+=temp;
        }
        return t;
    }
    string countAndSay(int n) {
        string s="1";
        if(n==1) return s;
        while(--n)
        {
            s=cas(s);
        }
        return s;
        
    }
};