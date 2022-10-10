class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int c=0;
        unordered_map<int,int> hash;
        for(auto it:nums) hash[it]++;
        for(auto it:hash) c+=it.second/2;
        int left=nums.size()-(2*c);
        return {c,left};
    }
};