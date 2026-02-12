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

    // Node* deleteHead(Node* head){
    //    if(head==NULL || head->next == NULL){
    //     return NULL;
    //    } 
    //    Node* prev = head;
    //    head=head->next;
    //    head->back = nullptr;
    //    prev->next = nullptr;
    //    delete(prev);
    //    return head;
    // }

    // Node* deleteTail(Node* head){
    //     if(head==NULL || head->next == NULL){
    //     return NULL;
    //    } 
    //    Node* tail = head;
    //    while(tail->next!=NULL){
    //     tail=tail->next;
    //    }
    //    Node* prev = tail->back;
    //    tail->back = nullptr;
    //    prev->next = nullptr;
    //    delete(tail);
    //    return head;
    // }

    // Node* deleteKthElement(Node* head,int k){
    //     if (head == nullptr || k <= 0) return head;
    //     if(k==1){
    //         Node* temp = head;
    //         head=head->next;
    //         head->back = nullptr;
    //         temp->next = nullptr;
    //         delete(temp);
    //         return head;
    //     }
    //     Node* temp = head;
    //     int cnt=1;
    //     while(temp!=NULL && cnt<k){
    //     temp = temp->next;
    //     cnt++;
    //     }
    //     if (temp == nullptr) return head;
    //     if (temp->back) temp->back->next = temp->next;
    //     if (temp->next) temp->next->back = temp->back;
    //     delete temp;
    //     return head;
    // }


    // Node* newHeadBeforeHead(Node* head, int val){
    //     Node* newHead = new Node(val,head,nullptr);
    //     head->back = newHead;
    //     return newHead;
    // }

    Node* newTailBeforeTail(Node* head, int val){
        Node* temp =head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        Node* prev = temp->back;

        Node* newTail= new Node(val,temp,prev);
        prev->next = newTail;
        temp->back = newTail;
        return head;

    }

int main(){
    vector<int> arr= {12, 5, 8, 7};
    Node* head = convertArrtoDLL(arr);
    head =newTailBeforeTail(head,5);
    print(head);
    return 0;
}

