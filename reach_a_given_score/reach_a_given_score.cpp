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

const int N = 1e3 + 1;

class Solution
{
    static int table[N];
    static void initTable()
    {
        const int points[3] = { 3, 5, 10 };
        iter_fix(i, 0, 3)
        {
            int point = points[i];
            iter_fix(j, point, N)
                Solution::table[j] += Solution::table[j - point];
        }
    }

    static int t;
    public: static void init()
    {
        Solution::initTable();

        cin >> t;
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
int Solution::table[N] = { 1 };


#undef int
int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution::init();

    return 0;
};