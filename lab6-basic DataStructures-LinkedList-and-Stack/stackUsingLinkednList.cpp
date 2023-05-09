#include<iostream>
#include <climits>
#include <chrono>
using namespace std;


class Node {
public:
    int data;
    Node* next;
    
    Node(int n)
    {
        this->data = n;
        this->next = NULL;
    }
};
  
class Stack {
    Node* top;
  
public:
    Stack() { top = NULL; }
  
    void push(int data)
    {
  
        Node* temp = new Node(data);
        if (!temp) {
            cout << "Stack Overflow";
            exit(1);
        }  
        temp->data = data;  
        temp->next = top;     
        top = temp;
    }
  
   
    bool isEmpty()
    {
                return top == NULL;
    }
  
    int peek()
    {
        if (!isEmpty())
            return top->data;
        else
            exit(1);
    }
  

    void pop()
    {
        Node* temp;
  
        if (top == NULL) {
            cout << "Stack Underflow" << endl;
        }
        else {
  
            temp = top;
            top = top->next;
            
            free(temp);
        }
    }
  
    void display()
    {
        Node* temp;
  
        if (isEmpty()) {
            cout << "\nStack Underflow";
        }
        else {
            temp = top;
            while (temp != NULL) {
                  cout << temp->data;
  
                temp = temp->next;
                if (temp != NULL)
                    cout << " -> ";
            }
        }
    }
};



  
// Driven Program
int main()
{
        auto start = chrono::high_resolution_clock::now();

    Stack s ;
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

    s.display();
    cout<< endl;


    // cout <<"Elements present in stack : ";
    //     s.display();

    
    for (int i=0; i<5;i++){
        s.pop();
    }
//    cout <<"Elements present in stack : ";
        s.display();
            cout<< endl;


    

    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);

//    cout <<"Elements present in stack : ";
        s.display();
            cout<< endl;


    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "Time taken by linkedList : " << duration.count() << " microseconds" << endl;
    
}