#ifndef MYSTRING_H
#define MYSTRING_H
#include<iostream>

using namespace std;

int strlen(const char* str);
void strcpy(char* dest, const char* src);
int strcmp(char* str1, char* str2);
char* strconcat(char* str1, char* str2);

class MyString{
  public:
    MyString(); //1
    MyString(const char* str); //2
    MyString(const MyString& other_myStr); //3
    ~MyString(); //4

    int size() const; //5
    int length() const; //6
    const char* c_str() const; //7

    bool operator== (const MyString& other_myStr) const; //8
    MyString& operator= (const MyString& other_myStr); //9
    MyString& operator+ (const MyString& other_myStr); //10
    char& operator[] (int position); //11a
		const char& operator[] (int position) const; //11b

		friend ostream& operator<< (ostream& os, const MyString& myStr); //12

  private:
    void buffer_deallocate(); //13
    void buffer_allocate(int size); //14

    char* m_buffer;
    int m_size;
};
#endif
