#include<bits/stdc++.h>
#include"2levelHashH.cpp"
#include"RandomFunctionsH.cpp"
using namespace std;
using namespace chrono;
int main() {
    ofstream ofile("Results2levelHash.csv");
    ostringstream oss;
    oss<<"Set_size";
    for(int i = 1; i <= 10; i++) {
        oss<<",Time"<<i<<"(ns),iter"<<i<<",isp"<<i<<",ExtraSpace"<<i;
    }
    for(int i = 1; i <= 10; i++) {
        oss<<",BinarySerchTim"<<i<<"(ns)";;
    }
    string res = oss.str();
    oss.str("");
    oss.clear();
    ofile<<res;
    for(unsigned long int i = 1, s = 10; i <= 7; i++, s *= 10){
        vector<long long> arr = random_list_of_size<long long>(s,-1,LLONG_MIN,LLONG_MAX);
        cout<<"\n////Array Creation Done////\n";
        vector<long long> randArr = fast_permute_list(arr,-1);
        cout<<"////Array Permutation Done////\n";
        oss<<"\n"<<s;
        cout<<"\nResults of"<<"s = 10^"<<i<<": "<<endl;
        // for 10 iteration
        for(int it = 1; it <= 10; it++){
            unsigned long long iter = 0, isp = 0;
            HashTable2Level<long long> *hash = NULL;
            unsigned long long col = s;
            while(col >= s) {
                cout<<"Makeing the HashTable"<<endl;
                iter++;
                if(hash != NULL)
                    delete hash;
                hash = new HashTable2Level<long long>(s);
                for(auto item : arr){
                    hash->insert(item);
                }
                col = hash->countCollition();
            }
            isp += iter * s;
            cout<<"Level1 done\n";
            auto info = hash->cvt();
            cout<<"Level2 done\n";
            iter += info[0];
            isp += info[1];
            auto start = high_resolution_clock::now();
            for(auto item : randArr) {
                auto xyz = hash->is_present(item);
            }
            auto stop = high_resolution_clock::now();
            oss<<","<<duration_cast<nanoseconds>(stop - start).count();
            oss<<","<<iter<<","<<isp<<","<<info[2];
            cout<<it<<endl;
            delete hash;
            hash = NULL;
        }
        for(int it = 1; it <= 10; it++) {
            vector<long long> randArr = fast_permute_list(arr,-1);
            cout<<"////Array Permutation Done////\n";
            auto start = high_resolution_clock::now();
            for(auto item : randArr) {
                auto xyz = upper_bound(arr.begin(),arr.end(),item);
            }
            auto stop = high_resolution_clock::now();
            oss<<","<<duration_cast<nanoseconds>(stop - start).count();
            cout<<"b: "<<it<<endl;
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