#include <bits/stdc++.h>

using namespace std;

#define int long long

#define iter(var, start, cond, end, diff) for(int var = (start); var cond (end); var += (diff))
#define iter_fix(var, start, end) iter(var, start, <, end, 1)
#define iter_arr(var) iter_fix(var, 0, this->n)
#define iter_reverse(var, start, end) iter(var, start, >=, end, -1)

#define iter_cont(var, cont) for(auto& var: cond)
#define iter_cont_it(var, cont, comm) for(auto var = cont.begin(); var != cont.end(); comm)
#define iter_cont_revit(var, cont, comm) for(auto var = cont.rbegin(); var != cont.rend(); comm)

const int N = 1e5;

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

    int n, k, arr[N], ret = 0;

    public: Solution(int ct)
    {
        this->ct = ct;

        cin >> n;
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
        sort(this->arr, this->arr + this->n, greater<int>());
        int table[this->n] = { 0 };
        
        iter_arr(i)
        {
            if(i < this->n - 1 && this->arr[i] - this->arr[i + 1] < this->k)
            {
                table[i] = table[i + 1] = this->arr[i] + this->arr[i + 1];
                
                if(i > 0)
                    table[i] = table[i + 1] += table[i - 1];
                i++;
            }
            else if(i > 0)
                table[i] = table[i - 1];
        }
        
        this->ret = table[this->n - 1];
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