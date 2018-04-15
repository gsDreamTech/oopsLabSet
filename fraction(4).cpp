#include<iostream>

using namespace std;

class FractionType{
	int num, den;
	public:
		friend ostream& operator<<(ostream&, const FractionType&);		
		friend istream& operator>>(istream&, FractionType&);	
		bool operator==(const FractionType&) const;
		FractionType operator+(const FractionType& ) const;
		FractionType(){ num=0; den=1; }
		FractionType(int a, int b){ num=a; den=b;}
		void simplify();
		int gcd(int, int);
};

int main(){
	FractionType f;
	cout<<f<<endl;
	cin>>f;
	cout<<f<<endl;
	FractionType f1(2,3);
	cout<<f+f1;
	f1.simplify();
	cout<<f1;
	return 0;
}

int FractionType :: gcd(int a, int b)
{
	if(b==0)
		return a;
	return(b,a%b);
}

void FractionType :: simplify(){
	int n;
	if(num>den)
		 n=gcd(num,den);
	else
		 n=gcd(den,num);
	num/=n;
	den/=n;
}

FractionType FractionType :: operator+(const FractionType& f) const{
	FractionType f1;
	f1.num=num*f.den+ den*f.num;
	f1.den=den*f.den;
	return f1;
}

bool FractionType :: operator==(const FractionType& f) const{
	return num == f.num && den == f.den;
}

ostream& operator<<(ostream &out, const FractionType &f){
	out<<f.num<<"/"<<f.den<<endl;
	return out;
}

istream& operator>>(istream &in, FractionType &f){
	cout<<"enter a fraction:";
	in>>f.num>>f.den;
	return in;
}
