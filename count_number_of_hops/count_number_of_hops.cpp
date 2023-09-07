#include <bits/stdc++.h>

using namespace std;

#define int long long

#define iter(var, start, cond, end, diff) for(int var = (start); var cond (end); var += (diff))
#define iter_fix(var, start, end) iter(var, start, <, end, 1)
#define iter_arr(var) iter_fix(var, 0, this->n)
#define iter_reverse(var, start, end) iter(var, start, >=, end, -1)

#define iter_cont(var, cont) for(auto& var: cont)
#define iter_cont_it(var, cont, comm) for(auto var = cont.begin(); var != cont.end(); comm)

const int N = 1e5 + 1;
const int mod = 1e9 + 7;

class Solution
{
    static int table[N];
    static void initTable()
    {
        iter_fix(i, 3, N)
            Solution::table[i] = (Solution::table[i - 1] + Solution::table[i - 2] + Solution::table[i - 3]) % mod;
    }

    static int t;
    public: static void init()
    {
        Solution::initTable();

        //cin >> t;
        int ct = 0;
        while(ct < t)
        {
            Solution* sl = new Solution(ct++);
            sl->process();
            sl->print();
            delete sl;
        }
    }

    
    private: int ct;

    int n, ret;

    public: Solution(int ct)
    {
        this->ct = ct;

        cin >> this->n;
    }

    void process()
    {
        this->ret = Solution::table[this->n];
    }

    void print()
    {
        cout << this->ret << "\n";
        //cout << "\n";
    }
};

int Solution::t = 1;
int Solution::table[N] = { 1, 1, 2 };

#undef int
int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution::init();

    return 0;
}