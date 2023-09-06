#include<bits/stdc++.h>

using namespace std;

#define int long long

#define iter(var, start, cond, end, diff) for(int var = (start); var cond (end); var += (diff))
#define iter_fix(var, start, end) iter(var, start, <, end, 1)
#define iter_arr(var) iter_fix(var, 0, this->n)
#define iter_reverse(var, start, end) iter(var, start, >=, end, -1)

#define iter_cont(var, cont) for(auto& var: cont)
#define iter_cont_it(var, cont, comm) for(auto var = cont.begin(); var != cont.end(); comm)

const int N = 5e2;

class Solution
{
    static int t;
    public: static void init()
    {
        //cin >> t;
        int ct = 0;
        while(ct < t)
        {
            Solution* sl = new Solution(ct++);
            sl->process();
            sl->print();
            delete sl;
        }
    }


    private: int ct;

    int n, e, ret = -1;
    vector<int> adj[N];
    bool visited[N];

    public: Solution(int ct)
    {
        this->ct = ct;

        cin >> this->n >> this->e;
        int e = this->e;
        while(e--)
        {
            int from, to;
            cin >> from >> to;
            this->adj[from].push_back(to);
        }
    }

    void process()
    {
	    fill(this->visited, this->visited + this->n, false);
	     
	    int v = 0;
	    iter_arr(i)
	    {
	        if(!this->visited[i])
	        {
	            this->walk(i);
	       	    v = i;
	        }  
	    }
	     
	    fill(this->visited, this->visited + this->n, false);
	    this->walk(v);
	    iter_arr(i)
	        if(!this->visited[i])
	            return;

        this->ret = v;
    }

    void walk(int vertex)
	{
	    if(this->visited[vertex])
	        return;
	    
        this->visited[vertex] = true;
        for(int x: this->adj[vertex])
            this->walk(x);
	}

    void print()
    {
        cout << this->ret << "\n";
        //cout << "\n";
    }
};

int Solution::t = 1;

#undef int
int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution::init();

    return 0;
}