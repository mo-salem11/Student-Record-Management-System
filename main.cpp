#include<iostream>
#include<fstream>
using namespace std;
void writing();
void deleting();
void searching();
class student{
public:
int age;
string name;
float gpa;
};
int main(){

int option;char t='y';
   do{
	cout<<"\n please enter option number to continue\n";
	cout<<"press 1 for new record insertion\n";
	cout<<"press 2 for record deletion\n";
	cout<<"press 3 for record searching\n";
	cout<<"press 4 if you want to close \n";
	cin>>(option);
	switch(option){
		case 1:{
			writing();
			break;
		}
		case 2:{
			deleting();
			break;

		}
		case 3:{
			searching();
			break;
		}
		case 4:{
		t='n';
		}



	}
}while(t=='y');
}


void writing(){
	student abc;
	cout<<"please enter the student name: ";
	cin>>abc.name;
	cout<<"please enter the student age: ";
	cin>>abc.age;
	cout<<"please enter the student gpa: ";
	cin>>abc.gpa;
	ofstream myfile;
	myfile.open("section.txt",ios::app|ios::out);
	myfile<<endl<<abc.name<<"          ";
	myfile<<abc.age<<"          ";
	myfile<<abc.gpa<<endl;
	myfile.close();

}




void deleting(){
string line, name;
cout<<"please enter the name of the file you want to delete ";
cin>>name;
ifstream myfile;
ofstream temp;
myfile.open("section.txt");
temp.open("temp.txt");
while(getline(myfile,line)){
   if(line.substr(0,name.size())!=name)
   {
   	  temp<<line<<endl;
   }
}
   cout<<"the record with the name "<<name<<" has been deleted "<<endl;
   myfile.close();
   temp.close();
   remove("section.txt");
   rename("temp.txt","section.txt");
}


void searching()
{
ifstream fileInput;
fileInput.open("section.txt");
string line,search;
bool check;
cout<<"please enter the term to search:";
cin>>search;
for(int curline=0;getline(fileInput,line);curline++)
{

  if(line.find(search)!=string::npos)
    {
	 cout<<"found "<<search<<" on line "<<curline<<endl;
     cout<<line<<endl;
     check=true;
     break;
    }
    else
    {
     check=false;

    }
}
if (check==false)
    {
       cout<<"error not found on file"<<endl;
       check=true;
   }


 }




























