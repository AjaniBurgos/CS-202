void strcpy(char* dest, char* src);
int strcmp(char* str1, char* str2);

class CarSensor
{
  public:
    CarSensor(){
      strcpy(m_type, (char*)"NULL");
      m_extracost=0.0;
      gps_cnt=0;
      camera_cnt=0;
      lidar_cnt=0;
      radar_cnt=0;
    }
    CarSensor(char* type, float extracost){

    }
    //CarSensor &sensors()
    void SetType(char* ){

    }
    void SetCost(){

    }
    char* GetType(){
      char* typptr = m_type;
      return typptr;
    }
    float GetCost(){
      return m_extracost;
    }
    int GetGPS(){
      return gps_cnt;
    }
    int GetCam(){
      return camera_cnt;
    }
    int GetLidar(){
      return lidar_cnt;
    }
    int GetRadar(){
      return radar_cnt;
    }
    void SetGPS(int gps){
      gps_cnt = gps;
    }
    void SetCam(int camera){
      camera_cnt = camera;
    }
    void SetLidar(int lidar){
      lidar_cnt = lidar;
    }
    void SetRadar(int radar){
      radar_cnt = radar;
    }
  private:
    char m_type[20];
    float m_extracost;
    static int gps_cnt;
    static int camera_cnt;
    static int lidar_cnt;
    static int radar_cnt;
};

class RentalCar
{
  public:
    int GetYear(){
      return m_year;
    }
    char* GetMake(){
      char* mptr = m_make;
      return mptr;
    }
    char* GetModel(){
      char* mptr = m_model;
      return mptr;
    }
    float GetPrice(){
      return m_baseprice;
    }
    float GetTank(){
      return m_tank;
    }
    bool GetAvailable(){
      return m_available;
    }
  //  RentalCar &cars();
  private:
    char m_make[20];
    char m_model[20];
    int m_year;
    float m_tank;
    CarSensor m_sensors[3];
    float m_baseprice;
    float m_finalprice;
    bool m_available;
    char m_owner[20];
};

class RentalAgency
{
  public:
    RentalAgency(){
      int* iptr = m_zipcode;
      strcpy(m_name, (char*)"NULL");
      for(int i=0;i<5;i++)
      {
        *iptr = 0;
        iptr++;
      }
    RentalCar();
    }
    void SetName(char* name){
      strcpy(m_name, name);
    }
    void SetZip(int* zip){
      int* iptr = m_zipcode;
      for(int i=0;i<5;i++)
      {
        *iptr = *zip;
        zip++;
        iptr++;
      }
    }
    char* GetName(){
      char* anptr = m_name;
      return anptr;
    }
    int* GetZip(){
      int* azptr = m_zipcode;
      return azptr;
    }
    RentalAgency(char* name, int* zip, RentalCar* cars){
      SetName(name);
      SetZip(zip);

    }
  private:
    char m_name[20];
    int m_zipcode[5];
    RentalCar m_inventory[5];
};
