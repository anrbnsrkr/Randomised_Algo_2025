
#include<iostream>
#include<type_traits>
#include<cstdlib>
#include<cstdio>
#include<climits>
#include<vector>
#include<random>
#include "LinkedListH.cpp"
#define max(a,b) ((a > b)? a : b)
class HashFunction {
private:
    unsigned long long a, b, p;
public:
    HashFunction(unsigned long long a, unsigned long long b,unsigned long long p) {
        this->a = a % max(1, p);
        this->b = b % max(1, p);
        this->p = p;
        // cout<<this->a<<", "<<this->b<<", "<<this->p<<endl;
    }
    unsigned long long fn(unsigned long long val){
        return (p == 0)? val : ((a * val) % p + b) % p;
    }
};

template<typename Type>
class HashTable{
private:
    unsigned long long  m, pos, total_items;
    HashFunction *F;
    LinkedList<Type> **arr;
public:
    //CONSTRUCTOR
    HashTable(unsigned long long size, unsigned long long a, unsigned long long b, unsigned long long p)
    {
        total_items = 0;
        if(size <10)
            this->m = 1024;
        else 
            this->m = size;
        p = (p > size && a > 0)? p : 0;
        F = new HashFunction(a,b,p);
        this->arr = new LinkedList<Type>*[size];
        for(int i = 0; i < m; i++) {
            arr[i] = new LinkedList<Type>;
        }
    }
    HashTable()
    {
        F = new HashFunction(0,0,0);
        total_items = 0;
        this->m = 1024;
        this->arr = new LinkedList<Type>[m];
        for(int i = 0; i < m; i++) {
            arr[i] = new LinkedList<Type>;
        }
    }

    /// @brief 
    /// @param size 
    HashTable(unsigned long long size) 
    {
        total_items = 0;
        if(size <10)
            this->m = 1024;
        else 
            this->m = size;
        this->F = new HashFunction(0,0,0);
        this->arr = new LinkedList<Type>*[size];
        for(int i = 0; i < m; i++) {
            arr[i] = new LinkedList<Type>;
        }
    }
    //distructor
    ~HashTable()
    {
        for(long unsigned int i = 0; i < m; i++)
            delete arr[i];
        delete F;
        delete arr;
    }

    //end Contructor and Distructor

    // insert
    bool insert(Type x)
    {
        pos = F->fn((unsigned long long) x) % m;
        int success = arr[pos]->find(x);
        if (success != -1)
            return false;
        total_items++;
        return arr[pos]->insert(x);
    }
    bool is_present(Type x)
    {
        pos = F->fn((unsigned long long)x) % m;
        int found = arr[pos]->find(x);
        if(found>=0)
            return true;
        
        return false;
    }
    bool del(Type x)
    {
        pos = F->fn((unsigned long long)x) % m;
        if(arr[pos]->del_data(x)){
            total_items--;
            return true;
        }
        return false;
    }
    void display() {
        cout<<"//table: //"<<endl;
        for(long unsigned i = 0; i < m; i++) {
            cout<<i<<" : ";
            arr[i]->display();
        }
        cout<<endl<<"//end//"<<endl;
    }
    
    // Get the length of all buckets(all lists)
    vector<int> bucket_size() {
        vector<int>bsize(m,0);
        for(int i = 0;i < m;i++) {
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
    vector<int> arr = {11, -12, 15, 17, 20, 22, 15, 17, 30,22,11,24};
    HashTable<int> lis(13, 12, 7, 41);
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
    HashTable<int> *lis2 = new HashTable<int>(11);
    for (auto i : arr)
        lis2->insert(i);
    delete lis2;
    return 0;
}
