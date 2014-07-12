#include <iostream>
#include <string>    // std::string
#include <fstream>
#include <algorithm>
#include <cctype>

using namespace std;

int main(int argc, char *argv[])
{
ifstream file;
file.open(argv[1]);
string lineBuffer;
while (!file.eof()) 
{
  getline(file, lineBuffer);
  if (lineBuffer.length() == 0)
    continue; //ignore all empty lines
  else 
  {
  	int arr[26];
  	for (int i = 0; i < 26; i++)
  	{
  		arr[i] = 0;
  	}
  	int subscript = 0;
   	for(int i = 0; i < lineBuffer.length(); i++)
    {
    	int condition_upper = ((int)lineBuffer.at(i) >= 65 && (int)lineBuffer.at(i) <= 90);
    	int condition_lower = ((int)lineBuffer.at(i) >= 97 && (int)lineBuffer.at(i) <= 122);
    	int condition = condition_upper || condition_lower;
    	if(!condition)
    		continue;
    	else if(isupper(lineBuffer.at(i)))
    	{
    		subscript = (int)(lineBuffer.at(i) - 'A');
    	}
    	else if(islower(lineBuffer.at(i)))
    		subscript = (int)(lineBuffer.at(i) - 'a');
      arr[subscript]++;
    }
    
    sort(arr, arr+26);
    reverse(arr, arr+26);
    int j = 26, i = 0, value = 0;
    while(arr[i] != 0)
    {
      value+=arr[i] * j;
      i++;
      j--;
    }
    cout << value << endl;
  }
}
return 0;
}