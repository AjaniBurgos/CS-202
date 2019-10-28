int strlen(char* string)
{
  int counter;
  while(*string != '\0')
  {
    counter++;
    string++;
  }
  return counter;
}
void strcpy(char* dest, char* src)
{
  while(*src != '\0')
  {
    *dest=*src;
    dest++;
    src++;
  }
  *dest='\0';
}
int strcmp(char* s1, char* s2)
{
  while(*s1 == *s2)
  {
    return *s1-*s2;
  }
  return *s1-*s2;
}
void intcpy(int* dest, int* src)
{
  for(int i=0;i<13;i++)
  {
    *dest=*src;
    dest++;
    src++;
  }
}
bool intcmp(int* int1, int* int2)
{
  for(int i=0;i<13;i++)
  {
    if(*int1!=*int2)
    {
      return false;
    }
  }
  return true;
}
void intprint(int* isbn)
{
  for(int i=0;i<13;i++)
  {
    cout << *isbn;
  }
}
