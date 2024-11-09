
#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    ~DoublyLinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void insertAtFront(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (tail == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void deleteFirst() {
        if (head == nullptr) {
            std::cout << "List is empty, nothing to delete." << std::endl;
            return;
        }
        Node<T>* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    void deleteLast() {
        if (tail == nullptr) {
            std::cout << "List is empty, nothing to delete." << std::endl;
            return;
        }
        Node<T>* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    int size() {
        int s = 0;
        Node<T>* temp = head;
        while (temp != nullptr) {
            s++;
            temp = temp->next;
        }
        return s;
    }

    Node<T>* find(T value) {
        Node<T>* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    void display() {
        Node<T>* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void displayReverse() {
        Node<T>* temp = tail;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->prev;
        }
        std::cout << std::endl;
    }
};


int main() {
    DoublyLinkedList<int> list;

    list.insertAtFront(1);
    list.insertAtFront(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);

    std::cout << "List from front to back: ";
    list.display(); 

    std::cout << "List from back to front: ";
    list.displayReverse(); 

    list.deleteFirst();
    std::cout << "After deleting first element: ";
    list.display(); 

    list.deleteLast();
    std::cout << "After deleting last element: ";
    list.display(); 

    std::cout << "Size of the list: " << list.size() << std::endl; 


    return 0;
}
