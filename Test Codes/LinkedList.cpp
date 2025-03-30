#include <iostream>
#include <type_traits>
#include <cstdlib>
#include <cstdio>
#include <climits>
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
    int x = true;
    while(x) {
        lis.display();
        x = lis.del_index(2);
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
        int item = lis.at_index(5);
        x = lis.del_data(item);
        cout<<x<<":   ";
    }
    cout<<endl;
    return 0;
}