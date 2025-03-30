#include<iostream>
#include<sstream>
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
#include <fstream>

using namespace std;

int main() {
    vector<unsigned int> numElements;
    HashTable<long long> *hash;
    ostringstream oss;
    oss<<"Set_size,Bucket_Size";
    ofstream ofile("ResultsforOmega_n.csv");
    for(int i = 1; i <= 10; i++) {
        oss<<",Result"<<i;
    }
    string res = oss.str();
    oss.str("");
    oss.clear();
    ofile<<res;
    //10 to 10^4
    for(unsigned long int i = 1, s = 10; i <= 8; i++, s *= 10){
        vector<long long> arr = random_list_of_size<long long>(s,18749,LLONG_MIN,LLONG_MAX);
        //bucket size = s to 16 * s
        for (int multi = 1; multi < 17;multi *= 2){
            unsigned long long num_buckets = multi * s;
            oss<<"\n"<<s<<","<<num_buckets;
            cout<<"\nNumber of collitions"<<"(m = "<<num_buckets<<", s = 10^"<<i<<"): "<<endl;
            // for 10 iteration
            for(int it = 1; it <= 10; it++){
                hash = new HashTable<long long>(num_buckets);
                for(auto i : arr) {
                    hash->insert(i);
                }
                int col = hash->countCollition();
                oss<<","<<col;
                delete hash;
            }
            res = oss.str();
            ofile<<res;
            cout<<res;
            oss.str("");
            oss.clear();
        }
        // // for bucket size = s ^ 2
        // unsigned long long size = s * s;
        // cout<<"\nNumber of collitions"<<"(m = "<<s<<"^2, s = "<<s<<"): "<<endl;
        // // for 10 iteratin
        // for(int it = 1; it < 10; it++){
        //     HashTable<long int> hash(size);
        //     for(auto i : arr) {
        //         hash.insert(i);
        //     }
        //     cout<<hash.countCollition()<<endl;
        // }
    }
    ofile.close();
    cout<<endl;
    return 0;
}