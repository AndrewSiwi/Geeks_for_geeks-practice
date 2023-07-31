#include <bits/stdc++.h>

using namespace std;

#define STEROID_NUMBER long long

#define ITER_ARR(start, end) for(int i = (start); i < (end); i++)
#define ITER_ARR_ALL ITER_ARR(0, this->n)
#define ITER_ARR_REVERSE(start, end) for(int i = (start); i >= (end); i--)

#define ITER_VEC(vec) for(int x: vec)

#define N 10

class Solution
{
    vector<int>* adj, ret;
    int V, E;


    public:

    Solution()
    {
        cin >> this->V >> this->E;
        this->adj = new vector<int>[this->V];
        int E = this->E;
        while(E--)
        {
            int from, to;
            cin >> from >> to;
            this->adj[from].push_back(to);
        }
    }

    void process()
    {
        queue<int> nodes;
        unordered_set<int> was;
        nodes.push(0);
        while(!nodes.empty())
        {
            this->ret.push_back(nodes.front());
            ITER_VEC(this->adj[nodes.front()])
            {
                if(was.find(x) == was.end())
                {
                    nodes.push(x);
                    was.insert(x);
                }
            }
            nodes.pop();
        }
    }
    
    void print()
    {
        ITER_VEC(this->ret)
        {
            cout << x << " ";
        }
        cout << "\n";
        //cout << "\n";
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