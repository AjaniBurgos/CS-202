#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "DataType.h"
#include <stdlib.h>

class ArrayList{
  public:
    ArrayList();																//(1)
    ArrayList(int size, const DataType& value); //(2)
    ArrayList(const ArrayList& other);				  //(3)
    ~ArrayList();																//(4)

    ArrayList& operator= (const ArrayList& other_arrayList);											//(5)
    friend ostream& operator<<(ostream& os, const ArrayList& arrayList); //(6)

    DataType* first();						 //(7a)
    const DataType* first() const; //(7b)

    DataType* last();						  //(8a)
    const DataType* last() const; //(8b)

    DataType* find(const DataType& target, DataType* previous); 									//(9a)
    const DataType* find(const DataType& target, const DataType* previous) const; //(9b)

    DataType* insertAfter(const DataType& target, const DataType& value, int count);  //(10)
    DataType* insertBefore(const DataType& target, const DataType& value, int count); //(11)
    DataType* removeForward(const DataType& target, int count);												//(12)
    DataType* removeBackward(const DataType& target, int count);											//(13)

    DataType& operator[] (int position);						 //(14a)
    const DataType& operator[] (int position) const; //(14b)

    int size() const;		//(15)
    bool empty() const; //(16)
    void clear();				//(17)

  private:
    void grow(int addsize); //(18)
    void trim();						//(19)

    DataType *m_array;
    int m_size;
    int m_maxsize;
};

#endif
