#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define fi(v, s, c, e, d) for(ll v = (s); v c (e); v += (d))
#define ff(v, s, e) fi(v, s, <, e, 1)
#define fn(v) ff(v, 0, n)
#define fr(v, s, e) ff(v, s, >=, e, -1)

#define fc(v, c) for(auto& v: c)
#define fci(v, c, cm) for(auto v = c.begin(); v != c.end(); cm)
#define fcir(v, c, cm) for(auto v = c.rbegin(); v != c.rend(); cm)

const int N = 1e1;

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    //ll CT = 0;
    while(cin >> n)
    {
        ll ret = 0;
        while(n > 0)
        {
            if(n % 2 == 0)
                n /= 2;
            else
                n -= 1;

            ret++;
        }
        cout << ret << "\n";
        //cout << "\n";
    }

    return 0;
}