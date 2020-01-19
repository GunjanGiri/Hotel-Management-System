//--------------------HOTEL MANAGEMENT SYSTEM----------------------//
#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<dos.h>

class hotel
{
 int room_no;
 char name[30];
 char address[50];
 char phone[10];

 public:
 void main_menu();
 void add();
 void display();
 void rooms();
 void edit();
 int check(int);
 void modify(int);
 void delete_rec(int);
};

void hotel::main_menu()
{
 int choice;

 while(choice!=5)
 {
  clrscr();
  cout<<"\n\t\t\t\t*************";
  cout<<"\n\t\t\t\t* MAIN MENU *";
  cout<<"\n\t\t\t\t*************";
  cout<<"\n\n\n\t\t\t1.Book A Room";
  cout<<"\n\n\n\t\t\t2.Customer Record";
  cout<<"\n\n\n\t\t\t3.Rooms Allotted";
  cout<<"\n\n\n\t\t\t4.Edit Record";
  cout<<"\n\n\n\t\t\t5.Exit";
  cout<<"\n\n\t\t\tEnter Your Choice:";
  cin>>choice;
//--------------------2---------------------------//
switch(choice)
	{
	 case 1:add();
		break;
	 case 2:display();
		break;
	 case 3:rooms();
		break;
	 case 4:edit();
		break;
	 case 5:break;
	 default:
		{
		cout<<"\n\n\t\tWrong Choice!!!";
		cout<<"\n\n\t\tPress any Key to Continue!!!";
		getch();
		}
	 }
	}
       }
void hotel::add()
{
 clrscr();
 int r,flag;
 ofstream fout("Recordhms.data",ios::app);

 cout<<"\n Enter Customer Details";
 cout<<"\n**************************";
 cout<<"\n\n room no:";
 cin>>r;
 flag=check(r);

 if(flag)
 {
  cout<<"\n Sorry...!!!Room is already Booked";
 }
 else
 {
  room_no=r;
  cout<<"Name:";
  gets(name);
  cout<<"Address:";
  gets(address);
  cout<<"Phone No:";
  gets(phone);
//--------------------------------3-------------------------//
fout.write((char*)this,sizeof(hotel));
cout<<"\nRoom is booked!!!";
}
cout<<"\nPress any key to continue!!";
getch();
fout.close();
}
void hotel::display()
{
clrscr();
ifstream fin("Recordhms.dat",ios::in);
int r,flag;
cout<<"\nEnter room no:";
cin>>r;
while(!fin.eof())
{
fin.read((char*)this,sizeof(hotel));
if(room_no==r)
{
clrscr();
cout<<"\n*************************";
cout<<"\nCoustmer Details";
cout<<"\n*************************";
cout<<"\n\nRoom no:"<<room_no;
cout<<"\nName:"<<name;
cout<<"\nAddress:"<<address;
cout<<"\nPhone no:"<<phone;
flag=1;
break;
}
}
if(flag==0)
cout<<"\nSorry Room no. not found or vacant!!";
cout<<"\n\nPress any key to continue!!";
getch();
fin.close();
}
void hotel::rooms()
{
//------------------------------4------------------------//
clrscr();
ifstream fin("Recordhms.dat",ios::in);
cout<<"\n\t\t\tList of Rooms alloted";
cout<<"\n\t\t\t**********************";
cout<<"\n\nRoom No.\tName\t\tAddress\t\tPhone No.\n";

while(!fin.eof())
{
fin.read((char*)this,sizeof(hotel));
cout<<"\n\n"<<room_no<<"\t\t"<<phone;

}
cout<<"\n\n\n\t\t\tPress any key to continue!!" ;
getch();
fin.close();
}
void hotel::edit()
{
clrscr();
int choice,r;

cout<<"\n EDIT MENU";
cout<<"\n*********";
cout<<"\n\n1.Modify Custumer Record";
cout<<"\n2.Delete Custumer Record";
cout<<"\nEnter Your Choice: ";
cin>>choice;

clrscr();
cout<<"\nEnter room no.:";
cin>>r;

switch(choice)
{
 case 1:modify(r);
 break;
 case 2:delete_rec(r);
 break;
 default:cout<<"\n Wrong Choice!!";
}
//------------------------------5--------------------------//
cout<<"\n Press any key to continue!!!";
getch();
}
int hotel::check(int r)
{
int flag=0;
ifstream fin("Recordhms.dat",ios::in);
while(!fin.eof())
{
fin.read((char*)this,sizeof(hotel));
if(room_no==r)
{
flag=1;
break;
}
}
fin.close();
return(flag);
}
void hotel::modify(int r)
{
long pos,flag=0;
fstream file("Recorhms.dat",ios::in|ios::out|ios::binary);
while(!file.eof())
{
pos=file.tellg();
file.read((char*)this,sizeof(hotel));
if(room_no==r)
{
cout<<"\n Enter New Details";
cout<<"\n*****************";
cout<<"\n Name:";
gets(name);
cout<<"Address:";
gets(address);
cout<<"Phone no:";
gets(phone);
file.seekg(pos);
file.write((char*)this,sizeof(hotel));
//-----------------------------6--------------------//
cout<<"\n record is modified!!";
flag=1;
break;
}
}
if(flag==0)
 cout<<"\n sorry room no.not found or vacant!!";
 file.close();
}
void hotel::delete_rec(int r) //to delete the record
{
 int flag=0;
 char ch;
 ifstream fin("recordhms.dat",ios::in);
 ofstream fout("temp.dat",ios::out);

 while(!fin.eof())
 {
 fin.read((char*)this,sizeof(hotel));
 if(room_no==r)
 {
 cout<<"\n name:"<<name;
 cout<<"\n address:"<<address;
 cout<<"phone no:"<<phone;
 cout<<"\n\ndo you want to delete this record(y/n)";
 cin>>ch;
 if(ch=='n')
 fout.write((char*)this,sizeof(hotel));

 flag=1;
 }
 else
 fout.write((char*)this,sizeof(hotel));
 }
 fin.close();
 fout.close();

 if(flag==0)
  cout<<"\n sorry room no.not found or vacant!!";
//----------------------------7--------------------------//
else
{
remove("Recordhms.dat");
rename("template.dat","Recordhms.dat");
}
}
void main()
{
hotel h;
textmode(80);
textbackground(WHITE);
textcolor(RED);
clrscr();
cout<<"\n\t\t\t====*****************====";
cout<<"\n\t\t\t*HOTEL MANAGEMENT PROJECT*";
cout<<"\n\t\t\t====*****************====";
sleep(2);
cout<<"\n\n\n\n PRESENTED BY:";
sleep(2);
cout<<"\n\n\n\t1. Adya Arpeeta Devi";
cout<<"\n\t\t\t2. Adyasha Rout";
cout<<"\n\t\t\t3. Priyanka Padhana";
cout<<"\n\t\t\t4. Rashmirekha Soren ";
cout<<"\n\t\t\t5. Abhyudaya Patra ";
cout<<"\n\t\t\t6. Gunjan Giri";
cout<<"\n\t\t\t7. Sidharth Behera";
cout<<"\n\n\n\n\t\t\t\t\t Press any key to CONTINUE!!";
getch();
h.main_menu();
}





