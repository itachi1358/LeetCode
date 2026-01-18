class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // row prefix sum
        vector<vector<int>> row_prefix = grid;
        // col prefix sum
        vector<vector<int>> col_prefix = grid;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                row_prefix[i][j] += row_prefix[i][j - 1];
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                col_prefix[i][j] += col_prefix[i - 1][j];
            }
        }

        // main diagonal prefix (top-left to bottom-right)
        vector<vector<int>> diag1(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                diag1[i][j] = grid[i][j];
                if (i > 0 && j > 0) diag1[i][j] += diag1[i - 1][j - 1];
            }
        }

        // anti diagonal prefix (top-right to bottom-left)
        vector<vector<int>> diag2(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = m - 1; j >= 0; j--) {
                diag2[i][j] = grid[i][j];
                if (i > 0 && j + 1 < m) diag2[i][j] += diag2[i - 1][j + 1];
            }
        }

        auto getRowSum = [&](int r, int c1, int c2) -> int {
            int res = row_prefix[r][c2];
            if (c1 > 0) res -= row_prefix[r][c1 - 1];
            return res;
        };

        auto getColSum = [&](int c, int r1, int r2) -> int {
            int res = col_prefix[r2][c];
            if (r1 > 0) res -= col_prefix[r1 - 1][c];
            return res;
        };

        auto getDiag1Sum = [&](int x1, int y1, int x2, int y2) -> int {
            // assumes (x2-x1) == (y2-y1)
            int res = diag1[x2][y2];
            if (x1 > 0 && y1 > 0) res -= diag1[x1 - 1][y1 - 1];
            return res;
        };

        auto getDiag2Sum = [&](int x1, int y1, int x2, int y2) -> int {
            // assumes (x2-x1) == (y1-y2)
            int res = diag2[x2][y2];
            if (x1 > 0 && y1 + 1 < m) res -= diag2[x1 - 1][y1 + 1];
            return res;
        };

        int ans = 1;

        // Try bigger k first (early exit)
        for (int k = min(n, m); k >= 2; k--) {
            for (int x = 0; x + k - 1 < n; x++) {
                for (int y = 0; y + k - 1 < m; y++) {

                    int x2 = x + k - 1;
                    int y2 = y + k - 1;

                    int target = getDiag1Sum(x, y, x2, y2);
                    int otherDiag = getDiag2Sum(x, y2, x2, y);

                    if (otherDiag != target) continue;

                    bool ok = true;

                    // check all rows
                    for (int i = x; i <= x2; i++) {
                        if (getRowSum(i, y, y2) != target) {
                            ok = false;
                            break;
                        }
                    }
                    if (!ok) continue;

                    // check all cols
                    for (int j = y; j <= y2; j++) {
                        if (getColSum(j, x, x2) != target) {
                            ok = false;
                            break;
                        }
                    }

                    if (ok) return k; // since we go from large to small
                }
            }
        }

        return ans;
    }
};
