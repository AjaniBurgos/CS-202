#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include "DataType.h"
const int ARRAY_MAX = 1000;

class ArrayQueue{
	public:
		ArrayQueue(){             									 //(1)
			m_front=0;
			m_back=-1;
			m_size=-1;
		}
		ArrayQueue(int size, const DataType& value){ //(2)
			m_size=size;
			m_front=0;
			m_back=m_size-1;
			for(int index=0;index<m_size;index++)
			{
				m_array[index] = value;
			}
		}
		ArrayQueue(const ArrayQueue& other){         //(3)
			m_size=other.m_size;
			m_front=other.m_front;
			m_back=other.m_back;
			for(int index=0;index<m_size;index++)
			{
				m_array[index]=other.m_array[index];
			}
		}
		~ArrayQueue(){                               //(4)
			clear();
		}

		ArrayQueue& operator= (const ArrayQueue& other_arrayQueue){ //(5)
			this->m_size=other_arrayQueue.m_size;
			this->m_front=other_arrayQueue.m_front;
			this->m_back=other_arrayQueue.m_back;
			for(int index=0;index<m_size;index++)
			{
				this->m_array[index]=other_arrayQueue.m_array[index];
			}
			return *this;
		}

	  DataType& front(){             //(6a)
			return m_array[m_front];
		}
		const DataType& front() const{ //(6b)
			return m_array[m_front];
		}

	  DataType& back(){             //(7a)
			return m_array[m_back];
		}
		const DataType& back() const{ //(7b)
			return m_array[m_back];
		}

	  void push(const DataType& value){ //(8)
			if(full()==false){
				m_size++;
				m_back=(m_back+1)%ARRAY_MAX;
				m_array[m_front]=value;
			}
		}
		void pop(){                       //(9)
			if(empty()==false)
			{
				m_size--;
				m_front=(m_front+1)%ARRAY_MAX;
				for(int index=0;index<m_back+1;index++)
				{
					m_array[index]=m_array[index+1];
				}
			}
		}

	  int size() const{   //(10)
			return m_size;
		}
		bool empty() const{ //(11)
			if(m_front==m_back+1)
			{
				return true;
			}
			return false;
		}
		bool full() const{  //(12)
			if(m_back==ARRAY_MAX-1)
			{
				return true;
			}
			return false;
		}
		void clear(){       //(13)
			if(empty()==false)
			{
				for(int index=0;index<m_back-1;index++)
				{
					m_size=-1;
					m_front=0;
					m_back=-1;
				}
			}
		}

    friend std::ostream& operator<<(std::ostream& os, const ArrayQueue& arrayQueue){ //(xx)
			for(int index=0;index<arrayQueue.m_back-1;index++)
			{
				os << arrayQueue.m_array[index] << " ";
			}
			return os;
		}

	private:
		DataType m_array[ARRAY_MAX];
		int m_front;
		int m_back;
		int m_size;
};
#endif
