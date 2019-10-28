const int STR_LEN = 20;

void strcpy(char* dest, char* src); /*Copies 1 string to another*/

class RentalCar
{
  public:
    void SetYear(int temp_year){
      m_year = temp_year;
    }
    void SetMake(char temp_make[STR_LEN]){
      strcpy(m_make,temp_make);
    }
    void SetModel(char temp_model[STR_LEN]){
      strcpy(m_model,temp_model);
    }
    void SetPrice(float temp_price){
      m_price = temp_price;
    }
    void SetAvailable(bool temp_available){
      m_available = temp_available;
    }
    int GetYear(){
      return m_year;
    }
    char* GetMake(){
      char* make = m_make;
      return make;
    }
    char* GetModel(){
      char* model = m_model;
      return model;
    }
    float GetPrice(){
      return m_price;
    }
    bool GetAvailable(){
      return m_available;
    }
  private:
    int m_year;
    char m_make[STR_LEN];
    char m_model[STR_LEN];
    float m_price;
    bool m_available;
};

struct RentalAgency
{
  char agency_name[STR_LEN];
  int zipcode[5];
  RentalCar inventory[5];
};
