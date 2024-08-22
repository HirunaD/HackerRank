#include <bits/stdc++.h>

using namespace std;

// Function to split a string based on spaces
vector<string> split_string(string);

// Complete the getMoneySpent function below.
int getMoneySpent(vector<int> keyboards, vector<int> drives, int b) {
    // Sort the keyboards and drives lists in ascending order
    sort(keyboards.begin(), keyboards.end());
    sort(drives.begin(), drives.end());

    int max_sum = -1; // Initialize max_sum to -1 (default if no valid combination exists)
    int n = keyboards.size();
    int m = drives.size();

    int i = 0;       // Pointer for keyboards
    int j = m - 1;   // Pointer for drives

    while (i < n && j >= 0) {
        int current_sum = keyboards[i] + drives[j];

        if (current_sum > b) {
            // Current sum exceeds budget, move to a cheaper USB drive
            j--;
        } else {
            // Current sum is within budget
            if (current_sum > max_sum) {
                max_sum = current_sum; // Update max_sum if current_sum is greater
            }
            // Move to a more expensive keyboard to try and maximize the sum
            i++;
        }
    }

    return max_sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string bnm_temp;
    getline(cin, bnm_temp);

    vector<string> bnm = split_string(bnm_temp);

    int b = stoi(bnm[0]); // Budget
    int n = stoi(bnm[1]); // Number of keyboard models
    int m = stoi(bnm[2]); // Number of USB drive models

    // Read keyboard prices
    string keyboards_temp_temp;
    getline(cin, keyboards_temp_temp);
    vector<string> keyboards_temp = split_string(keyboards_temp_temp);
    vector<int> keyboards(n);
    for (int keyboards_itr = 0; keyboards_itr < n; keyboards_itr++) {
        int keyboards_item = stoi(keyboards_temp[keyboards_itr]);
        keyboards[keyboards_itr] = keyboards_item;
    }

    // Read USB drive prices
    string drives_temp_temp;
    getline(cin, drives_temp_temp);
    vector<string> drives_temp = split_string(drives_temp_temp);
    vector<int> drives(m);
    for (int drives_itr = 0; drives_itr < m; drives_itr++) {
        int drives_item = stoi(drives_temp[drives_itr]);
        drives[drives_itr] = drives_item;
    }

    // Compute the maximum money that can be spent
    int moneySpent = getMoneySpent(keyboards, drives, b);

    fout << moneySpent << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    // Remove consecutive spaces
    string::iterator new_end = unique(input_string.begin(), input_string.end(), 
        [] (const char &x, const char &y) {
            return x == y and x == ' ';
        });

    input_string.erase(new_end, input_string.end());

    // Remove trailing spaces
    while (!input_string.empty() && input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));
        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i));

    return splits;
}
