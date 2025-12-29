/*
Problem Statement:
Given a 7×7 grid starting from (0,0), count the number of valid paths
to reach (6,0) in exactly 48 moves following a given string of directions.
Each move can be U, D, L, R or '?' where '?' allows any direction.
Each cell must be visited at most once.

Approach:
We use DFS with backtracking to explore all valid paths.
To optimize, dead-end pruning is applied:
If movement is blocked in both vertical directions but open horizontally
(or vice versa), the path is abandoned early.

Time Complexity:
O(4^48) in worst case, heavily reduced due to pruning.

Space Complexity:
O(7×7) for visited grid + recursion stack.

Example:
Input:
????????????????????????????????

Output:
88418

Submission Link:
https://cses.fi/problemset/task/1625/
*/

#include <bits/stdc++.h>
using namespace std;

string s;
bool vis[7][7];
int ans = 0;

bool inside(int r, int c) {
    return r >= 0 && r < 7 && c >= 0 && c < 7;
}

void dfs(int r, int c, int idx) {
    if (r == 6 && c == 0) {
        if (idx == 48) ans++;
        return;
    }
    if (idx == 48) return;

    bool up = (r == 0 || vis[r-1][c]);
    bool down = (r == 6 || vis[r+1][c]);
    bool left = (c == 0 || vis[r][c-1]);
    bool right = (c == 6 || vis[r][c+1]);

    if (up && down && !left && !right) return;
    if (left && right && !up && !down) return;

    vis[r][c] = true;

    char ch = s[idx];
    if (ch == '?' || ch == 'U')
        if (inside(r-1, c) && !vis[r-1][c]) dfs(r-1, c, idx+1);
    if (ch == '?' || ch == 'D')
        if (inside(r+1, c) && !vis[r+1][c]) dfs(r+1, c, idx+1);
    if (ch == '?' || ch == 'L')
        if (inside(r, c-1) && !vis[r][c-1]) dfs(r, c-1, idx+1);
    if (ch == '?' || ch == 'R')
        if (inside(r, c+1) && !vis[r][c+1]) dfs(r, c+1, idx+1);

    vis[r][c] = false;
}

int main() {
    cin >> s;
    dfs(0, 0, 0);
    cout << ans << "\n";
    return 0;
}
