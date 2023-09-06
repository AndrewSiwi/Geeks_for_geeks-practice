#include <bits/stdc++.h>

using namespace std;

#define STEROID_NUMBER long long

#define ITER(var, start, cond, end, diff) for(int var = (start); var cond (end); var += diff)
#define ITER_FIX(var, start, end) ITER(var, start, <, end, 1)
#define ITER_ARR(var) ITER_FIX(var, 0, this->n)
#define ITER_REVERSE(var, start, end) ITER(var, start, >=, end, -1)

#define ITER_CONT(var, cont) for(auto& var: cont)
#define ITER_CONT_IT(var, cont) for(auto var = cont.begin(); var != cont.end();)

#define N 1000

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

    int n, m, matrix[N][N], ret = 0;

    public: Solution(int ct)
    {
        this->ct = ct;

        cin >> this->n >> this->m;
        int n = this->n;
        while(n--)
        {
            int m = this->m;
            while(m--)
            {
                int x;
                cin >> x;
                this->matrix[this->n - n - 1][this->m - m - 1] = x;
            }
        }
    }

    void process()
    {
        ITER_FIX(i, 0, this->n)
        {
            ITER_FIX(j, 0, this->m)
            {
                if(this->matrix[i][j] == 1)
                {
                    int zero_count = 0;
                    if(j < this->m - 1 && this->matrix[i][j + 1] == 0) zero_count++;
                    if(j > 0 && this->matrix[i][j - 1] == 0) zero_count++;
                    if(i < this->n - 1 && this->matrix[i + 1][j] == 0) zero_count++;
                    if(i > 0 && this->matrix[i - 1][j] == 0) zero_count++;

                    if(j < this->m - 1 && i < this->n - 1 && this->matrix[i + 1][j + 1] == 0) zero_count++;
                    if(j > 0 && i > 0 && this->matrix[i - 1][j - 1] == 0) zero_count++;
                    if(i < this->n - 1 && j > 0 && this->matrix[i + 1][j - 1] == 0) zero_count++;
                    if(i > 0 && j < this->m - 1 && this->matrix[i - 1][j + 1] == 0) zero_count++;

                    if(zero_count > 0 && zero_count % 2 == 0) this->ret++;
                }
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