#include "helper.cpp"
#include<iostream>

int* Book::GetISBN(){
  return m_isbn;
}
void Book::SetISBN(int* isbn){
  strcpy(m_isbn, isbn);
}
char* Book::GetName(){
  return m_name;
}
void Book::SetName(char* name){
  strcpy(m_name, name);
}
bool Book::ReserveBook(char* name){
  if(m_available==false)
  {
    return false;
  }
  else
  {
    strcpy(m_name, name);
    m_available=false;
    return true;
  }
}
bool Book::FreeBook(){
  strcpy(m_name, "N/A");
  m_available=true;
  return true;
}
void operator <<(ostream& out, Book &b){
  out << b.m_title << "," << intprint(b.m_isbn) << "," << b.m_name << endl;
}
