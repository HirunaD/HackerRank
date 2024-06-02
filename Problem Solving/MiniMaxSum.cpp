#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'miniMaxSum' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

// Function to find the minimum and maximum sum of exactly four out of five integers
void miniMaxSum(vector<int> arr) {
    // Initialize variables to store the sum of all elements
    long totalSum = 0;
    // Calculate the total sum of all elements
    for (int num : arr) {
        totalSum += num;
    }
    
    // Initialize variables to find the minimum and maximum sums
    long minSum = totalSum - arr[0];
    long maxSum = totalSum - arr[0];

    // Iterate through the array to find the minimum and maximum sums
    for (int num : arr) {
        long currentSum = totalSum - num;
        if (currentSum < minSum) {
            minSum = currentSum;
        }
        if (currentSum > maxSum) {
            maxSum = currentSum;
        }
    }
    
    // Print the results
    cout << minSum << " " << maxSum << endl;
}

int main()
{
    // Read the input array from standard input
    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    // Split the input string into individual elements
    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    // Initialize the array to hold 5 integers
    vector<int> arr(5);

    // Convert the input strings to integers and store in the array
    for (int i = 0; i < 5; i++) {
        int arr_item = stoi(arr_temp[i]);
        arr[i] = arr_item;
    }

    // Call the miniMaxSum function
    miniMaxSum(arr);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;
    string::size_type start = 0;
    string::size_type end = 0;

    // Split the string by spaces and store in tokens
    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }

    // Add the last token
    tokens.push_back(str.substr(start));
    return tokens;
}
