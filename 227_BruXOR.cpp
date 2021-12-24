/*
    CTFLearn Challenge 227: BruXOR

        GOAL: Brute force decrypt the XOR encryption of a message with an unknown key.
              However, we can assume "flag" is likely contained in the decrypted text.
              (Using "FLAG" instead gets close, but not close enough)

    by SolRAzure
*/

#include<string>
#include<iostream>


int main()
{
    // Encrypted flag from question, along w/ known txt.
    std::string msg = "q{vpln'bH_varHuebcrqxetrHOXEj";
    std::string known = "flag";

    int key = 1;
    std::string test_str;

    // Loop through the encrypted msg until the known text string is found.
    do{
        test_str = "";
        std::cout << "Testing int key: " << key << std::endl;
        for(int i = 0; i < msg.size(); i++){
            test_str.push_back(msg[i] ^ (char)key);
        }
        key++;
    // std::string::npos is used to indicate no matches (== -1).
    }while(test_str.find(known) == std::string::npos);

    // Print out our flag, and subtract the extra key increment.
    std::cout << "\nFlag is: " << test_str << std::endl
              << "Int key is: " << key-1 << std::endl;

    return(0);
}
