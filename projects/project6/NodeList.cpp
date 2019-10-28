#include "NodeList.h"

NodeList::NodeList(){																 //(1)
	m_head=NULL;
}
NodeList::NodeList(int size, const DataType& value){ //(2)
	m_head=new Node[size];
	m_head->m_data=value;
	m_head->m_next=m_head+1;
}
NodeList::NodeList(const NodeList& other){					 //(3)
	if(!(m_head==NULL))
	{
		Node* cursor=new Node(m_head->m_data, m_head->m_next);
		cursor=m_head;
		while(!(cursor==NULL))
		{
			cursor->m_data = other.m_head->m_data;
			cursor=other.m_head->m_next;
		}
		m_head=other.m_head;
		cursor=NULL;
	}
}
NodeList::~NodeList(){															 //(4)
	Node* cursor=m_head;
	Node* tmp=cursor;
	while(!(cursor==NULL)) /*Gets to the end of the nodes*/
	{
		tmp=cursor;
		cursor=cursor->m_next;
		delete[] tmp;
	}
	delete[] cursor;
	cursor=NULL;
	delete[] m_head;
	m_head=NULL;
}

NodeList& NodeList::operator= (const NodeList& other_nodeList){							 //(5)
	this->m_head=other_nodeList.m_head;
	Node* cursor = m_head;
	while(!(cursor->m_next==NULL))
	{
		this->m_head->m_next=other_nodeList.m_head->m_next;
		this->m_head->m_data=other_nodeList.m_head->m_data;
		cursor=cursor->m_next;
	}
	return *this;
}
ostream& operator<<(ostream& os, const NodeList& nodeList){ //(6)
	for(int index=0;index<nodeList.size();index++)
	{
		os<<nodeList[index]<<" ";
	}
	return os;
}

DataType* NodeList::first(){						 //(7a)
	if(m_head==NULL)
	{
		return NULL;
	}
	return &(m_head->m_data);
}
const DataType* NodeList::first() const{ //(7b)
	if(m_head==NULL)
	{
		return NULL;
	}
	return &(m_head->m_data);
}

DataType* NodeList::last(){					    //(8a)
	Node* cursor=m_head;
	DataType* data=NULL;
	if(m_head==NULL)
	{
		return NULL;
	}
	while(!(cursor->m_next==NULL))
	{
		data=&(cursor->m_data);
		cursor=cursor->m_next;
	}
	cursor=NULL;
	return data;
}
const DataType* NodeList::last() const{ //(8b)
	Node* cursor=m_head;
	DataType* data=NULL;
	if(m_head==NULL)
	{
		return NULL;
	}
	while(!(cursor->m_next==NULL))
	{
		data=&(cursor->m_data);
		cursor=cursor->m_next;
	}
	cursor=NULL;
	return data;
}

DataType* NodeList::find(const DataType& target, Node* previous){												  //(9a)
	Node* cursor=m_head;
	while(!(cursor->m_next==NULL))
	{
		if(cursor->m_data==target)
		{
			return &(cursor->m_data);
		}
		previous=cursor;
		cursor=cursor->m_next;
	}
	return NULL;
}
const DataType* NodeList::find(const DataType& target, const Node* previous) const{ //(9b)
	Node* cursor=m_head;
	while(!(cursor->m_next==NULL))
	{
		if(cursor->m_data==target)
		{
			return &(cursor->m_data);
		}
		previous=cursor;
		cursor=cursor->m_next;
	}
	return NULL;
}

Node* NodeList::insertAfter(const DataType& target, const DataType& value, int count=1){  //(10)
	Node* cursor=new Node(value, NULL);
	Node* temp;
	Node* previous;
	cursor=m_head;
	while(!(cursor->m_next==NULL)) /*Loops to scroll through the nodeList*/
	{
		if(cursor->m_data==target)
		{
			temp=cursor->m_next;
			do
			{
				while(!(cursor->m_next==NULL)) /*Gets to the end of the nodes*/
				{
					previous=cursor;
					cursor=cursor->m_next;
				}
				cursor->m_data=previous->m_data; /*Sets last 'element' equal to the previous*/
			}
			while(!(cursor==temp)); /*Loops & copies everything until it gets back to the original node*/
			temp->m_data=value;
			previous=NULL;
			cursor=NULL;
			return temp;
		}
		cursor=cursor->m_next;
	}
	return NULL;
}
Node* NodeList::insertBefore(const DataType& target, const DataType& value, int count){ //(11)
	Node* cursor=new Node(value, NULL);
	Node* temp;
	Node* previous;
	cursor=m_head;
	while(!(cursor->m_next==NULL)) /*Loops to scroll through the nodeList*/
	{
		temp=cursor;
		if(cursor->m_data==target)
		{
			do
			{
				while(!(cursor->m_next==NULL)) /*Gets to the end of the nodes*/
				{
					previous=cursor;
					cursor=cursor->m_next;
				}
				cursor->m_data=previous->m_data; /*Sets last 'element' equal to the previous*/
			}
			while(!(cursor==temp)); /*Loops & copies everything until it gets back to the original node*/
			temp->m_data=value;
			return temp;
		}
		cursor=cursor->m_next;
	}
	return NULL;
}

Node* NodeList::removeForward(const DataType& target, int count){  //(12)
	Node* cursor=m_head;
	Node* previous=NULL;
	find(target,previous);
	if(cursor==NULL)
	{
		delete cursor;
		delete previous;
		cursor=NULL;
		previous=NULL;
		return NULL;
	}
	else if(previous==NULL)
	{
		m_head=cursor->m_next;
		return cursor;
	}
	else if(cursor->m_next==NULL)
	{
		delete cursor;
		delete previous;
		m_head=NULL;
		cursor=NULL;
		previous=NULL;
		return NULL;
	}
	previous->m_next=cursor->m_next;
	delete cursor;
	cursor=NULL;
	return previous->m_next;
}
Node* NodeList::removeBackward(const DataType& target, int count){ //(13)
	Node* cursor=m_head;
	Node* previous=NULL;
	find(target,previous);
	if(cursor==NULL)
	{
		return NULL;
	}
	else if(previous==NULL)
	{
		m_head=cursor->m_next;
		return cursor;
	}
	else if(cursor->m_next==NULL)
	{
		m_head=NULL;
	}
	previous->m_next=cursor->m_next;
	delete cursor;
	cursor=NULL;
	return previous;
}

DataType& NodeList::operator[] (int position){						 //(14a)
	Node* cursor=m_head;
	for(int index=0;index<position;index++)
	{
		cursor=cursor->m_next;
	}
	return cursor->m_data;
}
const DataType& NodeList::operator[] (int position) const{ //(14b)
	Node* cursor=m_head;
	for(int index=0;index<position;index++)
	{
		cursor=cursor->m_next;
	}
	return cursor->m_data;
}

int NodeList::size() const{		//(15)
	Node* cursor=m_head;
	int counter=0;
	while(!(cursor==NULL))
	{
		counter++;
		cursor=cursor->m_next;
	}
	return counter;
}
bool NodeList::empty() const{ //(16)
	if(m_head==NULL)
	{
		return true;
	}
	return false;
}
void NodeList::clear(){			  //(17)
	Node* cursor=m_head;
	Node* tmp;
	do
	{
		while(!(cursor->m_next==NULL)) //gets to the end, and deletes stuff in the end
		{
			tmp=cursor->m_next;
			delete[] cursor;
			cursor=tmp;
		}
		cursor=m_head;
	}
	while(!(cursor==m_head)); //used to repeatedly go back to the beginning
	tmp=NULL;
}
