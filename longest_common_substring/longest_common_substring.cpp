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
    static int t;
    public: static void init()
    {
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

    int ss1, ss2, ret = 0;
    string s1, s2;

    public: Solution(int ct)
    {
        this->ct = ct;

        cin >> ss1 >> ss2 >> s1 >> s2;
    }

    void process()
    {
        int table[N][N];
        iter_fix(i, 0, this->ss1 + 1)
            table[i][0] = 0;
        iter_fix(i, 0, this->ss2 + 1)
            table[0][i] = 0;

        iter_fix(i, 1, this->ss1 + 1)
            iter_fix(j, 1, this->ss2 + 1)
            {
                if(this->s1[i - 1] == this->s2[j - 1])
                {
                    table[i][j] = table[i - 1][j - 1] + 1;
                    if(this->ret < table[i][j])
                        this->ret = table[i][j];
                }
                else
                    table[i][j] = 0;
            }
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