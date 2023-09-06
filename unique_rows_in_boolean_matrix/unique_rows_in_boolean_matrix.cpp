#include <bits/stdc++.h>

using namespace std;

#define STEROID_NUMBER long long

#define ITER(var, start, cond, end, diff) for(int var = (start); var cond (end); var += diff)
#define ITER_FIX(var, start, end) ITER(var, start, <, end, 1)
#define ITER_ARR(var) ITER_FIX(var, 0, this->n)
#define ITER_REVERSE(var, start, end) ITER(var, start, >=, end, -1)

#define ITER_CONT(var, cont) for(auto &var: cont)
#define ITER_CONT_IT(var, cont) for(auto var = cont.begin(); var != cont.end();)

#define N 40

class Solution
{
    static int t;
    public: static void init()
    {
        //cin >> t
        ITER_FIX(i, 0, t)
        {
            Solution* sl = new Solution();
            sl->process();
            sl->print();
            delete sl;
        }
    }

    private:

    int m, n, matrix[N][N];
    unordered_map<string, int> uniq;
    map<int, string> uniq_ret;
    vector<vector<int>> ret;

    public:

    Solution()
    {
        cin >> m >> n;
        ITER_FIX(i, 0, this->m)
        {
            ITER_FIX(j, 0, this->n)
            {
                cin >> this->matrix[i][j];
            }
        }
    }

    void process()
    {
        ITER_FIX(i, 0, this->m)
        {
            string row = "";
            ITER_FIX(j, 0, this->n)
            {
                row += '0' + this->matrix[i][j];
            }
            if(this->uniq.find(row) == this->uniq.end())
            {
                this->uniq.insert({ row, i });
                this->uniq_ret.insert({ i, row });
            }
        }

        ITER_CONT_IT(it, this->uniq_ret)
        {
            string row = it->second;
            vector<int> ret_row;
            ITER_FIX(i, 0, this->n)
            {
                int item = row[i] - '0';
                ret_row.push_back(item);
            }
            this->ret.push_back(ret_row);
            it++;
        }
    }

    void print()
    {
        cout << "$";
        ITER_CONT(row, this->ret)
        {
            ITER_CONT(x, row) cout << x << " ";
            cout << "$";
        }
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