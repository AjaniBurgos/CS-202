class DynamicMatrix {
 public:
  // 1) instatiates a [0]x[0] NULL matrix
  DynamicMatrix(){
		m_rows=0;
		m_cols=0;
		m_matrix=NULL;
	}
  // 2) instatiates a [rows]x[cols] matrix with all elements set to [value]
  DynamicMatrix(int rows,int cols, int value=0){
		m_rows=rows;
		m_cols=cols;
		*m_matrix=value;
	}
  // 3  instantiates via matrix copy
  DynamicMatrix(DynamicMatrix& otherMatrix){
		m_rows=otherMatrix.m_rows;
		m_cols=otherMatrix.m_cols;
		m_matrix=otherMatrix.m_matrix;
	}
  // 4) destroys matrix and deallocates dynamic memory
  ~DynamicMatrix(){
		if(m_matrix!=NULL)
		{
			delete[] m_matrix;
			m_matrix=NULL;
			m_rows=0;
			m_cols=0;
		}
	}

  // 5) assignment operator
  DynamicMatrix& operator=(const DynamicMatrix& other){
		this->m_rows=other.m_rows;
		this->m_cols=other.m_cols;
		this->m_matrix=other.m_matrix;
	}
  // 6) parentheses operator, to be used for [row],[col] indexing
  int& operator()(int row_pos, int col_pos){

	}
  // 6) checks if two matrices are by-size-and-by-value equal
  bool operator==(const DynamicMatrix& other){
		if((m_rows!=other.m_rows) && (m_cols!=other.m_cols))
		{
			return false;
		}
		for(int i=0;i<m_rows;i++)
		{
			for(int j=0;j<m_cols;j++)
			{
				if(m_matrix[i][j]!=other.m_matrix[i][j])
				{
					return false;
				}
			}
		}
		return true;
	}

  DynamicMatrix Transpose(){  //returns object which is transpose of object matrix
    DynamicMatrix transpMatrix(m_cols,m_rows);
    for (int j=0;j<m_rows;++j){
      for (int i=0;i<m_cols;++i){
		transpMatrix.m_matrix[j][i] = m_matrix[i][j];
      }
    }
	return transpMatrix;
  }

  void Input(){  //gets values from user input
	cout<<"Enter elements of "<<m_rows<<"x"<<m_cols<<" matrix:"<<endl;
    for (int j=0;j<m_rows;++j){
      for (int i=0;i<m_cols;++i){
	    cin>>m_matrix[j][i];
      }
    }
  }
  void Output(){  //outputs values to terminal
	cout<<"Elements of "<<m_rows<<"x"<<m_cols<<" matrix are:"<<endl;
    for (int j=0;j<m_rows;++j){
      for (int i=0;i<m_cols;++i){
	    cout<<m_matrix[j][i]<<" ";
      }
	  cout<<endl;
    }
	cout<<endl;
  }

 private:
  int m_rows;
  int m_cols;
  int** m_matrix;
};
