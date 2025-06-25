#include <iostream>
#include<iomanip>
using namespace std;
// global variable
float total_be,discount, room_price,final_cost;
int id,book_rooms,occupant;
string room;

//untile here

//the declaration of the function;
float CalcFee(){
//user input(id)
	cout<<"enter the room id you want to Book: ";
	cin>>id;
	// cout<<endl;
	//user input(quantity)
	cout<<"enter the quantity of rooms to book: ";
	cin>>book_rooms;
	cout<<endl;
	//user input (occupant)
	label:
	cout<<"enter the number of occupants: ";
	cin>>occupant;
	cout<<endl<<endl<<endl;
	//end user input;

	if(occupant<1){
		cout<<"Occupant cant be less than 1"<<endl;
		goto label;
	}
		
	//the conditions of id;
	switch(id){
		case 1:
		room="single room";
		room_price=50;
		break;

		case 2:
		room="Double room";
		room_price=90;
		break;

		case 3:
		room="Deluxe room";
		room_price=150;
		break;

		case 4:
		room="suite";
		room_price=250;
		break;

		default:
		cout<<"Invalid room id"<<endl;
		goto label;
	}
	//end condition;
		
	//total price befor discount
	total_be=book_rooms*room_price;
	return total_be;
	
}

//declaration of the function
float getDisc(){

	//the condition 
	if (total_be>180){
		//the discount
		discount=total_be*0.05;
		//the final cost of the rooms;
	final_cost=	total_be-discount;
	
	}
	return final_cost;
}
//end of function;


int main(){

//Basically all of this for just to make the user see our Available Rooms;	
string names[]={"single room","Double Room","Deluxe Room","Suite"};
string prices[]={"50.00","90.00","150.00","     250.00"};

string occupants[]={"1","2","4","6"};

//welcome massage;
cout<<setw(67)<<"WELCOME TO OUR HOTEL "<<endl<<endl<<endl;

	cout<<"Available Rooms:"<<endl;
	cout<<endl<<"Room id"<<setw(13)<<"Room type"<<setw(28)<<"price per Room(RM)"<<setw(25)<<"Max occupants"<<endl<<endl;
	cout<<"-----------------------------------------------------------------------------------"<<endl;
	
		for(int p=0;p<4;p++){
			cout<<p<<setw(21)<<names[p]<<setw(22)<<prices[p]<<setw(23)<<occupants[p]<<endl<<endl;
		}
		
//untile Here;

cout<<endl<<endl<<endl;
	//calling the function
		CalcFee();
		getDisc();
	//untile here;
		
		//condition of number of occupants
		
	if (occupant>=1){
		cout<<"==================== Booking Summery====================="<<endl<<endl;
		cout<<"Room Type: "<<room<<endl<<endl;
		cout<<"Number of Rooms Booked: "<<book_rooms<<endl<<endl;
		cout<<"Number of Occupants: "<<occupant<<endl<<endl;
		
	
	}else{
		cout<<"there is no occupants (please enter the number of occupants) you cant enter (zero)"<<endl;
		return 0;
	}
	//untile here;
	
	
	//condition of price more than 180;
	if(total_be>180){
			cout<<"Total price (befor Discount): RM "<<fixed<<setprecision(2)<<total_be<<endl<<endl;
			cout<<"Discount Amount (5%): RM "<<discount<<endl<<endl;
			cout<<"Total price (after discount): RM "<<final_cost<<endl<<endl;
       }else{
       	cout<<"Total price: RM "<<fixed<<setprecision(2)<<total_be;
	   }
//untile here;	
}

