class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int sum=0;
        vector<int> ans;
        unordered_map<int,int> hash;
        for(auto it:nums)   sum+=it;
        for(auto it:nums)
        {
            hash[it]++;
            if(hash[it]==2)
            {
                ans.push_back(it);
                int n=nums.size();
                int x=n*(n+1)/2;
                ans.push_back((x-sum)+it);
                return ans;
            }
        }
        return ans;
    }
};