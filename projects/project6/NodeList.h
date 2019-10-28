#ifndef NODELIST_H
#define NODELIST_H

#include "DataType.h"
class NodeList;
class Node{
  public:
    Node(){
		//m_data = m_data(0,0.0);
		//unnecessary, DataType has default ctor that 0-initializes
		m_next = NULL;
	}
	Node(const DataType& data, Node* next = NULL){
		//uses DataType's assignment operator=
		m_next = next;
		m_data = data;
	}

	DataType& getData(){
		//gets non-const reference, can be used to modify value of underlying data
		return m_data;
	}
	const DataType& getData() const{
		//gets const reference, can be used to access value of underlying data
		return m_data;
	}
	friend class NodeList; //allows accessing of link(s) and data from NodeList (link remains otherwise inaccessible outside of Node)
	friend ostream& operator<<(ostream& os, const NodeList& nodeList); //(6)

  private:
		//the link to next node
    Node* m_next;
		//the actual data
    DataType m_data;
};

class NodeList{
	public:
    NodeList();																 //(1)
    NodeList(int size, const DataType& value); //(2)
    NodeList(const NodeList& other);					 //(3)
    ~NodeList();															 //(4)

    NodeList& operator= (const NodeList& other_nodeList);							 //(5)
    friend ostream& operator<<(ostream& os, const NodeList& nodeList); //(6)

    DataType* first();						 //(7a)
    const DataType* first() const; //(7b)

    DataType* last();					    //(8a)
    const DataType* last() const; //(8b)

    DataType* find(const DataType& target, Node* previous);												  //(9a)
    const DataType* find(const DataType& target, const Node* previous) const; //(9b)

    Node* insertAfter(const DataType& target, const DataType& value, int count);  //(10)
    Node* insertBefore(const DataType& target, const DataType& value, int count); //(11)

    Node* removeForward(const DataType& target, int count=1);  //(12)
    Node* removeBackward(const DataType& target, int count=1); //(13)

    DataType& operator[] (int position);						 //(14a)
    const DataType& operator[] (int position) const; //(14b)

    int size() const;		//(15)
    bool empty() const; //(16)
    void clear();			  //(17)

	private:
    Node *m_head;
};

#endif
