#include <iostream>

using namespace std;

// linked list node declaration
class Node {
	int data;
	Node * next;

    public:
        Node(int val) : data(val), next(nullptr) {}

        void setNext(Node* a){
            next = a;
        }

        Node* getNext(){
            return next;
        }

        int getValue(){
            return data;
        }
};

class List {
    // The pointer to the first node of the list
	Node *head; //default 는 private

	public:
        List(): head(nullptr){}

		// Insert a new node with data at the front of the list
		void insert(int data){
            Node *newNode = new Node(data);
	        // newNode->next = head; next는 private해서 안됨 
	        newNode -> setNext(head);
            head = newNode;
        }
		// Delete the first node at the front of the list
        // delete operator와 이름이 같아서 delete_ 붙임 
		void deleteFirst(){
            if (head == nullptr){
                std::cerr<< "Cannot delete from an empty list." << std::endl;
                return ;
            }

            Node * temp = head;
            head = temp -> getNext();
            // head -> setNext(temp->getNext()->getNext());
            delete head;
        }
		// Returns the value of the first node at the front of the list
		int first(){
            if (head != nullptr) {
                return head->getValue();
            } 
            
            else {
                cerr << "List is empty." << endl;
                return -1; // Just returning a placeholder value here
            }
        }

		// Check if the list is empty
		bool isEmpty(){
            return (head == nullptr);
        }

        Node* getHead(){
            return head;
        }
};


// Complete the following stack class implementation using the linked list class.
class Stack : private List {
	public:
		void push(int val);
		void pop(void);
		int top(void);
		// int isEmpty(void);
        bool isEmpty(void);
        void Print(void);
};

void Stack::push(int val){

	// head는 접근불가 여서 위는 오답
	insert(val);
}
void Stack::pop(void){
	//if (head) {
    //  Node* temp = head;
    //  head = head->next;
    //  delete temp;
    //      }
	// head는 접근불가 여서 위는 오답
	deleteFirst();
}

// Returns the value at the top of the stack
int Stack::top(void){
	return first();
}

// isEmpty는 다른 함수들과 다르게 함수명이 동일하므로 class scope을 정확히 명시해야함. 
bool Stack::isEmpty(void){
	return List::isEmpty(); //List:: 없이 isEmpty(); 만 작성시 2점 감점
}

void Stack::Print(void){
    Node* cur = List::getHead();
    while (cur != nullptr){
        cout << cur -> getValue() << " " ;
        cur = cur -> getNext();
        }
    cout << endl;
}

int main(){

    Stack my_stack ;
    my_stack.push(1);
    my_stack.push(7);
    my_stack.push(12);
    cout << "Here is my current stack: "; // 12 7 1 
    my_stack.Print();


    cout << "Print the top iteratively: " ; 

    while (my_stack.isEmpty() == false){
        cout << my_stack.top() << " "; // 12 7 1 
        my_stack.pop();
    }

    // cout << my_stack.top();
    return 0;

}