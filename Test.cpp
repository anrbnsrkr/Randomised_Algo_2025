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
#include "RandomFunctionsH.cpp"

using namespace std;

int main() {
    vector<long long> arr = random_list_of_size<long long>(10000,-1,LONG_MIN,LONG_LONG_MAX);
    cout<<"The array is: \n";
    // for(long long i = 0; i < arr.size();i++) {
    //     // if(i % 100000 == 0)
    //         printf("%6lld : %22lld\n",i, arr[i]);
    // }
    // vector<vector<long int>> z = n_permute_list<long int>(arr,1,-1);
    // int count = 0;
    // cout<<"\n\nThe permutations are: \n\n";
    // for(vector<long int> i : z) {
    //     cout<<"P :  ";
    //     for(long int j : i) {
    //             cout << j <<", ";
    //     }
    //     cout<<endl<<endl;
    // }
    cout<<"Hash table is:\n";
    HashTable<long int> hash(100000000);
    for(auto i : arr) {
        hash.insert(i);
    }
    // hash.display();
    // cout<<"Bucket Len are: \n";
    // vector<int> BucketLen = hash.bucket_size();
    // for(auto i : BucketLen)
    //     cout<<i<<", ";
    cout<<endl<<endl;
    cout<<"\nNumber of collitions: "<<hash.countCollition()<<endl;
    hash.display_abp();
    return 0;
}