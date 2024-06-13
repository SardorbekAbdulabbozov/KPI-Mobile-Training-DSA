#include <iostream>
using namespace std;

struct Node
{
public:
    int value;
    Node *next;

    Node(int value)
    {
        this->value = value;
        next = nullptr;
    }
};

class LinkedList
{
    int length;
    Node *head;
    Node *tail;

public:
    // constructor with member initializer list
    LinkedList() : head(nullptr), tail(nullptr), length(0) {}

    // desctructor
    ~LinkedList()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    // function to add element to the end
    void append(int newValue)
    {
        Node *newNode = new Node(newValue);
        if (tail == nullptr)
        {
            head = newNode;
            tail = head;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
        length++;
    }

    // function to remove element from the end
    void removeLast()
    {
        if (tail == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node *current = head;

            while (current->next != tail)
            {
                current = current->next;
            }

            delete tail;
            current->next = nullptr;
            tail = current;
        }
        length--;
    }

    // function to insert element at specified position
    void insertAt(int newValue, int index)
    {

        if (index < 0 || index > length)
        {
            cout << "ERROR: Index out of bounds" << endl;
            return;
        }

        Node *newNode = new Node(newValue);

        if (index == 0)
        {
            newNode->next = head;
            head = newNode;
            if (length == 0)
            {
                tail = newNode;
            }
        }
        else if (index == length)
        {
            append(newValue);
            return;
        }
        else
        {
            Node *current = head;
            for (int i = 0; i < index - 1; i++)
            {
                current = current->next;
            }

            newNode->next = current->next;
            current->next = newNode;
        }
        length++;
    }

    // function to remove element at specified position
    void removeAt(int index)
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (index < 0 || index >= length)
        {
            cout << "ERROR: Index out of bounds" << endl;
            return;
        }
        else if (index == 0)
        {
            if (head->next != nullptr)
            {
                Node *temp = head;
                head = head->next;
                delete temp;
            }
            else
            {
                delete head;
                head = nullptr;
                tail = nullptr;
            }
            length--;
        }
        else
        {
            Node *current = head;
            for (int i = 0; i < index - 1; i++)
            {
                current = current->next;
            }
            Node *nextNode = current->next->next != nullptr ? current->next->next : nullptr;
            delete current->next;
            current->next = nextNode;
            if (current->next == nullptr)
            {
                tail = current;
            }
            length--;
        }
    }

    // function to traverse elements
    void traverseList()
    {

        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *current = head;
        cout << "--> Length = " << length << endl;
        while (current != nullptr)
        {
            cout << "Node: " << current->value << endl;
            current = current->next;
        }
    }
};

int main()
{
    LinkedList linkedList = LinkedList();
    cout << endl;

    linkedList.append(101);
    linkedList.append(234);
    linkedList.append(94);
    linkedList.append(27);
    linkedList.append(68);
    linkedList.insertAt(1, 0);
    linkedList.insertAt(2, 1);
    linkedList.insertAt(3, 2);
    linkedList.insertAt(5, 7);

    linkedList.traverseList();

    cout << "\n----------------\n"
         << endl;

    linkedList.removeLast();
    linkedList.removeAt(0);
    linkedList.removeAt(6);
    linkedList.removeAt(1);

    linkedList.traverseList();
}
