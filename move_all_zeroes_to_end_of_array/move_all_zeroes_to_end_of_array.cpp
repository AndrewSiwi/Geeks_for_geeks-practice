#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define vi vector<int>
#define vvi vector<vi>

#define fi(v, s, c, e, d) for(int v = (s); v c (e); v += (d))
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

    int t = 1;
    //cin >> t;

    int ct = 0;
    while(ct++ < t /* cin >> */)
    {
        //in
        int n;
        vi arr;

        cin >> n;
        int nn = n;
        while(nn--)
        {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        //alg
        int j = 0;
        fn(i)
            if(arr[i] == 0)
            {
                if(j <= i)
                    j = i + 1;
                while(i < n && j < n && arr[j] == 0)
                    j++;
                if(j < n)
                    swap(arr[i], arr[j]);
            }

        //out
        fc(x, arr)
            cout << x << " ";
        cout << "\n";

        //cout << "\n";
    }

    return 0;
}
