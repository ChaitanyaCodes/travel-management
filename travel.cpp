#include<iostream>
#include<conio.h>
#include<fstream>
#include<cstring>
#include<string>
#include<windows.h>
using namespace std;

void clearScreen()
{
	system("cls");
}

void wait()
{
	Sleep(1000);
}

class Transport{
	protected:
	string transport_type;
	int transport_id;
	int transport_cost;
	
};

class Hotel{
	protected:
	string hotel_name;
	string hotel_address;
	string check_in_date;
	string check_out_date;
	int hotel_cost;
	
};

class Traveller {
	protected:
	string name;
	string address;
	int contact;	
};

class Trip {
	protected:
	int trip_id;
	string trip_start_date;
	string trip_end_date;
	string trip_to;
	string trip_from;
};

class Receipt {
	protected:
	int receipt_id;
	int total_cost;
};



int main()
{
	clearScreen();
	
	return 0;
}