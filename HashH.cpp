#pragma onse
#include<iostream>
#include<type_traits>
#include<cstdlib>
#include<cstdio>
#include<climits>
#include<vector>
#include<random>
#include<cmath>
#include "LinkedListH.cpp"
#define max(a,b) ((a > b)? a : b)
#define LOWER_RANGE 100000000000
#define UPPER_RANGE 100000000000000
#define SEED -1
bool is_prime(unsigned long long x) {
    unsigned long long i = 3, j =(unsigned long long)pow((long double)x, 0.5) + 10;
    if(x == 2) return true;
    if(x % 2 == 0) return false;
    while(i < j) {
        if(x % i == 0) return false;
        else i+=2;
    }
    return true;
} 
class HashFunction {
private:
    unsigned long long a, b, p;
    random_device rd;
    mt19937_64 mt;
    uniform_int_distribution<unsigned long long> rand_num_in_range;
public:
    HashFunction(unsigned long long a, unsigned long long b,unsigned long long p,unsigned long long LL, unsigned long long UL) : 
    rand_num_in_range(LL, UL), mt(SEED == -1? rd() : SEED){
        this->a = a % max(1, p);
        this->b = b % max(1, p);
        this->p = p;
        // cout<<this->a<<", "<<this->b<<", "<<this->p<<endl;
    }
    HashFunction(unsigned long long a, unsigned long long b,unsigned long long p) : 
    rand_num_in_range(LOWER_RANGE, UPPER_RANGE), mt(SEED == -1? rd() : SEED){
        this->a = a % max(1, p);
        this->b = b % max(1, p);
        this->p = p;
        // cout<<this->a<<", "<<this->b<<", "<<this->p<<endl;
    }
    HashFunction(unsigned long long LL, unsigned long long UL) : 
    mt(SEED == -1? rd() : SEED), rand_num_in_range(LL, UL){
        unsigned int i = (unsigned int)(mt() % 1024),r;
        while(i > 0) {
            r = mt();
            i--;
        }
        i = 100;
        this->p = rand_num_in_range(mt);
        while((!is_prime(p)) && i > 0){
            p = rand_num_in_range(mt);
            i--;
        }
        while (!is_prime(p)) {
            p++;
        }
        this->a = rand_num_in_range(mt);
        this->b = rand_num_in_range(mt);
        this->a = (this->a) % p;
        this->b = (this->b )% p;
        // cout<<this->a<<", "<<this->b<<", "<<this->p<<endl;
    }
    HashFunction() : 
    mt(SEED == -1? rd() : SEED), rand_num_in_range(LOWER_RANGE, UPPER_RANGE){
        unsigned int i = (unsigned int)(mt() % 128),r;
        while(i > 0) {
            r = mt();
            i--;
        }
        i = 100;
        this->p = rand_num_in_range(mt);
        while((!is_prime(p)) && i > 0){
            this->p = rand_num_in_range(mt);
            i--;
        }
        while (i == 0 && (!is_prime(p))) {
            this->p++;
        }
        this->a = rand_num_in_range(mt);
        this->b = rand_num_in_range(mt);
        this->a = (this->a) % p;
        this->b = (this->b) % p;
        // cout<<this->a<<", "<<this->b<<", "<<this->p<<endl;
    }


    unsigned long long fn(unsigned long long val){
        return (p == 0)? val : ((a * val) % p + b) % p;
    }
    void display_abp() {
        cout<<"a = "<<a<<", b = "<<b<<", p = "<<p<<endl;
    }
};

template<typename Type>
class HashTable{
private:
    unsigned long long  m, pos, total_items,collission;
    HashFunction *F;
    LinkedList<Type> **arr;
public:
    //CONSTRUCTOR
    HashTable(unsigned long long size, unsigned long long a, unsigned long long b, unsigned long long p)
    {
        this->collission = 0;
        this->total_items = 0;
        if(size <10)
            this->m = 1024;
        else 
            this->m = size;
        p = (p > m && a > 0)? p : 0;
        F = new HashFunction(a,b,p);
        this->arr = calloc(m,sizeof(LinkedList<Type>*));
        // for(int i = 0; i < m; i++) {
        //     arr[i] = new LinkedList<Type>;
        // }
    }
    HashTable()
    {
        this->collission = 0;
        this->F = new HashFunction(0,0,0);
        total_items = 0;
        this->m = 1024;
        this->arr = calloc(m,sizeof(LinkedList<Type>*));
        // for(int i = 0; i < m; i++) {
        //     arr[i] = new LinkedList<Type>;
        // }
    }

    HashTable(unsigned long long size) 
    {
        this->collission = 0;
        this->total_items = 0;
        size = max(1,size);
        this->m = size;
        this->F = new HashFunction((long long)size*10,(long long)size*1000);
        this->arr = (LinkedList<Type>**)calloc(sizeof(LinkedList<Type>*),m);
        // for(int i = 0; i < m; i++) {
        //     arr[i] = new LinkedList<Type>;
        // }
    }
    //distructor
    ~HashTable()
    {
        for(unsigned long long i = 0; i < m; i++){
            if(arr[i] != 0){
                delete arr[i];
            }
        }
        delete F;
        free(arr);
    }

    //end Contructor and Distructor

    // insert
    bool insert(Type x)
    {
        pos = F->fn((unsigned long long) x) % m;
        if(arr[pos] == 0)
            arr[pos] = new LinkedList<Type>;
        int success = arr[pos]->find(x);
        if (success != -1)
            return false;
        total_items++;
        collission += arr[pos]->len();
        return arr[pos]->insert(x);
    }
    bool is_present(Type x)
    {
        pos = F->fn((unsigned long long)x) % m;
        if(arr[pos] == 0)
            return false;
        int found = arr[pos]->find(x);
        if(found>=0)
            return true;
        
        return false;
    }
    bool del(Type x)
    {
        pos = F->fn((unsigned long long)x) % m;
        if(arr[pos] != 0 && arr[pos]->del_data(x)){
            collission -= arr[pos]->len();
            total_items--;
            return true;
        }
        return false;
    }
    void display() {
        cout<<"//table: //"<<endl;
        for(unsigned long long i = 0; i < m; i++) {
            cout<<i<<" : ";
            if(arr[i]!= 0){
                arr[i]->display();
            }
            else {
                cout<<"NULL"<<endl;
            }
        }
        cout<<endl<<"//end//"<<endl;
    }

    // Get the length of all buckets(all lists)
    vector<int> bucket_size() {
        vector<int>bsize(m,0);
        for(int i = 0;i < m;i++) {
            if(arr[i] != 0)
            bsize[i]=arr[i]->len();
        }
        return bsize;
    }
    unsigned long long item_count(){
        return total_items;
    }
    //Get number of collitions
    unsigned long long countCollition() {
        return collission;
    }
    int get_m(){
        return m;
    }
    void display_abp() {
        F->display_abp();
    }
};
#undef LOWER_RANGE
#undef UPPER_RANGE
#undef SEED
