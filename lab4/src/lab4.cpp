//============================================================================
// Name        : lab4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<fstream>
#include<string.h>
#include<stdio.h>
using namespace std;
class student
{
private:string name;
  string usn;
  string branch;
  string sem;
  string buffer;
  int rrn_list[100];
  fstream f1;
  int count;
public:void pack ();
  void creat_rrn ();
  void search_rrn (int);
  void read ();
};
void
student::read ()
{


  cout << "in read";
  cout << "enter name";
  cin >> name;
  cout << "enter usn";
  cin >> usn;
  cout << "enter branch";
  cin >> branch;
  cout << "enter sem";
  cin >> sem;

}

void
student::pack ()
{

  string temp;
  int pos;
  count = 0;
  buffer = usn + '|' + name + '|' + branch + '|' + sem;
 // buffer += temp;
  f1.open ("rrn1.txt", ios::out | ios::app);
  pos = f1.tellg ();
  f1 << buffer << endl;
  rrn_list[++count] = pos;
  f1.close ();

}

void
student::search_rrn (int rrn_no)
{
  int pos = -1;
  f1.open ("rrn1.txt");
  pos = rrn_list[rrn_no];
  f1.seekp (pos, ios::beg);
  getline (f1, buffer);
  cout << "record is" << buffer;
  f1.close ();
}

void
student::creat_rrn ()
{
  int pos = 0;
  count=0;
  f1.open ("rrn1.txt", ios::in);
  while (!f1.eof ())
    {
      getline (f1, buffer);
      if (buffer.empty ())
	continue;
      pos = f1.tellg ();
      rrn_list[++count] = pos;
    }
  f1.close ();
}

int
main ()
{
  student s;
  string fname;
  int choice;
  int rrn_no = 0;
  s.creat_rrn ();
  while (1)
    {
      cout << "1.insert 2.search 3.modify\n";
      cout << "enter ur choice";
      cin >> choice;
      switch (choice)
	{
	case 1:
	  s.read ();
	  s.pack ();
	  break;
	case 2:
	  cout << "enter rrn\n";
	  cin >> rrn_no;
	  s.search_rrn (rrn_no);
	  break;




	default:
	  cout << "terminates";
	  //break;
	}
    }
  return 0;
}
