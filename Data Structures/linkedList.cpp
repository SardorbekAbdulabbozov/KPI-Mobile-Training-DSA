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

public:
    // constructor with member initializer list
    LinkedList() : head(nullptr), length(0) {}

    // desctructor
    ~LinkedList()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    // function to add element to the end
    void append(int newValue)
    {
        if (head == nullptr)
        {
            head = new Node(newValue);
        }
        else
        {
            Node *newNode = new Node(newValue);
            Node *current = head;

            while (current->next != nullptr)
            {
                current = current->next;
            }

            current->next = newNode;
        }
        length++;
    }

    // function to remove element from the end
    void removeLast()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node *current = head;

            while (current != nullptr)
            {
                if (current->next->next == nullptr)
                {
                    break;
                }
                current = current->next;
            }

            delete current->next;
            current->next = nullptr;
        }
        length--;
    }

    // function to insert element at specified position
    void insertAt(int newValue, int index)
    {

        if (index < 0)
        {
            cout << "ERROR: Index out of bounds" << endl;
            return;
        }

        if (head == nullptr)
        {
            head = new Node(newValue);
            length++;
            return;
        }

        if (index < length)
        {
            Node *newNode = new Node(newValue);
            Node *current = head;

            for (int i = 0; i < index - 1; i++)
            {
                current = current->next;
            }

            if (index == 0)
            {
                newNode->next = head;
                head = newNode;
                length++;
                return;
            }

            if (current->next != nullptr)
            {
                newNode->next = current->next;
            }
            current->next = newNode;
            length++;
        }
        else if (index == length)
        {
            append(newValue);
        }
        else
        {
            cout << "ERROR: Index out of bounds" << endl;
            return;
        }
    }

    // function to remove element at specified position
    void removeAt(int index)
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        if (index < 0)
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
            }
            length--;
        }
        else
        {

            if (index < length)
            {
                Node *current = head;
                for (int i = 0; i < index - 1; i++)
                {
                    current = current->next;
                }
                Node *nextNode = current->next->next != nullptr ? current->next->next : nullptr;
                delete current->next;
                current->next = nextNode;
                length--;
            }
            else
            {
                cout << "ERROR: Index out of bounds" << endl;
            }
        }
    }

    // function to traverse elements
    void traverseList()
    {
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