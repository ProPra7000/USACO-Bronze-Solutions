// Gold 3 Solution - Feb 2021
// Link to Contest - http://www.usaco.org/index.php?page=viewproblem2&cpid=1115

#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

vector<ll> powersof3;

ll P(ll a)
{
    ll ans = (a % 3) % 2;
    ll v = 2;
    do
    {
        a /= 3;
        ans += (v * ((a % 3) % 2));
        v *= 2;
    } while (a > 0);
    return ans;
}

vector<int> base3(ll x, int digit)
{
    vector<int> ans(digit);
    for (int i = 0; i < digit; i++)
    {
        ans[i] = x % 3;
        x /= 3;
    }
    return ans;
}

ll solve(ll x, ll y, ll d)
{
    int digit = 39;
    auto x3 = base3(x, digit);
    auto y3 = base3(y, digit);
    auto d3 = base3(d, digit);
    ll ans = 0;
    int px = 0, py = 0;
    int last = -1;
    for (int i = 0; i < digit; i++)
    {
        x3[i] += px;
        y3[i] += py;
        px = x3[i] / 3;
        py = y3[i] / 3;
        x3[i] %= 3;
        y3[i] %= 3;
        while (x3[i] % 2 != y3[i] % 2)
        {
            x3[i]++;
            y3[i]++;
            d -= powersof3[i];
            px += x3[i] / 3;
            py += y3[i] / 3;
            x3[i] %= 3;
            y3[i] %= 3;
            last = i;
        }
    }
    for (int i = 0; i < last; i++)
    {
        if (x3[i] == y3[i])
        {
            d += x3[i] * powersof3[i];
            x3[i] = 0;
            y3[i] = 0;
        }
    }
    x = 0, y = 0;
    for (int i = 0; i < digit; i++)
    {
        x += powersof3[i] * x3[i];
        y += powersof3[i] * y3[i];
    }

    if (d < 0 || P(x) != P(y))
    {
        return 0;
    }
    ans = 1;
    ll v = 1;
    int prv = 0;
    for (int i = 0; i < digit; i++)
    {
        if (x3[i] == y3[i])
        {
            x3[i] += prv;
            y3[i] += prv;
            for (int j = x3[i]; j < 3; j++)
            {
                ll cost = powersof3[i];
                int k = i + 1;
                while (j == 2 && k < digit)
                {
                    if (x3[k] == y3[k])
                    {
                        break;
                    }
                    else
                    {
                        cost += powersof3[k] * 2;
                    }
                    k++;
                }
                if (d >= cost)
                {
                    ans += v;
                    d -= cost;
                    x3[i] += 1;
                    y3[i] += 1;
                }
            }
            prv = x3[i] / 3;
            x3[i] %= 3;
            y3[i] %= 3;
            v *= 3;
        }
        else
        {
        }
    }
    v = 1;
    for (int i = 0; i < digit; i++)
    {
        if (x3[i] == y3[i])
            v *= 3;
    }

    for (int i = digit - 1; i >= 0; i--)
    {
        if (x3[i] == y3[i])
        {
            v /= 3;
            while (x3[i] + 1 < 3 && d >= powersof3[i])
            {
                ans += v;
                d -= powersof3[i];
                x3[i]++;
                y3[i]++;
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    powersof3.push_back(1);
    for (int i = 1; i < 40; i++)
    {
        powersof3.emplace_back(powersof3.back() * 3);
    }

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        ll x, y, d;
        cin >> d >> x >> y;
        cout << solve(x, y, d) << endl;
    }
}
