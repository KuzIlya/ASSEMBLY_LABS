#include <iostream>
#include "mystring.h"

istream& operator>>(istream& in, Mystring& obj) {
    const int bufferSize = 1024;
    char* text = new char[bufferSize];
    in.getline(text, bufferSize);
    obj.__set_str(text);
    delete[] text;
    return in;
}

ostream& operator<<(ostream& os, const Mystring& obj) {
    os << obj.str;
    return os;
}

void Mystring::splitAndAddToLinkedList(const char* delimiter, LinkedList& list) {
        char* token = strtok(str, delimiter);
        while (token != nullptr) {
            list.append(token);
            token = strtok(nullptr, delimiter);
        }
}

int main() {
    Mystring input = "hello, wered";
    Mystring delimiter = "e";
    LinkedList list;

    input.splitAndAddToLinkedList(delimiter, list);
    list.print();

    return 0;
}

int Mystring::__find_substr(const char* substr) const {
        char* ptr = strstr(str, substr);
        if (ptr == nullptr)
            return -1;
        return ptr - str;
}

Mystring& Mystring::__assignment(const char* s) {
    if (this->str != s) {
        delete[] str;
        str = new char[get_length(s) + 1];
        strcpy(str, s);       
    }
    return *this;
}

int Mystring::get_length(const char* str) {
        if (str == nullptr) {
            return 0;
        }
        
        int length = 0;
        while (str[length] != '\0') {
            length++;
        }
        return length;
    }

Mystring::Mystring(const char* s) {
    if (s == nullptr) {
        str = new char[1];
        str[0] = '\0';
    } 
    else {
        str = new char[get_length(s) + 1];
        strcpy(str, s);
    }
}

Mystring::Mystring(const Mystring& s) {
    str = new char[get_length(s.str) + 1];
    strcpy(str, s.str);
}

Mystring::~Mystring() { delete[] str; }

int Mystring::find(const Mystring& substr) const {
    return __find_substr(substr.str);
}

int Mystring::find(const char* substr) {
    return __find_substr(substr);
}

int Mystring::find(char substr) {
    char s[2] = {substr, '\0'};
    return __find_substr(s);
}

bool Mystring::operator==(const Mystring& other) const {
    return strcmp(str, other.str) == 0;
}

Mystring Mystring::operator+(const Mystring& second) const {
    int len1 = get_length(str);
    int len2 = get_length(second.str);
    char* result = new char[len1 + len2 + 1];
    strcpy(result, str);
    for (int i = 0; i < len2; ++i) {
        result[len1 + i] = second.str[i];
    }
    result[len1 + len2] = '\0';
    Mystring res {result};
    delete[] result;
    return res;
}

Mystring Mystring::operator+(const char* second) const {
    if (second == nullptr)
        return *this;
    
    int len1 = get_length(str);
    int len2 = get_length(second);
    char* result = new char[len1 + len2 + 1];
    strcpy(result, str);
    for (int i = 0; i < len2; ++i) {
        result[len1 + i] = second[i];
    }
    result[len1 + len2] = '\0';
    Mystring res {result};
    delete[] result;
    return res;
}

Mystring Mystring::operator+(char second) const {
    int len = get_length(str) + 2;
    char* result = new char[len];
    strcpy(result, str);
    result[get_length(str)] = second;
    result[get_length(str) + 1] = '\0';
    Mystring res {result};
    delete[] result;
    return res;
}

Mystring& Mystring::operator=(const Mystring& other) {
    return __assignment(other.str);
}

Mystring& Mystring::operator=(const char* other) {
    return __assignment(other);
}

Mystring& Mystring::operator=(char other) {
    char temp[2] = {other, '\0'};
    return __assignment(temp);
}

void Mystring::strcpy(char* dest, const char* src) {
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
}

void Mystring::strcpy(char* dest, const char src) {
    *dest++ = src;
    *dest = '\0';
}

void Mystring::__set_str(const char* val) {
    delete[] str;

    if (val == nullptr) {
        str = new char[1];
        str[0] = '\0';
    }

    else {
        str = new char[get_length(val) + 1];
        strcpy(str, val);
    }
}

char* Mystring::strstr(char* origin, const char* substr) {
    if (substr == nullptr || *substr == '\0')
        return nullptr; 

    int len = get_length(substr);
    for (int i = 0; origin[i] != '\0'; ++i) {
        if (origin[i] == substr[0]) {
            int j;
            for (j = 1; j < len && origin[i + j] == substr[j]; ++j) {}
            if (j == len)
                return &origin[i];
        }
    }
    return nullptr;
}

char* Mystring::strstr(Mystring origin, const Mystring substr) {
    if (substr.str == nullptr || *substr.str == '\0')
        return nullptr; 

    int len = get_length(substr.str);
    for (int i = 0; origin.str[i] != '\0'; ++i) {
        if (origin.str[i] == substr.str[0]) {
            int j;
            for (j = 1; j < len && origin.str[i + j] == substr.str[j]; ++j) {}
            if (j == len)
                return &origin.str[i];
        }
    }
    return nullptr;
}