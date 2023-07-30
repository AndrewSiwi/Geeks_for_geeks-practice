#include  <bits/stdc++.h>

using namespace std;

#define STEROID_NUMBER long long

#define ITER_ARR(start, end) for(int i = (start); i < (end); i++)
#define ITER_ARR_ALL ITER_ARR(0, this->n)
#define ITER_ARR_REVERSE(start, end) for(int i = (start); i >= (end); i--)

#define ITER_VEC(vec) for(int x: vec)

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
        this->buildHeap();
        this->heapify();
    }

    int calculateParentIndex(int current_index)
    {
        return (current_index % 2 == 0) ? ((current_index - 2) / 2) : ((current_index - 1) / 2);
    }

    void buildHeap()
    {
        ITER_ARR_ALL
        {
            int current_index = i;
            int parent_index = this->calculateParentIndex(current_index);
            while(parent_index >= 0 && this->arr[current_index] > this->arr[parent_index])
            {
                swap(this->arr[current_index], this->arr[parent_index]);
                current_index = parent_index;
                parent_index = this->calculateParentIndex(current_index);
            }
        }
    }

    void heapify()
    {
        ITER_ARR_REVERSE(this->n - 1, 1)
        {
            swap(this->arr[0], this->arr[i]);
            int current_index = 0;
            while(1)
            {
                int first_child_index = current_index * 2 + 1;
                int second_child_index = current_index * 2 + 2;
                int higher_child_index = first_child_index;
                if(first_child_index >= i) break;
                if(second_child_index < i) higher_child_index = (this->arr[first_child_index] > this->arr[second_child_index]) ? first_child_index : second_child_index;
                if(this->arr[current_index] < this->arr[higher_child_index]) swap(this->arr[current_index], this->arr[higher_child_index]);
                current_index = higher_child_index;
            }
        }
    }

    void print()
    {
        ITER_ARR_ALL cout << this->arr[i] << " ";
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
}