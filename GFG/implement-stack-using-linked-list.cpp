/* class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class myStack {

  public:
    Node* head;

    myStack() {
        head = NULL;
    }

    bool isEmpty() {
        return head == NULL;
    }

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
        return;
    }

    void pop() {
        if(head == NULL){
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    int peek() {
        if(head == NULL) return -1;
        return head->data;
    }

    int size() {
        Node* temp = head;
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }
};