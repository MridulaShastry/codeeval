#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{

	ifstream file;
	file.open(argv[1]);
	string lineBuffer;
  int sum = 0;

while (!file.eof()) 
{
  getline(file, lineBuffer);
  if (lineBuffer.length() == 0)
    continue; //ignore all empty lines
  else 
  {
    int val = 0;
    istringstream(lineBuffer) >> val;
    sum+=val;
  } 
}
  cout << sum << endl;
	return 0;
}