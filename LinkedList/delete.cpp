#include<iostream>
#include<string>
#include<vector>
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
// Node* removeHead(Node* head){
//     if(head==NULL) return head;
//     Node* temp = head;
//     head = head->next;
//     delete temp;
//     return head;
// }

// Node* removeTail(Node* head){
//     if(head==NULL || head->next == NULL) return NULL;
//     Node* temp = head;
//     while(temp->next->next!=NULL){
//           temp = temp->next;
//     }
//     delete temp->next;
//     temp->next = nullptr;

//     return head;
// }

// Node* deleteKthEelement(Node* head, int k){
//     if(head == NULL) return head;
//     if(head->data==k){
//         Node* temp = head;
//         head = head->next;
//         delete(temp);
//         return head;
//     }
//     //int cnt=0; 
//     Node* prev = NULL; Node* temp = head;
//     while(temp!=NULL){
//         //cnt++;
//     if(temp->data == k){
//         prev->next = prev->next->next;
//         delete(temp);
//         break ;
//     }
//     prev = temp;
//     temp = temp->next;
//     }
//     return head;
// }

// Node* addNode(Node* head,int val){
//     Node* temp= new Node(val, head);
//     return temp; // instead write return new Node(val,head);
// }

Node* createTail(Node* head, int val){
    if(head == NULL){
        return new Node(val);
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    Node* newNode = new Node(val); 
    temp->next = newNode;
    return head;
}

Node* insertPositon(Node* head, int el, int k){
    if(head==NULL){
        if(k==1){
            return new Node(el);
        } else return head;
    }
    if(k==1){
        return new Node(el,head);
    }
    Node* temp = head;
    int cnt =0; 
    while(temp!=NULL){
    cnt++;
    if(cnt==(k-1)){
        Node* x = new Node(el,temp->next);
        temp->next = x;
        break;
    }
    temp = temp->next;
    }
    return head;
}


int main(){
    vector<int> arr= {12, 5, 8 ,7};
    Node* head = convert2LL(arr);
    head = insertPositon(head,9,3);
    print(head);
}