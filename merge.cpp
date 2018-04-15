#include <iostream>
#include <fstream>
using namespace std;

int main(int argc,char * argv)
{
    ifstream fin1,fin2;
    ofstream fout;
    fin1.open(argv[1],ios::in);
    fin2.open(argv[2],ios::in);
    fout.open("merge.txt",ios::out|ios::trunc);
    string s1,s2;
    while(getline(fin1,s1))
        if(getline(fin2,s2))
            fout<<s1<<endl<<s2<<endl;
    return 0;
}
