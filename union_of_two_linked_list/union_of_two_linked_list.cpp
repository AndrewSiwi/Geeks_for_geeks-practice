#include <bits/stdc++.h>

using namespace std;

#define STEROID_NUMBER long long

#define ITER(var, start, cond, end, diff) for(int var = (start); var cond (end); var += diff)
#define ITER_FIX(var, start, end) ITER(var, start, <, end, 1)
#define ITER_ARR(var) ITER_FIX(var, 0, this->n)
#define ITER_REVERSE(var, start, end) ITER(var, start, >=, end, -1)

#define ITER_CONT(var, cont) for(autp& var: cont)
#define ITER_CONT_IT(var, cont) for(auto it = cont.begin(); it != cont.end();)

#define N 10

struct Node
{
    int data;
    struct Node* next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
    static int t;
    public: static void init()
    {
        //cin >> t;
        ITER_FIX(i, 0, t)
        {
            Solution* sl = new Solution();
            sl->process();
            sl->print();
            delete sl;
        }
    }

    private:
        int n, m;
        Node* first, *second, *ret;


    public:

    Solution()
    {        
        cin >> this->n;
        this->first = buildList(n);
        
        cin >> this->m;
        this->second = buildList(m);
    }

    Node* buildList(int size)
    {
        int val;
        cin >> val;
        
        Node* head = new Node(val);
        Node* tail = head;
        
        for(int i = 0; i < size - 1; i++)
        {
            cin >> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        return head;
    }

    void process()
    {
        set<int> h;
        
        Node* current = this->first;
        ITER_FIX(i, 0, 2)
        {
            while(current != NULL)
            {
                h.insert(current->data);
                current = current->next;
            }
            current = this->second;
        }

        current = new Node(*h.begin());
        this->ret = current;
        auto it = h.begin();
        for(advance(it, 1); it != h.end(); it++)
        {
            current->next = new Node(*it);
            current = current->next;
        }
    }

    void print()
    {
        Node* current = this->ret;
        while(current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
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