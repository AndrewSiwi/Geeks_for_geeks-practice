#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution
{
    public:
        int n, arr[100000];
        long long s;

        vector<int> res = vector<int>(2);

    Solution()
    {
        cin >> this->n >> this->s;

        int n = this->n;

        while(n--)
        {
            int i;
            cin >> i;
            this->arr[this->n - n - 1] = i;
        }
    }
    
    void process()
    {
        long long sum = 0;
        this->res[0] = 1;
        for(int i = 0; i < this->n; i++)
        {
            sum += this->arr[i];
            this->res[1] = i + 1;
            while(sum > this->s && this->res[0] < this->res[1])
            {
                sum -= this->arr[this->res[0] - 1];
                this->res[0]++;
            }
            if(sum == this->s)
            {
                return;
            }
        }

        this->res[0] = -1;
        this->res.pop_back();
    }

    void print()
    {
        for(int res: this->res)
        {
            cout << res << " ";
        }
        cout << "\n";
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution* sl = new Solution();
    sl->process();
    sl->print();

    return 0;
}