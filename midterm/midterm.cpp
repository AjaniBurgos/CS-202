#include <iostream>
#include <fstream>
using namespace std;


/*
  Helper functions, you can use your own or replicate these
*/

void strcpy(char* dst, const char* src)
{
 while (dst && src && *src != '\0'){
   *dst = *src;
   ++src;
   ++dst;
 }
 if (dst){
   *dst = '\0';
 }
}

int strcmp(const char* str1, const char* str2)
{
 while (str1 && str2 && *str1 != '\0' &&
        *str2 != '\0' && *str1 == *str2){
   ++str1;
   ++str2;
 }
 if (!str1){
   return -256;
 }
 else if (!str2){
   return 256;
 }
 return *str1 - *str2;
}

void intcpy(int* dst, const int* src, int size)
{
 while (dst && src && --size >= 0){
   *dst = *src;
   ++src;
   ++dst;
 }
}

void intprint(ostream& os, const int* arr, int size)
{
 while (arr && --size >= 0){
   os << *arr;
   ++arr;
 }
}

bool intcmp(const int* arr1, const int* arr2, int size)
{
 while (arr1 && arr2 &&
	    *arr1 == *arr2 && --size >= 0)
 {
   ++arr1;
   ++arr2;
 }
 if (!arr1 || !arr2 || *arr1 != *arr2){
   return false;
 }
 return true;
}


/*
  Book class
*/

//constants for the Book class
const int STR_MAX = 255, ISBN_LEN = 13;
const char* DEFAULT_TITLE = "\0";
const int DEFAULT_ISBN[] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
const char* DEFAULT_RENTER = "none";

class Book {
  friend ostream& operator<<(ostream& os, const Book& book);
  public:
	Book();
	Book(const char *title, const int *isbn=DEFAULT_ISBN, const char *renter=DEFAULT_RENTER); //default parameters in list
	Book(const Book &other_book);

	void SetTitle(const char* title);
	const char* GetTitle() const;
	void SetIsbn(const int* isbn);
	const int* GetIsbn() const;
	void PrintIsbn(ostream& os) const; //an additional helper function (not requested, but helps with code reuse)

	bool GetAvailable() const;
	const char* GetRenter() const;
	bool ReserveBook(const char* renter);
	bool FreeBook();
  private:
	char m_title[STR_MAX];
	int m_isbn[ISBN_LEN];
	bool m_available;
	char m_renter[STR_MAX];
};

Book::Book(){
  SetTitle(DEFAULT_TITLE); //code reuse - set the title to default
  SetIsbn(DEFAULT_ISBN); //code reuse - set the isbn to default
  FreeBook(); //code reuse - mark as free
}
Book::Book(const char *title, const int *isbn, const char *renter){
  SetTitle(title);
  SetIsbn(isbn);
  FreeBook();
  if (strcmp(renter,DEFAULT_RENTER)){ //code reuse - mark as free or as rented whether the user put in an actual renter name or left everything to the default parameter list value
    ReserveBook(renter);
  }
}
Book::Book(const Book &other_book){
  SetTitle(other_book.m_title);
  SetIsbn(other_book.m_isbn);
  FreeBook(); //custom copy constructor will make book copy but mark new object as free
}

void Book::SetTitle(const char* title){
  strcpy(m_title,title);
}
const char* Book::GetTitle() const{
  return m_title;
}
void Book::SetIsbn(const int* isbn){
  intcpy(m_isbn, isbn, ISBN_LEN);
}
const int* Book::GetIsbn() const{
  return m_isbn;
}
void Book::PrintIsbn(ostream& os) const{
  intprint(os, m_isbn, ISBN_LEN);
}

bool Book::GetAvailable() const{
  return m_available;
}
const char* Book::GetRenter() const{
  return m_renter;
}
bool Book::ReserveBook(const char* renter){
  if (!m_available || !strcmp(renter,DEFAULT_RENTER)){ //basic sanity check: is the book available? are we giving a valid name for the renter?
    return false;
  }
  else{
    strcpy(m_renter, renter);
    m_available = true;
  }
  return true;
}
bool Book::FreeBook(){
  if (m_available){ //basic sanity check: already available, why are we freeing?
    strcpy(m_renter, DEFAULT_RENTER); //for any case
    return false;
  }
  else{
    strcpy(m_renter, DEFAULT_RENTER);
    m_available = true;
  }
}
ostream& operator<<(ostream& os, const Book& book){
  os << book.m_title <<" ";
  book.PrintIsbn(os);
  os << " " << book.m_renter;
  return os;
}

/*
  Library class
*/

const int N_BOOKS = 1000;
const int DEFAULT_NATIONALID = -1;
const char* DEFAULT_LIBRARY = "invalid";

class Library {
 public:
  Library();
  Library(int nationalId, const char* name=DEFAULT_LIBRARY);

  int GetNationalId() const;
  void SetName(const char* name);
  const char* GetName() const;

  void PrintAll(ostream& os) const;
  void ListAvailableBooksByTitle(const char* title) const;
  bool RentBook(int book_index, const char* name);
  Book* FindOpenSpot();

  bool operator+(const Book& book);
 private:
  const int m_nationalId;
  char m_name[STR_MAX];
  Book m_inventory[N_BOOKS];
};

Library::Library() : m_nationalId(DEFAULT_NATIONALID){ //member is const, have to use initializer list for all constructors
  SetName(DEFAULT_LIBRARY);
}
Library::Library(int nationalId, const char* name) : m_nationalId(nationalId){ //member is const, have to use initializer list for all constructors
  SetName(name);
}

int Library::GetNationalId() const{
  return m_nationalId;
}
void Library::SetName(const char* name){
  strcpy(m_name,name);
}
const char* Library::GetName() const{
  return m_name;
}

void Library::PrintAll(ostream& os) const{
  const Book *m_inventory_Pt = m_inventory;
  for (int i=0; i<N_BOOKS; ++i){
    if ( strcmp(m_inventory_Pt->GetTitle(), DEFAULT_TITLE) )
    {
      os << *m_inventory_Pt << endl;
    }
    ++m_inventory_Pt;
  }
}
void Library::ListAvailableBooksByTitle(const char* title) const{
  const Book *m_inventory_Pt = m_inventory;
  for (int i=0; i<N_BOOKS; ++i){
    if ( !strcmp(m_inventory_Pt->GetTitle(), title) &&
	 m_inventory_Pt->GetAvailable() )
    {
      cout << i << "-th available Book: " << *m_inventory_Pt << endl;
    }
    ++m_inventory_Pt;
  }
}
bool Library::RentBook(int book_index, const char* name){
  Book *m_inventory_Pt = m_inventory;
  for (int i=0; i<book_index; ++i){
    ++m_inventory_Pt;
  }
  if (!strcmp(m_inventory_Pt->GetTitle(),DEFAULT_TITLE) || !strcmp(name,DEFAULT_RENTER)){ //basic sanity check, trying to rent an uninitialized book or wrong renter
    return false;
  }
  return m_inventory_Pt->ReserveBook(name);
}
Book* Library::FindOpenSpot(){
  Book *m_inventory_Pt = m_inventory;
  for (int i=0; i<N_BOOKS; ++i){
    if ( !strcmp(m_inventory_Pt->GetTitle(), DEFAULT_TITLE) ){
      return m_inventory_Pt;
    }
    ++m_inventory_Pt;
  }
  return NULL;
}
bool Library::operator+(const Book& book){
  Book* open_book_Pt = FindOpenSpot();
  if (open_book_Pt && //check for NULL (if FindOpenSpot didn't find an open position)
      strcmp(book.GetTitle(),DEFAULT_TITLE)) //check that the book we're passing is valid
  {
    *open_book_Pt = book;
    return true;
  }
  return false;
}


/*
  IO functions
*/
void importBooks(Library& library){
  ifstream fin("LibraryIndex.txt");
  while (!fin.eof()){
    char title[STR_MAX];
    fin >> title;
    char isbn_char[ISBN_LEN];
    fin >> isbn_char;
    const char *isbn_char_Pt = isbn_char;
    int isbn[ISBN_LEN];
    int *isbn_Pt = isbn;
    for (int i=0; i<ISBN_LEN; ++i){
      *isbn_Pt = *isbn_char_Pt-'0';
      ++isbn_Pt;
      ++isbn_char_Pt;
    }
    char renter[STR_MAX];
    fin >> renter;
    if (fin.eof()){
      break;
    }

    Book book(title,isbn,renter);
    library + book;
  }
  fin.close();
}
void exportBooks(Library& library){
  ofstream fout("LibraryIndexPost.txt");
  library.PrintAll(fout);
  fout.close();
}

int main(){
  Library delamare(895570262,"DeLaMare Science and Engineering Library");

  importBooks(delamare);
  delamare.PrintAll(cout);

  char searchTitle[STR_MAX];
  cout << endl << "What title are you looking for?" << endl;
  cin >> searchTitle;
  delamare.ListAvailableBooksByTitle(searchTitle);

  int bookIndex;
  cout << endl << "What library book index would you like to rent?" << endl;
  cin >> bookIndex;
  char renterName[STR_MAX];
  cout << "What is your name?" << endl;
  cin >> renterName;
  if (!delamare.RentBook(bookIndex,renterName)){
    cout << "Could not reserve this library book based on its index, are you sure it is available?" << endl;
  }

  exportBooks(delamare);

  return 0;

}
