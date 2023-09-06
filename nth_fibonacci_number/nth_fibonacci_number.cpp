#include  <bits/stdc++.h>

using namespace std;

#define STEROID_NUMBER long long

#define ITER(var, start, cond, end, diff) for(int var = (start); var cond (end); var += diff)
#define ITER_FIX(var, start, end) ITER(var, start, <, end, 1)
#define ITER_ARR(var) ITER_FIX(var, 0, this->n)
#define ITER_REVERSE(var, start, end) ITER(var, start, >=, end, -1)

#define N 100000

class Solution
{
    static int t;
    public: static void init()
    {
        //cin >> t;
        ITER_FIX(i, 0, t)
        {
            Solution* sl = new Solution(i);
            sl->process();
            sl->print();
            delete sl;
        }
    }

    private:

    int ct;
    int n, ret = 0, tab[N] = { 0 };

    public:

    Solution(int ct)
    {
        this->ct = ct;

        cin >> this->n;
    }

    void process()
    {
        this->tab[0] = this->tab[1] = 1;
        ITER_FIX(i, 2, this->n) this->tab[i] = (this->tab[i - 1] + this->tab[i - 2]) % 1000000007;

        this->ret = this->tab[this->n - 1];
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

    return 0;
}