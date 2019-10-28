#ifndef NODEQUEUE_H
#define NODEQUEUE_H
template<class T> class NodeQueue;
template<class T>
class Node{
	public:
  	Node(){
			m_next = NULL;
		}
		Node(const T& data, Node<T>* next = NULL){
			m_next = next;
			m_data = data;
		}
		T& getData(){
			return m_data;
		}
		const T& getData() const{
			return m_data;
		}
		friend class NodeQueue<T>;
		friend std::ostream& operator<<(std::ostream& os, const NodeQueue<T>& nodeQueue);

	private:
    Node<T>* m_next;
    T m_data;
};
template<class T>
class NodeQueue{
	public:
		NodeQueue(){              									//(1)
			m_front=NULL;
			m_back=NULL;
		}
		NodeQueue(int size, const T& value){ //(2)
			Node<T>* cursor=m_front;
			for(int index=0;index<size;index++)
			{
				cursor->m_data=value;
				cursor=cursor->m_next;
			}
		}
		NodeQueue(const NodeQueue<T>& other){        	//(3)
			Node<T>* cursor;
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

    NodeQueue& operator= (const NodeQueue<T>& other_nodeQueue){ //(5)
			Node<T>* home;
			Node<T>* temp;

			if(!(this==&other_nodeQueue))
			{
				clear();
				home=other_nodeQueue.m_front;
				m_front=new Node<T>(home->m_data,NULL);
				temp=m_front;
				home=other_nodeQueue.m_front->m_next;
				while(!(home==NULL))
				{
		 			temp->m_next=new Node<T>(other_nodeQueue.m_front->m_data,NULL);
		 			home=home->m_next;
		 			temp=temp->m_next;
		 		}
		 		m_back=temp;
		 		temp=NULL;
			}
			return *this;
		}

    T& front(){ 						 //(6a)
			return m_front->m_data;
		}
		const T& front() const{ //(6b)
			return m_front->m_data;
		}

    T& back(){ 						//(7a)
			return m_back->m_data;
		}
		const T& back() const{ //(7b)
			return m_back->m_data;
		}

    void push(const T& value){ //(8)
			if(empty()==true)
			{
				Node<T>* temp=new Node<T>(value,NULL);
				m_front=temp;
				m_back=m_front;
				delete temp;
				temp=NULL;
			}
		else if(!empty())
			{
		 	Node<T>* temp=new Node<T>(value,NULL);
		 	m_back->m_next=temp;
		 	m_back=temp;
	 		}
		}
		void pop(){                       //(9)
			if(!(empty()))
			{
				Node<T>* temp=m_front;
				m_front=m_front->m_next;
				delete temp;
				temp=NULL;
			}
		}

    int size() const{	  //(10)
			int counter=1;
			Node<T>* cursor=m_front;
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
			Node<T>* cursor;
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

		friend std::ostream& operator<<(std::ostream& os, const NodeQueue<T>& nodeQueue){ //(xx)
			Node<T>* temp= nodeQueue.m_front;
			while(!(temp==NULL))
			{
				os << temp->m_data << " ";
				temp=temp->m_next;
			}
			temp=NULL;
			return os;
		}
	private:
    Node<T> *m_front;
		Node<T> *m_back;
};
#endif
