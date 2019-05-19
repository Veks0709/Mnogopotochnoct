#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <crypt.h>
#include <iomanip>
#include <fstream>

using namespace std;

/* ‘ункци€ поиска парол€ по известному хэшу перестановкой символов парол€
* ѕараметры:
* startPass Ч начальное значение парол€
* hash - хэш-функци€ от парол€
* ‘ункци€ использует следующие заголовочные файлы:
* algorithm Ч алгоритмы стандартной библиотеки
* crypt.h Ч криптографические функции Linux
*/
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
    int  c = 0;
    ifstream f("/root/8_Laba/Zadanie.txt");
    f.seekg(0, ios::end);
    int fsize = f.tellg();
    f.seekg(0, ios::beg);
    char *faile = new char [fsize];
    char *faile1 = new char[100];
    f.read(faile, fsize);
    for (int i = 0; i < fsize; i++) {
        if (faile[i] != '\n' && faile[i] != ' ' && faile[i] != '\t' && i != (fsize-1)) {
            faile1[c] = faile[i];
            c++;
            
        } else {
            findPass("123456789", faile1);
            delete[] faile1;
            faile1 = new char[100];
            c = 0;
            
        }
    }
    delete[] faile;
     delete[] faile1;

    return 0;
}
