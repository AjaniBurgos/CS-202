const int ROW = 3; const int COL = 3;

class Matrix {
  public:
    Matrix();
    Matrix(int initialValueForAllElements);
    Matrix(Matrix& otherMatrix);
    void operator=(Matrix& otherMatrix);
    bool operator==(Matrix& otherMatrix);
    void SetElement(int element, int value);
    void Transpose();
    void Diagonal();
    void Input();
    void Output();
  private:
    int m_array[ROW][COL];
 };
