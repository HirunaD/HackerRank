#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    string hour_str = s.substr(0, 2);
    string minute_str = s.substr(3, 2);
    string second_str = s.substr(6, 2);
    string period = s.substr(8, 2);
    
    int hour = stoi(hour_str);
    
    if (period == "AM") {
        if (hour == 12) {
            hour = 0;
        }
    } else { // period == "PM"
        if (hour != 12) {
            hour += 12;
        }
    }
    
    // Format hour to be two digits
    stringstream ss;
    ss << setw(2) << setfill('0') << hour << ":" << minute_str << ":" << second_str;
    
    return ss.str();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
