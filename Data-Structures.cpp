#include <iostream>
#include <cstring>

using namespace std;

struct IntNode
{
    int value;
    IntNode *nextNode;

    IntNode()
    {
        value = 0;
        nextNode = NULL;
    }
};

struct LinkedList
{
private:
    IntNode *headNode;
    IntNode *currentNode;
    IntNode *tempNode;

public:
    LinkedList()
    {
        headNode = NULL;
        currentNode = NULL;
        tempNode = NULL;
    }
    void addNode(int newValue)
    {
        IntNode *newNode = new IntNode();
        newNode->value = newValue;
        newNode->nextNode = NULL;

        if (headNode != NULL)
        {
            currentNode = headNode;

            while (currentNode->nextNode != NULL)
            {
                currentNode = currentNode->nextNode;
            }
            currentNode->nextNode = newNode;
        }
        else
        {
            headNode = newNode;
        }
    }
    void traverse()
    {
        currentNode = headNode;

        while (currentNode != NULL)
        {
            cout << currentNode->value << endl;
            currentNode = currentNode->nextNode;
        }
    }
};

struct IntStack
{
private:
    IntNode *stackPtr;

public:
    void push(int value)
    {
        IntNode *push = new IntNode;

        push->value = value;

        if (stackPtr == NULL)
        {
            stackPtr = push;
            stackPtr->nextNode = NULL;
        }
        else
        {
            push->nextNode = stackPtr;
            stackPtr = push;
        }
    }
    void readValue(IntNode *r)
    {
        cout << r->value << " ";
    }
    void print()
    {
        IntNode *print = stackPtr;

        if (stackPtr == NULL)
        {
            cout << "Stack is empty";
        }
        else
        {
            cout << "Stack is: ";
            while (print != NULL)
            {
                readValue(print);
                print = print->nextNode;
            }
            cout << "end of stack" << endl;
        }
    }
    void pop()
    {
        IntNode *pop = stackPtr;
        stackPtr = stackPtr->nextNode;
        pop->nextNode = NULL;
        delete pop;
    }

    IntStack()
    {
        stackPtr = NULL;
    }
    ~IntStack()
    {
        IntNode *pointer1;
        IntNode *pointer2;

        pointer1 = stackPtr;

        while (pointer1 != NULL)
        {
            pointer2 = pointer1;
            pointer1 = pointer1->nextNode;
            pointer2->nextNode = NULL;
            delete pointer2;
        }
    }
};

int main(void)
{
    cout << "LinkedList" << endl;
    LinkedList a;
    a.addNode(20);
    a.traverse();
    a.addNode(10);
    a.traverse();

    cout << "Stack" << endl;
    IntStack b;
    b.push(12);
    b.push(3);
    b.push(25);
    b.print();
    b.pop();
    b.pop();
    b.pop();
    b.print();
}
