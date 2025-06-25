#include <iostream>
#include<iomanip>
using namespace std;
// global variable
float total_be,discount, room_price,final_cost;
int id,book_rooms,occupant;
string room;


//the declaration of the function;
float CalcFee(){
	//user input(id)
	room_num:
	cout<<"enter the room id you want to Book: ";
	cin>>id;
	// cout<<endl;

	//Validate room number;
	switch(id){
		case 0:
		room="single room";
		room_price=50;
		break;

		case 1:
		room="Double room";
		room_price=90;
		break;

		case 2:
		room="Deluxe room";
		room_price=150;
		break;

		case 3:
		room="suite";
		room_price=250;
		break;

		default:
		cout<<"Invalid room id"<<endl;
		goto room_num;
	}


	cout<<"enter the quantity of rooms to book: ";
	cin>>book_rooms; 	//user input(quantity)
	cout<<endl;

	int max_occupants[] = {1, 2, 4, 6}; 	// Define max occupants for each room type

	label:
	cout<<"enter the number of occupants: "; 
	cin>>occupant; 		//user input (occupant)
	cout<<endl<<endl<<endl;

	if(occupant<1){
		cout<<"Occupant cant be less than 1"<<endl;
		goto label;
	}

	// Check if occupants exceed max allowed for the selected room
	if (id >= 0 && id < 4 && occupant > max_occupants[id]*book_rooms) {
		cout << "Number of occupants exceeds the maximum allowed for this room type (" << max_occupants[id] << "). Please enter a valid number." << endl;
		goto label;
	}
	
	total_be=book_rooms*room_price; 	//total price befor discount
	return total_be;
}

//declaration of the function
float getDisc(){
	//the condition 
	if (total_be>180){
		discount=total_be*0.05; 		//the discount
		final_cost=	total_be-discount; 	//the final cost of the rooms;
	}
	return final_cost;
}

void display(string room, int book_rooms, float total_be, float final_cost, int occupant, int id){
	cout<<"==================== Booking Summery====================="<<endl;
	cout<<"Room Type: "<<room<<endl;
	cout<<"Number of Rooms Booked: "<<book_rooms<<endl;
	cout<<"Number of Occupants: "<<occupant<<endl;
	if(total_be>180){ //condition of price more than 180;
		cout<<"Total price (before Discount): RM "<<fixed<<setprecision(2)<<total_be<<endl;
		cout<<"Discount Amount (5%): RM "<<discount<<endl;
		cout<<"Final cost (after discount): RM "<<final_cost<<endl;
		cout<<"Thank you for choosing our hotel!"<<endl;
    }else{
     	cout<<"Total price: RM "<<fixed<<setprecision(2)<<total_be<<endl;
		cout<<"Thank you for choosing our hotel!"<<endl;
	}
}



int main(){

	string names[]={"single room","Double Room","Deluxe Room","Suite"}; //Basically all of this for just to make the user see our Available Rooms;	

	string prices[]={"50.00","90.00","150.00","     250.00"};

	string max_occupants[]={"1","2","4","6"};

	cout<<setw(67)<<"WELCOME TO OUR HOTEL "<<"\n"<<endl; 	//welcome massage;


	cout<<"Available Rooms:"<<endl;
	cout<<"\n"<<"Room id"<<setw(13)<<"Room type"<<setw(28)<<"price per Room(RM)"<<setw(25)<<"Max occupants"<<"\n"<<endl;
	cout<<"-----------------------------------------------------------------------------------"<<endl;
	
	for(int p=0;p<4;p++){
		cout<<p<<setw(21)<<names[p]<<setw(22)<<prices[p]<<setw(23)<<max_occupants[p]<<"\n"<<endl;
	}
		
	cout<<"\n"<<"\n"<<endl;
	//calling the function
	float total_cost = CalcFee();
	float final_cost = getDisc();		
		
	display(room, book_rooms, total_cost, final_cost, occupant, id); //calling the function display
	
	
	

}

