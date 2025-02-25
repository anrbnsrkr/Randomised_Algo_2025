#include<iostream>
#include<type_traits>
#include<cstdlib>
#include<cstdio>
#include<climits>
#include<vector>
#include<random>
#include<set>
#include<iterator>
using namespace std;
int main() {
    set<int> s;
    pair<set<int>::iterator,bool> i1,i2;
     i1 = s.insert(10);
     i2 = s.insert(10);
    cout << *i1.first << ", " <<i1.second <<endl;
    cout << *i2.first << ", " <<i2.second <<endl;
    random_device rd;
    mt19937_64 mt(rd());
    auto i = mt();
    cout<<i<<endl;
    cout<<sizeof(i)<<endl;
    return 0;
}