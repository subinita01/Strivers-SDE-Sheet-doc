#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<vector<char>>> pieces;

vector<vector<vector<char>>> rotations(vector<vector<char>> p) {
    vector<vector<vector<char>>> rots;
    for (int r = 0; r < 4; r++) {
        rots.push_back(p);
        vector<vector<char>> newp(n, vector<char>(n, '.'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                newp[j][n - 1 - i] = p[i][j];
        p = newp;
    }
    return rots;
}

bool dfs(int idx, vector<vector<int>> board) {
    if (idx == m) {
        for (auto &row : board)
            for (auto cell : row)
                if (!cell) return false;
        return true;
    }

    for (auto &p : rotations(pieces[idx])) {
        for (int dx = 0; dx < n; dx++) {
            for (int dy = 0; dy < n; dy++) {
                auto b = board;
                bool ok = true;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (p[i][j] == '#') {
                            int x = i + dx, y = j + dy;
                            if (x >= n || y >= n || b[x][y]) ok = false;
                            else b[x][y] = 1;
                        }
                    }
                }
                if (ok && dfs(idx + 1, b)) return true;
            }
        }
    }
    return false;
}

void solve() {
    cin >> n >> m;
    pieces.resize(m, vector<vector<char>>(n, vector<char>(n)));
    for (int k = 0; k < m; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> pieces[k][i][j];

    vector<vector<int>> board(n, vector<int>(n, 0));
    cout << (dfs(0, board) ? "yes" : "no") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
