const int MAX_CHAR = 255;

class Book{
  public:
    int* GetISBN();
    void SetISBN(int* isbn);
    char* GetName();
    void SetName(char* name);
    bool ReserveBook(char* name);
    bool FreeBook();
    friend void operator <<(ostream& out, Book& b);

    Book();
    Book(char*, int*, bool, char*);
    Book(Book &b);

  private:
    char m_name[MAX_CHAR];
    int m_isbn[13];
    bool m_available;
    char m_renter[MAX_CHAR];
};
