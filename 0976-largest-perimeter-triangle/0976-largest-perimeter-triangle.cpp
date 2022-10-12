class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        // it is known that if size of two sides a+b greater than the third size c then the triangle exists.
        // Hence we sort the array to get the possible largest perimeter by traversing it from the last.
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-3;i>=0;i--)
        {
            if(nums[i]+nums[i+1]>nums[i+2]) return nums[i]+nums[i+1]+nums[i+2];
        }
        return 0;
    }
};
