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