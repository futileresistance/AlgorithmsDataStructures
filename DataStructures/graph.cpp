#include <iostream>
using namespace std;

struct Node
{
    int value, weight;
    Node* next;
};

struct Edge
{
    int source, destination, weight;
};

class Graph
{
    Node *getAdjListNode(int val, int wgt, Node *head)
    {
        Node *newNode = new Node;
        newNode->value = val;
        newNode->weight = wgt;
        newNode->next = head;
        return newNode;
    }

    int N;

public:

    Node **head;

    Graph(Edge edges[], int n, int N)
    {
        head = new Node*[N]();
        this->N = N;

        for (int i=0;i<N;++i)
        {
            head[i] = nullptr;
        }
        for (unsigned i=0;i<n;i++)
        {
            int start = edges[i].source;
            int end = edges[i].destination;
            int weight = edges[i].weight;
            Node *newNode = getAdjListNode(end, weight, head[start]);
            head[start] = newNode;
        }
    }

    ~Graph()
    {
        for (int i=0;i<N;i++)
        {
            delete[] head[i];
            delete[] head;
         }
    }

void displayAdjList(Node *ptr, int i)
{
    while (ptr != nullptr)
    {
        cout << "(" << i << ", " << ptr->value
             << ", " << ptr->weight << ") ";
        ptr = ptr->next;
    }
    cout << endl;
}

};

int main()
{
    Edge edges[] = {{0,1,2}, {0,2,4}, {1,4,3}, {2,3,2}, {3,1,4}, {4,3,3}};
    int N = 6;
    int n = sizeof (edges)/sizeof (edges[0]);
    Graph myGraph(edges, n, N);
    cout << "Graph adj list: " << endl;
    for (int i=0;i<N;i++)
    {
        myGraph.displayAdjList(myGraph.head[i], i);
    }
    return 0;
}
