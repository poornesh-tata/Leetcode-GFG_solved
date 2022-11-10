class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        
         vector<int> modified;
        for (int i : nums) {
            int pre = 0, cur = i;
            while (modified.size() && gcd(modified.back(), cur) > 1) {
                pre  = modified.back();
                cur = lcm(cur, pre);
                modified.pop_back();
            }
            modified.push_back(cur);
        }
        
        return modified;
        
        
    }
};