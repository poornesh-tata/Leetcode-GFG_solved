class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> v(index.size());
        for(int i=0;i<index.size();i++)
        {
            v.insert(v.begin()+index[i],nums[i]);
        }
        v.resize(index.size());
        return v;
    }
};