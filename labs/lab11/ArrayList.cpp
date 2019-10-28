#include "ArrayList.h"

ArrayList::ArrayList() {
  m_size = 0;
  m_cursor = -1;
}

ArrayList::ArrayList(const ArrayList& src) {
  if(!src.IsEmpty()) {
    m_size = src.m_size;
    m_cursor = m_size - 1;

    for(int i = 0; i < m_size; i++) {
      m_list[i] = src.m_list[i];
    }
  }
}

ArrayList::~ArrayList() {
  m_size = 0;
  m_cursor = -1;
}

void ArrayList::GoToNext() {
  if(!IsEmpty()) {
    if(m_cursor == m_size - 1) {
      m_cursor = 0;
    } else {
      m_cursor++;
    }
  }
}

void ArrayList::GoToPrevious() {
  if(!IsEmpty()) {
    if(m_cursor == 0) {
      m_cursor = m_size - 1;
    } else {
      m_cursor--;
    }
  }
}

bool ArrayList::IsEmpty() const {
  if(m_size == 0) {
    return true;
  }

  return false;
}

bool ArrayList::IsFull() const {
  if(m_size == MAX_SIZE) {
    return true;
  }
  return false;
}

bool ArrayList::InsertAfter(int new_value) {
	m_size++;
	for(m_cursor=m_size-1;m_cursor>new_value;m_cursor--)
	{
		if(m_cursor==m_size)
		{
			m_list[0]=m_list[m_cursor];
		}
		if(m_cursor!=new_value)
		{
			m_list[m_cursor]=m_list[m_cursor-1];
		}
	}
	m_list[m_cursor]=new_value;
	return true;
}

bool ArrayList::Remove(int &removed_value) {
	for(m_cursor=0;m_cursor<=m_size;m_cursor++)
	{
		if(m_cursor==removed_value)
		{
			m_list[m_cursor]=m_list[m_cursor+1];
		}
	}
	m_size--;
	for(m_cursor=m_size;m_cursor>removed_value;m_cursor--)
	{
		m_list[m_cursor]=m_list[m_cursor-1];
	}
	return true;
}

void ArrayList::PrintList() {
  if(IsEmpty()) {
    cout << "Empty list." << endl;
  } else {
    for(int i = 0; i < m_size; i++) {
      cout << m_list[i] << " | ";
    }
    cout << endl;
  }
}
