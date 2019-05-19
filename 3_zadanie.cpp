#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <crypt.h>
#include <iomanip>
#include <fstream>
#include <mutex>

using namespace std;

void findPass(string pass, string pass1, const string& hash)
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
        if (pass == pass1)
            break;
    } while ( next_permutation( pass.begin(), pass.end() ) );
    delete pCryptData;
}

int main(int argc, char** chislo)
{
    thread th_1;
    thread th_2;
    thread th_3;
    thread th_4;
    thread th_5;
    thread th_6;
    thread th_7;
    thread th_8;
    th_1=thread(findPass,"123456789","231456789",chislo[1]);

    th_2=thread(findPass,"231456789","341256789",chislo[1]);

    th_3=thread(findPass,"341256789","451236789",chislo[1]);

    th_4=thread(findPass,"451236789","561234789",chislo[1]);

    th_5=thread(findPass,"561234789","671234589",chislo[1]);

    th_6=thread(findPass,"671234589","781234569",chislo[1]);

    th_7=thread(findPass,"781234569","891234567",chislo[1]);

    th_8=thread(findPass,"891234567","999999999",chislo[1]);
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
