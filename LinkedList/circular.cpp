#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convert2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void print(Node* head){
    while(head!=NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

// bool isLoopPresent(Node* head){
//     unordered_map <Node*, int> mpp;
//      Node* temp = head;
//     while(temp!=NULL){
//         if(mpp.find(temp)!= mpp.end()){
//             return true;    
//         }
//         mpp[temp]=1;
//         temp = temp->next;
//     } 
//     return false ;
// }


bool detectLoop(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL & fast->next !=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}


int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = convert2LL(arr);

    // Creating a loop for testing: point last node's next to 2nd node
    Node* temp = head;
    Node* second = head->next;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = second;  // Creates loop

    if(detectLoop(head)){
        cout << "Loop is present in the linked list." << endl;
    } else {
        cout << "No loop detected." << endl;
        print(head); // Safe to print only if no loop
    }

    return 0;
}