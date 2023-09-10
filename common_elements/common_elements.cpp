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

const int N = 1e5;

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

    int n1, n2, n3, arr1[N], arr2[N], arr3[N];
    vector<int> ret;

    public: Solution(int ct)
    {
        this->ct = ct;

        cin >> this->n1 >> this->n2 >> this->n3;
        int n1 = this->n1;
        int n2 = this->n2;
        int n3 = this->n3;
        while(n1--)
        {
            int x;
            cin >> x;
            this->arr1[this->n1 - n1 - 1] = x;
        }
        while(n2--)
        {
            int x;
            cin >> x;
            this->arr2[this->n2 - n2 - 1] = x;
        }
        while(n3--)
        {
            int x;
            cin >> x;
            this->arr3[this->n3 - n3 - 1] = x;
        }
    }

    void process()
    {
        int i1 = 0, i2 = 0, i3 = 0;
        while(i1 != this->n1 && i2 != this->n2 && i3 != this->n3)
        {
            pair<int*, int> x[3] = { { &i1, this->arr1[i1] }, { &i2, this->arr2[i2] }, { &i3, this->arr3[i3] } };
            sort(x, x + 3, [](pair<int*, int> a, pair<int*, int> b)
            {
                return a.second < b.second;
            });

            if(x[0].second == x[1].second && x[1].second == x[2].second)
            {
                if(i1 == 0 || (i1 > 0 && this->arr1[i1] != this->arr1[i1 - 1])) 
                    this->ret.push_back(x[0].second);
                i1++;
            }
            else
            {
                (*(x[0].first))++;
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