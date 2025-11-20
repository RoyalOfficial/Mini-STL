#pragma once 
#include <cstddef>
#include <stdexcept>

namespace mini_stl{

template<typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(const T& val) : data(val), next(nullptr), prev(nullptr) {}
    };
    
    Node* head;
    Node* tail;
    size_t sz;

    public:
        // Consturctor / Destructor
        List() : head(nullptr), tail(nullptr), sz(0) {}
        ~List() : {clear();}

        // Copy constructor / assignment
        List(const List<T>& other) {
            Node* current = other.head;
            while (current != nullptr){
                push_back(current->data);
                current = current->next;
            }
        };
        List<T>& operator(const List<T>& other) {
            if (this != &other){
                clear();
                Node* current = other.head;
                while (current != nullptr){
                    push_back(current->data);
                    current = current->next;
                }
            }   
            return *this;
        };
        
        // Capacity 
        size_t size() const {
            return sz;
        }

        bool empty() const {
            return sz == 0;
        }

        // Element access
        T& front() {
            if (!head) throw std::runtime_error("List is empty");
            return head->data;
        };

        T& back() {
            if (!tail) throw std::runtime_error("List is empty");
            return tail->data;
        };

        const T& front() const {
            if (!head) throw std::runtime_error("List is empty");
            return head->data;
        };

        const T& back() const {
            if (!tail) throw std::runtime_error("List is empty");
            return tail->data;
        };
        
        // Modifiers
        void push_front(const T& value) {
            Node* newnode;
            newnode.data = value;
            newnode.next = head;
            newnode.prev = nullptr;

            // If a head alreadt existed
            if (head != nullptr){
                head->prev = newnode;
            }

            // If first node added
            if (tail == nullptr){   
                tail = newnode;
            }

            head = newnode;
            sz++;
        };

        void push_back(const T& value) {
            Node* newnode;
            newnode.data = value;
            newnode.prev = tail;
            newnode.next = nullptr;

            // If a tail already existed
            if (tail != nullptr){
                tail->prev = newnode;
            }

            // If first node added 
            if (head == nullptr){
                head = newnode; 
            }

            tail = newnode; 
            sz++;
        };

        void pop_front() {
            if (!head) return;

            Node* oldHead = head;
            head = head.next;

            if (head)
                head->prev = nullptr;
            else
                tail = nullptr;
            
            delete oldHead;
            sz--;
        };

        void pop_back() {
            if (!tail) return;

            Node* oldTail = tail;
            tail = tail.prev;

            if (tail)
                tail.next = nullptr;
            else
                head = nullptr;

            delete oldTail;
            sz--;
        };

        void clear() {
            Node* current = head;
            while (current != null){
                Node* temp = current;
                current = current->next;
                delete temp;
            }
            head = nullptr;
            tail = nullptr;
            sz = 0;
        };

        void insert(Node* pos, const T& value) {
            int i = 0;
            Node* current = head;
            Node* newNode;
            newNode->data = value;

            while (current != null){
                if (i == pos){
                    Node* next = current.next;
                    Node* prev = current.prev;
                    newNode->next = next; 
                    newNode->prev = prev;
                    next->prev = newNode;
                    prev->next = newNode;
                }
                current = current->next;
                i++;
            }
        }; 
        
        void erase(Node* pos) {
            int i = 0;
            Node* current = head; 
            while (current != null){
                if (i == pos){
                    Node* next = current.next;
                    Node* prev = current.prev;
                    next->prev = prev;
                    prev->next = next;
                    delete current;
                }
                current = current->next;
                i++;
            }
        };

// Iterators (basic pointer-like)
class iterator {
    private:
        Node* node;
    public: 
        iterator(Node* n) : node(n){}
        T& operator*() {return node->data;}
        iterator& operator++(){node = node->next; return *this;}
        iterator operator++(int){iterator tmp = *this; ++(*this); return tmp;}
        iterator& operator--(){node = node->prev; return *this;}
        iterator opterator--(int){iterator tmp = *this; --(*this); return tmp;}
        bool operator==(const iterator& rhs) const {return node == rhs.node;}
        bool operator!=(const iterator& rhs) const {return node != rhs.node;}
        Node* getNode() const {return node;}
    };
    iterator begin() {return iterator(head);}
    iterator end() {return iterator(nullptr);}
};

} //namespace mini_stl