class Solution {
private:
    static constexpr int GROUP_SIZE = 5;

    int getMedian(vector<int>& group) {
        sort(group.begin(), group.end(), greater<int>());
        return group[group.size() / 2];
    }

    int getPerfectPivot(const vector<int>& nums) {
        if (nums.size() <= GROUP_SIZE) {
            vector<int> group = nums;
            return getMedian(group);
        }

        vector<int> medians;
        for (size_t i = 0; i < nums.size(); i += GROUP_SIZE) {
            vector<int> group;
            for (size_t j = i; j < min(nums.size(), i + GROUP_SIZE); ++j) {
                group.push_back(nums[j]);
            }
            medians.push_back(getMedian(group));
        }

        return getPerfectPivot(medians); 
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() == 1) return nums[0];

        int pivot = getPerfectPivot(nums);

        vector<int> largerElements;
        vector<int> equalElements;
        vector<int> smallerElements;

        for (int num : nums) {
            if (num > pivot) largerElements.push_back(num);
            else if (num == pivot) equalElements.push_back(num);
            else smallerElements.push_back(num);
        }

        if (k <= largerElements.size()) {
            return findKthLargest(largerElements, k);
        }
        
        if (k <= largerElements.size() + equalElements.size()) {
            return pivot;
        }
        
        int remainingK = k - largerElements.size() - equalElements.size();
        return findKthLargest(smallerElements, remainingK);
    }
};