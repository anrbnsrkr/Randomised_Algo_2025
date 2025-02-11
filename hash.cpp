#include<bits/stdc++.h>
using namespace std;
using namespace chrono;

const int MIN = 0;
const int MAX = 100000000;

struct Node{
    int data;
    Node* next;
};

bool insert_node(Node* &head, int value){
    Node* node = new Node();
    if(node==NULL)
        return false;
    node->data=value;
    if(head==NULL){
        head=node;
        node->next=NULL;
    }
    else{
        node->next=head;
        head=node;
    }
    return true;
}

class Hashtable{
        Node** array; //an array of node pointers/linked lists
        int len;

    public:

        Hashtable(int n){
            array = new Node*[n]();
            len=n;
        }

        bool insert(int value){
            int index = (value % len);
            return insert_node(array[index],value);
        }

        bool search(int value){
            int index = (value % len);
            Node* temp = array[index];
            while (temp!=NULL){
                if (temp->data==value)
                    return true;
                temp=temp->next;
            }
            return false;
        }
};

int main(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(MIN, MAX);
    Hashtable H(100);
    for(int i=0;i<10;i++)
        H.insert(dist(gen));
    auto start = high_resolution_clock::now();
    for(int i=0;i<10000;i++)
        H.search(dist(gen));
    auto stop = high_resolution_clock::now();
    cout << duration_cast<nanoseconds>(stop - start).count() << endl;
    return 0;
}