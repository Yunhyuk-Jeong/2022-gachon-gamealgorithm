#include <iostream>

#define MAX_NODE 50000
#define MAX_EDGE 200000

using namespace std;

typedef struct Edge
{
    int from;
    int to;
    int weight;
    Edge *next;

    Edge()
    {
        from = 0;
        to = 0;
        weight = 0;
        next = NULL;
    }

    Edge(int newFrom, int newTo, int newWeight)
    {
        from = newFrom;
        to = newTo;
        weight = newWeight;
        next = NULL;
    }
} Edge;

typedef struct List
{
    Edge *head;

    List()
    {
        head = NULL;
    }
} List;

typedef struct Heap
{
    Edge heap[MAX_EDGE];
    int heapSize;

    Heap()
    {
        heapSize = 0;
    }
} Heap;

Heap h;
List *list[MAX_NODE];
int N, M;
bool included[MAX_NODE];

void listAdd(List *list, int from, int to, int weight)
{
    Edge *edge = new Edge(from, to, weight);
    Edge *head = list->head;

    if (list->head == NULL)
        list->head = edge;
    else
    {
        while (head->next != NULL)
            head = head->next;

        head->next = edge;
    }
}

void heapInit(Heap *h)
{
    h->heapSize = 0;
}

void heapPush(Heap *h, Edge edge)
{
    int idx = ++(h->heapSize);

    while (idx != 1 && (h->heap[idx / 2].weight > edge.weight))
    {
        h->heap[idx] = h->heap[idx / 2];
        idx /= 2;
    }

    h->heap[idx] = edge;
}

Edge heapPop(Heap *h)
{
    Edge edge = h->heap[1];
    Edge temp = h->heap[(h->heapSize)--];
    int parent = 1;
    int child = 2;

    while (child <= h->heapSize)
    {
        if (child < h->heapSize && h->heap[child].weight > h->heap[child + 1].weight)
            child++;
        if (temp.weight <= h->heap[child].weight)
            break;

        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }

    h->heap[parent] = temp;

    return edge;
}

int prim()
{
    int answer = 0;

    for (int i = 0; i < MAX_NODE; i++)
        included[i] = false;

    included[0] = true;

    Edge edge;
    heapInit(&h);

    Edge *head = list[0]->head;
    while (head != NULL)
    {
        heapPush(&h, *head);
        head = head->next;
    }

    int numCheck = 0;

    while (numCheck != N - 1)
    {
        edge = heapPop(&h);

        if (!included[edge.to])
        {
            answer += edge.weight;
            included[edge.to] = true;

            head = list[edge.to]->head;

            while (head != NULL)
            {
                if (!included[head->to])
                    heapPush(&h, *head);
                head = head->next;
            }
            numCheck++;
        }
    }

    return answer;
}

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int answer = 0;

    cin >> N;

    for (int i = 0; i < N; i++)
        list[i] = new List();

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        listAdd(list[from - 1], from - 1, to - 1, weight);
        listAdd(list[to - 1], to - 1, from - 1, weight);
    }

    cout << prim() << '\n';

    for (int i = 0; i < N; i++)
    {
        Edge *head = list[i]->head;
        while (head != NULL)
        {
            Edge *tmp = head;
            head = head->next;
            delete tmp;
        }
        delete[] list[i];
    }

    return 0;
}