class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int beg = 0;
        int end = nums.size()-1;        
        vector<int> res(nums.size());
        int i = end;
        while(end >= beg)
        {
            if(abs(nums[end]) >= abs(nums[beg]))
            {
                res[i] = nums[end] * nums[end];
                end--;
            }
            else
            {
                res[i] = nums[beg] * nums[beg];
                beg++;
            }
            i--;
        }
        return res;
    }
};