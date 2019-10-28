#ifndef NODEQUEUE_H
#define NODEQUEUE_H

#include "DataType.h"

class NodeQueue;
class Node{
	public:
  	Node(){
			m_next = NULL;
		}
		Node(const DataType& data, Node* next = NULL){
			m_next = next;
			m_data = data;
		}
		DataType& getData(){
			return m_data;
		}
		const DataType& getData() const{
			return m_data;
		}
		friend class NodeQueue;
		friend ostream& operator<<(ostream& os, const NodeQueue& nodeQueue);

	private:
    Node* m_next;
    DataType m_data;
};
class NodeQueue{
	public:
		NodeQueue(){              									//(1)
			m_front=NULL;
			m_back=NULL;
		}
		NodeQueue(int size, const DataType& value){ //(2)
			Node* cursor=m_front;
			for(int index=0;index<size;index++)
			{
				cursor->m_data=value;
				cursor=cursor->m_next;
			}
		}
		NodeQueue(const NodeQueue& other){        	//(3)
			Node* cursor;
			delete m_front;
			delete m_back;
			m_front=other.m_front;
			m_back=other.m_back;
			cursor=m_front;
			while(!(cursor==NULL))
			{
				cursor->m_data=other.m_front->m_data;
				cursor=cursor->m_next;
			}
		}
		~NodeQueue(){                 							//(4)
			clear();
		}

    NodeQueue& operator= (const NodeQueue& other_nodeQueue){ //(5)
			Node* cursor;
			Node* cursor2;
			this->clear();
			this->m_front=other_nodeQueue.m_front;
			this->m_back=other_nodeQueue.m_back;
			cursor=this->m_front;
			cursor2=other_nodeQueue.m_front;
			while(!(cursor2==NULL))
			{
				cursor->m_data=cursor2->m_data;
				cursor=cursor->m_next;
				cursor2=cursor2->m_next;
			}
			return *this;
		}

    DataType& front(){ 						 //(6a)
			return m_front->m_data;
		}
		const DataType& front() const{ //(6b)
			return m_front->m_data;
		}

    DataType& back(){ 						//(7a)
			return m_back->m_data;
		}
		const DataType& back() const{ //(7b)
			return m_back->m_data;
		}

    void push(const DataType& value){ //(8)
			m_back->m_next->m_data=value;
			m_back=m_back->m_next;
		}
		void pop(){                       //(9)
			m_front=m_front->m_next;
		}

    int size() const{	  //(10)
			int counter=0;
			Node* cursor=m_front;
			while(!(cursor==NULL))
			{
				counter++;
				cursor=cursor->m_next;
			}
			return counter;
		}
		bool empty() const{ //(11)
			if(m_front==NULL)
			{
				return true;
			}
			return false;
		}
		bool full() const{  //(12)
			return false;
		}
		void clear(){ 			//(13)
			Node* cursor;
			if(empty()==false)
			{
				while(!(m_front==NULL))
				{
					cursor=m_front;
					m_front=m_front->m_next;
					delete cursor;
				}
				cursor=NULL;
			}
		}

		friend std::ostream& operator<<(std::ostream& os, const NodeQueue& nodeQueue){ //(xx)
			Node* cursor=nodeQueue.m_front;
			while(!(cursor==NULL))
			{
				os << cursor->m_data << " ";
				cursor=cursor->m_next;
			}
			return os;
		}
	private:
    Node *m_front;
		Node *m_back;
};
#endif
