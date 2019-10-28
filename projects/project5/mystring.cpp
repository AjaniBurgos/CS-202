#include "mystring.h"

using namespace std;

MyString::MyString(){
  m_buffer=NULL;
  m_size=0;
}
MyString::MyString(const char* str){
	m_buffer=NULL;
	m_size=0;
	m_size=strlen(str)+1;
	buffer_allocate(m_size);
	strcpy(m_buffer, str);
}
MyString::MyString(const MyString& other_myStr){
	m_buffer=NULL;
	m_size=0;
	buffer_allocate(strlen(other_myStr.m_buffer)+1);
  strcpy(m_buffer,other_myStr.m_buffer);
  m_size=other_myStr.m_size;
}
MyString::~MyString(){
  /*Deallocates ANY & ALL dynamic memory currently allocated (@ end of scope)*/
  buffer_deallocate();
}

int MyString::size() const{
  return strlen(m_buffer)+1;
}
int MyString::length() const{
  return strlen(m_buffer);
}
const char* MyString::c_str() const{
	return m_buffer;
}

bool MyString::operator== (const MyString& other_myStr) const{
	if(!strcmp(m_buffer,other_myStr.m_buffer))
	{
		return true;
	}
	else
	{
		return false;
	}
}
MyString& MyString::operator= (const MyString& other_myStr){
  if(this!=&other_myStr)
  {
		buffer_allocate(strlen(other_myStr.m_buffer)+1);
    strcpy(this->m_buffer,other_myStr.m_buffer);
    this->m_size=other_myStr.m_size;
  }
	return *this;
}
MyString& MyString::operator+ (const MyString& other_myStr){
	m_size=strlen(m_buffer)+strlen(other_myStr.m_buffer)+1;
	char* tmp=new char[m_size];
	strcpy(tmp,strconcat(m_buffer,other_myStr.m_buffer));
	m_buffer=new char[m_size];
	strcpy(m_buffer,tmp);
	tmp=NULL;
	return *this;
}
char& MyString::operator[] (int position){
	if(position>0)
	{
		return m_buffer[position-1];
	}
	return m_buffer[0];
}
const char& MyString::operator[] (int position) const{
	if(position<=m_size && position>0)
	{
		return m_buffer[position-1];
	}
	return m_buffer[0];
}
ostream& operator<< (ostream& os, const MyString& myStr){
	os<<myStr.m_buffer;
	return os;
}

void MyString::buffer_deallocate(){
  if(m_buffer!=NULL)
  {
    delete[] m_buffer;
    m_buffer=NULL;
    m_size=0;
  }
}
void MyString::buffer_allocate(int size){
  if(m_buffer!=NULL)
  {
    delete[] m_buffer;
  }
  m_buffer=new char [size];
  m_size=size;
}

/*                                        		     -----STRING FUNCTIONS-----                                                  */

int strlen(const char* str)
{
  int counter=0;
  while(str[counter] != '\0')
  {
    counter++;
  }
  return counter;
}
void strcpy(char* dest, const char* src)
{
	int index;
	if(src!=NULL)
	{
	  for(index=0;index<strlen(src);index++)
	  {
	    dest[index] = src[index];
	  }
	  dest[index] = '\0';
	}
}
int strcmp(char* str1, char* str2)
{
  while(*str1!='\0' && *str2!='\0')
  {
    if(*str1!=*str2)
    {
      return *str1-*str2;
    }
    str1++;
    str2++;
	}
  return *str1-*str2;
}
char* strconcat(char* str1, char* str2)
{
	int i=0;
	char* result = new char[strlen(str1)+strlen(str2)+1];
	while(*str1!='\0')
	{
		result[i]=*str1;
		i++;
		str1++;
	}
	while(*str2!='\0')
	{
		result[i]=*str2;
		i++;
		str2++;
	}
	result[i]='\0';

	return result;
}
