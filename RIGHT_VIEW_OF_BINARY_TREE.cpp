#include <bits/stdc++.h>

using namespace std;

#define ITER_ARR(start, end) for(int i = (start); i < (end); i++)
#define ITER_ARR_ALL ITER_ARR(0, this->n)
#define ITER_ARR_REVERSE for(int i = this->n - 1; i >= 0; i--)

#define N 100000

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
  int n, height;
  Node* root;
  vector<int> ret;

  public:

  Solution()
  {
    string xs;
    getline(cin, xs);

    istringstream iss;
    iss.str(xs);

    for(char x; iss >> x;)
    {
      cout << iss.str() << "\n";
    }
  }

  void process()
  {
    this->recursive(this->root, 1);
  }

  void recursive(Node* node, int height)
  {
    if(node == NULL) return;
       
    if(height > this->height) { this->ret.push_back(node->data); this->height++; }
    this->recursive(node->right, ++height);
    this->recursive(node->left, height);
  }

  void print()
  {
    for(int x: this->ret)
    {
      cout << x << " ";
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
