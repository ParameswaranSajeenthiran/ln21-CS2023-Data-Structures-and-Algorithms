#include <iostream>
#include <chrono>
using namespace std;
#define SIZE 1000
  
class Stack {
    
  
public:
    int buffer[SIZE];
    int top;
  
    Stack() { 
        top = -1; 
        }
    void push(int x);
    int pop();
    int stackTop();
    bool isEmpty();
    void display();
};
  


  
int Stack::pop()
{
    if (isEmpty()) {
        cout << "Stack Underflow";
        return 0;
    }
    else {
        
        int value = buffer[top];
        top--;
        return value;
    }
}
int Stack::stackTop()
{
    if (top < 0) {
        cout << "Stack is Empty";
        return 0;
    }
    else {
        int x = buffer[top];
        return x;
    }
}
  
bool Stack::isEmpty()
{
    return (top < 0);
}


void Stack::push(int x)
{
    if (top == (SIZE+1)) {
        cout << "Stack Overflow";
    }
    else {
        buffer[++top] = x;
    }
}
void display(Stack s)
{   
    if (s.isEmpty())
        return;    
 
    int value = s.stackTop();
    s.pop();
    display(s);
    s.push(value);
    cout << value << " ";

}


  
void test(Stack s){
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    //print all elements in stack :
    cout<< endl;
    display(s);



    
    for (int i=0; i<5;i++){
        s.pop();
    }
   cout <<endl;
        display(s);

    

    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);

     cout <<endl;

    display(s);
         cout <<endl;


    
}

// Driver program to test above functions
int main()
{
    class Stack s;
    auto start = chrono::high_resolution_clock::now();


    test(s);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "Time taken by Implementing stack by Array: " << duration.count() << " nanoseconds" << endl;
    
    return 0;
}