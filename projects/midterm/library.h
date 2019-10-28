const int N_BOOKS = 1000;
const int MAX_CHAR = 255;

class Library{
  public:
    char* GetName();
    void SetName();
    const int GetID();
    bool ListAvailableBooksByTitle();
    bool RentBook();
    Book* FindOpenSpot();
    bool Library& operator+(Book& b);

    Library(char* name, const int id);
  private:
    char m_name[MAX_CHAR];
    const int m_nationalID;
    Book m_inventory[N_BOOKS];
};
