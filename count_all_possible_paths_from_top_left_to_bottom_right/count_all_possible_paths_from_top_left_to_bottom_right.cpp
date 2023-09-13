#include <bits/stdc++.h>

using namespace std;

#define int long long

#define iter(var, start, cond, end, diff) for(int var = (start); var cond (end); var += (diff))
#define iter_fix(var, start, end) iter(var, start, <, end, 1)
#define iter_arr(var) iter_fix(var, 0, this->n)
#define iter_reverse(var, start, end) iter(var, start, >=, end, -1)

#define iter_cont(var, cont) for(auto& var: cont)
#define iter_cont_it(var, cont, comm) for(auto var = cont.begin(); var != cont.end(); comm)
#define iter_cont_revit(var, cont, comm) for(auto var = cont.rbegin(); var != cont.rend(); comm)

const int N = 1e2 + 1;
const int MOD = 1e9 + 7;

class Solution
{
    static int t;
    public: static void init()
    {
        //cin >> t;
        int ct = 0;
        while(ct < t /* cin >> */)
        {
            Solution* sl = new Solution(ct++);
            sl->process();
            sl->print();
            delete sl;
        }
    }


    private: int ct;

    int m, n, table[N][N], ret = 0;

    public: Solution(int ct)
    {
        this->ct = ct;

        cin >> this->m >> this->n;

        iter_fix(i, 0, this->m + 1)
            this->table[0][i] = 1;
        iter_fix(i, 0, this->n + 1)
            this->table[i][0] = 1;
            
        iter_fix(i, 1, this->n + 1)
            iter_fix(j, 1, this->m + 1)
                this->table[i][j] = (this->table[i - 1][j] + this->table[i][j - 1]) % MOD;
    }

    void process()
    {
        this->ret = this->table[this->m - 1][this->n - 1];
    }

    void print()
    {
        cout << this->ret << "\n";
        //cout << "\n";
    }
};

int Solution::t = 1;

#undef int
int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution::init();

    return 0;
}