#include <iostream>

using namespace std;

int wordCompare(const char word1[],const char word2[]){
    return word1-word2;
}

int main(){
    string w="Ala";
    string s="Ala";
    cout << wordCompare(s.c_str(),w.c_str());
    return 0;
}
