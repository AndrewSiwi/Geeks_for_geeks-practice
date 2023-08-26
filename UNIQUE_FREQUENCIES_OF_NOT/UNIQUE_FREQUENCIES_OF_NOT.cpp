#include <bits/stdc++.h>

using namespace std;

#define N 100000

class Solution
{
    public:
        int n, arr[N];
        bool ret = true;

    Solution()
    {
        cin >> this->n;

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
        unordered_map<int, int> counts, uniq;
        for(int i = 0; i < this->n; i++) counts[this->arr[i]]++;
        for(auto& [key, val]: counts)
        {
            if(uniq[val] == 0) uniq[val] = key;
            else { this->ret = false; return; }
        }
    }

    void print()
    {
        //cout << "\n";

        cout << this->ret << "\n";
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