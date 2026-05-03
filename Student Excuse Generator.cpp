#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

// ✅ Remove leading and trailing spaces
string trim(string str) {
    int start = 0;
    int end = str.length() - 1;

    while (start <= end && isspace(str[start])) {
        start++;
    }

    while (end >= start && isspace(str[end])) {
        end--;
    }

    return str.substr(start, end - start + 1);
}

// ✅ Replace all {name} occurrences
string replaceName(string text, string name) {
    size_t pos = 0;

    while ((pos = text.find("{name}", pos)) != string::npos) {
        text.replace(pos, 6, name);
        pos += name.length();
    }

    return text;
}

int main() {
    string name;

    // ✅ Input validation loop
    while (true) {
        cout << "Enter student name: ";
        getline(cin, name);

        name = trim(name);

        if (!name.empty()) {
            break;
        }

        cout << "⚠️ Invalid input! Name cannot be empty or spaces only.\n";
    }

    srand(time(0));

    vector<string> excuses = {
        "{name} forgot to submit the homework because the laptop crashed.",
        "{name} lost internet connection during submission.",
        "{name}'s file mysteriously disappeared.",
        "{name}'s computer updated for 5 hours straight.",
        "{name} accidentally deleted the assignment.",
        "{name}'s keyboard stopped working suddenly.",
        "{name} got stuck in a Wi-Fi blackout zone.",
        "{name}'s system refused to save the file.",
        "{name} opened YouTube and forgot everything.",
        "{name}'s laptop battery died at 100%."
    };

    int index = rand() % excuses.size();

    string result = replaceName(excuses[index], name);

    cout << "\n📢 Excuse:\n" << result << endl;

    return 0;
}
