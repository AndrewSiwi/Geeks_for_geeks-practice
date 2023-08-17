#include <bits/stdc++.h>

using namespace std;

#define STEROID_NUMBER long long

#define ITER(var, start, cond, end, diff) for(int var = (start); var cond (end); var += diff)
#define ITER_FIX(var, start, end) ITER(var, start, <, end, 1)
#define ITER_ARR(var) ITER_FIX(var, 0, this->n)
#define ITER_REVERSE(var, start, end) ITER(var, start, >=, end, -1)

#define ITER_CONT(var, cont) for(auto& var: cont)
#define ITER_CONT_IT(var, cont) for(auto it = cont.begin(); it != cont.end();)

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

    int n, m, ks[N];
    queue<int> elems;
    vector<int> ret;


    public: Solution(int ct)
    {
        this->ct = ct;

        cin >> this->n;
        int n = this->n;
        while(n--)
        {
            int x;
            cin >> x;
            this->elems.push(x);
        }

        cin >> this->m;
        int m = this->m;
        while(m--)
        {
            int x;
            cin >> x;
            this->ks[this->m - m - 1] = x;
        }
    }

    void process()
    {
        ITER_FIX(i, 0, this->m)
        {
            this->ret.push_back(0);
            queue<int> elems = this->elems;
            while(!elems.empty())
            {
                if(elems.front() == this->ks[i]) this->ret[i]++;
                elems.pop();
            }
            if(this->ret[i] == 0) this->ret[i]--;
        }
    }

    void print()
    {
        ITER_CONT(x, this->ret) cout << x << " ";
        cout << "\n";
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