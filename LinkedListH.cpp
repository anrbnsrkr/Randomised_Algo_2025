#pragma once
#include <vector>
using namespace std;
template <typename Type>
struct LL
{
    Type data;
    LL *next;
};
template <typename Type>
class LinkedList
{
private:
    LL<Type> *head, **tail;
    int size;

public:

    // Initialisation
    LinkedList()
    {
        size = 0;
        head = NULL;
        tail = &head;
    }
    LinkedList(const vector<Type> &lis)
    {
        size = 0;
        head = NULL;
        tail = &head;
        for(Type data:lis) {
            this->insert(data);
        }
    }
    LL<Type>* get_head(){
        return head;
    }
    pair<LL<Type>*,LL<Type>**> setHeadToNull(){
        LL<Type>*ptr = head;
        LL<Type>**pptr = tail;
        head = NULL;
        tail = &head;
        return {ptr,pptr};
    }
    // insert an item
    bool insert(Type data)
    {
        LL<Type> *temp = new LL<Type>;
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
    Type del_index(int n)
    {
        LL<Type> **temp, *d;
        temp = &head;
        if (n < 0||n > size - 1)
            return 0;
        for (; n > 0; n--)
            temp = &((*temp)->next);
        d = *temp;
        *temp = ((*temp)->next);
        if(*temp==NULL) {
            tail = temp;
        }
        Type data = d->data;
        delete d;
        size--;
        return data;
    }
    bool del_data(Type data)
    {
        LL<Type> **temp, *d;
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
    int find(Type data)
    {
        LL<Type> *ptr = head;
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

    Type at_index(int i)
    {
        LL<Type> *ptr = head;
        if (i < 0 || i > size - 1)
            return 0;
        for (; i > 0; i--)
            ptr = ptr->next;
        return ptr->data;
    }

    // print
    void display()
    {
        LL<Type> *ptr;
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
        LL<Type> *ptr;
        while (head != NULL)
        {
            ptr = head;
            head = head->next;
            delete ptr;
        }
    }
};