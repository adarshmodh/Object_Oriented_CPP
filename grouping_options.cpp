#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'countOptions' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER people
 *  2. INTEGER groups
 */

long countOptions(int people, int groups) {
    if (groups == 0) {
        if (people == 0)
            return 1;
        return 0;
    }
    if (groups > people)
        return 0;
    vector<vector<int>> DP(people+1, vector<int>(groups + 1, 0));
    DP[0][0] = 1;
    for (int i = 1; i <= people; i++) {
        for (int j = 1; j <= groups; j++) {
            if (j > i)
                break;
            DP[i][j] = DP[i-j][j] + DP[i-1][j-1]; 
        }
    }
    return DP[people][groups];  
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string people_temp;
    getline(cin, people_temp);

    int people = stoi(ltrim(rtrim(people_temp)));

    string groups_temp;
    getline(cin, groups_temp);

    int groups = stoi(ltrim(rtrim(groups_temp)));

    long result = countOptions(people, groups);

    fout << result << "\n";

    fout.close();

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
