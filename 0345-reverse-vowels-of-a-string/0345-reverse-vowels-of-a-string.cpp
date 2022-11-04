class Solution {
public:
    bool isVowel(char c)
    {
        return (c=='a' || c=='A' || c=='e' ||
                c=='E' || c=='i' || c=='I' ||
                c=='o' || c=='O' || c=='u' ||
                c=='U');
    }
    string reverseVowels(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<j)
        {
            while(!isVowel(s[i]) and i<j)
            {
                i++;
            }
            while(!isVowel(s[j]) and i<j)
            {
                j--;
            }
            if(i<j)
            {
                swap(s[i],s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};