class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // 建立圖：graph[i] 存放「i 討厭的人」
        vector<vector<int>> graph(n + 1);

        for (auto dislike : dislikes) {
            int a = dislike[0];
            int b = dislike[1];

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        // parent[i] 代表 i 的根節點
        vector<int> parent(n + 1);

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        // 檢查每個人
        for (int person = 1; person <= n; person++) {
            // 如果這個人沒有討厭任何人，就跳過
            if (graph[person].empty()) {
                continue;
            }

            // person 討厭的第一個人
            int firstDisliked = graph[person][0];

            // 把 person 討厭的所有人都合併成同一組
            for (int dislikedPerson : graph[person]) {

                // 如果 person 和他討厭的人已經在同一組，代表不可能分組
                if (find(parent, person) == find(parent, dislikedPerson)) {
                    return false;
                }

                // 把所有被 person 討厭的人放到同一組
                unionSet(parent, firstDisliked, dislikedPerson);
            }
        }

        return true;
    }

private:
    // 找出 x 所屬集合的根節點
    int find(vector<int>& parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]); // 路徑壓縮
        }

        return parent[x];
    }

    // 合併兩個集合
    void unionSet(vector<int>& parent, int a, int b) {
        int rootA = find(parent, a);
        int rootB = find(parent, b);

        if (rootA != rootB) {
            parent[rootA] = rootB;
        }
    }
};