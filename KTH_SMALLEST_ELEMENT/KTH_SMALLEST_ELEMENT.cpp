#include <bits/stdc++.h>

using namespace std;

#define int long long

#define ITER(var, start, cond, end, diff) for(int var = (start); var cond (end); var += diff)
#define ITER_FIX(var, start, end) ITER(var, start, <, end, 1)
#define ITER_ARR(var) ITER_FIX(var, 0, this->n)
#define ITER_REVERSE(var, start, end) ITER(var, start, >=, end, -1)

#define ITER_CONT(var, cont) for(auto& var: cont)
#define ITER_CONT_IT(var, cont, comm) for(auto var = cont.begin(); var != cont.end(); comm)

const int N = 1e5;

class Solution
{
    static int t;
    public: static void init()
    {
        //cin >> t;
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

    int n, arr[N], k, ret;

    public: Solution(int ct)
    {
        this->ct = ct;

        cin >> this->n;
        int n = this->n;
        while(n--)
        {
            int x;
            cin >> x;
            this->arr[this->n - n - 1] = x;
        }
        cin >> this->k;
    }

    void process()
    {
        this->ret = this->recursive(0, this->n - 1, this->k);
    }

    int recursive(int l, int r, int k)
    {
        int pivot = this->arr[r], pos = l;
        ITER_FIX(j, l, r)
            if(this->arr[j] <= pivot)
                swap(this->arr[j], this->arr[pos++]);
        swap(this->arr[r], this->arr[pos]);

        if(pos - l + 1 == k)
            return this->arr[pos];
        if(pos - l + 1 > k)
            return this->recursive(l, pos - 1, k);
        return this->recursive(pos + 1, r, k - pos + l - 1);
    }

    void print()
    {
        cout << this->ret << "\n";
        //cout << "\n";
    }
};

int Solution::t = 1;

#undef int
#define int int
int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solution::init();

    return 0;
}