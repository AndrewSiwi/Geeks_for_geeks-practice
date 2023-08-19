#include <bits/stdc++.h>

using namespace std;

#define STEROID_NUMBER long long

#define ITER(var, start, cond, end, diff) for(int var = (start); var cond (end); var += diff)
#define ITER_FIX(var, start, end) ITER(var, start, <, end, 1)
#define ITER_ARR(var) ITER_FIX(var, 0, this->n)
#define ITER_REVERSE(var, start, end) ITER(var, start, >=, end, -1)

#define ITER_CONT(var, cont) for(auto& var: cont)
#define ITER_CONT_IT(var, cont) for(auto var = cont.begin(); var != cont.end();)

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

    private: int ct;

    int n, arr[N];
    STEROID_NUMBER k;
    vector<int> ret;

    public: Solution(int ct)
    {
        this->ct = ct;

        cin >> this->n >> k;
        int n = this->n;
        while(n--)
        {
            int x;
            cin >> x;
            this->arr[this->n - n - 1] = x;
        }
    }

    void process()
    {
        STEROID_NUMBER sum = 0;
        int i = -1, j = -1;
        while(j < this->n)
        {
            if(sum < this->k && i < this->n - 1) sum += this->arr[++i];
            else if(sum > this->k) sum -= this->arr[++j];
            else break;
        }
        if(sum == this->k && i > -1) this->ret = { j + 2, i + 1 };
        else this->ret.push_back(-1);
    }

    void print()
    {
        ITER_CONT(x, this->ret) cout << x << " ";
        cout << "\n";
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