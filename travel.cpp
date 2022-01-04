#include<iostream>
#include<conio.h>
#include<cstdio>
#include<fstream>
#include<sstream>
#include<cstring>
#include<string>
#include<cstdlib>
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
	int transport_id;
	string transport_type;
	int transport_cost;
	
	public:
	Transport(){
		transport_id = 0;  // can have random function which will set the id
		transport_type = "";
		transport_cost = 0;
	}
	
	void getTransportDetails(){
		cout << "Enter transport type from the following " << endl;
		cout << "1. Cab." << endl;
		cout << "2. Flight." << endl;
		cout << "3. Train." << endl;
		cout << "4. Ship." << endl;
		getline(cin, transport_type);
		
		// if statements depending on the type enter assign cost to the variable
	}
	void bookTransport();
	void cancelTransport();
	void showtransportDetails();
};

class Hotel{
	protected:
	string hotel_name;
	string hotel_address;
	string check_in_date;
	string check_out_date;
	int hotel_cost;
	
	public:
	Hotel() {
		hotel_name = "";
		hotel_address = "";
		check_in_date = "";
		check_out_date = "";
		hotel_cost = 0;
	}
	
	void getHotelDetails(){
		// either this or we can do same as what we did for transport by giving a predefined list
		cout << "Hotel Name: ";
		getline(cin, hotel_name);
		cout << "Hotel Address: ";
		getline(cin, hotel_address);
		cout << "Checkin date: ";
		getline(cin, check_in_date);
		cout << "Checkout date: ";
		getline(cin, check_out_date);
		cout << "Hotel cost: ";
		getline(cin, hotel_cost);
	}
	
	void bookHotel();
	void cancelHotel();
	void showHotelDetails();
};

class Traveller {
	protected:
	string name;
	string address;
	int contact;
	
	public: 
	Traveller(){
		name = "";
		address = "";
		contact = 0;
	}
	
	void setTDetails(){
		cout << "Name: "; 
		getline(cin, name);
		cout << "Address: ";
		getline(cin, address);
		cout << "Contact: ";
	}
	void showTDetails();
};

class Receipt {
	protected:
	int receipt_id;
	int total_cost;
	
	public:
	Receipt() {
		receipt_id = 0;
		total_cost = 0;
	}
 	void generateReceipt();
};

class Trip:public Traveller, Transport, Hotel, Receipt{
	protected:
	int trip_id;
	string trip_start_date;
	string trip_end_date;
	string trip_to;
	string trip_from;
	
	public:
	Trip() {
		trip_id = 0;
		trip_start_date = "";
		trip_end_date = "";
		trip_to = "";
		trip_from = "";
	}
	
	void getTripDetails(){
		setTDetails();
		getTransportDetails();
		getHotelDetails();
		cout << "Trip from: ";
		getline(cin, trip_from);
		cout << "Trip destination: ";
		getline(cin, trip_to);
		cout << "Trip start date: ";
		getline(cin, trip_start_date);
		cout << "Trip end date: ";
		getline(cin, trip_end_date);
	}
	void bookTrip(){
		getTripDetails();
		cout << "booked" << endl;
	} // will invoke all other booking functions // book functions will do the work of saving data to text file.
	void cancelTrip(){
		cout << "Canceled" << endl;  // this function will delete the trip from the text file.
	}
	void showTripDetails();
};





int main()
{
	clearScreen();

    system("title Travel Agency Management System Program");


    // Variables
    int chooseOneFromMenu = 0;
    char exitSurity;
    Trip tripObject;

    cout << "Welcome To Travel Agency Management System" << endl << endl;
    cout << "Travel Agency Management Menu" << endl;
    cout << "1. New Travel Trip." << endl;
    cout << "2. Add Trip." << endl;
    cout << "3. Edit Trip." << endl;
    cout << "4. Delete Trip." << endl;
    cout << "5. Exit." << endl;
    cout << "Choose One: ";
    cin >> chooseOneFromMenu;

    switch (chooseOneFromMenu)
    {
    case 1:
        tripObject.bookTrip();
        break;
    case 2:
       // AddTrip();  // we can implement operator overloading to edit no of passengers
        break;
    case 3:
       // EditTrip(); // temporary if we get time we can add
        break;
    case 4:
        tripObject.cancelTrip();
        break;
    case 5:
        ExitProgram:
        cout << "Program terminating. Are you sure? (y/N): ";
        cin >> exitSurity;
        if (exitSurity == 'y' || exitSurity == 'Y') {
            return 0;
        }else if (exitSurity == 'n' || exitSurity == 'N') {
            system("cls");
            main();
        }else {
            cout << "Next time choose after read the corresponding line." << endl;
            goto ExitProgram;
        }
        break;
    default:
        cout << "Please choose between 1 - 5. Press Enter To Continue...";
        getch();
        system("cls");
        main();
        break;
    }
    return 0;
}