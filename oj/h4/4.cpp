#include <iostream>

using namespace std;

string Str;

bool FindStr(string s){
    int length = s.length();
    int parts = 2;
    int part_len = length;
    while (part_len > 1){
        if (part_len % parts == 0){
            int k = length / parts;
            string str1 = s.substr(0, length - k);
            string str2 = s.substr(k);
            if (!str1.compare(str2)){
                if (FindStr(s.substr(0, k)) == false){
                    Str = s.substr(0, k);
                }
                return true;
            }
            part_len /= parts;
            while (part_len % parts == 0) {
                part_len /= parts;
            }
        }
        parts ++;
    }
    return false;
}

int main(){
    string Str_input;
    cin >> Str_input;
    if (FindStr(Str_input) == false){
        cout << "-1";
    }
    else{
        cout << Str;
    }
    return 0;
}