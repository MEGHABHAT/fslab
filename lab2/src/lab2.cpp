//============================================================================
// Name        : lab2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//============================================================================
// Name        : prog.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<fstream>
#include<string.h>
using namespace std;
class student{
private:string name;
        string usn;
        string branch;
        string sem;
public:void pack(string fname);
       /*void unpack();
       void modify();
       int search();
       int delet();*/
       void read();
       //void write();
};

void student::read()
{


	cout<<"in read";
	cout<<"enter name";
	cin>>name;
	cout<<"enter usn";
	cin>>usn;
	cout<<"enter branch";
	cin>>branch;
	cout<<"enter sem";
	cin>>sem;

}
void student::pack(string fname)
{

	 string temp;
	 temp=usn+'|'+name+'|'+branch+'|'+sem;
	 temp.resize(100,'$');
	 ofstream f1(fname.c_str(),ios::app);
	 f1<<temp<<endl;
	 f1.close();

}
void student::search(string key,string fname)
{
	student s[10];
	int i=0,count=0;
	ifstream myf(fname.c_str());
	while(!myf.eof())
	{
		cout<<"in search";
		s[i].unpack(fname);
		if(key==s[i].usn)
		{
			cout<<"record found\n";
			cout<<s[i].usn<<"\t"<<s[i].name;
			break;

		}
		i++;
	}
	myf.close();
}

int main()
{ 	student s;
	string fname;
	int choice;


			  cout<<"enter the filename";
		       cin>>fname;
			   s.read();
			   cout<<"After read\n";
		      s.pack(fname);
		       /*break;
		//case 2:search();
		  //     break;

		//case 3:delet();
		    //   break;
		//case 4:modify();
		   //    break;
		default:cout<<"terminates";
		break;
		}
	}*/
		       return 0;
}
