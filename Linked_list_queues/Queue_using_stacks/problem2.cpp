#include<iostream>
#include <stack>
#include<climits>
using namespace std;

class Queue{
private:
    stack<int> stack1, stack2;
public:
    Queue();
    void EnQueue(int data){
        stack1.push(data);   
    }

    int DeQueue(){
        if(stack1.empty()){
            cout<<"Stack is empty."<<endl;
            return false;
        }
        /*Transfer elements from one stack to another so the first in
            comes on top of the second stack*/
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop(); 
        }

        int j = stack2.top();
        stack2.pop();
        
        /*Place the elements back in stack1 from stack2*/
        while(!stack2.empty()){
            stack1.push(stack2.top());
            stack2.pop(); 
        }
        return j;
    }

};
//constructor for the class Queue
Queue::Queue(){
    // to empty one of the stacks
    while(!stack1.empty()){
        stack2.push(stack1.top());
        stack1.pop();
    }
}

int main(){
    Queue q;
    for(int i=0; i<10; i++){
        q.EnQueue(i);
    }
    cout<<q.DeQueue()<<endl;
    cout<<q.DeQueue()<<endl;
    for(int i=10; i<20; i++){
        q.EnQueue(i);
    }
    cout<<q.DeQueue()<<" ";
    cout<<q.DeQueue()<<endl;
    return 0;
}