class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = nums[n - 1] - nums[0];
        
        for (int i = 0; i < n - 1; i++) { //從左到右一一比過去
            
            int high = max(nums[n - 1] - k, nums[i] + k);
            int low = min(nums[0] + k, nums[i + 1] - k); //找新的最大和最小值
            
            ans = min(ans, high - low); //算一下差距有沒有比之前小
        }
        return ans;
    }
};