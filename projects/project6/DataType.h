#ifndef DATATYPE_H
#define DATATYPE_H

#include <iostream>
using namespace std;

class DataType{
  public:
    DataType();
    DataType(int intVal, double doubleVal);

    bool operator==(const DataType& other_dataType) const;
    DataType& operator= (const DataType& other_dataType);

		friend ostream& operator<<(ostream& os, const DataType& dataType);

  private:
		int m_intVal;
		double m_doubleVal;
};

#endif
