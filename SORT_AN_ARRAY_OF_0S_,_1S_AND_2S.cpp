#include <bits/stdc++.h>

using namespace std;

#define ITER_ARR for(int i = 0; i < this->n; i++)
#define N 1000000

class Solution
{
    int n, arr[N];

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
        int i_zero = 0, i_two = this->n - 1;
        ITER_ARR if(this->arr[i] == 0) swap(this->arr[i_zero++], this->arr[i]);
        for(int i = this->n - 1; i >= i_zero; i--) if(this->arr[i] == 2) swap(this->arr[i_two--], this->arr[i]);
    }

    void print()
    {
        //cout << "\n";
        ITER_ARR
        {
            if(i > 0) cout << " ";
            cout << this->arr[i];
        }
        cout << "\n";
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