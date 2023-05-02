#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head = NULL;

void setup(int n);
Node *remove(Node *to_delete);

int main()
{
    int N, M;

    cout << "Welcome to Josephus Problem!" << endl;

    cout << "Please enter the number of players: ";
    cin >> N;
    while (N < 1) {
        cout << "Invalid value for number of players, please enter again: ";
        cin >> N;
    }

    cout << "Please enter the number of rotations: ";
    cin >> M;

    setup(N);

    Node *temp = head;
    while (true)
    {   
        if(head->next == head)
            break;
        // 1 2 3 4 5 6 7 8 9 10
        for (int i = 1; i <= M; i++)
            temp = temp->next;

        temp = remove(temp);
    }
    
    cout << "Lasting member is: " << head->data << endl;
}

void setup(int n)
{
    Node *temp;
    for (int i = 1; i <= n; i++) {
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data = i;
        newnode->next = NULL;

        // If circle is empty.
        if (i == 1) {
            head = newnode;
            newnode->next = head;
            temp = newnode;
            continue;
        }

        temp->next = newnode;
        newnode->next = head;
        temp = newnode;
    }
}

Node *remove(Node *to_delete)
{
    if (to_delete == head) {

        while (to_delete->next != head)
            to_delete = to_delete->next;

        to_delete->next = head->next;
        to_delete = head;
        head = to_delete->next;

        cout << "number " << to_delete->data << " has died." << endl;
        delete to_delete;

        return head;
    }

    Node *temp = head;
    for (int i = 1; temp->next != to_delete; i++) {
        temp = temp->next;
    }    

    temp->next = to_delete->next;
    cout << "number " << to_delete->data << " has died." << endl;
    delete to_delete;

    return temp->next;
}
