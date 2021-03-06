#include<iostream>
#include<conio.h>
//#include<cstdio>
#include<fstream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<windows.h>
#include<iomanip>
#include<time.h>
using namespace std;

const int LINELENGTH = 80;

enum Position{ LEFT, CENTRE, RIGHT };

void clearScreen()
{
	system("cls");
	cout << "Click 'ctrl + c' to exit the program." << endl;
}

void wait(int time = 800)
{
	Sleep(time);
}

int generateRandomId(){
	wait();
	srand(time(0));
	return rand();
}

void print( Position pos, string s, int linelength )
{
   int spaces = 0;
   switch( pos )
   {
      case CENTRE: spaces = ( linelength - s.size() ) / 2; break;
      case RIGHT : spaces =   linelength - s.size()      ; break;
   }
   if ( spaces > 0 ) cout << string( spaces, ' ' );
   cout << s << '\n';
}

void print(int LINELENGTH){
	string border(LINELENGTH, '=');
	cout << border << endl;
	print( CENTRE, "Welcome To Travel Agency System", LINELENGTH );
	cout << endl << border << endl;
}

void printMainMenu(int LINELENGTH){
		print(CENTRE, "Travel Agency Menu", LINELENGTH);
	    cout << "\n 1. Plan new trip." << endl;
	    cout << " 2. Cancel Trip." << endl;
	    cout << " 3. Exit." << endl;
	    cout << "\n Choose One: ";
}

class Transport{
	protected:
	int transport_id;
	string transport_type;
	int transport_cost;
	
	public:
	Transport(){
		transport_id = 0;  // can have random function which will set the id
		transport_type = "";
		transport_cost = 0;
	}
	
	void getTransportDetails(int tripOption){
		// assigning id
		transport_id = generateRandomId();
		
		
		
		
		// taking input for transport type
		cout << "\n Enter(exact word) transport type from the following " << endl;
		string border(LINELENGTH,'*');
		cout << endl << border;
		cout << "|" << left << setw(20) << " " << " | " << left << setw(55) << "Transport type" << right << "|";
		cout << border;
		cout << "|" << left << setw(20) << " 1" << " | " << left << setw(55) << "Bus" << right << "|";
		cout << "|" << left << setw(20) << " 2" << " | " << left << setw(55) << "Flight" << right << "|";
		cout << "|" << left << setw(20) << " 3" << " | " << left << setw(55) << "Train" << right << "|";
		cout << "|" << left << setw(20) << " 4" << " | " << left << setw(55) << "Cab" << right << "|";
		cout << border << endl;
		cout << ": ";
		getline(cin, transport_type);
		
		// assigning the transport cost
		if(transport_type == "Bus" || transport_type == "bus" || transport_type == "BUS"){
			transport_cost = 1200 * tripOption;
		}else if(transport_type == "Flight" || transport_type == "flight" || transport_type == "BUS"){
			transport_cost = 4500 * tripOption;
		}else if(transport_type == "Train" || transport_type == "train" || transport_type == "TRAIN"){
			transport_cost = 900 * tripOption;
		}else if(transport_type == "Cab" || transport_type == "cab" || transport_type == "CAB"){
			transport_cost = 4000 * tripOption;
		}else {
			transport_cost = 3000;
		}
	}
	
	void bookTransport(int trip_id){
		ofstream fout;
		fout.open("transport-details.txt", ios::app);
		fout << trip_id << " " << transport_id  << " "<< transport_type << " " <<  transport_cost << endl;
		fout.close();
	}
	
	void cancelTransport(int delete_trip_id){
		ifstream fin;
		string readLine;
		ofstream fout;
		
		fin.open("transport-details.txt", ios::in);
		if(fin.is_open())
		{
			while(getline(fin, readLine))
			{
				int fileTripId = 0;
				int size = readLine.length();
				char tripD[size+1];
				int temp = 0, i=0;
				strcpy(tripD, readLine.c_str());
				while((temp = tripD[i++]) != 32)
					fileTripId = fileTripId * 10 + (temp - 48);
				if(fileTripId != delete_trip_id)
				{
					fout.open("temp.txt", ios::app);
					fout<<readLine<<endl;
					fout.close();
				}
			}
			fin.close();
		}
		remove("transport-details.txt");
		rename("temp.txt","transport-details.txt");
	}
};

class Hotel{
	protected:
	string hotel_name;
	string check_in_date;
	string check_out_date;
	int hotel_cost;
	
	public:
	Hotel() {
		hotel_name = "";
		check_in_date = "";
		check_out_date = "";
		hotel_cost = 0;
	}
	
	void printHotelMenu(int LINELENGTH){
		string border(LINELENGTH,'*');
		cout << endl << border;
		cout << "|" << left << setw(20) << "Sr No." << " | " << left << setw(30) << "Hotel Name" << " | " << left << setw(22) << "Price/Day" << right << "|";
		cout << border;
		cout << "|" << left << setw(20) << " 1" << " | " << left << setw(30) << "ITC Gardenia" << " | " << left << setw(22) << "5000" << right << "|";
		cout << "|" << left << setw(20) << " 2" << " | " << left << setw(30) << "Novotel" << " | " << left << setw(22) << "3000" << right << "|";
		cout << "|" << left << setw(20) << " 3" << " | " << left << setw(30) << "Woodville Palace" << " | " << left << setw(22) << "2500" << right << "|";
		cout << "|" << left << setw(20) << " 4" << " | " << left << setw(30) << "Ibis" << " | " << left << setw(22) << "2000" << right << "|"; 
		cout << border << endl;
	}
	
	void setHotelNameCost(int& hotelOption){
		SelectHotel:	
					cout << "\n Enter Hotel sr.no: ";
					cin >> hotelOption;
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					switch(hotelOption){
						case 1: hotel_name = "ITC Gardenia";
								hotel_cost = 5000;
						break;
						
						case 2: hotel_name = "Novotel";
								hotel_cost = 3000;
						break;
						
						case 3: hotel_name = "Woodville Palace";
								hotel_cost = 2500;
						break;
						
						case 4: hotel_name = "Ibis";
								hotel_cost = 2000;
						break;
						default: cout << "\n Enter Correct option from above..." << endl;
								 goto SelectHotel;
						break;
						
					}
	}
	
	void getHotelDetails(int LINELENGTH){
		int hotelOption = 0;
		// print hotel list here
		printHotelMenu(LINELENGTH);
		setHotelNameCost(hotelOption);
		cout << " Checkin date: ";
		getline(cin, check_in_date);
		cout << " Checkout date: ";
		getline(cin, check_out_date);
	}
	
	void bookHotel(int trip_id){
		ofstream fout;
		fout.open("Hotel-details.txt", ios::app);
		fout << trip_id << " " << hotel_name  << " "<< check_in_date << " " <<  check_out_date << " " << hotel_cost << endl;
		fout.close();
	}
	
	void cancelHotel(int delete_trip_id){
		ifstream fin;
		string readLine;
		ofstream fout;
		
		fin.open("Hotel-details.txt", ios::in);
		if(fin.is_open())
		{
			while(getline(fin, readLine))
			{
				int fileTripId = 0;
				int size = readLine.length();
				char tripD[size+1];
				int temp = 0, i=0;
				strcpy(tripD, readLine.c_str());
				while((temp = tripD[i++]) != 32)
					fileTripId = fileTripId * 10 + (temp - 48);
				if(fileTripId != delete_trip_id)
				{
					fout.open("temp.txt", ios::app);
					fout<<readLine<<endl;
					fout.close();
				}
			}
			fin.close();
		}
		remove("Hotel-details.txt");
		rename("temp.txt","Hotel-details.txt");
	}
};

class Traveller {
	protected:
	string name;
	string address;
	string contact;
	string gender;
	
	public: 
	Traveller(){
		name = "";
		address = "";
		gender = "";
		contact = "";
	}
	
	void setTDetails(){
		cout << "\n Name: "; 
		getline(cin, name);
		cout << " Gender(M/F): "; 
		getline(cin, gender);
		cout << " Address: ";
		getline(cin, address);
		cout << " Contact: ";
		getline(cin, contact);
	}
	
	void storeTDetails(int trip_id){
		ofstream fout;
		fout.open("traveller-details.txt", ios::app);
		fout << trip_id << " " << name << " " << gender << " " <<  address << " " << contact << endl;
		fout.close();	
	}
	
	void deleteTravellerDetails(int delete_trip_id){
		ifstream fin;
		string readLine;
		ofstream fout;
		
		fin.open("traveller-details.txt", ios::in);
		if(fin.is_open())
		{
			while(getline(fin, readLine))
			{
				int fileTripId = 0;
				int size = readLine.length();
				char tripD[size+1];
				int temp = 0, i=0;
				strcpy(tripD, readLine.c_str());
				while((temp = tripD[i++]) != 32)
					fileTripId = fileTripId * 10 + (temp - 48);
				if(fileTripId != delete_trip_id)
				{
					fout.open("temp.txt", ios::app);
					fout<<readLine<<endl;
					fout.close();
				}
			}
			fin.close();
		}
		remove("traveller-details.txt");
		rename("temp.txt","traveller-details.txt");
	}
};

class Receipt {
	protected:
	int receipt_id;
	int sub_total;
	int tax;
	int grand_total;
	
	public:
	Receipt() {
		receipt_id = 0;
		sub_total = 0;
		tax = 0;
		grand_total = 0;
	}
	
 	void generateReceipt(int trip_id, int transport_cost, int hotel_cost, int noOfDays, string name){
	 	receipt_id = generateRandomId();
	 	
	 	sub_total = (hotel_cost * noOfDays) + transport_cost;
	 	tax = (sub_total * 18)/100;
	 	grand_total = sub_total + tax;
	 	cout << grand_total << endl;
	 	printReceipt(trip_id, sub_total, tax, grand_total, transport_cost, hotel_cost, noOfDays, name);
 	}
 	
 	void printReceipt(int trip_id, int sub_total, int tax, int grand_total, int transport_cost, int hotel_cost, int noOfDays, string name){
 		int hotelTotal = sub_total - transport_cost;
	 	
	 	clearScreen();
		string border(LINELENGTH, '^');
		cout << border;
		print(CENTRE, "Trip Booked", LINELENGTH);
		cout << endl << border;
		cout << "Receipt -> Loading...";
		wait(4000);
		clearScreen();
		print(LINELENGTH);
		cout << border;
		print(CENTRE, "Booking Receipt", LINELENGTH);
		cout << endl << border;
		cout << "Trip Id: " << trip_id << endl;
		cout << "Name: " << name << endl;
		cout << "Days(stay): " << noOfDays << endl;
		cout << endl << border;
		cout << left << setw(20) << "SR.NO" << left << setw(20) << "Description" << right << setw(40) << "Total Price";
		cout << endl << border;
		cout << left << setw(20) << "01" << left << setw(20) << "Transport" << right << setw(40) << setprecision(2) << transport_cost;
		cout << left << setw(20) << "02" << left << setw(20) << "Hotel" << right << setw(40) << setprecision(2) << hotelTotal;
		cout << left << setw(60) << " " << right << setfill('-') << setw(20) << "-";
		cout << left << setfill(' ') << setw(40) << " " << left << setw(20) << "SUBTOTAL:" << right << setw(20) << sub_total;
		cout << left << setw(40) << " " << left << setw(20) << "TAX(18%):" << right << setw(20) << tax;
		cout << left << setw(40) << " " << left << setw(20) << "GRAND TOTAL:" << right << setw(20) << grand_total;
		cout << endl << border;
		
	 }
	 
 	void storeReceipt(int trip_id, int transport_cost, int hotel_cost, int noOfDays, string name){
 		
 		generateReceipt(trip_id, transport_cost, hotel_cost, noOfDays, name);
	 	ofstream fout;
		fout.open("Receipt-details.txt", ios::app);
		fout << trip_id << " " << receipt_id  << " " << sub_total << " " << grand_total << endl;
		fout.close();
		
 	}
 	
 	void deleteReceipt(int delete_trip_id){
		ifstream fin;
		string readLine;
		ofstream fout;
		
		fin.open("Receipt-details.txt", ios::in);
		if(fin.is_open())
		{
			while(getline(fin, readLine))
			{
				int fileTripId = 0;
				int size = readLine.length();
				char tripD[size+1];
				int temp = 0, i=0;
				strcpy(tripD, readLine.c_str());
				while((temp = tripD[i++]) != 32)
					fileTripId = fileTripId * 10 + (temp - 48);
				if(fileTripId != delete_trip_id)
				{
					fout.open("temp.txt", ios::app);
					fout<<readLine<<endl;
					fout.close();
				}
			}
			fin.close();
		}
		remove("Receipt-details.txt");
		rename("temp.txt","Receipt-details.txt");
	}
};

class Trip:public Traveller, Transport, Hotel, Receipt{
	protected:
	int trip_id;
	string trip_start_date;
	string trip_end_date;
	string trip_to;
	string trip_from;
	int noOfDays;
	
	public:
	Trip() {
		trip_id = 0;
		trip_start_date = "";
		trip_end_date = "";
		trip_to = "";
		trip_from = "";
		noOfDays = 0;
	}
	
	void printTripMenu(int LINELENGTH){
		
		string border(LINELENGTH,'*');
		cout << endl << border;
		cout << "|" << left << setw(20) << " Trip option" << " | " << left << setw(55) << "Trip route" << right << "|";
		cout << border;
		cout << "|" << left << setw(20) << " 1" << " | " << left << setw(55) << "Goa to Bangalore" << right << "|";
		cout << "|" << left << setw(20) << " 2" << " | " << left << setw(55) << "Goa to Mumbai" << right << "|";
		cout << "|" << left << setw(20) << " 3" << " | " << left << setw(55) << "Goa to Delhi" << right << "|";
		cout << "|" << left << setw(20) << " 4" << " | " << left << setw(55) << "Goa to Shimla" << right << "|";
		cout << border << endl;
		
	}
	
	void setTripDestinations(int& tripOption){
		SelectTrip:	cout << " Enter trip option: ";
					cin >> tripOption;
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					switch(tripOption){
						case 1: trip_from = "Goa";
								trip_to = "Bengaluru";
						break;
						
						case 2: trip_from = "Goa";
								trip_to = "Mumbai";
						break;
						
						case 3: trip_from = "Goa";
								trip_to = "Delhi";
						break;
						
						case 4: trip_from = "Goa";
								trip_to = "Shimla";
						break;
						default: cout << "\n Enter Correct option from above..." << endl;
								 goto SelectTrip;
						break;
					}
	}
	
	void getTripDetails(int LINELENGTH){
		int tripOption = 0;
	 	trip_id = generateRandomId();
	 	
		// set traveller details
		print(CENTRE,"Traveller Details", LINELENGTH);
		setTDetails();
		cout << endl;
		
		// set trip details 
		print(CENTRE,"Trip Details", LINELENGTH);
		
		printTripMenu(LINELENGTH);
		setTripDestinations(tripOption);
		cout << " Trip start date: ";
		getline(cin, trip_start_date);
		cout << " Trip end date: ";
		getline(cin, trip_end_date);
		cout << " Days(stay): ";
		cin >> noOfDays;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << endl;
		
		
		//set transport details
		print(CENTRE,"Transport Details", LINELENGTH);
		getTransportDetails(tripOption);
		cout << endl;
		
		// set hotel details
		print(CENTRE,"Hotel Details", LINELENGTH);
		getHotelDetails(LINELENGTH);
		
		
	}
	
	void storeTripDetails(){
		ofstream fout;
		fout.open("trip-details.txt", ios::app);
		fout << trip_id << " " << trip_start_date  << " " << trip_end_date << " " << trip_from << " " << trip_to << " " << noOfDays << endl;
		fout.close();
	}
	
	void bookTrip(int LINELENGTH){
		clearScreen();
		print(LINELENGTH); // prints the header 
		getTripDetails(LINELENGTH); // get trip and other details
		
		storeTDetails(trip_id);
		bookTransport(trip_id);
		bookHotel(trip_id);
		storeTripDetails();
		storeReceipt(trip_id, transport_cost, hotel_cost, noOfDays, name);
	}
	
	void deleteTripDetails(int delete_trip_id){
		clearScreen();
		print(LINELENGTH);
		
		ifstream fin;
		string readLine;
		ofstream fout;
		
		fin.open("trip-details.txt", ios::in);
		if(fin.is_open())
		{
			while(getline(fin, readLine))
			{
				int fileTripId = 0;
				int size = readLine.length();
				char tripD[size+1];
				int temp = 0, i=0;
				strcpy(tripD, readLine.c_str());
				while((temp = tripD[i++]) != 32)
					fileTripId = fileTripId * 10 + (temp - 48);
				if(fileTripId != delete_trip_id)
				{
					fout.open("temp.txt", ios::app);
					fout<<readLine<<endl;
					fout.close();
				}
			}
			fin.close();
		}
		remove("trip-details.txt");
		rename("temp.txt","trip-details.txt");
	}
	
	void cancelTrip(){
		string border(LINELENGTH, '^');
		int delete_trip_id = 0;
		
		cout << "Enter trip id of the trip to be cancelled: ";
		cin >> delete_trip_id;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		
		deleteTripDetails(delete_trip_id);
		cancelTransport(delete_trip_id);
		cancelHotel(delete_trip_id);
		deleteTravellerDetails(delete_trip_id);
		deleteReceipt(delete_trip_id);
		
		cout << border;
		print(CENTRE, "Trip Cancelled", LINELENGTH);
		cout << endl << border;
	}
};

int main()
{
	clearScreen();
    system("title Travel Agency System");
    
    // Variables
    int chooseOneFromMenu = 0;
    char exitSurity;
    Trip tripObject;
    
	// menu
	MainMenu:   
		clearScreen();
		print(LINELENGTH);
		printMainMenu(LINELENGTH);
	    cin >> chooseOneFromMenu;
	    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (chooseOneFromMenu)
    {
    case 1:
        tripObject.bookTrip(LINELENGTH);
        break;
    case 2:
        tripObject.cancelTrip(); // delete from the file
        break;
    case 3:
        ExitProgram:
	        cout << "Program terminating. Are you sure? (Y/N): ";
	        cin >> exitSurity;
	        if (exitSurity == 'y' || exitSurity == 'Y') {
	            return 0;
	        }else if (exitSurity == 'n' || exitSurity == 'N') {
	            clearScreen();
	            goto MainMenu;
	        }else {
	            cout << "Next time choose after read the corresponding line." << endl;
	            goto ExitProgram;
	        }
	        break;
    default:
        cout << "Please choose between 1 - 3.";
        clearScreen();
        system("PAUSE");
        goto MainMenu;
        break;
    }
    system("PAUSE");
    goto MainMenu;
    return 0;
}