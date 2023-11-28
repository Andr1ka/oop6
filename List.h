#pragma once

#include <iostream>

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& value) {
            data = value;
            next = nullptr;
        }
        
    };

    Node* head;

    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
public:
    List() {
        head = nullptr;
    }

    
    void insert(const T& value) {
       
            if (head == nullptr) {
                Node* newNode = new Node(value);
                newNode->next = head;
                head = newNode;
            }
            else {
                Node* newNode = new Node(value);
                Node* temp = head;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
    }


    void merge(const List& other) {
        Node* temp = other.head;
        Node* mainListtemp = head;
        while (mainListtemp->next != nullptr) {
            mainListtemp = mainListtemp->next;
        }
        while (temp != nullptr) {
            mainListtemp->next = new Node(temp->data);
            mainListtemp = mainListtemp->next;
            temp = temp->next;
        }
    }

    
    void mergeSorted(const List& other) {

        this->merge(other);

        Node* temp = other.head;
        Node* mainListtemp = head;
        temp = head;
        if (head->next != nullptr) {
            mainListtemp = head->next;
            while (temp->next != nullptr) {
                while (mainListtemp != nullptr)
                {
                    if (mainListtemp->data < temp->data) {
                        T date = mainListtemp->data;
                        mainListtemp->data = temp->data;
                        temp->data = date;
                    }
                    mainListtemp = mainListtemp->next;
                }
                temp = temp->next;
                mainListtemp = temp;
            }
        }
    }

    
    friend std::ostream& operator<<(std::ostream& out, const List<T>& list) {
        Node* temp = list.head;
        while (temp != nullptr) {
            out << temp->data << " ";
            temp = temp->next;
        }
        return out;
    }
  
    friend std::istream& operator>>(std::istream& in, List<T>& list) {
        T value;
        while (in >> value) {
            list.insert(value);
        }
        return in;
    }

    
    class Iterator {
    public:
        Node* current;

        Iterator(Node* node) : current(node) {}

        T& operator*() const {
            if(current != nullptr)
            return current->data;
        }

        Iterator& operator++() {
            current = current->next;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };

    Iterator begin() const {
        return Iterator(head);
    }

    Iterator end() const {
        return Iterator(nullptr);
    }

    void insert(const T& value, Iterator iter) {
        if (iter.current == nullptr) {
            Node* newNode = new Node(value);
            newNode->next = head;
            head = newNode;
        }
        else {
            Node* newNode = new Node(value);
            newNode->next = iter.current->next;
            iter.current->next = newNode;
        }
    }

    void erase(Iterator iter) {
        if (head == nullptr || iter.current == nullptr) {
            return;
        }

        if (iter.current == head) {
            head = head->next;
            delete iter.current;
        }
        else {
            Node* temp = head;
            while (temp->next != iter.current) {
                temp = temp->next;
            }

            temp->next = iter.current->next;
            delete iter.current;
        }
    }


    ~List() {
        clear();
    }


};