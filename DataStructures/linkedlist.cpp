#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};


class SinglyLinkedList
{
private:

public:
    node *head;
    int size = 0;
    SinglyLinkedList()
    {
        head = NULL;
    }

void PushFront(int x)
{
    cout << "PUSH FRONT " << x << endl;
    node *new_node = new node;
    new_node->data = x;
    new_node->next = NULL;
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        node *tmp = head;
        head = new_node;
        new_node->next = tmp;
    }
    size++;
}

int topFront()
{
   cout << "TOP FRONT" << endl;
   if (head == NULL)
   {
       cout << "Linked list is empty" << endl;
       return 0;
   }
   return head->data;
}

void PopFront()
{
    cout << "POP FRONT" << endl;
    if (head == NULL)
    {
        cout << "Linked list is empty" << endl;
        return;
    }

    size--;
    if (head->next == NULL){
        delete head;
        head = NULL;
        return;
    }

    node *tmp_head = head->next;
    delete head;
    head = tmp_head;

}

void PopBack()
{
    cout << "POP BACK" << endl;
    if (head == NULL)
    {
        cout << "Linked list is empty" << endl;
        return;
    }
    size--;
    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    node *before_last_node = head;
    while (before_last_node->next->next != NULL)
    {
        before_last_node = before_last_node->next;
    }

    delete before_last_node->next;
    before_last_node->next = NULL;

}

void PushBack(int x)
{
    cout << "PUSH BACK " << x << endl;
    node *new_node = new node;
    new_node->data = x;
    new_node->next = NULL;
    size++;
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        node *last_node = head;
        while (last_node->next != NULL)
        {
            last_node = last_node->next;
        }
        last_node->next = new_node;
    }

}

int TopBack()
{
    cout << "TOP BACK" << endl;
    if (head == NULL)
    {
        cout << "Linked list is empty" << endl;
        return 0;
    }
    node *last_node = head;
    while (last_node->next != NULL)
    {
        last_node = last_node->next;
    }
    return last_node->data;
}

bool Find(int x)
{
    cout << "FIND " << x << endl;
    if (head == NULL)
    {
        cout << "Linked list is empty" << endl;
        return false;
    }
    node *tmp_node = head;
    while (tmp_node->next != NULL)
    {
        tmp_node = tmp_node->next;
        if (tmp_node->data == x)
        {
            return true;
        }
    }
    return false;
}

node* FindAtIndex(int index)
{
    if ((index > size - 1) || (index < 0))
        {
            cout << "Linked list has only " << size << " elements, incorrect index value" << endl;
            return NULL;
        }

    node *tmp_node = head;
    int tmp_size = 0;
    while (tmp_size != index)
    {
        tmp_node = tmp_node->next;
        tmp_size++;
    }
    return tmp_node;
}



void Erase(int index)
{
    cout << "ERASE AT " << index << endl;
    node *node_to_be_erased = FindAtIndex(index);
    if (node_to_be_erased == NULL)
    {
        return;
    }
    size--;
    if (head == node_to_be_erased)
    {
        node *tmp = node_to_be_erased->next;
        delete head;
        head = tmp;
        return;
    }

    node *prev_node = head;
    while (prev_node->next != node_to_be_erased)
    {
        prev_node = prev_node->next;
    }

    node *tmp = node_to_be_erased->next;
    delete node_to_be_erased;
    prev_node->next = tmp;
}

bool Empty()
{
    cout << "IS EMPTY?" << endl;
    if (head == NULL)
    {
        return true;
    }
    return false;
}

void AddBefore(node *next_node, int x)
{
    cout << "ADD BEFORE NODE" << endl;
    if (next_node == NULL)
    {
        cout << "THE NEXT NODE IS REQUIRED, CANNOT BE NULL";
        return;
    }
    size++;
    node *new_node = new node;
    new_node->data = x;

    node *before_node = head;
    while (before_node->next != next_node)
    {
        before_node = before_node->next;
    }
    before_node->next = new_node;
    new_node->next = next_node;
}

void AddAfter(node *prev_node, int x)
{
    cout << "ADD AFTER NODE" << endl;
    if (prev_node == NULL)
    {
        cout << "THE PREVIOUS NODE IS REQUIRED, CANNOT BE NULL";
        return;
    }
    size++;
    node *new_node = new node;
    new_node->data = x;
    new_node->next = prev_node->next;
    prev_node->next = new_node;

}

void PrintList()
{
    if (head == NULL)
    {
        cout << "Linked List is empty" << endl;
        return;
    }
    node *tmp_head = head;
    cout << "HEAD-->";

    while (tmp_head != NULL)
    {
        cout << tmp_head->data << "-->";
        tmp_head = tmp_head->next;
    }

    cout << "NULL" << endl;
}

};

int main()
{
    SinglyLinkedList a;
    a.PopFront();
    cout << boolalpha << a.Empty() << endl;
    a.PushFront(1);
    a.PopFront();
    cout << boolalpha << a.Empty() << endl;
    a.PushFront(2);
    a.PushBack(3);
    a.PopBack();
    a.PushBack(4);
    a.PushFront(5);
    a.PrintList();
    cout << "List size: " << a.size << endl;
    a.Erase(3);
    a.Erase(2);
    a.PushBack(6);
    a.PushBack(7);
    a.PrintList();
    a.PopFront();
    a.PrintList();
    a.AddAfter(a.head->next, 10);
    a.PrintList();
    a.AddBefore(a.head->next, 10);
    a.PrintList();
    a.Find(10);
    a.Find(100);
    a.PopBack();
    a.PrintList();
    cout << "List size: " << a.size << endl;
    cout << "DONE!" << endl;
    return 0;
}


