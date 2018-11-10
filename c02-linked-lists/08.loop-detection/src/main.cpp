#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int value;
    Node *next;
};

void printList(Node *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        if (cnt == 20) break;
        cout << head->value << " ";
        head = head->next;

        cnt++;
    }

    cout << endl;
}

bool findLoop(Node *head, int *loopStart)
{
    if (head == NULL) return false;

    Node *slowRunner = head;
    Node *fastRunner = head;

    do
    {
        if (slowRunner == NULL) return false;
        if (fastRunner == NULL) return false;
        if (fastRunner->next == NULL) return false;

        slowRunner = slowRunner->next;
        fastRunner = fastRunner->next;
        fastRunner = fastRunner->next;
    } while (slowRunner != fastRunner);

    slowRunner = head;
    while (slowRunner != fastRunner)
    {
        if (slowRunner == NULL) return false;
        if (fastRunner == NULL) return false;

        slowRunner = slowRunner->next;
        fastRunner = fastRunner->next;
    }
    
    *loopStart = slowRunner->value;
    return true;
}

void formLoop(Node *head, Node *tail, int loopIndex)
{
    Node *currentNode = head;
    for (int i = 0; i < loopIndex; i++)
    {
        assert(currentNode != NULL);
        currentNode = currentNode->next;
    }
    
    tail->next = currentNode;
}

int main()
{
    int N;
    int loopIndex;
    cin >> N;
    
    Node *head = new Node;
    cin >> head->value;

    Node *tail = head;
    for (int i = 1; i < N; i++)
    {
        Node *newNode = new Node;
        tail->next = newNode;
        tail = newNode;

        cin >> tail->value;
    }
    
    cin >> loopIndex;
    formLoop(head, tail, loopIndex);

    int foundIndex;
    if (findLoop(head, &foundIndex))
    {
        cout << foundIndex << endl;
    }
    else 
    {
        cout << "Linked list does not form a loop" << endl;
    }
}
