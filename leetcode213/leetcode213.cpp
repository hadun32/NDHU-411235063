class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        
        // A：偷 index 0 ~ n-2，不偷最後一間
        // B：偷 index 1 ~ n-1，不偷第一間
        int route_A = robber(nums, 0, n - 2);
        int route_B = robber(nums, 1, n - 1);

        return max(route_A, route_B);
    }

private:
    int robber(vector<int>& nums, int start, int end) {
        int prev2 = nums[start];
        int prev1 = max(nums[start], nums[start + 1]);

        for (int i = start + 2; i <= end; i++) {
            int curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};