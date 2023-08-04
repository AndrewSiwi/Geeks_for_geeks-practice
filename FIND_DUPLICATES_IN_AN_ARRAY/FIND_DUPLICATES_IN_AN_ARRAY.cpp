#include <bits/stdc++.h>

using namespace std;

#define STEROID_NUMBER long long

#define ITER_ARR(start, var, end) for(int var = (start); var < (end); var++)
#define ITER_ARR_ALL(var) ITER_ARR(0, var, this->n)
#define ITER_ARR_REVERSE(start, var, end) for(int var = (start); var >= (end); var--)

#define ITER_CONT(cont) for(auto& x: cont)
#define ITER_CONT_IT(cont) for(auto it = cont.begin(); it != cont.end();) //dont forget for ++i!

#define N 100000

class Solution
{
    public: 

        static int t;
        static void init()
        {
            //cin >> t;
            ITER_ARR(0, i, t)
            {
                Solution* sl = new Solution();
                sl->process();
                sl->print();
            }
        }

    private:
        
        int n, arr[N];
        unordered_map<int, int> numbers;
        vector<int> ret;

    public:

        Solution()
        {
            cin >> this->n;
            int n = this->n;
            while(n--)
            {
                int x;
                cin >> x;
                this->arr[this->n - n - 1] = x;
            }
        }

        void process()
        {
            ITER_ARR_ALL(i)
            {
                if(this->numbers.find(this->arr[i]) == this->numbers.end()) this->numbers.insert({ this->arr[i], 1 });
                else this->numbers[this->arr[i]]++;
            }

            ITER_CONT_IT(this->numbers)
            {
                if (it->second == 1) it = this->numbers.erase(it);
                else ++it;
            }

            if(this->numbers.empty()) this->ret.push_back(-1);
            else
            {
                ITER_CONT(this->numbers) this->ret.push_back(x.first);
                sort(this->ret.begin(), this->ret.end());
            }
        }

        void print()
        {
            ITER_CONT(this->ret) cout << x << " ";
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
}