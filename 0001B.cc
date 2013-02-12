#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;


int main() {
    int n = 0;
    for(cin >> n; n--;) {
        
        // 0. input data
        string input("");
        cin >> input;
            
        // 1. Define the variables.
        // 1.1. The row and col vars, 1-based index.
        int r(0), c(0);
        // 1.2. Buffer to convert number to string.
        char buf[20] = "";
    
        // 2. Decode the index from the input.
        // 2.1. Get the axis_type. 
        //      True if RXXXCXXX format, else ABC123 format.
        bool axis_type = input[0] == 'R' 
                     && isdigit(input[1]) 
                     && input.find('C') != string::npos;
        // 2.2. Get the row and col.
        // 2.2.1. Format as RXXXCXXX
        if(axis_type) {
            // obviously
            int pos = input.find('C');
            r = atoi(input.substr(1, pos-1).c_str());
            c = atoi(input.substr(pos+1).c_str());
        }
        // 2.2.2. Format as ABC123
        else {
            // 2.2.2.1. pos to be the first digit index.
            int pos = 0;
            while(isalpha(input[pos])) pos++;
            // 2.2.2.2. get the row index. (1-based)
            r = atoi(input.substr(pos).c_str());
            // 2.2.2.3. get the column index.
            // the last level count.
            for(int i = c = 0; i < pos; ++i) {
                c *= 26;
                c += input[i] - 'A';
            }
            // now c is increased to the full circles before the last level.
            for(int i = 1, k = 26; i < pos; ++i) {
                c += k;
                k *= 26;
            }
            // 1-based column index.
            c += 1;
        }
        
        // 3. Encode the index.
        string output("");
        // 3.3.1. Return format as ABC123
        if(axis_type) {
            int plus = c, k = 26, len = 1;
            // 3.3.1.1. decrease the circles, and get the level.
            while(plus > k) {
                plus -= k;
                k *= 26;
                len += 1;
            }
            // turn it into 0-based index.
            plus -= 1;
            // 3.3.2.2. Generate as the last level.
            for(int i = 0; i < len; ++i) {
                output = string(1, 'A' + plus % 26) + output;
                plus /= 26;
            }
            // 3.3.2.3. Adding the row index.
            sprintf(buf, "%d", r);
            output += buf;
        }
        // 3.3.2. Return format as RXXXCXXX
        else {
            // 3.3.2.1. Adding the row index.
            sprintf(buf, "%d", r);
            output += string("R") + buf;
            // 3.3.2.2. Adding the col index.
            sprintf(buf, "%d", c);
            output += string("C") + buf;
        }
    
        cout << output << endl;
    }
    return 0;
}