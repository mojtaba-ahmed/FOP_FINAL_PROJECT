#include <iostream>;
#include<iomanip>
using namespace std;
// global varible
float total_be,discount, room_price,final_cost;
int id,book_rooms,occupant;
string room;

//untile here



//the declartion of the function;
int CalcFee(){


//user input(id)
	cout<<"enter the room id you want to Book: ";
		cin>>id;
		cout<<endl;
		//user input(quntity)
		cout<<"enter the quntity of rooms to book: ";
		cin>>book_rooms;
		cout<<endl;
		//user input (occupant)
		cout<<"enter the number of occupants: ";
		cin>>occupant;
		cout<<endl<<endl<<endl;
		//end user input;
		
		
		//the condtions of id;
			if(id==0){
		room="single room";
		room_price=50;
	
	}else if(id==1){
		room="Double room";
		room_price=90;
	}else if(id==2){
		room="Dluex room";
		room_price=150;
		
	}else if(id==3){
		room="suite";
		room_price=250;
	}
	//end condtion;
	
	
		
//total price befor discount
	total_be=book_rooms*room_price;
	
	
	
	
	
}
//end of the function




//declartion of the function
int getDisc(){

	//the condtion 
	if (total_be>180){
		//the discount
		discount=total_be*0.05;
		//the final cost of the rooms;
	final_cost=	total_be-discount;
	
	}
	
	
	

}
//end of function;







int main(){

//basicaly all of this for just to make the user see our Avalible Rooms;	
string names[]={"single room","Double Room","Deluxe Room","Suite"};
string prices[]={"50.00","90.00","150.00","     250.00"};

string occupants[]={"1","2","4","6"};

//welcime massage;
cout<<setw(67)<<"WELCOME IN OUR HOTEL "<<endl<<endl<<endl;

	cout<<"Availble Rooms:"<<endl;
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
		
		//condtion of number of occupants
		
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
	
	
	//condtion of price more than 180;
	if(total_be>180){
			cout<<"Total price (befor Discount): RM "<<fixed<<setprecision(2)<<total_be<<endl<<endl;
			cout<<"Discount Amount (5%): RM "<<discount<<endl<<endl;
			cout<<"Total price (after discount): RM "<<final_cost<<endl<<endl;
       }else{
       	cout<<"Total price: RM "<<fixed<<setprecision(2)<<total_be;
	   }
//untile here;	
}

