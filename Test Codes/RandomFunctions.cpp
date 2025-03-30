#include<iostream>
#include<type_traits>
#include<cstdlib>
#include<cstdio>
#include<climits>
#include<vector>
#include<random>
#include<set>
#include "HashH.cpp"
#include "LinkedListH.cpp"

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


int main() {
    vector<long int> arr = random_list_of_size<long int>(50,-1, 0, 100);
    vector<vector<long int>> z = n_random_list<long int>(arr,3,-1);
    int count = 0;
    cout<<"The array is: ";
    for(auto i : arr) {
        cout<<i<<", ";
    }
    cout<<"\n\nThe permutations are: \n\n";
    for(vector<long int> i : z) {
        cout<<"P :  ";
        for(long int j : i) {
                cout << j <<", ";
        }
        cout<<endl<<endl;
    }
    cout<<"Hash table is:\n";
    Hash<long int> hash(11);
    for(auto i : arr) {
        hash.insert(i);
    }
    hash.display();
    cout<<"Bucket Len are: \n";
    vector<int> BucketLen = hash.bucket_size();
    for(auto i : BucketLen)
        cout<<i<<", ";
    cout<<endl<<endl;
    cout<<"\nNumber of collitions: "<<hash.countCollition()<<endl;
    return 0;
}