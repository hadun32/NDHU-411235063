class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int windowSize = s1.length();
        int s2Length = s2.length();

        if (windowSize > s2Length) {
            return false;
        }

        vector<int> targetCount(26, 0);
        vector<int> windowCount(26, 0);

        // 1. 初始化：建立目標字串的字母頻率表
        for (char c : s1) {
            targetCount[c - 'a']++;
        }

        // 2. 開始滑動視窗
        for (int i = 0; i < s2Length; i++) {
            // 吃進右邊新字母
            windowCount[s2[i] - 'a']++;

            // 如果長度超載，吐出最左邊的舊字母
            if (i >= windowSize) {
                windowCount[s2[i - windowSize] - 'a']--;
            }

            // 當長度達到 windowSize，才進行比對
            if (i >= windowSize - 1) {
                if (targetCount == windowCount) {
                    return true;
                }
            }
        }

        return false;
    }
};