#include<iostream>

using namespace std;

//     1m=3.28feet            1cm=0.393701inch 
class DM;

class DB{
	int feet, inch;
	public:
	friend DB add( DM&, DB& );
	DB(int a, int b){ feet=a; inch=b; }
	void show() {cout<<feet<<" feet , "<<inch<<"inches \n";}
	
}; 

class DM{
	int m, cm;
	public:
	friend DB add( DM&, DB& );
	DM(int a, int b){ m=a; cm=b; }
	void show() {cout<<m<<" meter , "<<cm<<"centimeter \n";}
};

DB add(DM &dm, DB &db)
{
	DB d(0,0);
	d.feet=db.feet + dm.m*3.28;
	d.inch=db.inch + dm.cm*0.383701;
	int a=dm.m*3.28;
	cout<<(dm.m*3.28 - a); 	
	d.inch += (dm.m*3.28 - a)*12/0.393701;
	
	return d;
}

int main(){
	DB db(2,3);
	DM dm(5,70);
	DB db1= add(dm, db);
	
	cout<<"\ndb: ";
	db.show();
	cout<<"\ndm: ";
	dm.show();
	cout<<"\ndm+db: ";
	db1.show();
	
}