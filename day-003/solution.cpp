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

    // Dead-end pruning
    if ((r == 0 || vis[r-1][c]) && (r == 6 || vis[r+1][c])) {
        if (c > 0 && !vis[r][c-1] && c < 6 && !vis[r][c+1]) return;
    }
    if ((c == 0 || vis[r][c-1]) && (c == 6 || vis[r][c+1])) {
        if (r > 0 && !vis[r-1][c] && r < 6 && !vis[r+1][c]) return;
    }

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
    cout << ans << endl;
}
