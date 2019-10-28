#include <ostream>

template <class T> class NodeQueue;  //forward declaration of (any) class or function that will be a friend of Node
template <class T> std::ostream& operator<<(std::ostream& os, const NodeQueue<T>& nodeQueue);  //forward declaration of (any) class or function that will be a friend of NodeQueue

template <class T>
class Node{
public:
  Node(){ m_next = NULL; }
  Node(const T& data, Node<T>* next = NULL){ m_data = data; m_next = next; }
  const T& getData() const{ return m_data; }
  T& getData(){ return m_data; }
friend class NodeQueue<T>;  //declaration of templated friend class
private:
  Node<T>* m_next;
  T m_data;
};

template <class T>
class NodeQueue{
public:
  NodeQueue();
  ~NodeQueue();
  NodeQueue<T>& operator=(const NodeQueue<T>& other);
  const T& front() const;
  T& front();
  const T& back() const;
  T& back();
  void push(const T& value);
  void pop();
  int size() const;
  void clear();
friend std::ostream& operator<< <> (std::ostream& os, const NodeQueue<T>& nodeQueue); 
private:
  Node<T> *m_front;
  Node<T> *m_back;
};

template <class T>
NodeQueue<T>::NodeQueue(){
    m_front = NULL;
    m_back = NULL;
}

template <class T>
NodeQueue<T>& NodeQueue<T>::operator=(const NodeQueue<T>& other){
  clear();
  Node<T>* otherNode = other.m_front;
  if (otherNode){
    Node<T>* myNode = m_front = new Node<T>(otherNode->getData());  
    while (otherNode->m_next){
        otherNode = otherNode->m_next;
        myNode = myNode->m_next = new Node<T>(otherNode->getData()); 
    }
    m_back = myNode;
  }
  return *this;
}

template <class T>
NodeQueue<T>::~NodeQueue(){
  clear();
}

template <class T>
const T& NodeQueue<T>::front() const{
  return m_front->getData();
}

template <class T>
T& NodeQueue<T>::front(){
  return m_front->getData();
}

template <class T>
const T& NodeQueue<T>::back() const{
  return m_back->getData();
}

template <class T>
T& NodeQueue<T>::back(){
  return m_back->getData();
}

template <class T>
void NodeQueue<T>::push(const T& value){
  if (!m_back){ 
    m_back = m_front = new Node<T>(value);
  }
  else{ 
    m_back = m_back->m_next = new Node<T>(value);
  }
}

template <class T>
void NodeQueue<T>::pop(){
  if (m_front){
    Node<T>* del_Pt = m_front;
    m_front = m_front->m_next;
    delete del_Pt; 
    if (!m_front){
      m_back = NULL;
    }
  }
}

template <class T>
int NodeQueue<T>::size() const{
  int size = 0;
  Node<T>* trav_Pt = m_front;
  while (trav_Pt){
    ++size;
    trav_Pt = trav_Pt->m_next;
  }
  return size;
}

template <class T>
void NodeQueue<T>::clear(){
  while (m_front){
    Node<T>* del_Pt = m_front;
    m_front = m_front->m_next;
    delete del_Pt; 
  }
  m_front = NULL;
  m_back = NULL;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const NodeQueue<T>& nodeQueue){
  NodeQueue<T> nQ_tmp;
  nQ_tmp = nodeQueue;
  while (nQ_tmp.size()){
    os << nQ_tmp.front() << " " ;
    nQ_tmp.pop();
  }
  return os;
}
