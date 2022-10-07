class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int temp=x;
        long long rev=0;
        while(x)
        {
            rev=(rev*10)+x%10;
            x/=10;
        }
        if(rev==temp) return true;
        else return false;
    }
};