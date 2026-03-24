#include <string>
#include <iostream>

using namespace std;

struct Node{
	string String;
	Node* next;
};

void displayList(Node* myNode) {
	if (myNode == NULL) {
		cout << "Your List is empty" << endl;
		return;
	}
	while (myNode != NULL) {
		cout << "[" << myNode->String << "] --> ";
		myNode = myNode->next;
	}
    cout << "NULL";
	cout << endl;
    
}

void undo(Node*& myNode) {
    if (myNode == NULL) {
        cout << "Your List has no word to remove" << endl;
        return;
    }

    if (myNode->next == NULL) {
        delete myNode;  
        myNode = NULL;   
    }
    else {
        Node* temp = myNode;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL; 
    }
}
void addNewWord(Node*& myNode, string MyString) {
    Node* newNode = new Node;
    newNode->String = MyString;
    newNode->next = NULL;

    if (myNode == NULL) {
        myNode = newNode;
    }
    else {
        Node* temp = myNode;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int main() {
    Node* myNode = NULL;

    string MyString;
    while (MyString != "exit") {
        cout << "Enter a Word (display/undo/exit): ";
        cin >> MyString;

        if (MyString == "display") {
            displayList(myNode);
        }
        else if (MyString == "undo") {
            undo(myNode);
        }
        else if (MyString != "exit") {
            addNewWord(myNode, MyString);
        }
    }
    return 0;
}