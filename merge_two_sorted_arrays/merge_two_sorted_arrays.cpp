#include <bits/stdc++.h>

#define STEROID_NUMBER long long

#define I_MAX 10000000

#define ITER(var, start, cond, end, diff) for(int var = start; var cond end; var += diff)

using namespace std;

class Solution
{
    public:
        int n, m;
        STEROID_NUMBER arr1[I_MAX], arr2[I_MAX];

    Solution()
    {
        cin >> this->n >> this->m;

        int n = this->n;
        int m = this->m;

        while(n--)
        {
            STEROID_NUMBER i;
            cin >> i;
            this->arr1[this->n - n - 1] = i;
        }

        while(m--)
        {
            int i;
            cin >> i;
            this->arr2[this->m - m - 1] = i;
        }
    }

    void process()
    {
        int n2 = this->n;
        ITER(i, (0), <, this->m && n2--, 1) if(this->arr1[n2] > this->arr2[i]) swap(this->arr1[n2], this->arr2[i]);
            
        sort(this->arr1, this->arr1 + this->n);
        sort(this->arr2, this->arr2 + this->m);
    }

    void print()
    {
        for(int i = 0; i < this->n; i++)
        {
            cout << this->arr1[i] << " ";
        }
        for(int i = 0; i < this->m; i++)
        {
            cout << this->arr2[i] << " ";
        }
        cout << "\n";
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution* sl = new Solution();
    sl->process();
    sl->print();

    return 0;
}