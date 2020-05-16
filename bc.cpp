/****
bc.cpp was mostly used to combine all 12 bit binary numbers into one string


 ******/


#include <iostream>
#include <string>
using namespace std;

string binaryConvert(int num);
void checkLock(string code);
int main()
{
  string code = "";
  for(int i = 0; i < 4096; i++)
    {
      code +=  binaryConvert(i);

    }

  cout << "check" << endl;
  checkLock(code);

  return 0;
}

// used to convert regular numbes into binary numbers
string binaryConvert(int num)
{
  int mod;
  int quotient;
  string converted = "";
  string zeroes = "";

  mod = num % 2;
  converted =  to_string(mod) + converted;
  quotient = num / 2;

  while(quotient != 0)
    {
      mod = quotient % 2;
      converted = to_string(mod) + converted;
      quotient = quotient / 2;
    }

  //adds zeroes to the fron of the binary numbers

  if(converted.size() <= 12)
    {
      int numZero = 12 - converted.size();
      
      for(int i = 0; i < numZero; i++)
	{
	  zeroes += "0";
	}

      converted = zeroes + converted;
    }

  return converted;
}


//can be used to find if the code is within the 12 bit code is in the string
//was meant to be used for other things
void checkLock(string message)
{
  string pass = "111111111111";
  string ch = "";

  if(message.substr(0,12) == pass)
    cout << "Unlocked" << endl;
  else
    {
      cout << "we start" << endl;
      ch = message[0];
      message = message.substr(1);
      message += ch;
     

      while(message.substr(0,12) != pass)  
      {
	cout << message.substr(0,12) << endl;
	ch = message[0];
	message = message.substr(1);
	message += ch;	
      }
      
      cout << "Door unlocked with code" << message.substr(0,12) << endl; 
    }
}
