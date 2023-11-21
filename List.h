#pragma once
template<typename T>
#include <iostream>
class Node
{
	T data;
	Node* next;
	Node* prev;

	Node(T* dat) {
		this->data =  *dat ;
		this->next = nullptr;
		this->prev = nullptr;
	}
	Node() {
		this->next = nullptr;
		this->prev = nullptr;
	}
	~Node{
		delete next;
	    delete prev;
	}
};


template<typename T>
struct Iterator {
	Node<T>* node;

	Iterator(Node<T>* nod) {
		node = nod;
	}
    Iterator begin() {
        return head;
    }
     Iterator end() {
        return tail;
    }
    Iterator& operator++() {
        node = node->next;
        return *this;
    }

    bool operator!=(const Iterator& other) const {
        return node != other.node;
    }
    T& operator*() const {
        return node->data;
    }

    void erase(Iterator position) {
        if (head == nullptr || position.node == nullptr) {
            return;
        }

        if (position.node == head) {
            head = head->next;
            delete position.node;
        }
        else {
            Node* temp = head;
            while (temp->next != position.node) {
                temp = temp->next;
            }

            temp->next = position.node->next;
            delete position.node;
        }
    }

    void insert(const T& value, Iterator position) {
        if (position.node == nullptr) {
            Node* newNode = new Node(value);
            newNode->next = head;
            head = newNode;
        }
        else {
            Node* newNode = new Node(value);
            newNode->next = position.node->next;
            position.node->next = newNode;
        }
    }

	~Iterator() {
		delete node;
	}
};










template<typename T>
class List {
protected:
	size_t length;
	Node<T>* head;
	Node<T>* tail;

public:

    friend std::ostream& operator<<(std::ostream& os, const List<T>& list) {
        Node* temp = list.head;
        while (temp != nullptr) {
            os << temp->data << " ";
            temp = temp->next;
        }
        return os;
    }

    // Перегрузка оператора ввода
    friend std::istream& operator>>(std::istream& is, List<T>& list) {
        T value;
        while (is >> value) {
            list.insert(value, nullptr);
        }
        return is;
    }
};