#include <iostream>
using namespace std;

class Node {
public:
    char* data;
    Node* next;

    Node(const char* str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
        next = nullptr;
    }

    ~Node() {
        delete[] data;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void append(const char* str) {
        Node* newNode = new Node(str);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void print() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << endl;
            current = current->next;
        }
    }
};

class Mystring {

    char* str;

    int __find_substr(const char* substr) const;
    void __set_str(const char* val);
    Mystring& __assignment(const char* s);

public:
    Mystring(const char* s = nullptr);
    Mystring(const Mystring& s);
    ~Mystring();

    void splitAndAddToLinkedList(const char* delimiter, LinkedList& list);

    friend istream& operator>>(istream& in, Mystring& obj);
    friend ostream& operator<<(ostream& os, const Mystring& obj);

    static int get_length(const char* str);

    static void strcpy(char* dest, const char* src);
    static void strcpy(char* dest, const char src);
    static char* strstr(char* origin, const char* substr);
    static char* strstr(Mystring origin, const Mystring substr);

    int find(const Mystring& substr) const;
    int find(const char* substr);
    int find(const char substr);

    Mystring& operator=(const Mystring& other);
    Mystring& operator=(const char* other);
    Mystring& operator=(char other);
    bool operator==(const Mystring& other) const;
    Mystring operator+(const Mystring& second) const;
    Mystring operator+(const char* second) const;
    Mystring operator+(char second) const;
    operator const char*() {return str;}
};
