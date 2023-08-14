#include <bits/stdc++.h>

using namespace std;

#define STEROID_NUMBER long long

#define ITER(var, start, cond, end, diff) for(int var = (start); var cond (end); var += diff)
#define ITER_FIX(var, start, end) ITER(var, start, <, end, 1)
#define ITER_ARR(var) ITER_FIX(var, 0, this->n)
#define ITER_REVERSE(var, start, end) ITER(var, start, >=, end, -1)

#define ITER_CONT(var, cond) for(auto& var: cond)
#define ITER_CONT_IT(var, cond) for(auto var = cond.begin(); var != cond.end();)

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

    int n, k, ret;


    public: Solution(int ct)
    {
        this->ct = ct;

        cin >> this->n >> this->k;
    }

    void process()
    {
        int j = this->n + 1;
        ITER(i, 1, <, j, 0)
        {
            ITER_FIX(k, 0, this->k)
            {
                if(i >= j) return;
                this->ret = i++;
            }
            ITER_REVERSE(k, this->k, 1)
            {
                if(i >= j) return;
                this->ret = --j;
            }
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

    return 0;
}