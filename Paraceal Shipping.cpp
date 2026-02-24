#include<iostream>
using namespace std;
float weight_calculate(float weight);
float distance_price(float distance);
float total_price(float weight,float distance);
float express_delivery_charges(float total_price);
void bill_print(int id,int type,float weight,float distance,float totalprices);
void per_day_report_print(float PackageRecived, float rweight,float rdistance, float rpayment);
//
int main(){
	// all data types defines multiple purposes 
	float distance[100],type[100],weight[100],totalprice[100],weight_price[100],distanceprice[100],temp[100],totalprices[100];
	int a=0,choice=0,id=0;
	float PackageRecived=0,rdistance=0,rweight=0,rpayment=0,profit=0;
	
	
	//user requied data 
	do{

	// if statemet are use index number are not exside a=100 
	if(a<=100){

	cout<<"Enter a package Weight--(Kg)=";
	cin>>weight[a];
	cout<<"Enter a Distance--(Km)=";
	cin>>distance[a];	
	
	// if condition check weight and duistance are enter greater then 0 number 
	if(weight[a]>0&&distance[a]>0){

	cout<<"Shipping Type= (1 for Standard) & (2 for Express)=";
	cin>>type[a];

	 rweight=rweight+weight[a];
	 rdistance=distance[a]+rdistance;

	

	weight_price[a]=weight_calculate(weight[a]);
	distanceprice[a]=distance_price(distance[a]);
	totalprice[a]=total_price(weight_price[a],distanceprice[a]);
	
	if(type[a]==2){
		totalprices[a]= express_delivery_charges(totalprice[a]);
		}
	else{
		totalprices[a]=totalprice[a];	
		}
	
//bill calculation
    bill_print(id,type[a],weight[a],distance[a],totalprices[a]);
	
	rpayment=rpayment+totalprices[a];
	id++;
	PackageRecived++;
	
	}
	else{
		cout<<"Some this wrong Enter a negative value"<<endl;
	}
	
	// use choices to repeate task are not 
	cout<<"Press 1 New & 0 for Skip";
	cin>>choice;
		}
		
	else{
			cout<<"Per day Limit Complete"<<endl;
		}
		// this is use to hoe packages are recived 
	
	
	}while(choice==1);

//per day report
per_day_report_print(PackageRecived,rweight,rdistance,rpayment);

return 0;
}
//end of main function
// function are use to calculate the weight price
float weight_calculate(float weight){

	return weight*2;
}
// function are use to calculate the distance price
float distance_price(float distance){

	return distance*1.5;
}
// function are use to calculate the total priice
float total_price(float weight,float distance){

return weight+distance;
}
// function are use to calculate the express delivery charges
float express_delivery_charges(float total_price){
       float temp;
	   temp= total_price/4;
		total_price=total_price+temp;
		return total_price;
}
// this function are used to print bill
void bill_print(int id, int type,float weight,float distance,float totalprices){


	//bill calculation
	cout<<endl;
	cout<<endl;
	cout<<"-----------Token-----------"<<endl;
	cout<<" "<<" Token-id="<<id<<endl;
if(type==1){
cout<<"  "<<" Service="<<"Standard"<<endl;	
}
else{
cout<<"  "<<" Service="<<"Express"<<endl;	
}
	cout<<"  "<<" Weight="<<weight<<"Kg"<<endl;
	cout<<"  "<<" Distance="<<distance<<"Km"<<endl;
	cout<<"---------"<<endl;
	cout<<"  "<<"Chargies="<<totalprices<<endl;
	cout<<"---------"<<endl;
	cout<<"-------------------------------"<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;

}
// this function are use to print per day report
void per_day_report_print(float PackageRecived, float rweight,float rdistance, float rpayment){
cout<<endl;
cout<<endl;
cout<<"------Per-Day-Report------"<<endl;
cout<<"  Package-Recived="<<PackageRecived<<endl;
cout<<"  Weight-Recived="<<rweight<<endl;
cout<<"  Distance-record="<<rdistance<<endl;
cout<<"  Payment-recived="<<rpayment<<endl;
cout<<"---------------------------------"<<endl;
float profit=(rpayment/100)*20;
cout<<"  Per-day Profit="<<profit;
cout<<endl;
cout<<endl;

}