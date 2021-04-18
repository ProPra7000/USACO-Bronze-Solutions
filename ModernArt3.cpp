//Gold 2 Solution - Feb 2021
//Link to Contest - http://www.usaco.org/index.php?page=viewproblem2&cpid=1114

#include <bits/stdc++.h>

#define ll long long
#define endl '\n'

using namespace std;

int getMinStrokes(vector<int> &A, int N)
{
    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(N, vector<int>(N, -1)));

    function<int(int, int, int)> calc = [&](int color, int l, int r) {
        while (l <= r && A[l] == color)
        {
            l++;
        }
        while (r >= l && A[r] == color)
        {
            r--;
        }
        if (r < l)
        {
            return 0;
        }
        if (l == r)
        {
            return 1;
        }
        auto &ans = dp[color][l][r];
        if (ans != -1)
        {
            return ans;
        }
        int newColor = A[l];
        ans = 1 + calc(color, l + 1, r);
        for (int rr = l + 1; rr <= r; rr++)
        {
            if (A[rr] == newColor)
            {
                int res = 1 + calc(newColor, l + 1, rr) + calc(color, rr + 1, r);
                ans = min(ans, res);
            }
        }
        dp[color][l][r] = ans;
        return ans;
    };

    return calc(0, 0, N - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> painting;
    for (int i = 0; i < N; i++)
    {
        int color;
        cin >> color;
        painting.push_back(color);
    }
    cout << getMinStrokes(painting, N) << endl;
}
