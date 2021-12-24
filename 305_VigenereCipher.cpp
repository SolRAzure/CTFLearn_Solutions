/*
    CTFLearn Challenge 305: Vigenere Cipher

        GOAL: Decrypt provided text using provided key via Vigenere cipher. 
              Be wary of '{' and '}' characters. 

    by SolRAzure
*/

#include<string>
#include<iostream>


// Lengthen the key to the input string's length (i.e. keykeykey...etc.)
std::string generateLongKey(std::string str, std::string key)
{
    int x = str.size();
    for(int i = 0; ; i++){
        if(x == i) i = 0;
        if(str.size() == key.size()) break;
        key.push_back(key[i]);
    }
    return(key);
}


// Problem was already ciphered, we only want to decipher.
std::string decipherTxt(std::string cipher_txt, std::string key)
{
    std::string orig_txt;
    int offset = 0; // Offset used to ignore special characters '{' and '}'
    for(int i = 0; i < cipher_txt.size(); i++){
        if(cipher_txt[i] == '{' || cipher_txt[i] == '}'){
            orig_txt.push_back(cipher_txt[i]);
            offset++;
        }
        else{
            char x = (cipher_txt[i] - key[i-offset] + 26) % 26;
            // These next two lines ensure proper translation for (upper/lower)case.
            if(cipher_txt[i] > 'Z') x+= 'a';
            else x+= 'A'+6;
            orig_txt.push_back(x);
        }
    }
    return(orig_txt);
}


int main()
{
    // Encrypted message and its key, provided in challenge.
    std::string str = "gwox{RgqssihYspOntqpxs}";
    std::string key = "blorpy";

    std::string longkey = generateLongKey(str, key);

    std::cout << "Original: " << decipherTxt(str, longkey) << std::endl;

}
