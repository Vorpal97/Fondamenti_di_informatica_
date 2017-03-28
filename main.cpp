#include <iostream>
#include <fstream>
using namespace std;

int main(){

    char b1,b2;
    bool f = false;;
    fstream fp1,fp2;
    fp1.open("/Users/Manuel/Desktop/miofile.dat",ios::in);
    fp2.open("/Users/Manuel/Desktop/miofile2.dat",ios::in);
    
    while((fp1.eof() == 0) || (fp2.eof() == 0)){
        fp1.get(b1);
        fp2.get(b2);
        if(b1 != b2){
            cout << "ERROR OFFSET 0x" << fp1.tellg() << ": 0x" << hex <<(int) b1 <<" = 0x" << hex <<(int) b2 <<endl;
            f=false;
            break;
        }else{
            cout << "OK OFFSET 0x" << fp1.tellg() << ": 0x" << hex <<(int) b1 <<" = 0x" << hex <<(int) b2 <<endl;
            f=true;
        }
    }
    
    fp1.close();
    fp2.close();
    
    cout << "FILE " <<  ((f)?"UGUALI":"DIVERSI") << endl;
    
    return 0;
}
