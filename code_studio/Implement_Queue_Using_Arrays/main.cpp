class Queue {
public:
    int front1;
    int end;
    vector <int> array;
    
    Queue() {
        front1=-1;
        end=-1;
        // Implement the Constructor
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if (end==front1){
            return true;
        }else{
            return false;
        }
        // Implement the isEmpty() function
    }

    void enqueue(int data) {
       array.push_back(data);
       end+=1;
        // Implement the enqueue() function
    }

    int dequeue() {
        if (isEmpty()==false){
        int result = array.front();
        array.erase(array.begin());
        end-=1;
        return result;
        }else{
            return -1;
        }
        // Implement the dequeue() function
    }

    int front() {
        // if not empty 
        if(isEmpty()==false){
            return array.front();
        }else{
            return -1;
        }
        
        
        // Implement the front() function
    }
};



