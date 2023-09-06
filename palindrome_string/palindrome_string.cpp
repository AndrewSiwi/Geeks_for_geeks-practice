#include <bits/stdc++.h>

using namespace std;

#define STEROID_NUMBER long long

#define ITER(var, start, cond, end, diff) for(int var = (start); var cond (end); var += diff)
#define ITER_FIX(var, start, end) ITER_FIX(var, start, <, end, 1)
#define ITER_ARR(var) ITER_FIX(var, 0, this->n)
#define ITER_REVERSE(var, start, end) ITER(var, start, >=, end, -1)

#define ITER_CONT(var, cont) for(auto& var: cont)
#define ITER_CONT_IT(var, cont) for(auto var = cont.begin(); var != cont.end();)

class Solution
{
    static int t;
    public: static void init()
    {
        //cint >> t;
        int i = 0;
        while(i < t /*!cin.eof()*/)
        {
            Solution* sl = new Solution(i++);
            sl->process();
            sl->print();
            delete sl;
        }
    }


    private: int ct;

    string s;
    int n, ret = 0;

    public: Solution(int ct)
    {
        this->ct = ct;

        cin >> this->s;
        this->n = this->s.size();
    }

    void process()
    {
        string s2 = "";
        ITER_REVERSE(i, this->n - 1, 0)
        {
            s2 += this->s[i];
        }

        if(this->s == s2) this->ret = 1;
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