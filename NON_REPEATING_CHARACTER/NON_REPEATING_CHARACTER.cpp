#include <bits/stdc++.h>

using namespace std;

#define STEROID_NUMBER long long

#define ITER_ARRAY(start, var, end) for(int var = (start); var < (end); i++)
#define ITER_ARRAY_ALL(var) ITER_ARRAY(0, var, this->n)
#define ITER_ARRAY_REVERSE(start, var, end) for(int var = (start); var >= (end); var--)

#define ITER_CONT(cont) for(auto& x: cont)

#define N 10000

class Solution
{
    int n;
    string s;
    char ret = '$';
    unordered_map<char, int> chars;
    vector<char> poss;

    public:

    Solution()
    {
        cin >> s;
    }

    void process()
    {
        this->n = this->s.length();

        ITER_ARRAY_ALL(i)
        {
            if(this->chars.find(this->s[i]) == this->chars.end())
            {
                this->chars.insert({ this->s[i], 1 });
                this->poss.push_back(this->s[i]);
            }
            else this->chars.at(this->s[i])++;
        }

        ITER_CONT(this->poss) if(this->chars.at(x) == 1) { this->ret = x; return; }
    }

    void print()
    {
        cout << this->ret << "\n";
        //cout << "\end";
    }
};

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution* sl = new Solution();
    sl->process();
    sl->print();

    return 0;
}