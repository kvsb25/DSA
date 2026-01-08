class Node {
  public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

class myQueue {

  public:
  
    Node* front, * rear;
    
    myQueue() {
        front = rear = NULL;
    }

    bool isEmpty() {
        return (front == NULL && rear == NULL);
    }

    void enqueue(int x) {
        Node* newNode = new Node(x);
        if(front == NULL && rear == NULL){
            front = newNode;
            rear = newNode;
        }else{
            rear->next = newNode;
            rear = rear->next;
        }
        return;
    }

    void dequeue() {
        Node* temp = front;
        if(front == NULL && rear == NULL){
            return;
        } else if(front->next == NULL){
            front = rear = NULL;
        } else {
            front = front->next;
            temp->next = NULL;
        }
        delete temp;
        return;
    }

    int getFront() {
        if(front == NULL) return -1;
        return front->data;
    }

    int size() {
        Node* temp = front;
        int count = 0;
        while(temp != NULL){
            temp = temp->next;
            count++;
        }
        return count;
    }
};
