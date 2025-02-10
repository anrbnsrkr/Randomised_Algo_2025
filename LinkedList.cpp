#include <iostream>
#include <type_traits>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <vector>

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

int main()
{
    vector<int> arr = {10, 12, 15, 17, 20, 22, 15, 17, 30};
    LinkedList<int> lis;
    for (auto i : arr)
        lis.insert(i);

    lis.display();
    cout << lis.del_index(8) << endl;
    cout << lis.del_data(9) << endl;
    cout << lis.find(20) << endl;
    cout << lis.del_index(3) << endl;
    lis.display();
    cout<<lis.at_index(8)<<endl;
    cout<<lis.at_index(4)<<endl;
    cout << lis.find(20) << endl;
    cout << lis.find(15) << endl;
    cout<<lis.insert(100)<<endl;
    lis.display();
    bool x = true;
    while(x) {
        lis.display();
        x = lis.del_index(0);
        cout<<x<<":   ";
    }
    lis.display();
    lis.insert(50);
    lis.display();
    lis.del_index(0);
    for (auto i : arr){
        lis.insert(i);
    }
    x = 1;
    cout<<x<<":   ";
    while(x) {
        lis.display();
        int item = lis.at_index(0);
        x = lis.del_data(item);
        cout<<x<<":   ";
    }
    cout<<endl;
    return 0;
}