#include <iostream>
#include <string>
#include "DoubleLinkedListTemplates.hpp"
#include <memory>

using namespace std;

int main(int argc, const char * argv[]) {
    
    DoubleLinkedListTemplates<string> l;
    
    while(true){
        string input;
        cout << "What do you want to do?\r(add / delete) > ";
        cin >> input;
        
        if(input == "add"){
            
            string newVal;
            cout << "What value do you want to insert?\r<string> > ";
            cin >> newVal;
            cout << "Should I add at head or tail?\r(head / tail) > ";
            cin >> input;
            if(input == "head"){
                l.AddHead(newVal);
            }else if(input == "tail"){
                l.AddTail(newVal);
            }else{
                cout << "I'm afraid I don't know what you mean...";
            }
            
        }
        else if(input == "delete"){
            cout << "Do you want to delete by value or index?\r(value / index) > ";
            cin >> input;
            if(input == "value"){
                string nodeToRem;
                cout << "What value should I remove??\r<string> > ";
                cin >> nodeToRem;
                l.RemoveNode(nodeToRem);
            }else if(input == "index"){
                int posToRem;
                cout << "What index should I remove??\r<int> > ";
                cin >> posToRem;
                l.RemoveAt(posToRem);
            }else{
                cout << "I'm afraid I don't know what you mean...";
            }
        }else{
            cout << "I don't know what you mean.";
        }
        
        cout << "Your new list: ";
     
        shared_ptr<DoubleLinkedNodeTemplates<string>> curr = l.head;
        if(l.head == nullptr){
            cout << "[List empty]";
        }else{
            while(curr != NULL){
                cout << curr->value << ",";
                curr = curr->next;
            }
            while(curr != NULL){
                cout << curr->value << ",";
                curr = curr->prev;
            }
        }
        
        cout << "\r~~~~~~~~~~~~~~~\r";
     
    }
     
}
