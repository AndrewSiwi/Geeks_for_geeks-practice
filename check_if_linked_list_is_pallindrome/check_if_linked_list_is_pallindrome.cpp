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

const int N = 1e1;

struct Node
{
    int data;
    Node* next;

    Node(int x)
    {
        this->data = x;
        this->next = NULL;
    }
};

class Solution
{
    static int t;
    public: static void init()
    {
        //cin >> t;
        int ct = 0;
        while(ct < Solution::t)
        {
            Solution* sl = new Solution(ct++);
            sl->process();
            sl->print();
            delete sl;
        }
    }


    private: int ct;

    int n;
    Node* head;
    bool ret = true;
    
    public: Solution(int ct)
    {
        this->ct = ct;

        cin >> this->n;
        int n = this->n;
        int x;
        cin >> x;
        this->head = new Node(x);
        Node* current = this->head;
        n--;
        while(n--)
        {
            cin >> x;
            current->next = new Node(x);
            current = current->next;
        }
    }

    void process()
    {
        Node* mid = this->head;
        iter_fix(i, 0, (this->n / 2))
            mid = mid->next;

        
        Node* first = mid, *second = mid->next, *third = NULL;
        first->next = NULL;
        while(second != NULL)
        {
            third = second->next;
            second->next = first;
            first = second;
            second = third;
        }

        Node* current = this->head;
        Node* reverseCurrent = first;
        while(reverseCurrent != NULL)
        {
            if(current->data != reverseCurrent->data)
            {
                this->ret = false;
                return;
            }
            current = current->next;
            reverseCurrent = reverseCurrent->next;
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
int main(int main, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution::init();

    return 0;
}
