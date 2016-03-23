//============================================================================
// Name        : lab7.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class coseq
{
public:	
	string list1[100], list2[100];
	int count1, count2;

	void load_list();
	void sort_list();
	void match();
};

void coseq::load_list()
{
	fstream file,file1;
	int i;
	string name;
	count1=-1;count2=-1;
	file.open("name1.txt",ios::out);
	name.erase();
	while(1)
	{
		cout<<"Enter the list1 names  ";
		cin>>name;
		if(name=="0")
			break;
		name=name+'\n';
		file<<name;
	}
	file.close();
	file.open("name1.txt");
	while (!file.eof()){
		name.erase();		
		getline(file,name);		
		list1[++count1]=name;
		cout<<"\nlist "<<list1[count1];
		}
	file.close();

	file1.open("name2.txt",ios::out);
	name.erase();
	while(1)
	{
		cout<<"Enter the names for list2  ";
		cin>>name;
		if(name=="0")
			break;
		name=name+'\n';
		file1<<name;
	}
	file1.close();
	file1.open("name2.txt");
	while (!file1.eof())
	{
		name.erase();		
		getline(file1,name);		
		list2[++count2]=name;
		cout<<"\ninside"<<list2[count2];
	}
	
	file.close();
}

void coseq::sort_list()
{
	int i,j;
	string temp;	
	for (i=0;i<=count1;i++)
	{
	  for (j=i+1;j<=count1;j++)
	  {
		if (list1[i]>list1[j])
		{
		  temp=list1[i];
		  list1[i]=list1[j];
		  list1[j]=temp;
		}
	  }
	}

/*	for(i=0;i<=count1;i++)
	{
		cout<<"\nsorted list1 "<<list1[i];
	}*/
	for (i=0;i<=count2;i++)
	{
	  for (j=i+1;j<=count2;j++)
	  {
		if (list2[i]>list2[j])
		{
		  temp=list2[i];
		  list2[i]=list2[j];
		  list2[j]=temp;
		}
	  }
	}
/*	for(i=0;i<=count2;i++)
	{
		cout<<"\nsorted list2 "<<list2[i];
	}*/

}

void coseq::match()
{
	fstream file;
	int i=0,j=0;
	string name;
	file.open("name3.txt",ios::out);
	while (i<=count1 && j<=count2)
	{
		if (list1[i]==list2[j]) 
		{
			cout<<"\n"<<list1[i];
			name=list1[i]+'\n';
			file<<name;
			i++;
			j++;
		}
		if (list1[i] < list2[j]) i++;
		if (list1[i] > list2[j]) j++;
	}
	file.close();
}
	
	
int main()
{
	coseq c1;
	c1.load_list();
	c1.sort_list();
	c1.match();	
	return 0;
}	

