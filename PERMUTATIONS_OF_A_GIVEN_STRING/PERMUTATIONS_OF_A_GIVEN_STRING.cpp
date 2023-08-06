#include <bits/stdc++.h>

using namespace std;

#define STEROID_NUMBER long long

#define ITER(var, start, cond, end, diff) for(int var = (start); var cond (end); var += diff)
#define ITER_FIX(var, start, end) ITER(var, start, <, end, 1)
#define ITER_ARR(var) ITER_FIX(var, 0, this->n)
#define ITER_REVERSE(var, start, end) ITER(var, start, >=, end, -1)

#define ITER_CONT(var, cont) for(auto& var: cont)
#define ITER_CONT_IT(var, cont) for(auto var = cont.begin(); var != cont.end();)

#define N 10

class Solution
{
    static int t;
    public: static void init()
    {
        ITER_FIX(i, 0, t)
        {
            Solution* sl = new Solution();
            sl->process();
            sl->print();
            delete sl;
        }
    }

    private:

    string s, h;
    int n;
    vector<string> ret;

    public:

    Solution()
    {
        cin >> s;
    }

    void process()
    {
        this->n = this->s.size();
        this->h = this->s;

        this->recursive(0);

        sort(this->ret.begin(), this->ret.end());
    }

    void recursive(int start)
    {
        if(start == this->n - 1)
        {
            this->ret.push_back(this->h);
            return;
        }
        ITER_FIX(i, start, this->n)
        {
            swap(this->h[start], this->h[i]);
            this->recursive(start + 1);
            swap(this->h[start], this->h[i]);
        }
    }

    void print()
    {
        ITER_CONT(x, this->ret) cout << x << " ";
        cout << "\n";
        //cout << "\n";
    }
};

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution::init();

    return 0;
}

int Solution::t = 1;