#include<iostream>

using namespace std;

class bankAccount{
	int balAmt;
	string accHolderName, amtDepoName, accType;
	
	public:
	void DepositAmount( int );	
	void withdrawAmount( int );
	void showDetails( );
	bankAccount(string accHolder, string depoName, string type, int bal){
		if(bal<0)
			cout<<"invalid amount....intialized to zero balance...";
		bal=0;
		accHolderName=accHolder;
		amtDepoName=depoName;
		accType=type;
		balAmt=bal;
	}
	
};

int main(){

	bankAccount acc("gs","gs","savings",5000);
	acc.showDetails();
	acc.DepositAmount(3000);
	acc.showDetails();
	acc.withdrawAmount(2000);
	acc.showDetails();
	
	return 0;
}

void bankAccount:: showDetails(){
	cout<<"Account holder:"<<accHolderName<<endl;
	cout<<"Depositor name:"<<amtDepoName<<endl;
	cout<<"Account Type:"<<accType<<endl;
	cout<<"Balance amount:"<<balAmt<<endl;
}

void bankAccount:: DepositAmount( int amt ){
	if(amt<0)
		cout<<"Sorry invalid input..";
	else{
		balAmt+=amt;
		cout<<amt<<" RS is credited into your account. \n";
	}
}

void bankAccount:: withdrawAmount( int amt ){
	if(amt>balAmt)
		cout<<"Sorry you dont have balance....\n";
	else{
		balAmt-=amt;
		cout<<amt<<" RS is debited from your account. \n";
	}
}