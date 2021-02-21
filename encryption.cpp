//  Created by Ege Berk Yurtkoruyan on 28.04.2020.
#include <iostream>

using namespace std;

unsigned char P (unsigned char c){
    // This is the function to permutate the char
    unsigned char c1 = (c & int(0x22)) >> 1;    // i took the 2nd and 6th index (1 and 5) and shifted by 1
    unsigned char c2 = (c & int(0x88)) >> 2;    // did the same for the other indexes into given indexes.
    unsigned char c3 = (c & int(0x11)) << 2;
    unsigned char c4 = (c & int(0x44)) << 1;

    return c1 | c2 | c3 | c4;                   // I returned the combination of the shifted value.
}

int main() {
    
    string key, plain_txt;
    cout << "*** Welcome to the Simple Data Encryption Application ***" << endl;
    cout << "Please enter the encryption key: ";
    getline(cin,key);
    
    while(printf("Please enter the plaintext to be encrypted: ") && getline(cin, plain_txt)){
    
        cout << "Ciphertext: " ;
        
        for(int i = 0 ; i < plain_txt.length() ; i++){
            unsigned char ch = P(plain_txt[i]);
            ch = char(ch ^ int(key[i % key.length()])); // i % key.length() will change index everytime.
            cout << hex << int(ch);                     // I don't know what to comment it's only 35 lines zaten
        }
        cout << endl << endl;                           // I ended line here :D ?
    }
    return 0;
}
