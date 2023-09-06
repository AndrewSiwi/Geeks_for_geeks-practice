#include <bits/stdc++.h>

using namespace std;

#define ITER_ARR(start, end) for(int i = (start); i < (end); i++)
#define ITER_ARR_ALL ITER_ARR(0, this->n)
#define ITER_ARR_REVERSE for(int i = this->n - 1; i >= 0; i--)

#define N 10

struct Node
{ 
  int data;
  Node* next;

  Node(int x)
  {
    data = x;
    next = NULL;
  }
};

class Solution
{
  int n;
  Node* head;

  public:

  Solution()
  {
    cin >> this->n;
    int n, value, i;
    // scanf("%d",&n);
    n = this->n;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        cin >> value;

        if (i == 0) {
            temp = new Node(value);
            this->head = temp;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
  }

  void process()
  {
    vector<int> vals;
        
        for(int i = 0; i < 3; i++)
        {
            Node* current = this->head;
            while(current != NULL)
            {
                if(current->data == i) vals.push_back(current->data);
                current = current->next;
            }
        }
        
        Node* start = new Node(vals[0]);
        Node* current_end = start;
        
        for(int i = 1; i < vals.size(); i++)
        {
            current_end->next = new Node(vals[i]);
            current_end = current_end->next;
        }

        this->head = start;
  }

  void print()
  {
    Node* x = this->head;
    ITER_ARR_ALL
    {
      cout << x->data << " ";
      x = x->next;
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
