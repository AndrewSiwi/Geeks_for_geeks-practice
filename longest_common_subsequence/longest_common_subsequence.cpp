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

    int ss1, ss2, TAB[N + 1][N + 1] = { { 0 } }, ret = 0;
    string s1, s2;

    public: Solution(int ct)
    {
        this->ct = ct;

        cin >> this->ss1 >> this->ss2 >> s1 >> s2;
    }

    void process()
    {
        ITER_FIX(i, 0, this->s1.size() + 1)
        {
            ITER_FIX(j, 0, this->s2.size() + 1)
            {
                if(i == 0 | j == 0) this->TAB[i][j] = 0;
                else if(this->s1[i - 1] == this->s2[j - 1]) this->TAB[i][j] = 1 + this->TAB[i - 1][j - 1];
                else this->TAB[i][j] = max(this->TAB[i - 1][j], this->TAB[i][j - 1]);
            }
        }

        this->ret = this->TAB[this->ss1][this->ss2];
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