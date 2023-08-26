#include <bits/stdc++.h>

using namespace std;

#define STEROID_NUMBER long long

#define ITER(var, start, cond, end, diff) for(int var = (start); var cond (end); var += diff)
#define ITER_FIX(var, start, end) ITER(var, start, <, end, 1)
#define ITER_ARR(var) ITER_FIX(var, 0, this->n)
#define ITER_REVERSE(var, start, end) ITER_FIX(var, start, >=, end, -1)

#define ITER_CONT(var, cont) for(auto& var: cont)
#define ITER_CONT_IT(var, cont) for(auto var = cont.begin(); var != cont.end();)

#define N 100000

class Solution
{
    static int t;
    public: static void init()
    {
        //cint >> t;
        int ct = 0;
        while(ct < t /*!cin.eof()*/)
        {
            Solution* sl = new Solution(ct++);
            sl->process();
            sl->print();
            delete sl;
        }
    }


    private: int ct;

    int n, ret = -1;
    STEROID_NUMBER arr[N], sum_after = 0;

    public: Solution(int ct)
    {
        this->ct = ct;

        cin >> this->n;
        int n = this->n;
        while(n--)
        {
            STEROID_NUMBER x;
            cin >> x;
            this->sum_after += x;
            this->arr[this->n - n - 1] = x;
        }
    }

    void process()
    {
        STEROID_NUMBER sum_before = 0;
        ITER_FIX(i, 1, this->n + 1)
        {
            sum_after -= this->arr[i - 1];
            if(sum_before == sum_after)
            {
                this->ret = i;
                break;
            }
            sum_before += this->arr[i - 1];
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