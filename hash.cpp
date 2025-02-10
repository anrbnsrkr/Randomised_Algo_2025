#include<iostream>
#include<type_traits>
#include<cstdlib>
#include<cstdio>
#include<climits>
#include<vector>
#include "LinkedList.h"

template<typename type>
class Hash{
private:
    long unsigned int key, pos, items;
    LinkedList<type> **arr;
public:
    //CONSTRUCTOR
    Hash(long unsigned int _key)
    {
        items = 0;
        if(_key <10)
            this->key = 1024;
        key = _key;
        this->arr = new LinkedList<type>*[key];
        for(int i = 0; i < key; i++) {
            arr[i] = new LinkedList<type>;
        }
    }
    Hash()
    {
        items = 0;
        this->key = 1024;
        this->arr = new LinkedList<type>[key];
        for(int i = 0; i < key; i++) {
            arr[i] = new LinkedList<type>;
        }
    }
    //distructor
    ~Hash()
    {
        for(long unsigned int i = 0; i < key; i++)
            delete arr[i];
        delete arr;
    }

    //end Contructor and Distructor

    // insert
    bool insert(type x)
    {
        pos = ((long unsigned int) x) % key;
        int success = arr[pos]->find(x);
        if (success != -1)
            return false;
        return arr[pos]->insert(x);
    }
    bool is_present(type x)
    {
        pos = ((long unsigned int)x) % key;
        int found = arr[pos]->find(x);
        if(found>=0)
            return true;
        
        return false;
    }
    bool del(type x)
    {
        pos = ((long unsigned int)x) % key;
        return arr[pos]->del_data(x);
    }
    void display() {
        cout<<"//table: //"<<endl;
        for(long unsigned i = 0; i < key; i++) {
            cout<<i<<" : ";
            arr[i]->display();
        }
        cout<<endl<<"//end//"<<endl;
    }
};

int main() {
    vector<int> arr = {10, -12, 15, 17, 20, 22, 15, 17, 30};
    Hash<int> lis(11);
    for (auto i : arr)
        lis.insert(i);

    lis.display();
    cout << lis.del(12) << endl;
    cout << lis.del(9) << endl;
    cout << lis.is_present(20) << endl;
    cout << lis.del(3) << endl;
    lis.display();
    cout<<lis.del(20)<<endl;
    cout<<lis.is_present(4)<<endl;
    cout << lis.is_present(20) << endl;
    cout << lis.del(15) << endl;
    lis.display();
    return 0;
}