#include<iostream>
#include<type_traits>
#include<cstdlib>
#include<cstdio>
#include<climits>
#include<vector>
#include<random>
#include<cmath>
#include "LinkedListH.cpp"
#include "HashH.cpp"
template<typename Type>
class Link_N_Hash{
private:
    LinkedList<Type>*ll;
    HashTable<Type> *hash;
    HashFunction *F;
public:
    Link_N_Hash() {
        ll = new LinkedList<Type>;
        hash = NULL;
    }
    ~ Link_N_Hash() {
        if(ll != NULL)
            delete ll;
        if(hash != NULL)
            delete hash;
    }
    int cvt() {
        long long len = ll->len();
        if(len <= 1) 
            return 0;
        int collission = 1;
        int iter = 0;
        while (collission > 0 && iter < 5){
            LL<Type> *ptr = ll->get_head();
            if(hash != NULL){
                delete hash;
            }
            hash = new HashTable<Type>((unsigned long long)(len * len));
            while(ptr!= NULL){
                hash->insert(ptr->data);
                ptr = ptr->next;
            }
            collission = hash->countCollition();
            iter++;
        }
        delete ll;
        ll = NULL;
        return iter;
    }
    bool insert(Type x) {
        if(ll->find(x) != -1)
            return false;
        ll->insert(x);
        return true;
    }
    int find(Type x) {
        if(ll == NULL)
            return hash->is_present(x)?1:-1;
        else
            return ll->find(x);
        
    }
    long long len() {
        if(ll == NULL)
            return hash->get_m();
        else 
            return ll->len();
    }
    unsigned long long item_count(){
        if(ll == NULL)
            return hash->item_count();
        else 
            return (unsigned long long)ll->len();
    }
    void display() {
        if(ll == NULL)
            return hash->display();
        else
            return ll->display();
    }

};
template<typename Type>
class HashTable2Level{
private:
    unsigned long long  m, pos, total_items,collission;
    HashFunction *F;
    Link_N_Hash<Type> **arr;
public:

    HashTable2Level(unsigned long long size) 
    {
        this->collission = 0;
        this->total_items = 0;
        this->m =max(1, size);
        this->F = new HashFunction();
        this->arr = (Link_N_Hash<Type>**)calloc(sizeof(Link_N_Hash<Type>*),m);
        this->pos = 0;
        // for(int i = 0; i < m; i++) {
        //     arr[i] = new LinkedList<Type>;
        // }
    }
    //distructor
    ~HashTable2Level()
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
            arr[pos] = new Link_N_Hash<Type>;
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

    //Get number of collitions
    unsigned long long countCollition() {
        return collission;
    }
    void display_abp() {
        F->display_abp();
    }
    vector<unsigned long long> cvt() {
        unsigned long long iter = 0,temp;
        unsigned long long IEP = 0;
        unsigned long long espace = 0;
        for(int i = 0; i < m; i++) {
            if(arr[i] != 0){
                temp = arr[i]->cvt();
                iter += temp;
                IEP  += temp * arr[i]->item_count();
                espace += arr[i]->len();
            }
        }
        return {iter, IEP ,espace};
    }
};