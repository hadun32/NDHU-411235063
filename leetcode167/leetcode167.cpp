class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int start = 0;
        int end = numbers.size() - 1;

        while (start < end) {
            int sum = numbers[start] + numbers[end];

            if (sum == target) {
                // C++ 裡可以直接用大括號 {} 來回傳一個 vector
                return {start + 1, end + 1}; 
            } else if (sum > target) {
                end--;   // 總和太大，把比較大的數字換小，右指標左移
            } else {
                start++; // 總和太小，把比較小的數字換大，左指標右移
            }
        }
        
        // 如果都找不到，回傳空的 vector (雖然題目保證一定有解)
        return {}; 
    }
};