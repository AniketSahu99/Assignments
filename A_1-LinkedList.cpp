#include <iostream>

using namespace std;

class Node{

    public:
    
    int data;
    Node* next;

    Node(int n)
    {
        this -> data = n;
        this -> next = NULL;
    }

    ~Node()
    {
        this -> next = NULL;
        delete next;
    }

};

void free(Node* node)
{
    node -> next = NULL;
    delete node;
}

void deleteFront(Node* &head)
{
    Node* prev = head;
    head = head -> next;
    free(prev);
}

void deleteBack(Node* &head)
{
    Node* temp = head;
    Node* prev = NULL;
    while(temp -> next != NULL)
    {
        prev = temp;
        temp = temp -> next;

    }
    prev -> next = NULL;
    free(temp);
}

void deleteAt(Node* &head, int pos = 0)
{
    if(pos == 0)
    {
        deleteFront(head);
        return;
    }

    Node* prev = NULL;
    Node* temp = head;
    while(pos  > 0)
    {
        prev = temp;
        temp = temp -> next;
        pos--;
    }
    prev -> next = temp -> next;
    temp -> next = NULL;
    free(temp);

}

void deletetAfter(Node* &head, int pos = 0)
{
    deleteAt(head, pos + 1);
}

void deleteBefore(Node* &head, int pos = 1)
{
    deleteAt(head, pos - 1);
}

void deleteAll(Node* &head)
{
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL)
    {
        prev = temp;
        temp = temp -> next;
        free(prev);
    }
    head = NULL;
}

void insertFront(int data , Node* &head)
{
    if(head == NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        return;
    }
    Node* newNode = new Node(data);
    newNode -> next = head;
    head = newNode;

}
void insertAt(int data , Node* &head, int pos = 0)
{
    if(head == NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        return;
    }

    if(pos == 0)
    {
        insertFront(data,head);
        return;
    }

    Node* temp = head;
    while(pos - 1 > 1)
    {
        temp = temp -> next;
        pos--;
    }
    Node* newNode = new Node(data);
    newNode -> next = temp -> next;
    temp -> next = newNode;


}
void insertBack(int data , Node* &head)
{
    if(head == NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        return;
    }

    Node* newNode = new Node(data);
    Node* temp = head;
    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = newNode;
    
}

void insertAfter(int data, Node* &head, int pos = 0)
{
    insertAt(data,head, pos + 1);
}

void insertBefore(int data, Node* &head, int pos = 1)
{
    insertAt(data,head, pos - 1);
}

void print( Node* &head)
{
    if(head == NULL)
    {
        cout << "Empty Linked List" << endl;
        return;
    }
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main()
{
    Node* node = new Node(10);
    Node* head = node;
    insertFront(5,head);
    insertBack(15,head);
    insertAt(20,head,2);
    insertAt(40,head);
    print(head);
    cout << "Head -> " << (*head).data << endl << endl;
    deleteFront(head);
    print(head);
    cout << "Head -> " << (*head).data << endl << endl;
    deleteBefore(head,2);
    cout << "Delete Before "<< 2 <<endl;
    print(head);
    cout << "Head -> " << (*head).data << endl << endl;
    deleteAt(head,1);
    cout << "Delete At " << 1 <<endl;
    print(head);
    cout << "Head -> " << (*head).data << endl << endl;
    deleteAll(head);
    cout << "Deleted ALL " <<endl;
    print(head);
    cout << "Head -> " << (*head).data << endl << endl;

    
}