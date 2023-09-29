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

const int N = 1e1;

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

    int n;
    vector<int> ret;
    const int coins[10] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };

    public: Solution(int ct)
    {
        this->ct = ct;

        cin >> this->n;
    }

    void process()
    {
        int n = this->n;
        iter_reverse(i, 9, 0)
        {
            int coin = this->coins[i];
            while(n - coin >= 0)
            {
                this->ret.push_back(coin);
                n -= coin;
            }
        }
    }

    void print()
    {
        iter_cont(x, this->ret)
            cout << x << " ";
        cout << "\n";
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