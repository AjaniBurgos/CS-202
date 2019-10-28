#include<iostream>
#include "helper.cpp"

char* Library::GetName(){
  return m_name;
}
void Library::SetName(char* name){
  strcpy(m_name, name);
}
const int Library::GetID(){
  return m_nationalID;
}
bool Library::ListAvailableBooksByTitle(){

}
bool Library::RentBook(){

}
Book* Library::FindOpenSpot(){
  
}
bool Complex::operator+(Book& b){

}
Library::Library(char* name, const int id){

}
