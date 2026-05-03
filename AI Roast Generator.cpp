#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to replace {name} with user input
string replaceName(string text, string name) {
    size_t pos = text.find("{name}");
    while (pos != string::npos) {
        text.replace(pos, 6, name);
        pos = text.find("{name}");
    }
    return text;
}

int main() {
    string name;
    int choice;

    cout << "Enter your name: ";
    getline(cin, name);

    // ✅ Handle empty input safely
    if (name.empty()) {
        cout << "⚠️ Name cannot be empty. Please restart the program." << endl;
        return 0;
    }

    // ✅ Seed randomness ONCE
    srand(time(0));

    // Roast categories
    vector<string> light = {
        "{name}, you’re doing fine… just a bit slow.",
        "{name}, your code needs a little coffee.",
        "{name}, not bad… keep improving."
    };

    vector<string> medium = {
        "{name}'s code works… sometimes.",
        "Bugs feel comfortable in {name}'s code.",
        "{name} debugs by guessing."
    };

    vector<string> savage = {
        "{name}'s code has more bugs than logic.",
        "Even Google avoids {name}'s questions.",
        "{name} doesn't debug—they create new bugs."
    };

    // Menu
    cout << "\nChoose Roast Level:\n";
    cout << "1. Light Roast\n";
    cout << "2. Medium Roast\n";
    cout << "3. Savage Roast\n";
    cout << "Enter choice: ";
    cin >> choice;

    vector<string> selected;

    if (choice == 1) {
        selected = light;
    }
    else if (choice == 2) {
        selected = medium;
    }
    else if (choice == 3) {
        selected = savage;
    }
    else {
        cout << "Invalid choice!" << endl;
        return 0;
    }

    // ✅ Random selection
    int index = rand() % selected.size();
    string roast = replaceName(selected[index], name);

    // Output
    cout << "\n🔥 Roast:\n" << roast << endl;

    return 0;
}
