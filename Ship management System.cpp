#include <iomanip>
#include <iostream>
#include <string.h>
#include <Windows.h>
#include<conio.h>
#include <bits/stdc++.h>
#include<vector>
using namespace std;

bool check(char []);
bool check_alphabet(char []);

pair<int,string> p1(0,"India");
pair<int,string> p2(1,"Singapore");
pair<int,string> p3(2,"Germany");
pair<int,string> p4(3,"Kenya");
pair<int,string> p5(4,"Canada");
vector<vector<int> > g;


struct passenger
{								//Structure of passenger is made to store passenger's attributes.
	int ticketno;
	char name[20];
	char passport[10];
	char cell[10];
	char ship[20];
	char address[40];
	struct passenger *nextname;
	struct passenger *nextship;
	struct passenger *nextno;
};

class sms
{
    int ticket_number;

    struct passenger *fl[9];
    struct passenger *ml[2];
public:
    sms()
    {
        ticket_number=0;
        ml[0]=NULL;        //name
        ml[1]=NULL;       //ticket
        fl[0]=fl[1]=fl[2]=fl[3]=fl[4]=fl[5]=fl[6]=fl[7]=fl[8]=NULL;
    }
    int ret_tick_no()
    {
        return ticket_number;
    }

    void gotoxy(int x, int y)
	{
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}

	void printpath(vector<int>& path, int b)
    {
        int price = 0;
        int ship_rate[5][5]={ {0,1500,0,0,2500},
                        {5000,0,3000,0,0},
                        {0,0,0,1700,0},
                        {0,0,1900,0,1800},
                        {2100,0,2200,0,0},
                      };
        int size = path.size();
        cout<<"    "<<b<<". ";
        for (int i=0; i<path.size()-1;i++)
            {
                    price = price + ship_rate[path[i]][path[i+1]];
            }
        for (int i = 0; i < size; i++)
        {
            if(path[i]==p1.first)
            {
                cout<<p1.second<<" ";
            }
            else if(path[i]==p2.first)
            {
                cout<<p2.second<<" ";
            }
            else  if(path[i]==p3.first)
            {
                cout<<p3.second<<" ";
            }
            else if(path[i]==p4.first)
            {
                    cout<<p4.second<<" ";
            }

            else if(path[i]==p5.first)
            {
                    cout<<p5.second<<" ";
            }
            cout<<"-->";
        }
        cout<<"    Price of the ticket "<<price;
           // cout << path[i] << " ";
        cout << endl;
    }

    // utility function to check if current
    // vertex is already present in path
    int isNotVisited(int x, vector<int>& path)
    {
        int size = path.size();
        for (int i = 0; i < size; i++)
            if (path[i] == x)
                return 0;
        return 1;
    }

    // utility function for finding paths in graph
    // from source to destination
    vector<vector<int> > findpaths(vector<vector<int> >&g, int src,
                                     int dst, int v)
    {
        vector<vector<int> > pa;
        int b=0;
        // create a queue which stores
        // the paths
        queue<vector<int> > q;

        // path vector to store the current path
        vector<int> path;
        path.push_back(src);
        q.push(path);
        while (!q.empty()) {
            path = q.front();
            q.pop();
            int last = path[path.size() - 1];

            // if last vertex is the desired destination
            // then print the path
            if (last == dst)
            {
                printpath(path, ++b);
                pa.push_back(path);
            }


            // traverse to all the nodes connected to
            // current vertex and push new path to queue
            for (int i = 0; i < g[last].size(); i++) {
                if (isNotVisited(g[last][i], path)) {
                    vector<int> newpath(path);
                    newpath.push_back(g[last][i]);
                    q.push(newpath);
                }
            }
        }
        return pa;
    }

	void enqueue(char nm[],char pp[],char cl[],char flt[],char adrs[], int tick)
	{
	    struct passenger *temp;
	    temp=new passenger;
	    temp->ticketno=tick;
        strcpy(temp->name,nm);
        strcpy(temp->passport,pp);
		strcpy(temp->cell,cl);
		strcpy(temp->ship,flt);
		strcpy(temp->address,adrs);
		temp->nextname=NULL;
		temp->nextship=NULL;
		temp->nextno=NULL;
        //Ticket  No insertion starts
        if (ml[1]==NULL)
        {
            ml[1]=temp;
        }
        else
        {
            struct passenger *p=ml[1];
            if (p->ticketno > temp->ticketno)
            {
                temp->nextno=ml[1];
                ml[1]=temp;
            }
            else
            {
                while (p->ticketno < temp->ticketno && p->nextno!=NULL)
                {
                    p=p->nextno;
                }
                if (p->nextno!=NULL)
                {
                    temp->nextno=p->nextno;
                    p->nextno=temp;
                }
                else
                {
                    p->nextno=temp;

                }
            }
        }
        //Ticket No insertion ends
        //Name insertion starts
        if (ml[0]==NULL)
        {
            ml[0]=temp;
        }
        else
        {
            struct passenger *p=ml[0];
            if (strcmp(p->name,temp->name)>0)
            {
                temp->nextname=ml[0];
                ml[0]=temp;
            }
            else
            {
                while ((strcmp(p->name,temp->name)<0) && p->nextname!=NULL)
                {
                    p=p->nextname;
                }
                if (p->nextname!=NULL)
                {
                    temp->nextname=p->nextname;
                    p->nextname=temp;
                }
                else
                {
                    p->nextname=temp;

                }
            }
        }
        //Name insertion ends
        //Ship insertion starts

        int i;
        if (strcmp(temp->ship,"ISR-108")==0)
        {
            i=0;
        }
        else if (strcmp(temp->ship,"ISR-109")==0)
        {
            i=1;
        }
        else if (strcmp(temp->ship,"ISR-110")==0)
        {
            i=2;
        }
        else if (strcmp(temp->ship,"ISR-111")==0)
        {
            i=3;
        }
        else if (strcmp(temp->ship,"ISR-112")==0)
        {
            i=4;
        }
        else if (strcmp(temp->ship,"ISR-113")==0)
        {
            i=5;
        }
        else if (strcmp(temp->ship,"ISR-114")==0)
        {
            i=6;
        }
        else if (strcmp(temp->ship,"ISR-115")==0)
        {
            i=7;
        }
        else if (strcmp(temp->ship,"ISR-116")==0)
        {
            i=8;
        }
        if (fl[i]==NULL)
        {
            fl[i]=temp;
        }
        else
        {
            struct passenger *p=fl[i];
            while(p->nextship!=NULL)
            {
                p=p->nextship;
            }
            p->nextship=temp;
        }
	}

	void displaybyname()
	{
	    struct passenger *p= ml[0];
	    while (p!=NULL)
        {
            cout<<p->name<<" ";
            p=p->nextname;
        }
	}

	void displaybyno()
	{
	    struct passenger *p= ml[1];
	    while (p!=NULL)
        {
            cout<<p->name<<" ";
            p=p->nextno;
        }
	}

	void displaybyship(int i)
	{
	    struct passenger *p=fl[i];
	    int x=4;
        int y=8;
		int s=2;
		gotoxy(31,4);
		cout<<"PASSENGER DETAILS";
		gotoxy(4,6);
		cout<<left<<setw(10)<<"Ticket#"<<setw(10)<<"Name"<<setw(15)<<"Passport No."<<setw(15)<<"Cell No."<<setw(13)<<"Ship No."<<"Address";
	    while (p!=NULL)
        {
            gotoxy(x,y+1);
            cout<<left<<setw(10)<<p->ticketno<<setw(10)<<p->name<<setw(15)<<p->passport<<setw(15)<<p->cell<<setw(13)<<p->ship<<p->address;
            gotoxy(s,y+2);
            y=y+2;
            p=p->nextship;
        }
	}

	void display_ticket(int ticket_no)
		{
			bool run=false;
			struct passenger *p=ml[1];
			int x=42;
			while(p!=NULL)
            {
                if (p->ticketno==ticket_no)
                {
                    gotoxy(19,6);
					cout<<"Ticket No:             "<<p->ticketno;
					gotoxy(19,8);
					cout<<"Name:                  "<<p->name;
					gotoxy(19,10);
					cout<<"Passport:              "<<p->passport;
					gotoxy(19,12);
					cout<<"Cell No:               "<<p->cell;
					gotoxy(19,14);
					cout<<"Ship No:             "; gotoxy(x,14);cout<<p->ship;
					gotoxy(19,16);
					cout<<"Address:               "<<p->address;
					gotoxy(17,18);
					run=true;
					x=x+10;
                }
                p=p->nextno;
            }
			if(run==false)
			{
				system("CLS");
				cout<<"Ticket Number You Entered Is Not Valid..."<<endl<<endl;
			}
		}

    void ship_passenger()
	{
        int ch;
        gotoxy(2,25);
        cout<<"\nEnter Serial No. of Ship Whose Passengers You Want To Know: ";
        cin>>ch;
        if (ch>=1 && ch<=9)
        {
            system("CLS");
            displaybyship(ch-1);
        }
        else
        {
            system("CLS");
            cout<<"Invalid   Number..."<<endl;
        }
	}

	void display()
		{
            int x=4;
            int y=8;
			int s=2;
			struct passenger *p=ml[1];
			while (p!=NULL)
            {
                gotoxy(x,y+1);
				cout<<left<<setw(10)<<p->ticketno<<setw(10)<<p->name<<setw(15)<<p->passport<<setw(15)<<p->cell<<setw(13)<<p->ship<<p->address;
				gotoxy(s,y+2);
				y=y+3;
				p=p->nextno;
            }
            gotoxy(x+31,y+2);
            cout<<"Finish";
			gotoxy(s,y+3);
			}
    void ship_code()
    {
        system("COLOR 0E");
        gotoxy(4,1);
		cout<<"AVAILABLE Source and Destination with their code";
		gotoxy(4,4);
		cout<<left<<setw(6)<<"Code"<<setw(50)<<"Location";
		gotoxy(4,6);
		cout<<left<<setw(6)<<"0"<<setw(50)<<"India";
		gotoxy(4,8);
		cout<<left<<setw(6)<<"1"<<setw(50)<<"Singapore";
		gotoxy(4,10);
		cout<<left<<setw(6)<<"2"<<setw(50)<<"Germany";
		gotoxy(4,12);
		cout<<left<<setw(6)<<"3"<<setw(50)<<"Kenya";
		gotoxy(4,14);
		cout<<left<<setw(6)<<"4"<<setw(50)<<"Canada";
    }
	void show_reserve_menu()
	{
		int choice;
		char ch='y';
		char name[20],passport[10],cell[10],ship[10],address[40];
		while(ch=='y' || ch=='Y')
		{
            system("CLS");
			ship_code();
			int s, d;
			sc:
            cout<<"\n\n    Enter Source Code = ";
            cin>>s;
            while (s<0 || s>4)
            {
                cout<<"\nWrong source code!!!! Enter again";
                goto sc;
            }
            dc:
            cout<<"\n\n    Enter Destination Code =  ";
            cin>>d;
            while (d<0 || d>4 ||s==d)
            {
                cout<<"\nIncorrect destination code!!!! Enter again";
                goto dc;
            }
            string source,destination;

                 if(s==p1.first)
                {
                    source=p1.second;
                }
                else if(s==p2.first)
                {
                    source=p2.second;
                }
                else  if(s==p3.first)
                {
                    source=p3.second;
                }
                else if(s==p4.first)
                {
                    source=p4.second;
                }
                else if(s==p5.first)
                {
                    source=p5.second;
                }



                 if(d==p1.first)
                {
                    destination=p1.second;
                }
                else if(d==p2.first)
                {
                    destination=p2.second;
                }
                else  if(d==p3.first)
                {
                    destination=p3.second;
                }
                else if(d==p4.first)
                {
                    destination=p4.second;
                }
                else if(d==p5.first)
                {
                    destination=p5.second;
                }

            cout<<"\n\n";
            cout <<"    Possible routes\n";
            vector<vector<int> > p;
            p=findpaths(g, s, d, 5);
            cout<<"\n";
            int c=0;
            if (p.size()>1)
            {
                lab:
                cout<<"    Enter your choice ";
                cin>>c;
                while (c<=0 || c>p.size())
                {
                    cout<<"Wrong choice!!! Enter Again \n";
                    goto lab;
                }
                c=c-1;
            }
            else if (p.size()==1)
            {
                cout<<"   ";
                system("pause");
            }
            vector<int> a=p[c];
            int fl[5][5]={ {0,1,0,0,2},
                        {4,0,3,0,0},
                        {0,0,0,5,0},
                        {0,0,7,0,6},
                        {8,0,9,0,0},
                      };
            vector<int> f;
            system("COLOR FC");
            for (int i=0; i<a.size()-1;i++)
            {
                    f.push_back(fl[a[i]][a[i+1]]);
            }
                    system("CLS");
					gotoxy(23,3);
					ticket_number++;
					cout<<"Enter Passenger Name: ";
					cin>>name;
					while(check(name)==false)
					{
						gotoxy(45,3);
						cout<<"                       "<<endl;
						gotoxy(45,3);
						cin>>name;
					}
					gotoxy(23,6);
					cout<<"Enter Passport Number: ";
					cin>>passport;
					/*for(int i=0;i<=size-1;i++)
					{
						if(passport==arr[i].passport)
						{
							gotoxy(46,6);
							cout<<"                       "<<endl;
							gotoxy(46,6);
							cin>>passport;
						}
					}*/
					while(check_alphabet(passport)== false)
					{
						gotoxy(46,6);
						cout<<"                       "<<endl;
						gotoxy(46,6);
						cin>>passport;
					}
					gotoxy(23,9);
					cout<<"Enter Cell Number: ";
					cin>>cell;
					/*for(int i=0;i<=size-1;i++)
					{
						if(cell==arr[i].cell)
						{
							gotoxy(42,9);
							cout<<"                       "<<endl;
							gotoxy(42,9);
							cin>>cell;
						}
					}*/
					while(check_alphabet(cell)==false)
					{
						gotoxy(42,9);
						cout<<"                   "<<endl;
						gotoxy(42,9);
						cin>>cell;
					}
					gotoxy(23,12);
					cout<<"Enter Address: ";
					cin>>address;
					while(check(address)==false)
					{
						gotoxy(38,12);
						cout<<"                       ";
						gotoxy(38,12);
						cin>>address;
					}
					gotoxy(23,15);
                for (int i=0; i<f.size(); i++)
                {
                    switch(f[i])
                    {
                        case 1:
                            strcpy(ship,"ISR-108");
                            break;
                        case 2:
                            strcpy(ship,"ISR-109");
                            break;
                        case 3:
                            strcpy(ship,"ISR-110");
                            break;
                        case 4:
                            strcpy(ship,"ISR-111");
                            break;
                        case 5:
                            strcpy(ship,"ISR-112");
                            break;
                        case 6:
                            strcpy(ship,"ISR-113");
                            break;
                        case 7:
                            strcpy(ship,"ISR-114");
                            break;
                        case 8:
                            strcpy(ship,"ISR-115");
                            break;
                        case 9:
                            strcpy(ship,"ISR-116");
                            break;
                    }
                    enqueue(name,passport,cell,ship,address,ticket_number);
                    system("CLS");
                }
                    cout<<"\nYOUR RECORD HAS BEEN SUCCESSFULLY ENTERED...\n\n"<<endl;
                    cout<<"Do you want to enter again(Y/N):  ";
                    cin>>ch;
                    system("CLS");
		}
	}

	void ships_info()
	{
        system("COLOR 1E");
		gotoxy(31,1);
		cout<<"AVAILABLE SHIPS";
		gotoxy(4,4);
		cout<<left<<setw(6)<<"No."<<setw(15)<<"Ship No"<<setw(14)<<"From"<<setw(17)<<"Destination"<<setw(14)<<"Time"<<"Fare";
		gotoxy(4,6);
		cout<<left<<setw(6)<<"1"<<setw(15)<<"ISR-108"<<setw(14)<<"India"<<setw(17)<<"Singapore"<<setw(14)<<"11:00 PM"<<"Rs.1500";
		gotoxy(4,8);
		cout<<left<<setw(6)<<"2"<<setw(15)<<"ISR-109"<<setw(14)<<"India"<<setw(17)<<"Canada"<<setw(14)<<"12:00 PM"<<"Rs.2500";
		gotoxy(4,10);
		cout<<left<<setw(6)<<"3"<<setw(15)<<"ISR-110"<<setw(14)<<"Singapore"<<setw(17)<<"Germany"<<setw(14)<<"03:00 PM"<<"Rs.3000";
		gotoxy(4,12);
		cout<<left<<setw(6)<<"4"<<setw(15)<<"ISR-111"<<setw(14)<<"Singapore"<<setw(17)<<"India"<<setw(14)<<"02:00 AM"<<"Rs.5000";
		gotoxy(4,14);
		cout<<left<<setw(6)<<"5"<<setw(15)<<"ISR-112"<<setw(14)<<"Germany"<<setw(17)<<"Kenya"<<setw(14)<<"09:00 AM"<<"Rs.1700";
		gotoxy(4,16);
		cout<<left<<setw(6)<<"6"<<setw(15)<<"ISR-113"<<setw(14)<<"Kenya"<<setw(17)<<"Canada"<<setw(14)<<"09:00 AM"<<"Rs.1800";
		gotoxy(4,18);
		cout<<left<<setw(6)<<"7"<<setw(15)<<"ISR-114"<<setw(14)<<"Kenya"<<setw(17)<<"Germany"<<setw(14)<<"09:00 AM"<<"Rs.1900";
		gotoxy(4,20);
		cout<<left<<setw(6)<<"8"<<setw(15)<<"ISR-115"<<setw(14)<<"Canada"<<setw(17)<<"India"<<setw(14)<<"09:00 AM"<<"Rs.2100";
		gotoxy(4,22);
		cout<<left<<setw(6)<<"9"<<setw(15)<<"ISR-116"<<setw(14)<<"Canada"<<setw(17)<<"Germany"<<setw(14)<<"09:00 AM"<<"Rs.2200";
	}

	void Menu()
	{
        system("COLOR 0A");
		gotoxy(35,3);
		cout<<"MAIN MENU"<<endl;
		gotoxy(28,1);
		cout<<"What do you want to do?"<<endl;
		gotoxy(4,6);
		cout<<"1-Reserve Seat"<<endl;
		gotoxy(4,8);
		cout<<"2-My Ticket"<<endl;
		gotoxy(4,10);
		cout<<"3-Ships Schedule"<<endl;
		gotoxy(4,12);
		cout<<"4-Display Passengers"<<endl;
		gotoxy(4,14);
		cout<<"5-Shortest Path"<<endl;
		gotoxy(4,16);
		cout<<"6-Quit Program"<<endl;
	}

    void printshortpath(vector<int>& path, int min_cost)
    {
        int price = 0;
        int size = path.size();
        int fl[5][5]={ {0,1500,0,0,2500},
                        {5000,0,3000,0,0},
                        {0,0,0,1700,0},
                        {0,0,1900,0,1800},
                        {2100,0,2200,0,0},
                      };
        for (int i=0; i<path.size()-1;i++)
            {
                    price = price + fl[path[i]][path[i+1]];
            }
        if (price == min_cost)
        {
            for (int i = 0; i < size; i++)
            {
                if(path[i]==p1.first)
                {
                    cout<<p1.second<<" ";
                }
                else if(path[i]==p2.first)
                {
                    cout<<p2.second<<" ";
                }
                else  if(path[i]==p3.first)
                {
                    cout<<p3.second<<" ";
                }
                else if(path[i]==p4.first)
                {
                        cout<<p4.second<<" ";
                }

                else if(path[i]==p5.first)
                {
                        cout<<p5.second<<" ";
                }
                cout<<"-->";
            }

        cout<<"    Price of the ticket "<<price;
           // cout << path[i] << " ";
        cout << endl;
        }
    }
    void print(vector<vector<int> > p, int m)
    {
        for(int i=0; i<p.size(); i++)
        {
            printshortpath(p[i],m);
        }

    }

    int ffloyd(int c[][5],int s, int d)
    {
        int i, j, k , pc1 , pc2 , choice , f=0;
        int b[5][5];

        for(i = 0 ; i < 5 ; i++)
        {
            for(j = 0 ; j < 5 ; j++)
            {
                b[i][j]=c[i][j];
            }
        }

        for (k = 0; k < 5; k++)
        {
            for (i = 0; i < 5; i++)
            {
                for (j = 0; j < 5; j++)
                {
                    if ((b[i][k] * b[k][j] != 0) && (i != j))
                    {
                        if ((b[i][k] + b[k][j] < b[i][j]) || (b[i][j] == 0))
                        {
                            b[i][j] = b[i][k] + b[k][j];
                        }
                    }
                }
            }
        }
        return b[s][d];
    }
    void sp()
    {
        system("COLOR 5B");
        int pc1,pc2;
        int b[5][5]={ {0,1500,0,0,2500},
                            {5000,0,3000,0,0},
                            {0,0,0,1700,0},
                            {0,0,1900,0,1800},
                            {2100,0,2200,0,0},
                          };
        cout<<"\n    Places with respective codes are as follows\n";
        cout<<"\n    0: India";
        cout<<"\n    1: Singapore";
        cout<<"\n    2: Germany";
        cout<<"\n    3: Kenya";
        cout<<"\n    4: Canada";
        psc:
            cout<<"\n\n    Enter Source Code = ";
            cin>>pc1;
            while (pc1<0 || pc1>4)
            {
                cout<<"\nWrong source code!!!! Enter again";
                goto psc;
            }
        pdc:
            cout<<"\n\n    Enter Destination Code =  ";
            cin>>pc2;
            while (pc2<0 || pc2>4 ||pc1==pc2)
            {
                cout<<"\nIncorrect destination code!!!! Enter again";
                goto pdc;
            }
        int mincost=ffloyd(b,pc1,pc2);
        vector<vector<int> > vec;
        for (int i = 0; i < 5; i++){        //creating row
            vec.push_back(vector<int>());
        }

        for (int n = 0; n < 5; n++){        //creating columns for the rows
            for (int m = 0; m < 5; m++){
                vec[m].push_back(b[n][m]);
            }
        }
        vector<vector<int> > pa;
        cout<<"\n\n    Possible routes \n\n";
        pa=findpaths(g,pc1,pc2,5);
        cout<<"\n\n    Route with lowest fare \n    ";
        print(pa,mincost);
    }
};

int main()
{
    // number of vertices
    int v = 5;
    g.resize(5);
    g[0].push_back(1);
    g[0].push_back(4);
    g[1].push_back(2);
    g[1].push_back(0);
    g[2].push_back(3);
    g[3].push_back(2);
    g[3].push_back(4);
    g[4].push_back(0);
    g[4].push_back(2);
    sms obj;
    int choice,tcno;
start:
    system("COLOR 0A");
	system("CLS");
	obj.Menu();
	obj.gotoxy(4,18);
	cout<<"Enter Your Choice: ";
	l:
	char c=getch();
  		if(c>='1' && c<='8')
		{
		choice=c-48;
		cout<<c;
	  		goto l2;
		}
		else
		{
			choice=getch();
		}
  	goto l;
	l2:
  	Sleep(200);
  	system("CLS");
	switch(choice)
	{
		case 1:
			system("CLS");
			obj.show_reserve_menu();
			system("pause");
			system("CLS");
			goto start;
			break;
		case 2:
			system("CLS");
			if(obj.ret_tick_no()==0)
			{
				cout<<"Record Is Empty....! \n"<<endl;
			}
			else
			{
				cout<<"Enter Your Ticket Number: ";
				cin>>tcno;
				obj.display_ticket(tcno);
			}
			system("pause");
			system("CLS");
			goto start;
			break;
		case 3:
			system("CLS");
			if(obj.ret_tick_no()==0)
			{
                obj.ships_info();
				cout<<"\n\n    Record Is Empty....! \n"<<endl;
			}
			else
			{
				obj.ships_info();
				obj.ship_passenger();
			}
			system("pause");
			system("CLS");
			goto start;
			break;
		case 4:
			system("CLS");
			system("COLOR 3F");
			if(obj.ret_tick_no()==0)
			{
				cout<<"Record Is Empty....! \n"<<endl;
			}
			else
			{
                obj.gotoxy(31,4);
                cout<<"PASSENGER DETAILS";
                obj.gotoxy(4,6);
                cout<<left<<setw(10)<<"Ticket#"<<setw(10)<<"Name"<<setw(15)<<"Passport No."<<setw(15)<<"Cell No."<<setw(13)<<"Ship No."<<"Address";
                obj.display();
            }
            system("pause");
            system("CLS");
            goto start;
            break;
        case 5:
            obj.sp();
            system("pause");
			system("CLS");
            goto start;
            break;
        case 6:
                return 0;
                break;
        default:					//Default value for invalid Input.
                cout<<"Invalid Number..."<<endl;
                system("pause");
                system("CLS");
                goto start;
			}
	return 0;
}

bool check(char a[])
{
	int i=0;
	while(a[i]!='\0')
	{
		if(a[i]>=48 && a[i]<=57)
		{
			return false;
		}
		else
		{
			i++;
		}
	}
	return true;
}

bool check_alphabet(char a[])
{
	int i=0;
	while(a[i]!='\0')
	{
		if(a[i]>=65 && a[i]<=122)
		{
			return false;
		}
		else
		{
			i++;
		}
	}
	return true;
}
