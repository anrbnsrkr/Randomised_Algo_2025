#include<iostream>
#include<type_traits>
#include<cstdlib>
#include<cstdio>
#include<climits>
#include<vector>
#include "LinkedListH.cpp"
template<typename Type>
class Hash{
private:
    long unsigned int key_gen, pos, total_items;
    LinkedList<Type> **arr;
public:
    //CONSTRUCTOR
    Hash(long unsigned int _key_gen)
    {
        total_items = 0;
        if(_key_gen <10)
            this->key_gen = 1024;
        this->key_gen = _key_gen;
        this->arr = new LinkedList<Type>*[key_gen];
        for(int i = 0; i < key_gen; i++) {
            arr[i] = new LinkedList<Type>;
        }
    }
    Hash()
    {
        total_items = 0;
        this->key_gen = 1024;
        this->arr = new LinkedList<Type>[key_gen];
        for(int i = 0; i < key_gen; i++) {
            arr[i] = new LinkedList<Type>;
        }
    }
    //distructor
    ~Hash()
    {
        for(long unsigned int i = 0; i < key_gen; i++)
            delete arr[i];
        delete arr;
    }

    //end Contructor and Distructor

    // insert
    bool insert(Type x)
    {
        pos = ((long unsigned int) x) % key_gen;
        int success = arr[pos]->find(x);
        if (success != -1)
            return false;
        total_items++;
        return arr[pos]->insert(x);
    }
    bool is_present(Type x)
    {
        pos = ((long unsigned int)x) % key_gen;
        int found = arr[pos]->find(x);
        if(found>=0)
            return true;
        
        return false;
    }
    bool del(Type x)
    {
        pos = ((long unsigned int)x) % key_gen;
        if(arr[pos]->del_data(x)){
            total_items--;
            return true;
        }
        return false;
    }
    void display() {
        cout<<"//table: //"<<endl;
        for(long unsigned i = 0; i < key_gen; i++) {
            cout<<i<<" : ";
            arr[i]->display();
        }
        cout<<endl<<"//end//"<<endl;
    }
    
    // Get the length of all buckets(all lists)
    vector<int> bucket_size() {
        vector<int>bsize(key_gen,0);
        for(int i = 0;i < key_gen;i++) {
            bsize[i]=arr[i]->len();
        }
        return bsize;
    }
    
    //Get number of collitions
    unsigned long long countCollition() {
        vector<int> ListLen = bucket_size();
        unsigned long long collitions = 0;
        for(int i : ListLen) {
            collitions += (i * (i - 1)) / 2;
        }
        return collitions;
    }
};


int main() {
    vector<int> arr = {10, -12, 15, 17, 20, 22, 15, 17, 30,22,11,24};
    Hash<int> lis(11);
    for (auto i : arr)
        lis.insert(i);

    lis.display();
    cout << lis.del(-12) << endl;
    cout << lis.del(9) << endl;
    cout << lis.is_present(20) << endl;
    cout << lis.del(3) << endl;
    lis.display();
    cout<<lis.del(20)<<endl;
    cout<<lis.is_present(4)<<endl;
    cout << lis.is_present(20) << endl;
    cout << lis.del(15) << endl;
    lis.display();
    Hash<int> *lis2 = new Hash<int>(11);
    for (auto i : arr)
        lis2->insert(i);
    delete lis2;
    return 0;
}