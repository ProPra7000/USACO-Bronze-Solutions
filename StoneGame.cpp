// Gold 1 Solution - Feb 2021 Contest
// Link to Contest - http://www.usaco.org/index.php?page=viewproblem2&cpid=1113

#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

ll solve(vector<int> &A, int n)
{
    int m = *max_element(A.begin(), A.end()) + 1;
    vector<ll> P(m);
    vector<ll> C(m);
    vector<int> W(m);
    for (auto &c : A)
    {
        P[c]++;
    }
    for (int i = 1; i < m; i++)
    {
        P[i] = (P[i] + P[i - 1]);
    }

    ll ans = 0;
    for (int i = 1; i < m; i++)
    {
        vector<ll> V;
        ll prv = 0;
        for (int j = i - 1; j < m; j += i)
        {
            if (j >= i)
            {
                V.push_back(P[j] - prv);
            }
            prv = P[j];
        }
        if (m % i != 0)
        {
            V.push_back(P[m - 1] - prv);
        }
        int sz = (int)V.size();
        vector<int> SS(sz), PS(sz);
        int sum = 0;
        for (int j = 0; j < sz; j++)
        {
            sum += V[j] % 2;
            PS[j] = sum;
        }

        sum = 0;
        for (int j = sz - 1; j >= 0; j--)
        {
            sum += V[j] % 2;
            SS[j] = sum;
        }
        ll value = 0;
        for (int j = 1; j < sz; j++)
        {
            if (V[j] % 2 == 1 && V[j - 1] % 2 == 1)
            {
                int leftPair = 0;
                if (j - 2 >= 0)
                {
                    leftPair = PS[j - 2];
                }
                int rightPair = 0;
                if (j + 1 < sz)
                {
                    rightPair = SS[j + 1];
                }
                if (leftPair == 0 && rightPair == 0)
                {
                    value += V[j];
                }
            }
        }

        if (sz > 0 && V[0] % 2 == 1)
        {
            int rightPair = 0;
            if (1 < sz)
            {
                rightPair = SS[1];
            }
            if (rightPair == 0)
            {
                value += V[0];
            }
        }

        ans += value;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> piles(N);
    for (auto &c : piles)
    {
        cin >> c;
    }
    cout << solve(piles, N) << endl;
    return 0;
}ton
