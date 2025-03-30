
#include<iostream>
#include<type_traits>
#include<cstdlib>
#include<cstdio>
#include<climits>
#include<vector>
#include<random>
#include<bits/stdc++.h>
#include "LinkedListH.cpp"
#include "HashH.cpp"
#include"RandomFunctionsH.cpp"
#define max(a,b) ((a > b)? a : b)
#define LOWER_RANGE 10000000000000000
#define UPPER_RANGE 1000000000000000000
#define SEED -1
template<typename Type>
class HashCollisionCounter{
private:
    HashFunction *F;
    vector<pair<Type,unsigned long long>> arr;
    unsigned long long m, LL, UL;
    static bool compare(const pair<Type,unsigned long long>& a, const pair<Type,unsigned long long>& b) {
        return a.second < b.second;
    }
public:
    //CONSTRUCTOR
    HashCollisionCounter(vector<Type>&vec, unsigned long long size)
    : arr(vec.size(), {0,0}) {
        m = size;
        F = NULL;
        LL = max(1, size) * 10;
        UL = max(1, size) * 1000;
        for(unsigned long long i = 0; i < vec.size();i++) {
            arr[i].first = vec[i];
        }
    }
    unsigned long long Simulate_Collision() {
        if(F != NULL)
            delete F;
        F = new HashFunction(LL,UL);
        for(long long i = 0; i < arr.size();i++)
            arr[i].second = (F->fn(arr[i].first)) % m;
        sort(arr.begin(),arr.end(),this->compare);
        return this->count_collision();
    }
    unsigned long long count_collision() {
        unsigned long long collissions = 0, same = 0;
        for(long long i = 1; i < arr.size();i++) {
            if(arr[i-1].second == arr[i].second){
                same++;
                collissions += same;
            }
            else {
                same = 0;
            }
        }
        return collissions;
    }
    void display() {
        for(auto x: arr)
            cout<<x.first<<"->"<<x.second<<",  ";
        cout<<endl;
    }
};
#undef LOWER_RANGE
#undef UPPER_RANGE
#undef SEED

int main() {
    vector<long long> arr = random_list_of_size<long long>(10,18749,LLONG_MIN,LLONG_MAX);
    ostringstream oss;
    oss<<"Set_size,Bucket_Size";
    ofstream ofile("ResultsforOmega_n^2.csv");
    for(int i = 1; i <= 10; i++) {
        oss<<",Result"<<i;
    }
    string res = oss.str();
    oss.str("");
    oss.clear();
    ofile<<res;
    for(unsigned long int i = 1, s = 10; i <= 8; i++, s *= 10){
        vector<long long> arr = random_list_of_size<long long>(s,18749,LLONG_MIN,LLONG_MAX);
        unsigned long long num_buckets = s * s;
        oss<<"\n"<<s<<","<<num_buckets;
        cout<<"\nNumber of collitions"<<"(m = "<<num_buckets<<", s = 10^"<<i<<"): "<<endl;
        HashCollisionCounter<long long> simulator(arr,num_buckets);
        // for 10 iteration
        for(int it = 1; it <= 10; it++){
            unsigned long long col = simulator.Simulate_Collision();
            // simulator.display();
            // cout<<endl;
            oss<<","<<col;
        }
        res = oss.str();
        ofile<<res;
        cout<<res;
        oss.str("");
        oss.clear();
    }  
    cout<<endl;
    return 0;
}
