#pragma once
#include "LinkedListH.cpp"
#include <climits>
#include <vector>
#include <random>
#include <set>
using namespace std;

// Create a random array with unique seed use -1 to insert random seed[Does not works for floating point values]
template<typename Type> vector<Type>random_list_of_size
(int size, unsigned long int seed, Type LowerLimit, Type UpperLimit)
{
    random_device rd;
    mt19937 mt((seed == UINT64_MAX)? rd() : seed);
    uniform_int_distribution<Type> rand_range(LowerLimit, UpperLimit);
    set<Type> s;
    vector<Type> x;
    Type num;
    int fail = 0;
    while(s.size() < size) {
        num = rand_range(mt);
        if(s.insert(num).second == false) {
            fail++;
        } else {
            fail = 0;
        }
        if(fail > 20)
            return x;
    }
    for(auto i : s) {
        x.push_back(i);
    }
    return x;
}

// Overload
vector<long int>random_list_of_size(int size)
{
    return random_list_of_size<long int>(size,18749,LONG_MIN,LONG_MAX);
}

// Create n permutation of the given vector
template<typename Type> vector<vector<Type>>n_random_list
(vector<Type> &vec, int n, unsigned int seed)
{
    vector<vector<Type>>z;
    if(n <= 0)
        return z;
    z = vector<vector<Type>>(n);
    vector<LinkedList<Type>*>copy_lis;
    random_device rd;
    mt19937 mt(seed == UINT32_MAX? rd() : seed);


    for(int i = 0; i < n;i++){
        copy_lis.push_back(new LinkedList(vec));
    }
    for(int i = 0, pos,j; i < n;i++) {
        j = copy_lis[i]->len();
        Type data;
        while(j > 0){
            pos = (int)((unsigned int)mt() % (unsigned int)j);
            data = copy_lis[i]->del_index(pos);
            z[i].push_back(data);
            j--;
        }
    }
    for(auto add: copy_lis)
        delete add;
    return z;
}