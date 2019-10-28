#ifndef VECTORMATRIX_H_
#define VECTORMATRIX_H_

#include <ostream>
#include <vector>

template<class T> class VectorMatrix;
template<class T> std::ostream& operator<<(std::ostream& os, const VectorMatrix<T> vm);

template<class T>
class VectorMatrix {
 public:
  // 1) instatiates a [0]x[0] no-element matrix
  VectorMatrix();  
  // 2) instatiates a [rows]x[cols] matrix with all elements set to [value]
  VectorMatrix(std::size_t rows,std::size_t cols, const T& value=T());  
  // 3  instantiates via matrix copy
  VectorMatrix(const VectorMatrix<T>& otherMatrix);  
  // 4) destroys matrix
  ~VectorMatrix(); 

  // 5) assignment operator
  VectorMatrix<T>& operator=(const VectorMatrix<T>& other);  
  // 6) parentheses operator, to be used for [row],[col] indexing
  const T& operator()(std::size_t row_pos, std::size_t col_pos) const;
  T& operator()(std::size_t row_pos, std::size_t col_pos);
  // 7) checks if two matrices are by-size-and-by-value equal
  bool operator==(const VectorMatrix<T>& other); 

  // 8) returns object which is transpose of object matrix
  VectorMatrix<T> transpose();
  // 9) gets values from user input
  void input(std::size_t rows, std::size_t cols);
  // 10) outputs values
  friend std::ostream& operator<< <> (std::ostream& os, const VectorMatrix<T> vm);

 private:
  std::size_t m_cols;
  std::vector< std::vector<T> > m_matrix;
};

#endif
