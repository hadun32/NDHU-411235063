class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long long s = 0;
        int n = nums.size();
        vector<int> avgs(n, -1);

        for (int i = 0; i < n; i++) {
            s += nums[i];
            
            if (i < 2 * k) continue;
            
            avgs[i - k] = s / (2 * k + 1);
            s -= nums[i - 2 * k];
        }
        
        return avgs;
    }
};