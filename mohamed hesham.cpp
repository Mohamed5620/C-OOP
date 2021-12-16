//mohamed hesham mohamed abdelmenam
//sec:3          Bn:44
//seatnumber:31152
#include<iostream>
#include<fstream>
#include<string>
#include<cstdio>
using namespace std;
struct location{string city, resident;int zip ;} address;
const int n=6;                 //assume that the number of subjects is 6
class student{ 
private:
string fname,lname;            //first name and last name are required with no spaces
string dep;
int stnumber;
location address ;
float marks[n];
public:
	int rollno;
	student (){ rollno=0;}    //start the program with 0 students 

void insert(student s[10])   // insert function is used to start adding data or to add more to the text file
{system("cls");
string a,b,c,d,f; int roll,z,y,no; float q,w,e,r,t,u; int l=0;    // some variables to read the database feom th text file
fstream file;y=0; 
file.open("student.txt",ios::in); 
while(file>>roll>>z>>q>>w>>e>>r>>t>>u>>a>>b>>c>>d>>f){s[y].fname=a;s[y].lname=b;
s[y].dep=c;s[y].address.city=d;s[y].address.resident=f;s[y].stnumber=roll;s[y].address.zip=z;
s[y].marks[0]=q;s[y].marks[1]=w;s[y].marks[2]=e;s[y].marks[3]=r;s[y].marks[4]=t;
s[y].marks[5]=u;
y++;}rollno=y;              // storing the data to the class
file.close();cin.ignore();
while(l>=0){
cout<<"\n don't use spaces when entering the first name \n";
cout<<"\n enter the student first name     : ";
getline(cin,s[rollno].fname);
l=s[rollno].fname.find(" ");}l=0; 
while(l>=0){
cout<<"\n don't use spaces when entering the last name \n";
cout<<"\n enter the student last name      : ";
getline(cin,s[rollno].lname); 
l=s[rollno].lname.find(" ");}l=0;
while(l>=0){
cout<<"\n don't use spaces when entering the department name \n";
cout<<"\n enter the student department     : ";
getline(cin,s[rollno].dep); 
l=s[rollno].dep.find(" ");}l=0; s[rollno].dep.insert(0," ");
while(l>=0){
cout<<"\n don't use spaces when entering the city name \n";
cout<<"\n enter the student city           : ";
getline(cin,s[rollno].address.city);
l=s[rollno].address.city.find(" ");}l=0; 
while(l>=0){
cout<<"\n don't use spaces when entering the city name \n";
cout<<"\n enter the student residence      : ";
getline(cin,s[rollno].address.resident);
l=s[rollno].address.resident.find(" ");}l=0; 
cout<<"\n enter the student zip code       : ";cin>>s[rollno].address.zip;
cout<<"\n enter the id                     : ";cin>>s[rollno].stnumber;
label:
for(int j=0;j<rollno;j++)
if(s[rollno].stnumber==s[j].stnumber)
{cout<<"\n this id is already exist please enter a new one : ";
cin>>s[rollno].stnumber; goto label;}
cout<<"\n enter the student score in the 6 subjects by using spaces between them  \n";         // the maximum score in each subject is 100
for(int j=0;j<n;j++)
	cin>>s[rollno].marks[j];
file.open("student.txt",ios::out);no=0;                         //inserting the data to the file
while(file&&(no<=rollno)){
file<<s[no].stnumber <<"  ";
file<<s[no].address.zip<< "  ";
for (int m=0; m < n; m++)  
file<<s[no].marks[m]<<"   ";		
file<<s[no].fname<<" ";
file<<s[no].lname<<" ";
file<<s[no].dep <<" ";
file<<s[no].address.city <<" ";
file<<s[no].address.resident<<"\n";	no++;}  
file.close();
cout<<"\ninsert is seccessful\n";
}

void Grades(student s[10])                    //Grades function is used to calculate the total score and grade for any student by using the id
{system("cls");
string a,b,c,d,f; int roll,z,y,x; float q,w,e,r,t,u; int l=0;
ifstream file;
file.open("student.txt"); y=0;
while(file>>roll>>z>>q>>w>>e>>r>>t>>u>>a>>b>>c>>d>>f)       //reading the data from the text file and store it in the class
{s[y].stnumber=roll;
s[y].marks[0]=q;s[y].marks[1]=w;s[y].marks[2]=e;s[y].marks[3]=r;s[y].marks[4]=t;
s[y].marks[5]=u;  
y++;}
file.close();
float sum=0;int id;
double percentage;	
cout<<" enter the student id   : ";cin>>id;
	for(int j=0;j<10;j++)
		if(id==s[j].stnumber)
	     { x=j;  l=1; break;}                   //finding the correct id and store it's place in x
		if(l){
for(int m=0;m<n;m++) 
sum+=s[x].marks[m];                              
percentage=(sum/n);
	cout<<"\n the total score is "<<sum<<" out of 600 with percentage of "<<percentage<<endl;   
	if(percentage<50)
	cout<<"\n the studet grade is F \n";
	else if (percentage<65)
	cout<<"\n the studet grade is D \n";
	else if(percentage<75)
	cout<<"\n the studet grade is C \n";
	else if(percentage<85)
	cout<<"\n the studet grade is B \n";
	else  
	cout<<"\n the studet grade is A \n";
	return ;
	}
		else 
	cout<<"\n not found \n";}


void edit(student s[10])               //edit function is used to edit the data of a certain student
{system("cls");
string a,b,c,d,f; int roll,z,y,x; float q,w,e,r,t,u; int l=0,enter;int space=0;
fstream file;y=0;
file.open("student.txt",ios::in); 
while(file>>roll>>z>>q>>w>>e>>r>>t>>u>>a>>b>>c>>d>>f){s[y].fname=a;s[y].lname=b;
s[y].dep=c;s[y].address.city=d;s[y].address.resident=f;s[y].stnumber=roll;s[y].address.zip=z;
s[y].marks[0]=q;s[y].marks[1]=w;s[y].marks[2]=e;s[y].marks[3]=r;s[y].marks[4]=t;
s[y].marks[5]=u;
y++;}rollno=y;
file.close();
int j;
int id; cout<<" enter the student id : "; cin>>id;             //start the edit using the id
for(j=0;j<10;j++)
 if(id==s[j].stnumber)
 { x=j; l=1; break;}                                            
if(l){cout<<"\n if you want to change the student name enter any number if no enter 0\n";
cin>>enter;cin.ignore();
if(enter)
{while(space>=0){
cout<<"\n don't use spaces when entering the first name \n";
cout<<"\n enter the student first name     : ";getline(cin,s[x].fname);
space=s[x].fname.find(" ");}space=0; 
while(space>=0){
cout<<"\n don't use spaces when entering the last name \n";
cout<<"\n enter the student last name      : ";getline(cin,s[x].lname); 
space=s[x].lname.find(" ");}space=0; 
}
cout<<"\nif you want to change the student department enter any number if no enter 0\n";
cin>>enter;cin.ignore();
if(enter){while(space>=0){
cout<<"\n don't use spaces when entering the department name \n";
cout<<"\n enter the student department     : ";getline(cin,s[x].dep); 
space=s[x].dep.find(" ");}space=0; 
}
cout<<"\nif you want to change the student address enter any number if no enter 0\n";
cin>>enter;cin.ignore();
if(enter){
while(space>=0){
cout<<"\n don't use spaces when entering the city name \n";
cout<<"\n enter the student city           : ";getline(cin,s[x].address.city); 
space=s[x].address.city.find(" ");}space=0; 
while(space>=0){
cout<<"\n don't use spaces when entering the city name \n";
cout<<"\n enter the student residence      : ";getline(cin,s[x].address.resident); 
space=s[x].address.resident.find(" ");}space=0; 
cout<<"\n enter  the student zip code      : ";cin>>s[x].address.zip;cout<<endl;cout<<endl;}
cout<<"\nif you want to change the student id enter any number if no enter 0\n";
cin>>enter;
if(enter){
cout<<"\nenter the new id                : ";cin>>id;
label:
for(int j=0;j<rollno;j++)
if(id==s[j].stnumber)
{cout<<"\n this id is already exist please enter a new one : ";
cin>>id; goto label;}
s[x].stnumber=id;}
cout<<"\nif you want to change the student marks enter any number if no enter 0\n";
cin>>enter;if(enter){
cout<<"\nenter the new scores in the 6 subjects by using spaces between them  \n ";
for(int m=0;m<n;m++)
	cin>>s[x].marks[m]; }
cout<<"\nupadte is succsesful "<<endl; }
 else {cout<<"\nnot found \n"; return;}
file.open("student.txt",ios::out);j=0;          //write the data from the class to the text file with the new data
while(file&&(j<rollno)){
file<<s[j].stnumber <<"  ";
file<<s[j].address.zip<< "  ";
for (int m=0; m < n; m++)  
file<<s[j].marks[m]<<"   ";		
file<<s[j].fname<<" ";
file<<s[j].lname<<" ";
file<<s[j].dep << " ";
file<<s[j].address.city << " ";
file<<s[j].address.resident<<"\n";	j++;}  
file.close();
return ;
}


void search(student s[10])                         //search function is used to search for a certain student and display his data
{system("cls");
string a,b,c,d,f; int roll,z,y,x=0; float q,w,e,r,t,u; int l=0;
ifstream file;y=0; 
file.open("student.txt"); 
while(file>>roll>>z>>q>>w>>e>>r>>t>>u>>a>>b>>c>>d>>f){s[y].fname=a;s[y].lname=b;
s[y].dep=c;s[y].address.city=d;s[y].address.resident=f;s[y].stnumber=roll;s[y].address.zip=z;
s[y].marks[0]=q;s[y].marks[1]=w;s[y].marks[2]=e;s[y].marks[3]=r;s[y].marks[4]=t;
s[y].marks[5]=u;  
y++;}
file.close();
int choice; string firstname,lastname;  int id; int j;
cout<<"you can search by names or by id\n\n1.names\n\n2.id\n\nenter your choice:";
cin>>choice;
if (choice==1) {
cout<<"\nenter the student  name    :";                    // in searching by names you should enter the first an last name
cin>>firstname>>lastname;
for(j = 0; j < 10; j++) 
	if((firstname==s[j].fname)&&(lastname==s[j].lname)) {
cout<<"\n the student id is         : "<< s[j].stnumber << endl;
cout<<"\n the student department is : "<< s[j].dep << endl;
cout<<"\n the student lives in      : "<< s[j].address.city <<"  "<< s[j].address.resident<<endl;
cout<<"\n and the zipcode is        : "<< s[j].address.zip << endl;
cout<<"\n the student scores are    : ";
for(int m=0;m<n;m++) cout<<s[j].marks[m]<<"  ";
cout<<"\n_______________________________\n";l=1;}
	if(l) return ;
	else cout<<"\n not found\n";
}
else if (choice == 2) {
cout<<"\nenter the student id :";                                //start searching by id
cin>>id;
for(j=0;j<10;j++) 
if(id==s[j].stnumber){x=j;l=1;break;}
if(l){
cout<<"\n the student name is       : "<<s[x].fname<<"   "<<s[x].lname<<endl;
cout<<"\n the student department is : "<<s[x].dep << endl;
cout<<"\n the student address       : "<<s[x].address.city <<"  "<< s[x].address.resident <<endl;
cout<<"\n and the zipcode is        : "<<s[x].address.zip << endl;
cout<<"\n the student scores are    : ";
for(int m=0;m<n;m++) cout<<s[x].marks[m]<<"  ";
cout<<"\n_______________________________\n";
return; } 
else cout<<"\n not found \n";
}
else
{cout << "\n you have to choose between 1 and 2 only \n\n";
search(s);}
}			


void display(student s[10])                              // display function is used to display the data of all students in the class 
{system("cls");
string a,b,c,d,f; int roll,z,y; float q,w,e,r,t,u;
ifstream file;y=0;
file.open("student.txt"); 
while(file>>roll>>z>>q>>w>>e>>r>>t>>u>>a>>b>>c>>d>>f){s[y].fname=a;s[y].lname=b;
s[y].dep=c;s[y].address.city=d;s[y].address.resident=f;s[y].stnumber=roll;s[y].address.zip=z;
s[y].marks[0]=q;s[y].marks[1]=w;s[y].marks[2]=e;s[y].marks[3]=r;s[y].marks[4]=t;
s[y].marks[5]=u;  
y++;}
file.close();
for(int j=0;j<y;j++)
{
cout<<"\n student no "<<j+1<<" name is       : "<<s[j].fname<<"   "<<s[j].lname<<endl;
cout<<"\n student no "<<j+1<<" id is         : "<<s[j].stnumber<<endl;
cout<<"\n student no "<<j+1<<" department is : "<<s[j].dep << endl;
cout<<"\n student no "<<j+1<<" address is    : "<<s[j].address.city <<"  "<< s[j].address.resident <<endl;
cout<<"\n student no "<<j+1<<" zipcode is    : "<<s[j].address.zip << endl;
cout<<"\n_______________________________\n";	}
}

};

int main(){
student s[10];int i;int use=1;
while(use){
cout<<"1. insert a student into the system \n";
cout<<"2. calculate the total score and get grade of a student \n";
cout<<"3. display the students information\n";
cout<<"4. search for a student via id or his name \n";
cout<<"5. edit student details via their id number \n";
cout<<"\n choose the option number  :";
cin>>i;       	
switch(i)
{
case 1:{s->insert(s);cout<<"\n if you want to use this program one more time enter any number if no enter 0 :  ";cin>>use;system("cls");} break;
case 2:{s->Grades(s);cout<<"\n if you want to use this program one more time enter any number if no enter 0:   ";cin>>use;system("cls");} break;
case 3:{s->display(s);cout<<"\n if you want to use this program one more time enter any number if no enter 0:   ";cin>>use;system("cls");} break;
case 4:{s->search(s);cout<<"\n if you want to use this program one more time enter any number if no enter 0:   ";cin>>use;system("cls");}break;
case 5:{s->edit(s);cout<<"\n if you want to use this program one more time enter any number if no enter 0:  ";cin>>use;system("cls");} break;

default:{cout<<"\n if you want to use this program enter any number if no enter 0:  ";
cin>>use;system("cls");} break;}
} 
cout<<" thanks for using my program \n\n\n";
	return 0;}

// in testing the code if you want to make a new database you should use the insert function 
// or you can use this sample :
//111  11  100   100   90   80   90   80   mohamed hesham elctronics giza agouza
//222  22  90   90   90   90   90   90   moataz ibrahim computer giza haram
//333  33  100   80   70   100   80   70   hesham mohamed commuincation luxor aswan
//444  44  0   0   0   0   0   0   abdelrahman mohamed mechanics cairo masrelgdeda
// take them with the same type of writing and put them in text file called student