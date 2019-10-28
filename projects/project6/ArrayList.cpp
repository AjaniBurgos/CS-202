#include "ArrayList.h"
ArrayList::ArrayList(){														    	//(1)
	m_array=NULL;
	m_size=0;
	m_maxsize=0;
}
ArrayList::ArrayList(int size, const DataType& value){ //(2)
	m_size=size;
	m_maxsize=size;
	m_array=new DataType[m_size];
	for(int index=0;index<m_size;index++)
	{
		m_array[index]=value;
	}
}
ArrayList::ArrayList(const ArrayList& other){				  //(3)
	m_size=other.m_size;
	m_maxsize=other.m_maxsize;
	m_array=new DataType[other.m_size];
}
ArrayList::~ArrayList(){																					//(4)
	if(m_array!=NULL)
	{
		m_size=0;
		m_maxsize=0;
		delete[] m_array;
		m_array=NULL;
	}
}

ArrayList& ArrayList::operator= (const ArrayList& other_arrayList){		  //(5)
	this->m_size = other_arrayList.m_size;
	this->m_maxsize = other_arrayList.m_maxsize;
	this->m_array = new DataType[other_arrayList.m_size];
	for(int index=0;index<m_size;index++)
	{
		this->m_array[index]=other_arrayList.m_array[index];
	}
	return *this;
}
ostream& operator<<(ostream& os, const ArrayList& arrayList){ //(6)
	for(int index=0;index<arrayList.m_size;index++)
	{
		os<<arrayList.m_array[index];
	}
	return os;
}

DataType* ArrayList::first(){						 //(7a)
	if(m_array==NULL)
	{
		return NULL;
	}
	return &m_array[0];
}
const DataType* ArrayList::first() const{ //(7b)
	if(m_array==NULL)
	{
		return NULL;
	}
	return &m_array[0];
}

DataType* ArrayList::last(){						  //(8a)
	if(m_array==NULL)
	{
		return NULL;
	}
	return &m_array[m_size-1];
}
const DataType* ArrayList::last() const{ //(8b)
	if(m_array==NULL)
	{
		return NULL;
	}
	return &m_array[m_size-1];
}

DataType* ArrayList::find(const DataType& target, DataType* previous){ 									//(9a)
	if(m_array==NULL)
	{
		return NULL;
	}
	previous=NULL;
	for(int index=0;index<m_size;index++)
	{
		if(m_array[index]==target)
		{
			return &m_array[index];
			previous=&m_array[index-1];
			if(index==0)
			{
				return &m_array[index];
			}
		}
	}
	return NULL;
}
const DataType* ArrayList::find(const DataType& target, const DataType* previous) const{ //(9b)
	if(m_array==NULL)
	{
		return NULL;
	}
	previous=NULL;
	for(int index=0;index<m_size;index++)
	{
		if(m_array[index]==target)
		{
			previous=&m_array[index-1];
			return &m_array[index];
		}
	}
	return NULL;
}

DataType* ArrayList::insertAfter(const DataType& target, const DataType& value, int count){  //(10)
	int index=0;
	if(m_array==NULL)
	{
		return NULL;
	}
	grow(1);
	index=m_maxsize;
	while(!(m_array[index]==target))
	{
		m_array[index]=m_array[index-1];
		index--;
	}
	m_array[index]=value;
	return &m_array[index];
}
DataType* ArrayList::insertBefore(const DataType& target, const DataType& value, int count){ //(11)
	int index;
	if(m_array==NULL)
	{
		return NULL;
	}
	grow(1);
	index=m_maxsize;
	while(!(m_array[index]==target))
	{
		m_array[index]=m_array[index-1];
		index--;
	}
	m_array[index]=m_array[index-1];
	index--;
	m_array[index]=value;
	return &m_array[index];
}
DataType* ArrayList::removeForward(const DataType& target, int count){												//(12)
	int index=0;
	int tmp_target;
	while(!(m_array[index]==target))
	{
		m_array[index]=m_array[index+1];
		index++;
	}
	tmp_target=index+1;
	for(;index<m_size-1;index++)
	{
		m_array[index]=m_array[index+1];
	}
	return &m_array[tmp_target];
}
DataType* ArrayList::removeBackward(const DataType& target, int count){											//(13)
	int index=0;
	int tmp_target;
	while(!(m_array[index]==target))
	{
		m_array[index]=m_array[index+1];
		index++;
	}
	tmp_target=index-1;
	for(;index<m_size-1;index++)
	{
		m_array[index]=m_array[index+1];
	}
	return &m_array[tmp_target];
}

DataType& ArrayList::operator[] (int position){						 //(14a)
	return m_array[position];
}
const DataType& ArrayList::operator[] (int position) const{ //(14b)
	return m_array[position];
}

int ArrayList::size() const{   		//(15)
	return m_size;
}
bool ArrayList::empty() const{ 		//(16)
	if(m_array==NULL)
	{
		return true;
	}
	return false;
}
void ArrayList::clear(){						//(17)
	delete[] m_array;
	m_array=NULL;
}
void ArrayList::grow(int addsize){ //(18)
	DataType* tmp = new DataType[m_maxsize+addsize];
	for(int index=0;index<m_size;index++)
	{
		tmp[index]=m_array[index];
	}
	delete[] m_array;
	m_maxsize+=addsize;
	m_array=tmp;
	tmp=NULL;
}
void ArrayList::trim(){					  //(19)
	DataType* tmp = new DataType[m_size];
	for(int index=0;index<m_size;index++)
	{
		tmp[index]=m_array[index];
	}
	m_maxsize=m_size;
	delete[] m_array;
	m_array=tmp;
	tmp=NULL;
}
