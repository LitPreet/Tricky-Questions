
#include<iostream>
#include<string>
#include<fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct student
{
string stnumber;
string stname;
string gender;
double quizz1;
double quizz2;
double assignment;
double midterm;
double finalmarks;
double total;
double avg;
}students;

students obj[10];

void readRecordsintoStruture()
{
ifstream in("file.txt");

if(!in) {
	cout << "Cannot open input file - may be file not there in correct directory\n";
}

char str[500];
int row = 0;
while(in && row <10) {
	in.getline(str, 500);  // delim defaults to '\n'
	//if(in) cout << str << endl;
	//char *ptr = strtok_s (str," ,");
        char* context	= NULL;
        char *ptr = strtok_s(str,  ",", &context);
		
	if(ptr!= NULL) 
	{
	//read stnumber from file
	obj[row].stnumber = std::string(ptr); cout<<	obj[row].stnumber <<", " ;
	
	ptr = strtok_s (NULL,  ",", &context);
	//read stname form file
	obj[row].stname= std::string(ptr); cout<<	obj[row].stname <<", ";
	
	//ptr = strtok_s (NULL, ",");
	ptr = strtok_s (NULL,  ",", &context);
	//read gender form file
	obj[row].gender = std::string(ptr);cout<< obj[row].gender <<", ";
	
	//ptr = strtok_s (NULL, ",");
	ptr = strtok_s (NULL,  ",", &context);
	//read quizz1 form file
	obj[row].quizz1 = atof(ptr);cout<< obj[row].quizz1 <<", ";
	
	//ptr = strtok_s (NULL, ",");
	ptr = strtok_s (NULL,  ",", &context);
	//read quizz2 form file
	obj[row].quizz2 = atof(ptr);cout<<	obj[row].quizz2 <<", ";
	
	//ptr = strtok_s (NULL, ",");
	ptr = strtok_s (NULL,  ",", &context);
	//read assignment form file
	obj[row].assignment = atof(ptr);cout<< obj[row].assignment <<", ";
	
	//ptr = strtok_s (NULL, ",");
	ptr = strtok_s (NULL,  ",", &context);
	//read midterm form file
	obj[row].midterm = atof(ptr);cout<<	obj[row].midterm <<", ";
	
	//ptr = strtok_s (NULL, ",");
	ptr = strtok_s (NULL,  ",", &context);
	//read finalmarks form file
	obj[row].finalmarks = atof(ptr);cout<< obj[row].finalmarks <<", ";
	
	//ptr = strtok_s (NULL, ",");
	ptr = strtok_s (NULL,  ",", &context);
	//read total form file
	obj[row].total = atof(ptr);cout<< obj[row].total <<", \n";

	}
	
    row++;
}

in.close();
}

void printMaxMarkStudent()
{
float Totalmarks = 0;

for(int i = 0; i<10; i++)
{
  if(obj[i].total > Totalmarks)
  	Totalmarks = obj[i].total;
  	
}	
cout<<"\n Maximum marks : " << Totalmarks;

}

void deleteRecord(string stnumber)
{
    bool check = false;    
    for(int i = 0; i<9; i++)
    {
	if(obj[i].stnumber.compare(stnumber) == 0 || (check==true))
	 { check=true;
	obj[i].stnumber = obj[i+1].stnumber;
	obj[i].stname = obj[i+1].stname;
	obj[i].gender = obj[i+1].gender;
	obj[i].quizz1 = obj[i+1].quizz1;
	obj[i].quizz2 = obj[i+1].quizz2;
	obj[i].assignment = obj[i+1].assignment;
	obj[i].midterm = obj[i+1].midterm;
	obj[i].finalmarks = obj[i+1].finalmarks;
	obj[i].total = obj[i+1].total;
	}
    } 
}      
       
void calcualteStdAvg(string stnumber)
{ 
    for(int row = 0; row<10; row++)
    {   
	float avg = 0;
	
	avg = obj[row].total;
	avg = avg/5;
	
	cout<<"\n Avg of -"<<row+1<<" student is :"<<avg;           
	}
}

void stdWithNegativeMarks()
{
  for(int i = 0; i<10; i++)
    {
	 if(obj[i].total< 0)
	 {
	cout<<obj[i].stnumber;
	cout<<" , " <<obj[i].stname;
	cout<<" , " <<obj[i].gender;
	cout<<" , " <<obj[i].quizz1;
	cout<<" , " <<obj[i].quizz2 ;
	cout<<" , " <<obj[i].assignment ;
	cout<<" , " <<obj[i].midterm ;
	cout<<" , " <<obj[i].finalmarks ;
	cout<<" , " <<obj[i].total; 
	    }   
    } 
	
}
 
int main(int argc, char** argv) {
	
readRecordsintoStruture();

printMaxMarkStudent();

//calcualte avg  marks of any students  with stnumber 101
string  studentNumber= "101";
calcualteStdAvg(studentNumber);

stdWithNegativeMarks();

//delete record with stnumber with 102
studentNumber = "102";
deleteRecord(studentNumber);
	
return 0;
}
