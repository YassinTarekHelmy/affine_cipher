#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};


void encryption()
{
    char cipher[80];
    cout <<"please enter a cipher: ";
    cin.ignore();
    cin.getline(cipher,80,'\n');
    for (int i = 0;i < strlen(cipher);i++)
    {
        cipher[i] = tolower(cipher[i]);
        auto itr_1 = find(alphabet,alphabet + 26,cipher[i]);
        if (isalpha(cipher[i]))
        {
            int index_1 = distance(alphabet,itr_1);
            int cipher_letter = (5*index_1 + 8) % 26;
            cipher[i] = alphabet[cipher_letter];
            cout << cipher[i];
        }
        else if (!isalpha(cipher[i]))
        {
            cout << cipher[i];
        }
    }
}
void decryption()
{
    string cipher;
    cout <<"please enter a cipher: ";
    cin.ignore();
    getline(cin,cipher);
    for (char & i : cipher)
    {
        i = tolower(i);
        auto itr_1 = find(alphabet,alphabet + 26,i);
        if (isalpha(i))
        {
            int index_1 = distance(alphabet,itr_1);
            int cipher_letter =  (21*(index_1 - 8)) % 26;
            if (cipher_letter < 0) cipher_letter += 26;
            i = alphabet[cipher_letter];
            cout << i;
        }
        else if (!isalpha(i))
        {
            cout << i;
        }

    }
}


int main()
{
    string input;
    cout << "Please enter what do you want to do\n" << "1- Encryption.\n" << "2- Decryption.\n" << "3- Exit.\n";
    cin >> input;
    if (input == "1")
    {
        encryption();
    }
    else if (input == "2")
    {
        decryption();
    }
    else if (input == "3")
    {
        cout << "Thanks For using The Affine Cypher Program see you soon.";
    }
    else
    {
        cout << "Wrong Input!";
        main();
    }
}