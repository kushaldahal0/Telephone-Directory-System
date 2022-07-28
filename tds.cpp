#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<fstream>
#include<conio.h>
#include<string.h>




using namespace std;

class stud
{	
	char address[20];
    unsigned int ph_no;
	public:
	char name[20];
    
    

	    void get(void);
	    void show(void);
	    void modify(void);
};

void stud::get(void){

    int i=0;
    cout<<"\n\tEnter name -> ";
    cin.getline(name,20,'\n');
    cout<<"\n\tEnter address -> ";
    cin.getline(address,20,'\n');
    fflush(stdin);
    cout<<"\n\tEnter ph_no\t-> \t";
    cin>>ph_no;
    fflush(stdin);

}

void stud::show(void){
    cout<<"\n";
    cout<<"\tNAME      :"<<"\t"<<name<<"\n";
    cout<<"\tADDRESS   :"<<"\t"<<address<<"\n";
    cout<<"\tPh_No     :"<<"\t"<<ph_no<<"\n";
}

void stud:: modify(void){
	int i=0;
    cout<<"\n\tEnter new name -> ";
    cin.getline(name,20,'\n');
    cout<<"\n\tEnter new address -> ";
    cin.getline(address,20,'\n');
    fflush(stdin);
    cout<<"\n\tEnter new ph_no\t-> \t";
    cin>>ph_no;
    fflush(stdin);
	
}

int main(){
	stud s;
	char u;
M:	int choice;
	system("cls");
	cout<<"\t\t\t\t\tWelcome to phone directory\n";
	cout<<setw(101)<< setfill('-') <<'-'<<endl<<endl;
	cout<<"press any key from 1 to 6"<<endl;
	cout<<"1. To Add"<<endl;
	cout<<"2. To Show"<<endl;
	cout<<"3. To Search"<<endl;
	cout<<"4. To Modify"<<endl;
	cout<<"5. To Delete"<<endl;
	cout<<"6. To Exit"<<endl<<endl;
	cin>> choice;
	fflush(stdin);
	
	
	switch(choice){
		case 1:
		{
			//adding directory
			system("cls");
			cout<<"\t\t\t\t\tAdding to the Directory\n";
			cout<<setw(101)<< setfill('-') <<'-'<<endl<<endl;
			fstream file("record",ios::in|ios::out|ios::ate|ios::app|ios::binary);
			s.get();
			file.write((char *)&s,sizeof(stud));
			cout<<"file added!\n";
			file.close();
			cout<<"Do you want to continue(Y/N):- ";
			u = getch();
			if(u =='y'){
				goto M;
			}
			else{
				exit(1);
			}
			break;
		}
			
			
		case 2:
		{
			system("cls");
			cout<<"\t\t\t\t\tShowing Directory"<<endl;
			cout<<setw(101)<< setfill('-') <<'-'<<endl<<endl;
			fstream file("record",ios::in|ios::out|ios::ate|ios::app|ios::binary);
			file.seekg(0);
			int ctr=0;

            while(file.read((char *)&s,sizeof(s)) )
            {
                ctr++;
				cout<<ctr<<"."<<endl;
                if(ctr==8)
                {
                    getchar();
                    ctr=0;
                }
                s.show();

                if(file.eof()==1)
                {
                    break;
                }
            }
            cout<<"total "<<ctr<<" files"<<endl;
            file.close();
			cout<<"Do you want to continue(Y/N):- ";
			u = getch();
			if(u =='y'){
				goto M;
			}
			else{
				exit(1);
			}
			break;
		}	
			
			
			
		case 3:
		{
			char sname[20];
			system("cls");
			cout<<"\t\t\t\t\tSearch"<<endl;
			cout<<setw(101)<< setfill('-') <<'-'<<endl<<endl;
			fstream file("record",ios::in|ios::out|ios::ate|ios::app|ios::binary);
			file.seekg(0);
			cout<<"\n Enter  name  whose record to be search  :\t";
            cin.getline(sname,20,'\n');
            
            do
            {
                file.read((char *)&s,sizeof(s));
                if(file.eof()==1)
                {
                    break;
                }
                if(strcmp(s.name,sname)==0)
                {
                    s.show();
                }
            }
            while(file);
			file.close();
			
			cout<<"Do you want to continue(Y/N):- ";
			u = getch();
			if(u =='y'){
				goto M;
			}
			else{
				exit(1);
			}
			break;
		}	
			
			
		case 4:
		{
			int p ;
			char sname[20];
			system("cls");
			cout<<"\t\t\t\t\tModify Directory"<<endl;
			cout<<setw(101)<< setfill('-') <<'-'<<endl<<endl;
			fstream file("record",ios::in|ios::out|ios::binary);
			file.seekg(0);
			cout<<"\n Enter  name  whose record to be modified  :\t";
            cin.getline(sname,20,'\n');
            
            while(!file.eof()){
            	p = file.tellg();
            	file.read((char*)&s, sizeof(s));
            	if(file){
            		if(strcmp(s.name,sname)==0){
            			cout<<"current data\n";
            			s.show();
            			cout<<"update data\n";
            			s.modify();
            			file.seekp(p);
            			file.write((char*)&s,sizeof(s));
            			break;
					}
				}
            	
			}
			file.close();
			cout<<"Do you want to continue(Y/N):- ";
			u = getch();
			if(u =='y'){
				goto M;
			}
			else{
				exit(1);
			}
			break;
		}
			
			
		case 5:
		{
			int c;
			char sname[20];
			system("cls");
			cout<<"\t\t\t\t\tDelete Directory"<<endl;
			cout<<setw(101)<< setfill('-') <<'-'<<endl<<endl;
			ifstream fin("record",ios::in|ios::binary);
			fstream fout("temp",ios::out|ios::binary);
			cout<<"\n Enter  name  whose record to be deleted  :\t";
            cin.getline(sname,20,'\n');
            
            while(!fin.eof()){
            	fin.read((char *)&s,sizeof (stud));
            	if(fin){
				
                    if(strcmp(s.name,sname)==0)
                    {
                        cout<<"Data to be deleted:\n";
                        s.show();
                        c=1;
                        
                    }
                    else
                    {  
                        fout.write((char *)&s,sizeof(stud));
                    }
                }
            }
            fin.close();
            fout.close();
            if(c == 1)
            	cout<<"Data deleted!!......."<<endl;
            else
            	cout<<"Data not found!!....."<<endl;
            remove("record");
            rename("temp", "record");

			
			cout<<"Do you want to continue(Y/N):- ";
			u = getch();
			if(u =='y'){
				goto M;
			}
			else{
				exit(1);
			}
			break;
		}
			
			
		case 6:{
	
			system("cls");
			cout<<"\t\t\t\t\tEXITING\n";
			cout<<setw(101)<< setfill('-') <<'-'<<endl<<endl;
			cout<<"\t\t\t\t\tTHANK YOU";
				exit(1);
			break;
		}
			
			
		default:{
			
			cout<<"invalid output!";
			exit(1);

		}
	}
	
}
