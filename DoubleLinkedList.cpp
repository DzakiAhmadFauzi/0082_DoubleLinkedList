#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int noMhs;
    Node *next;
    Node *prev;
};

class DoubleLinkedList
{
private:
    Node *START;

public:
    DoubleLinkedList()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        cout << "\nEnter the roll number of the student: ";
        cin >> nim;

        // step 1 : allocate memory for new node
        Node *newNode = new Node();

        // step 2 : assign value to the data fields
        newNode->noMhs = nim;

        // step 3 : insert ar the beginning if list is empty or nim is smaller than the first node
        if (START == NULL || nim <= START->noMhs)
        {
            if (START != NULL && nim == START->noMhs)
            {
                cout << "\nDuplicate number not allowed" << endl;
                return;
            }
            // step 4 : newnode.next = start
            newNode->next = START;

            // step 5 : start.prev = newnode (if start exists)
            if (START != NULL)
                START->prev = newNode;

            // step 6 : newnode.prev = null
            newNode->prev = NULL;

            // step 7 : start = newnode
            START = newNode;
            return;
        }

        //  insert in between node
        // step 8 : Locate position to insertion
        Node *current = START;
        while (current->next != NULL && current->next->noMhs < nim)
        {
            current = current->next;
        }

        if (current->next != NULL && nim == current->next->noMhs)
        {
            cout << "\nDuplicate roll number not allowed" << endl;
            return;
        }

        // step 9: Insert between current and current->next
        newNode->next = current->next; // step 9a: newnode.next = current->next
        newNode->prev = current;       // step 9b: newnode.prev = current

        // insert lost node
        if (current->next != NULL)
            current->next->prev = newNode; // step 9c: current->next.prev = newnode

        current->next = newNode; // step 9d: current.next = newnode
    }

    void hapus()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        cout << "\nEnter thr roll number of the student whose record is to be deleted: ";
        int rollNo;
        cin >> rollNo;

        Node *current = START;

        // step 1: Traverse the list to find the node
        while (current != NULL && current->noMhs != rollNo)
            current = current->next;

        if (current == NULL)
        {
            cout << "Record not found" << endl;
            return;
        }

        // step 2: if node is at the beginning
        if (current == START)
        {
            START = current->next; // step 2a: START = START.next
            if (START != NULL)
                START->prev = NULL; // step 2b: START.prev = null
        }
        else
        {
            // step 3: Link previous node to next node of current
            current->prev->next = current->next;

            // step 4: If current is not the last node
            if (current->next != NULL)
                current->next->prev = current->prev;
        }

        
