#include <bits/stdc++.h>

using namespace std;

#define STEROID_NUMBER long long

#define ITER(start, var, eq, end, diff) for(int var = (start); var eq (end); var += (diff))
#define ITER_FIX(start, var, end) ITER(start, var, <, end, 1)
#define ITER_ARR(var) ITER(0, var, <, this->n, 1)
#define ITER_ARR_REVERSE(start, var, end) ITER(start, var, >=, end, -1)

#define ITER_CONT(var, cont) for(auto& var: cont)
#define ITER_CONT_IT(var, cont) for(auto var = cont.begin(); var != cont.end();)

#define N 100000

class Solution
{
    static int t;
    public: static void init()
    {
        //cin >> t;
        ITER_FIX(0, i, t)
        {
            Solution* sl = new Solution();
            sl->process();
            sl->print();
            delete sl;
        }
    }

    private:

    int n, m, arr[N], ret = 2000000000;

    public:

    Solution()
    {
        cin >> this->n;
        int n = this->n;
        while(n--)
        {
            int x;
            cin >> x;
            this->arr[this->n - n - 1] = x;
        }
        cin >> this->m;
    }

    void process()
    {
        sort(this->arr, this->arr + this->n);
        ITER(0, i, <, this->n + 1 - this->m, 1)
        {
            int diff = this->arr[i + this->m - 1] - this->arr[i];
            if(diff < this->ret) this->ret = diff;
        }
    }

    void print()
    {
        cout << this->ret << "\n";
        //cout << "\n";
    }
};

int Solution::t = 1;

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution::init();
}