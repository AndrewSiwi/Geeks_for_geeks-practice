#include <bits/stdc++.h>

using namespace std;

#define STEROID_NUMBER long long

#define ITER_ARR(start, var, end) for(int var = (start); var < (end); i++)
#define ITER_ARR_ALL ITER_ARR(0, i, this->n)
#define ITER_ARR_REVERSE(start, var, end) for(int var = (start); var >= (end); var--)

#define ITER_VEC(vec) for(int x: vec)

#define N 10

class Solution
{
    int v, e;
    vector<int>* adj, ret;
    unordered_set<int> was;

    public:

    Solution()
    {
        cin >> this->v >> this->e;
        this->adj = new vector<int>[this->v];
        int e = this->e;
        while(e--)
        {
            int source, target;
            cin >> source >> target;
            this->adj[source].push_back(target);
        }
    }

    void process()
    {
        stack<int> nodes;
        nodes.push(0);
        while(!nodes.empty())
        {
            int current = nodes.top();
            
            if(this->was.find(current) != this->was.end()) nodes.pop();
            else
            {
                this->was.insert(current);
                this->ret.push_back(current);        
                for(int i = this->adj[current].size() - 1; i >= 0; i--) nodes.push(this->adj[current][i]);
            }
        }
    }

    void print()
    {
        ITER_VEC(this->ret) cout << x << " ";
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