#pragma once
using namespace std;
template <typename T>
struct LL
{
    T data;
    LL *next;
};
template <typename T>
class LinkedList
{
private:
    LL<T> *head, **tail;
    int size;

public:

    // Initialisation
    LinkedList()
    {
        size = 0;
        head = NULL;
        tail = &head;
    }
    // insert an item

    bool insert(T data)
    {
        LL<T> *temp = new LL<T>;
        if (temp == NULL)
            return false;
        *tail = temp;
        (*tail)->data = data;
        tail = &((*tail)->next);
        *tail = NULL;
        size++;
        return true;
    }
    int len() {
        return size;
    }

    // delete
    bool del_index(int n)
    {
        LL<T> **temp, *d;
        temp = &head;
        if (n < 0||n > size - 1)
            return false;
        for (; n > 0; n--)
            temp = &((*temp)->next);
        d = *temp;
        *temp = ((*temp)->next);
        if(*temp==NULL) {
            tail = temp;
        }
        delete d;
        size--;
        return true;
    }
    bool del_data(T data)
    {
        LL<T> **temp, *d;
        temp = &head;
        while (*temp != NULL && (*temp)->data != data)
            temp = &((*temp)->next);
        d = *temp;
        if (d == NULL)
            return false;
        *temp = ((*temp)->next);
        if(*temp==NULL) {
            tail = temp;
        }
        delete d;
        size--;
        return true;
    }

    // GET
    int find(T data)
    {
        LL<T> *ptr = head;
        int i = 0;
        while (ptr != NULL)
        {
            if (ptr->data == data)
                break;
            ptr = ptr->next;
            i++;
        }
        if (ptr == NULL)
            return -1;

        return i;
    }

    T at_index(int i)
    {
        LL<T> *ptr = head;
        if (i < 0 || i > size - 1)
            return INT_MIN;
        for (; i > 0; i--)
            ptr = ptr->next;
        return ptr->data;
    }

    // print
    void display()
    {
        LL<T> *ptr;
        ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->data << " -> ";
            ptr = ptr->next;
        }
        cout << "Length = " << size << endl;
    }
    // Delete
    ~LinkedList()
    {
        LL<T> *ptr;
        while (head != NULL)
        {
            ptr = head;
            head = head->next;
            delete ptr;
        }
    }
};