#include <bits/stdc++.h>

using namespace std;

#define STEROID_NUMBER long long

#define N 10

#define ITER_ARR(start, end) for(int i = (start); i < (end); i++)
#define ITER_ARR_ALL ITER_ARR(0, this->n)
#define ITER_ARR_REVERSE(start, end) for(int i = (start); i >= (end); i--)

#define ITER_VEC(vec) for(int x: vec)

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
    Node* root;
    int x;
    long ret = LONG_MAX;

    public:

    Solution()
    {
        int n;
        cin >> n;

        //cout << n << endl;
        while(n--)
        {
            string s;
            cin.ignore();
            getline(cin, s);

            this->buildTree(s);

            cin >> this->x;

            
            this->process();
            this->print();
        }
    }

    void buildTree(string str)
    {
        if(str.length() == 0 || str[0] == 'N') return;

        vector<string> ip;
        istringstream iss(str);
        for(string str; iss >> str;) ip.push_back(str);


        Node* root = new Node(stoi(ip[0]));
        queue<Node*> queue;
        queue.push(root);

        int i = 1;
        while(!queue.empty() && i < ip.size())
        {
            Node* currNode = queue.front();
            queue.pop();

            string currVal = ip[i];
            if(currVal != "N")
            {
                currNode->left = new Node(stoi(currVal));
                queue.push(currNode->left);
            }

            i++;
            if(i >= ip.size()) break;
            currVal = ip[i];
            
            if(currVal != "N")
            {
                currNode->right = new Node(stoi(currVal));
                queue.push(currNode->right);
            }
            i++;
        }
        
        this->root = root;
    }

    void process()
    {
        Node* current = this->root;
        while(current != NULL)
        {
            if(current->data < this->ret && current->data > this->x) this->ret = current->data;
            if(current->data <= this->x) current = current->right;
            else current = current->left;
        }
        if(this->ret == LONG_MAX) this->ret = -1;
    }

    void print()
    {
        cout << this->ret << "\n";
    }
};

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution* sl = new Solution();
    //sl->process();
    //sl->print();

    return 0;
}