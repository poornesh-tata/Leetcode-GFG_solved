class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
        for(auto it:address)
        {
            if(isdigit(it)) ans+=it;
            else
            {
                ans+="[.]";
            }
        }
        return ans;
    }
};