// Linked_List_Find_Loop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Node {//used for creating new nodes
public:
    int val; 
    Node* next;

    Node() {
        val = 0;
        next = NULL;
    }
};

bool Find_Loop(Node *list){
    Node* slow = list;//goes through the list slowly to find the duplicate connections
    Node* fast = list;

    //if slow == fast then there is a loop in the List
    do {
        if (fast == NULL || fast->next == NULL) {
            return false;
        }

        fast = fast->next->next;//fast goes at twice the speed of slow
        slow = slow->next;

    } while (slow != fast);
    
    return true;
}

int main()
{
    std::cout << "Karl Nueckel Linked List Find Loop Program\n";

    Node* head = new Node;//creating a list from the class Node
    head->val = 2;

    head->next = new Node;//adding another node
    head->next->val = 4;

    head->next->next = new Node;//adding another node
    head->next->next->val = 8;

    Node* loop = head->next->next; //loop node

    std::string input;

    std::cout << "Should the List have a loop? (Enter yes/no)" << std::endl;
    std::cin >> input;

    if (input == "Yes" || input == "yes") {
        loop->next = head; //connecting the loop   
    }

    if (Find_Loop(head) == true) {
        std::cout << "There is a loop in the List\n";
    }
    else {
        std::cout << "There is no loop in the List\n";
    }
   
    system("pause");
    return 0;
}