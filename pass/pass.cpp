class RentalCar
{
  public:
    RentalCar(char* = "blank", char* = "blank", int = 2000, float = 0.0, bool = 1);

    //overload the + operator to add to the base cost of the car (as a member function)
    void operator+(float extCost);
    //assignment operator
    RentalCar& operator=(const RentalCar &rhs);
  private:
    char m_make[20];
    char m_model[20];
    int m_year;
    float m_cost;
    bool m_available;
};

RentalCar::RentalCar(char* initMake, char* initModel, int initYear, float initPrice, bool initAvailable)
{

}
RentalCar& RentalCar::operator=(const RentalCar &rhs)
{
  if(this != &rhs)
  {
    this->m_year=rhs.m_year;
    m_cost=rhs.m_cost; /*These two do the same thing, this-> is implicitly done*/
    m_available=rhs.m_available;
    strcpy(m_make, rhs.m_make);
    strcpy(m_model, rhs.m_model);
  }
  return *this;
}

void RentalCar::operator+(float extCost)
{
  if(extCost >= 0.0)
  {
    m_price+=extCost;
  }
}

int main()
{
  RentalCar myCar, yourCar, otherCar;
  RentalCar *carPtr = NULL;
  carPtr = &myCar;

  myCar = *carPtr; /*This is bad because we're trying to take out and put the value back in (myCar=myCar)*/

  myCar = yourCar = otherCar; /*Evaluates your=other, and then my=the result*/
  cout << myCar; /*This doesn't work since the member object is on the right side*/
  fin >> myCar; /*This doesn't work since the member object is on the right side*/
  return 0;
}
