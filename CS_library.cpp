

#include<limits>
#include<cstdio>
#include<iostream>
#include<fstream>
#include<string.h>
#include<stdio.h>
//#include<CONIO.h>
#include<string>
#include<iomanip>
#include<stdlib.h>
using namespace std;
class Library
{
    const string t = "Sushil";
   // string Sname;
    char Sname[20];
    int Sid;
    long int Phno;
    //string Bname;
    //string Btitle;
    char Bname[20];
    char Bartr[20];
    int Bid;
    int noofBook=0;
    string Ibid;
    string Isid;

public:
    static void Style()
    {   cout<<__DATE__"\t"<<__TIME__<<endl<<endl;
        cout<<"\t\t\t*********** CS Library ***********\n";
        for(int i=0;i<1;i++)
        cout<<"-----------------------------------------------------------------------------\n";
    }
    int  Password();
    void AddStudent();
    void StoreStudentdata();
    void ShowStudent();
    void Searchstudent();
    void Searchstudent(int );
    void UpdateStudent();
    void RemoveStudent();
    void ShowBook();
    void AddBook();
    void StoreBookdata();
    void RemoveBook();
    void SearchBook();
    int  SearchBook(int );
    void IsuzuBook();
    void UpdateBook();
    void Printstudentdata();
    void Printbookdata();
    void ShowIsuzu();
    void Search();
};
 int Library::Password()
 {
    string paswd;
    string hold;
 int count=3;
 for(int i=0;i<3;i++)
 {
  cout<<"\nEnter Library Password:";
  getline(cin ,paswd);
    if( paswd == t)
      {
       i=4;
        return 1;
       }
    else
        {
            if(i<2)
               cout<<"\n Try again";
             else
             {
              cout<<"Wrong password";
              exit(0);
             }
          }
        }

 }


  void Library::StoreStudentdata()
  {
    ofstream F;
    F.open("csstudentdata.txt", ios::app);
    if(!F)
     cout<<"File not found";
     else
    F.write((char *)this , sizeof(*this));
    F.close();
}
  void Library::AddStudent()
  {
    cout<<"Enter Student id:";
    //cin.ignore();
    cin>>Sid;
   while(cin.fail()) {
        cout << "Error:only number input" << endl;
        cin.clear();
        cout<<"Enter Student id : ";
        cin.ignore(256,'\n');
        cin >> Sid;
        }
        while(Sid<=1000 )
        {
            cout<<"Error:id 1000 t0 9999\n";
            cin.clear();
            cout<<"Enter Student id : ";
            cin>>Sid;
        }
         while(Sid>=9999)
         {
             cout<<"Error:id 1000 t0 9999\n";
            cin.clear();
            cout<<"Enter Student id : ";
            cin>>Sid;
         }
    cout<<"Enter Student Name:";
    //getline(cin, Sname);
    cin.ignore();
    cin.get(Sname,20 );
    while(strlen(Sname)<=3)
    {
        cout<<"Error:name size > =3 \nEnter Student name : ";
        cin.ignore();
        cin.get(Sname, 20);
    }
    cout<<"Enter Phone Number:";
    cin.ignore();
    cin>>Phno;
     while(cin.fail()) {
        cout << "Error:only number input" << endl;
        cin.clear();
        cout<<"Enter Phone Number  : ";
        cin.ignore(256,'\n');
        cin >> Phno;
        }
    while(Phno<1000000000)
     {
         cout<<"\nError: not valid number\nEnter Phone number:";
            cin>>Phno;

     }
        while(Phno>9999999999)
                {
                   cout<<"\nError: not valid number\nEnter Phone number:";
                    cin>>Phno;
                }
           // cout<<"\nThis is not valid number\nEnter Phone number:";
            //cin>>Phno;
      //}
    StoreStudentdata();
  //}
}

 void Library::Printstudentdata()
 {
    //Search();
    cout<<  Sid <<setw(25)<< Sname <<setw(20)<< Phno<<endl  ;// clrscr(1);
    /*ifstream F;
     string l;
     F.open("csstudentdata.dat", ios::in);
     if(!F)
      cout<<"\n File not found";
      else
      {
        l = F.get();
     while(!F.eof())
     {
        l=  F.get();
        cout<<l;
     }
     F.close();
  }*/
 }
 void Library::ShowStudent()
 {
   // delete  this;
     ifstream F;
     F.open("csstudentdata.txt", ios::in|ios::binary);
     if(!F)
      cout<<"\n File not found";
      else
     {
         F.read((char*)this , sizeof(*this));
         cout<<"Student id"<<setw(22)<<"NAME"<<setw(20)<<"Phone_no.\n";
         cout<<"____________________________________________________\n";
       while(!F.eof())
        {
           Printstudentdata();
            F.read((char*)this , sizeof(*this));

        }
     F.close();
 }
}

void Library::Searchstudent()
{
    int id,count=0;
    //char searchname[20];
    cout<<"\n Enter Student id: ";
    //cin.ignore();
    cin>>id;
   // cin.get(searchname,20);
    while(cin.fail()) {
        cout << "Error:only number input" << endl;
        cin.clear();
        cout<<"Enter Student id : ";
        cin.ignore(256,'\n');
        cin >> id;
        }
    ifstream f;
    f.open("csstudentdata.txt");
    if(!f)
     cout<<"\n file not found";
     else
     {
      f.read((char*)this , sizeof(*this));
    while(!f.eof())
    {
    // if(strcmp(Sname ,searchname))
      if(Sid == id)
      {
        cout<<endl;
         Printstudentdata();
         count++;
         }
        f.read((char*)this , sizeof(*this));
     }
     if(count ==0)
     cout<<"\n No Record Found";
     }
     f.close();

}

void Library::Searchstudent(int x)
{
    int id,count=0;
    //char searchname[20];
    cout<<"\n Enter Student id: ";
    //cin.ignore();
    cin>>id;
   // cin.get(searchname,20);
    while(cin.fail()) {
        cout << "Error:only number input" << endl;
        cin.clear();
        cout<<"Enter Student id : ";
        cin.ignore(256,'\n');
        cin >> id;
        }
    ifstream f;
    f.open("csstudentdata.txt");
    if(!f)
     cout<<"\n file not found";
     else
     {
      f.read((char*)this , sizeof(*this));
    while(!f.eof())
    {
    // if(strcmp(Sname ,searchname))
      if(Sid == id)
      {
        cout<<endl;
         Printstudentdata();
         cout<<"\n\t\t --.Book Isuzu.--.\n\n";
         count++;
         }
        f.read((char*)this , sizeof(*this));
     }
     if(count ==0)
     {
     cout<<"\n Your are not Student of CS Library\n";
      exit(1);
      }
     }
     f.close();

}



 void Library::UpdateStudent()
 {
    int id,c=0;
    fstream f;
    f.open("csstudentdata.txt",ios::in|ios::out|ios::ate);
     f.seekg(0);
    if(!f)
     cout<<"file is not found \n";
     else
     {
        cout<<"Enter Student id : ";
        cin>>id;
     // cin.get(searchname,20);
        while(cin.fail()) {
        cout << "Error:only number input" << endl;
        cin.clear();
        cout<<"Enter Student id : ";
        cin.ignore(256,'\n');
        cin >>id;
        }

        f.read((char*)this, sizeof(*this));
        while(!f.eof())
        {
            if(Sid == id)
            {
                c= 1;
                cout<<"\n Enter new Record \n";
                 f.seekp( f.tellp()-sizeof(*this));
                AddStudent();

                f.write((char*)this , sizeof(*this));
                break;
            }

            f.read((char*)this , sizeof(*this));
        }

         if(c==0)
         cout<<"no record found ";
    }
        f.close();

 }


void Library::RemoveStudent()
{   int id;
    ifstream f;
    ofstream F;
    f.open("csstudentdata.txt");
    if(!f)
    {
        cout<<"\n File not found";
    }
    else
    {
    F.open("tempStudent.txt");
    cout<<"Enter Student id:";
    cin>>id;
     while(cin.fail()) {
        cout << "Error:only number input" << endl;
        cin.clear();
        cout<<"Enter Student id : ";
        cin.ignore(256,'\n');
        cin >>id;
        }
     f.read((char*)this , sizeof(*this));
     while(!f.eof())
     {
        if(!(Sid == id))
            F.write((char*)this , sizeof(*this));
            f.read((char*)this , sizeof(*this));
     }
     f.close();
     F.close();
     remove("csstudentdata.txt");
     rename("tempStudent.txt","csstudentdata.txt");
     }
     cin.ignore();
}

void Library::AddBook()
  {
    cout<<"Enter Book id : ";
    cin>>Bid;
    while(cin.fail()) {
        cout << "Error:only number input" << endl;
        cin.clear();
        cout<<"Enter Book id : ";
        cin.ignore(256,'\n');
        cin >> Bid;
        }
         while(Bid<=10000 )
        {
            cout<<"Error:id 1000 t0 9999\n";
            cin.clear();
            cout<<"Enter Student id : ";
            cin>>Bid;
        }
         while(Bid>=99999)
         {
             cout<<"Error:id 1000 t0 9999\n";
            cin.clear();
            cout<<"Enter Student id : ";
            cin>>Bid;
         }
    cout<<"Enter Book Name : ";
    //getline(cin, Sname);
    cin.ignore();
    cin.get(Bname,20 );
    cout<<"Enter Author Name : ";
    cin.ignore();
    cin.get(Bartr,20);
    while(strlen(Bartr)<2)
    {
        cout<<"This is not valid name \nEnter Aurthor Name : ";
        cin.ignore();
         cin.get(Bname,20 );
    }
    cout<<"Enter No.of copy Book : ";
    cin.ignore();
    cin>>noofBook;
     while(cin.fail()) {
        cout << "Error:only number input" << endl;
        cin.clear();
        cout<<" Enter No.of Same Book : ";
        cin.ignore(256,'\n');
        cin >> noofBook;
        }
    StoreBookdata();
    cin.ignore();
  }

   void Library::Printbookdata()
 {
    // clrscr(1);
    cout<<  Bid <<setw(22)<< Bname <<setw(20)<< Bartr<<setw(12)<<noofBook<<endl ; //clrscr(1);
    /*ifstream F;
     string l;
     F.open("csstudentdata.dat", ios::in);
     if(!F)
      cout<<"\n File not found";
      else
      {
        l = F.get();
     while(!F.eof())
     {
        l=  F.get();
        cout<<l;
     }
     F.close();
  }*/
 }

   void Library::StoreBookdata()
  {
    ofstream F;
    F.open("csbookdata.txt", ios::app);
    if(!F)
     cout<<"File not found";
     else
    F.write((char *)this , sizeof(*this));
    F.close();
}

void Library::ShowBook()
{
    ifstream F;
     F.open("csbookdata.txt", ios::in|ios::binary);
     if(!F)
      cout<<"\n File not found";
      else
     {
         F.read((char*)this , sizeof(*this));
         cout<<"Book id "<<setw(20)<<"NAME "<<setw(20)<<"Aurthor"<<setw(15)<<"Av_Book \n";
         cout<<"_________________________________________________________________\n";
       while(!F.eof())
        {
            Printbookdata();
            F.read((char*)this , sizeof(*this));
        }
     F.close();
 }
}


void Library::SearchBook()
{
    int id,count = 0;
   // char searchname[20];
    cout<<"\n Enter Book id : ";
   cin>>id;
    //cin.get(searchname,20);
     while(cin.fail()) {
        cout << "Error:only number input" << endl;
        cin.clear();
        cout<<"Enter Book id : ";
        cin.ignore(256,'\n');
        cin >>id;
        }
    ifstream f;
    f.open("csbookdata.txt");
    if(!f)
        cout<<"\nfile not found";
     else
     {
        f.read((char*)this , sizeof(*this));
    while(!f.eof())
    {

    // if(strcmp(Sname ,searchname))
    if(Bid == id)
     {
        count++;
         Printbookdata();
     }
        f.read((char*)this , sizeof(*this));
     }
     if(count == 0)
         cout<<" No Record Found \n";
         }
     f.close();
}

int Library::SearchBook(int x)
{
    int id,count = 0;
   // char searchname[20];
    cout<<"\n Enter Book id : ";
   cin>>id;
    //cin.get(searchname,20);
     while(cin.fail()) {
        cout << "Error:only number input" << endl;
        cin.clear();
        cout<<"Enter Book id : ";
        cin.ignore(256,'\n');
        cin >>id;
        }
    ifstream f;
    f.open("csbookdata.txt");
    if(!f)
        cout<<"\nfile not found";
     else
     {
        f.read((char*)this , sizeof(*this));
    while(!f.eof())
    {

    // if(strcmp(Sname ,searchname))
    if(Bid == id)
     {
        count++;
         cout<<"\n Your Book is found\n";
         Printbookdata();
         return 1;
     }
        f.read((char*)this , sizeof(*this));
     }
     if(count == 0)
      {
         cout<<" No Record Found \n";
         // break ;
         return 0;
         }
         }
     f.close();
}


 void Library::UpdateBook()
 {
    int id,c=0;
    fstream f;
    f.open("csbookdata.txt",ios::in|ios::out|ios::ate);
     f.seekg(0);
    if(!f)
     cout<<"file is not found \n";
     else
     {
        cout<<"Enter Book id : ";
        cin>>id;
     // cin.get(searchname,20);
        while(cin.fail()) {
        cout << "Error:only number input" << endl;
        cin.clear();
        cout<<"Enter Student id : ";
        cin.ignore(256,'\n');
        cin >>id;
        }

        f.read((char*)this, sizeof(*this));
        while(!f.eof())
        {
            if(Bid == id)
            {
                c= 1;
                AddBook();
               f.seekp( f.tellp()-sizeof(*this));
                f.write((char*)this , sizeof(*this));
                break;
            }

            f.read((char*)this , sizeof(*this));
        }

         if(c==0)
         cout<<"\n no record found ";
    }
        f.close();

 }

void Library::RemoveBook()
{   int id;
    ifstream f;
    ofstream F;
    f.open("csbookdata.txt");
    if(!f)
    {
        cout<<"\n File not found";
    }
    else
    {
    F.open("tempStudent.txt");
    cout<<"Enter Book id:";
    cin>>id;
     while(cin.fail()) {
        cout << "Error:only number input" << endl;
        cin.clear();
        cout<<"Enter Student id : ";
        cin.ignore(256,'\n');
        cin >> id;
        }
     f.read((char*)this , sizeof(*this));
     while(!f.eof())
     {
        if(!(Bid == id))
            F.write((char*)this , sizeof(*this));
            f.read((char*)this , sizeof(*this));
     }
     f.close();
     F.close();
     remove("csbookdata.txt");
     rename("tempStudent.txt","csbookdata.txt");
     }
     cin.ignore();
}

 void Library::IsuzuBook()
 {
    int i[100],j[100];
    fstream FILE;
    FILE.open("isuzudata.txt",ios::out);
    //F.open("csbookdata.txt");
   if( SearchBook(0))
   {
     Searchstudent(0);
      if(!FILE)
     cout<<"File not found";
     else
      {
            FILE.write((char*)this , sizeof(*this));

     }

   }
    FILE.close();
  }

  void Library::ShowIsuzu()
  {

  ifstream f;
    f.open("isuzudata.txt",ios::out|ios::in);
    if(!f)
    cout<<"\n File not found\n";
    else
    {
   // if(Sid ==0 || Bid ==0)
    //{
       // cout<<"\n No record\n";
     //}
     //else
     //{
   f.read((char*)this , sizeof(*this));
   cout<<"Student id \t "<<"Student name\t "<<"Book id \t"<<"Book name\n";
   cout<<Sid<<"\t\t"<<Sname<<"\t"<<Bid<<"\t\t"<<Bname<<endl;
   while(!f.eof())
   {
     cout<<Sid<<"\t\t"<<Sname<<"\t"<<Bid<<"\t"<<Bname<<endl;
     f.read((char*)this , sizeof(*this));
  // }
   }
   }
   f.close();
 }

/*void Library::Search()
{
   // int round,i;
  /* string line;
   int size(0);
   ifstream f;
   f.open("csstudentdata.txt");
   f.seekg(0,ios::beg);
	while(getline(f,line))
			{size++;}
		f.clear();
	f.seekg(0,ios::beg);
	for(int i=0;i<size;i++)
	{
		f>>Sid[i];
	}
   for(int a=0;a<5;a++)
	{
		for(int b=a+1;b<5;b++)
		{
			if(Sid[b]<Sid[a])
			{
				int tmp;
				tmp=Sid[a];
				Sid[a]=Sid[b];
				Sid[b]=tmp;
			}
		}
	}

*/

int main()
{
 Library::Style();
 Library s,b;
 if(s.Password())
 {
 system("clear");
{
 int swiloop;
 //cin.ignore();
  while(1){
            Library::Style();
        cout<<"\n \t \tEnter your choice:\n";
        cout<<"\n\t1. Show Student Details \n\t2. Add Student \n\t3. Search Student \n\t4. Update Student Data \n\t5. Remove Student \n\t6. Show Book Details \n\t7. Add Book";
        cout<<"\n\t8. Search Book   \n\t9. Isuzu Book \n\t10. Update Book Data\n\t11. Remove Book \n\t12. Show Isuzu Book\n\t13. Exit\n ";
         cin>>swiloop;
         cin.ignore();
          while(cin.fail()) {
        cout << "Error:only number input" << endl;
        cin.clear();
        cout<<"\n  Enter your choice:";
        cin.ignore(256,'\n');
        cin >>swiloop;
        }
        system("clear");
    switch(swiloop){
            case 1:
                 b.ShowStudent();
                break;
            case 2:
                 b.AddStudent();
                break;
            case 3:
                b.Searchstudent();
                break;
           case 4:
                b.UpdateStudent();
                break;
            case 5:
                b.RemoveStudent();
                break;
            case 6:
               b.ShowBook();
                break;
            case 7:
                b.AddBook();
                break;
            case 8:
                b.SearchBook();
                break;
            case 9:
               b.IsuzuBook();
               break;
              case 10:
                b.UpdateBook();
                break;
           case 11:
                b.RemoveBook();
                break ;
            case 12:
                b.ShowIsuzu();
                break;
            case 13:
                    cout<<"\n\n\n\n\t\t\t** Thank You **\n\n\n\n";
                exit(0);
            default:
                cout<<"\n Wrong choice";

    }
   cin.get();
   system("clear");
  }
}
}
   return 0;
}



