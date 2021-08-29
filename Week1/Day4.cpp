class MyCircularQueue {
public:
    
    //initializing a vector and variables to define que
    vector<int> myqueue;
    int front = 0, rear = 0,k;
    
    MyCircularQueue(int k) {
        myqueue = vector<int>(k,-1);
        this->k = k; //assigning the value of passed by function to global variable using this keyword.
    }
    
    bool enQueue(int value) {
        //checking before pushing whether queue is full or not
        if(!isFull())
        {
            myqueue[rear++ % k] = value;
            return true;
        }

        return false;
    }
    
    bool deQueue() {
        //checking before deleting whether queue has values or not
        if(!isEmpty())
        {
            myqueue[front++ % k] = -1;
            return true;
        }

        return false;
    }
    
    int Front() {
        return myqueue[front % k];
    }
    
    int Rear() {
        //reducing -1 as rear points to next element where value is to be entered 
        //but to display last element of queue if use rear-1
        return myqueue[(rear-1) % k];
    }
    
    bool isEmpty() {
        //if rear and front both pointing at one location means queue is empty
        //as we shift rear when we push new value
        return rear - front == 0;
    }
    
    bool isFull() {
        //if last index - front index covers the size of queue, means the queue is full
        return rear - front == k;
    }

};
