#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node*next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertArrtoDLL(vector<int> &arr){
        Node* head = new Node(arr[0]);
        Node* prev= head;
        for(int i=1; i<arr.size(); i++){
            Node*temp = new Node(arr[i],nullptr,prev);
            prev->next= temp;
            prev = temp;
        }
        return head;
    }
void print(Node* head){
        while(head!=NULL){
            cout<<head->data<<" ";
            head=head->next;
        }
    }

Node* mergeOddThenEven(Node* head){
    if(head==NULL || head->next==NULL) return head;
    Node*odd = head;
    Node*even = head->next;
    Node*evenHead = even;

    while(even && even->next){
       odd->next = even->next;
       odd=odd->next; 

       even->next = odd->next;
       even=even->next;
    }
    odd->next=evenHead;
    return head;
}
int main() {
    
    vector<int> arr = {2, 4, 3, 7, 9, 1, 5};  
    Node* head = convertArrtoDLL(arr);
    head=mergeOddThenEven(head);
    print(head);
    return 0;
}