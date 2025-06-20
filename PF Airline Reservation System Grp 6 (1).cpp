#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
int seats(int num);
int package(int num);
void info(void);
int schedule(void);
void survey(void);


struct passenger
{
	string name;
	string last_name;
	string fname;
	int age;
	int seats;
	int pnr;
	long long contact;
	string flight;
	string departure;
	string arv;
	string route;
};

int main()
{
	cout<<"\t\tAirline Reservation System."<<endl<<endl;
	schedule();
	int seat;
	seat=170;
	seats(seat);
	info();
	survey();
	getch();
	
}

int seats(int num)  //main operation where most of the processing takes place
{
	passenger p[num];  //used structures to store information such as name,age,contact etc/*
	int sum=0;
	long int min=1000000,max=9999999;
	long long pnr[num];      //a datatype to store extremely large numbers.
	char choice;
	cout<<"\n\nSeats Available: "<<num;
	
	cout<<"\n\nEnter your Information.";
	
		for(int i=0;i<num;i++)   //loop for storing information in arrays.
		{
		
			cout<<"\n\nFirst Name: ";
			cin>>p[i].name;
			
			cout<<"\nLastname:";
			cin>>p[i].last_name;
			cout<<"\nEnter father name: ";
			cin>>p[i].fname;
			
			
			cout<<"\nAge: ";
			cin>>p[i].age;
			
			cout<<"\nPhone: ";
			cin>>p[i].contact;
			
			cout<<"\nSeats: ";
			cin>>p[i].seats;
			
			if(p[i].seats>170){
				cout<<"\nWe don't have these much seats.";
			    cout<<"\nDo you want to book again?(y/n)";
			    cin>>choice;
			    if(choice!='n')
			    {
			    	continue;
				}
				else
				exit(0);
				
			}
			

			if(num<0)   //in case the user wants to book a seat when the whole flight is already booked.
		{
			cout<<"\nNo seats left...You can board the next flight\n";
			cout<<"Thank You for Visiting Pakistan International Airline...\nGreat People To Fly With.";
			return 0;
		}
			package(p[i].seats);
	    	pnr[i]=rand()%(max-min+1)+min;   //random function used and gave a limit for passenger ID
			num=num-p[i].seats;
			sum+=p[i].seats;     //total seats booked
			
			
			
			cout<<"\n\nDo you want to look at the information you put in?\n(y/n)";
			cin>>choice;
		if(choice=='y'||choice=='Y')
		{
		cout<<"\nName: "<<p[i].name<<" "<<p[i].last_name; //display information for each person.
		cout<<"\nAge: "<<p[i].age;
		cout<<"\nContact no.: "<<p[i].contact;
		cout<<"\nSeats Reserved: "<<p[i].seats;
		cout<<"\nPassenger ID: "<<pnr[i];
		cout<<"\n\nSeats Available now: "<<num;
		
		
		}
		else
		{
		cout<<"\n\nSeats Available now: "<<num;
		
		}
			cout<<"\n\nDo you want to make more reservations?\n(y/n)"; //if user wants to make a reservation with a new name.
			cin>>choice;
			if(choice=='n'||choice=='N')
			{
				break;
			}	
			
			
		}
		cout<<"\n\nTotal seats reserved: "<<sum;

	
	cout<<"\n\nThanks for visiting Pakistan International Airline";
}

int package(int num)  //asks the user which class he wants to book his seat in.
{
	string pkg;
	cout<<"\nEnter the Class you want to reserve your seat in: (economy+/economy) ";
	cin>>pkg;
	cout<<"\n\nYou have reserved "<<num<<" seats in "<<pkg<<" class.";	
}

void info(void)
{
	cout<<"\nTo Ensure a smooth and enjoyable journey  please take note of the following.";
	cout<<"\n1. Please arrive at the airport at least 2 hours before the scheduled departure time.";
	cout<<"\n2. Ensure you have a valid government-issued photo ID with you. This is essential for check-in and security procedures.";
	cout<<"\n3. Keep your electronic or printed ticket accessible. You may be asked to present it at various points during your journey.";
	cout<<"\n5.Follow all safety instructions provided by the cabin crew during the flight. Smoking and the use of electronic devices may be restricted.";
	cout<<"\n4.Follow the security and boarding procedures as instructed by our staff. Your cooperation ensures a timely departure.";
	cout<<"\n\nPlease be aware of our baggage allowance policy.";
	cout<<"\nAny changes to your flight must be made in accordance with our policies. Additional fees may apply.";
	cout<<"\n\nPlease review our full terms and conditions on our website for more details.";
	cout<<"\n\nPIA\nGreat People To Fly With";
}
int schedule(void)     //information of flights i.e routes, times 
{
	passenger p[6];
	string booking;
	int i=0,j,index=-1;
	char choice='y';
	
    p[0].route = "ISB-KHI";
    p[1].route = "ISB-GIL";
    p[2].route = "ISB-MUX";
    p[3].route = "ISB-SKZ";
    p[4].route = "ISB-UET";
    p[5].route = "ISB-KDU";
    
    p[0].flight = "PK-301";
    p[1].flight = "PK-601";
    p[2].flight = "PK-681";
    p[3].flight = "PK-631";
    p[4].flight = "PK-325";
    p[5].flight = "PK-451";

    p[0].departure = "1000 hrs";
    p[1].departure = "1630 hrs";
    p[2].departure = "1230 hrs";
    p[3].departure = "0700 hrs";
    p[4].departure = "0900 hrs";
    p[5].departure = "1100 hrs";

    p[0].arv = "1155 hrs";
    p[1].arv = "1705 hrs";
    p[2].arv = "1400 hrs";
    p[3].arv = "0830 hrs";
    p[4].arv = "1015 hrs";
    p[5].arv = "1200 hrs";

	
	cout<<"\tFlight Schedule\n";
	for(j=0;j<6;j++)
	{
		cout<<p[j].route;
		cout<<endl;
	}
	
	
	
	do
	{
		
		cout<<"\n\nEnter your desired flight from the above schedule: ";
		cin>>booking;
		cout<<endl<<endl;
		for(i=0;i<6;i++)
		{
		
		if(p[i].route==booking)
		 {
			index=i;
			choice='n';
			break;
			
		 }
		
		}
	if(choice=='y')
		{
			cout<<"No such flight was found....\nDo you want to book another flight?(y/n)";
			cin>>choice;
		}
		
	}while(choice!='n');
	
	cout<<"\tFlight:"<<p[index].flight;
	cout<<"\n\tRoute: "<<p[index].route;
	cout<<"\n\tDeparture:"<<p[index].departure;
	cout<<"\n\tArrival: "<<p[index].arv;
	
	
	
}

void survey(void)
{
	int choice;
	cout<<"\n\nHow was your experience on our website?";
	cout<<"\n1: Very Good\n2: Good\n3: Moderate\n4: Requires Improvement\n5: I won't visit again";
	cout<<"\n\nEnter your Rating: ";
	cin>>choice;
	if(choice==4||choice==5)
	{
		cout<<"We are very sorry for any inconvenience caused by our side, \nWe will improve our website and We really Hope to expect another visit from you";
	}
	else if(choice==1||choice==2)
	{
		cout<<"Thank You Very Much!:) We will be expecting you soon";
	}
}
	
