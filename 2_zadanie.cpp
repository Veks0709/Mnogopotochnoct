#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <crypt.h>
#include <iomanip>
#include <fstream>
#include <mutex>

using namespace std;

void findPass(string pass, const string& hash)
{
    crypt_data *pCryptData = new crypt_data;
    size_t pos = hash.find_last_of('$');
    string hashHead = hash.substr(0,pos);
    do {
        string newHash(crypt_r(pass.data(),hashHead.data(),pCryptData));
        if (newHash == hash) {
            cout<<"Hash: "<<hash<<endl<<"Pass: "<<pass<<endl;
            break;
        }
    } while ( next_permutation( pass.begin(), pass.end() ) );
    delete pCryptData;
}

int main()
{
    thread th_1;
    thread th_2;
    thread th_3;
    thread th_4;
    thread th_5;
    thread th_6;
    thread th_7;
    thread th_8;
    int c = 0;
    int argc;
    int c1 = 0;
    ifstream f("/root/8_Laba/Zadanie.txt");
    //cin>>argc;
    argc=8;
    argc=argc+1;
    f.seekg(0, ios::end);
    int fsize = f.tellg();
    f.seekg(0, ios::beg);
    char *faile = new char [fsize];
    char *faile1 = new char[100];
    string chislo [argc];
    f.read(faile, fsize);
    for (int i = 0; i < fsize; i++) {
        if (faile[i] != '\n' && faile[i] != ' ' && faile[i] != '\t' && i != (fsize-1)) {
            faile1[c] = faile[i];
            c++;
            
        } else {
            if (c1 < argc-1){
            c1++;
            chislo[c1] = (string)faile1;} 
            delete[] faile1;
            faile1 = new char[100];
            c = 0;
            
        }
    }
    delete[] faile;
    delete[] faile1;
    for (int i=1; i<argc;i++){cout<<chislo[i]<<endl;}
    if (argc-1 > 0)
        th_1=thread(findPass,"123456789",chislo[1]);
    if (argc-1 > 1)
        th_2=thread(findPass,"123456789",chislo[2]);
    if (argc-1 > 2)
        th_3=thread(findPass,"123456789",chislo[3]);
    if (argc-1 > 3)
        th_4=thread(findPass,"123456789",chislo[4]);
    if (argc-1 > 4)
        th_5=thread(findPass,"123456789",chislo[5]);
    if (argc-1 > 5)
        th_6=thread(findPass,"123456789",chislo[6]);
    if (argc-1 > 6)
        th_7=thread(findPass,"123456789",chislo[7]);
    if (argc-1 > 7)
        th_8=thread(findPass,"123456789",chislo[8]);
    if (th_1.joinable())
        th_1.join();
    if (th_2.joinable())
        th_2.join();
    if (th_3.joinable())
        th_3.join();
     if (th_4.joinable())
        th_4.join();
    if (th_5.joinable())
        th_5.join();
     if (th_6.joinable())
        th_6.join();
     if (th_7.joinable())
        th_7.join();
     if (th_8.joinable())
        th_8.join();
    cout<<"MAIN finished\n";
    return 0;
}
