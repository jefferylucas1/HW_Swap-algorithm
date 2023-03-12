#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// Function/Method Declaration - START
//	define function/method declaration signatures between the two markers
string sorts(string s)
{
    char c[s.length() + 1];
    strcpy(c, s.c_str());
    sort(c, c + s.length());
    int al_c = 0, nu_c = 0;
    while (c[al_c] < 'a') {
        al_c++;
    }
    for (int i = 0; i < s.length(); i++) {
        if (s[i] < 'a') {
            s[i] = c[nu_c++];
        }
        else {
            s[i] = c[al_c++];
        }
    }
    return s;
}
// Function/Method Declaration - END


// Function/Method Definition - START
//	define function/method definition between the two markers
int main()
{
    // Variable - START
    // define variables that are global between the two Variable markers
    int a = 0, n = 0, nod = 0, i;
    string numa[100] = {""};
    string alpha = "";
    string opp = "";
    string input, str, newopp, total, total_opp, total_al, total_num;
    int len;
    // Variable - END

    cout << "Enter things to sort:  ";
    cin >> input;
    cout << "\n";
    len = input.length();
    for(int i = 0; i < len; i++){
        char c = input[i];

        if (c == '%' || c == '/' || c == '*' || c == '+' || c == '-' || c == ' ' || c == '!' || c == '"' || c == '#'|| c == '$'|| c == '&' ||
            c == ')' || c == '(' || c == ',' || c == '.' || c == '=' || c == ':' || c == ';'|| c == '@'|| c == '<'|| c == '>'|| c == '['|| c == '&'|| 
            c == '[' || c == ']'|| c == '{'|| c == '}'|| c == '`'|| c == '~'|| c == '_'|| c == '|' || input[i] == ' ') {
            opp.push_back(c);
            nod++;
        }

        if (isalpha(input[i])){
            alpha.push_back(c);
            a++;
        }

        if (isdigit(input[i])){
            numa[n] = c;
            n++;
        } 
    }

    newopp = sorts(opp); //goes to a function
    for(int i = 0; i < nod; ++i){
        total_opp += newopp[i];
    }

    a -= 1;
    total_al = sorts(alpha);//goes to a function

    sort(numa, numa + n);
    for(int i = 0; i < n; ++i){
        total_num += numa[i];
    }

    total = total_opp + total_al + total_num; // adds all of them together
    cout << total;

    return 0;
}
// Function/Method Definition - END
