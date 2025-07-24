#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void createNewFile(const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        cout << "New file '" << filename << "' created successfully.\n";
        file.close();
    } else {
        cout << "Failed to create file.\n";
    }
}

void writeToFile(const string& filename) {
    ofstream file(filename, ios::app); // append mode
    if (file.is_open()) {
        cout << "Enter text to write (type ':wq' to save and quit):\n";
        string line;
        while (getline(cin, line)) {
            if (line == ":wq") break;
            file << line << "\n";
        }
        file.close();
    } else {
        cout << "Unable to open file.\n";
    }
}

void readFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        cout << "Contents of '" << filename << "':\n\n";
        string line;
        while (getline(file, line)) {
            cout << line << "\n";
        }
        file.close();
    } else {
        cout << "File not found.\n";
    }
}

int main() {
    int choice;
    string filename;

    while (true) {
        cout << "\n--- Text Editor Menu ---\n";
        cout << "1. Create new file\n";
        cout << "2. Open file\n";
        cout << "3. Write to file\n";
        cout << "4. View file content\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // flush newline

        switch (choice) {
            case 1:
                cout << "Enter filename: ";
                getline(cin, filename);
                createNewFile(filename);
                break;

            case 2:
                cout << "Enter filename: ";
                getline(cin, filename);
                readFile(filename);
                break;

            case 3:
                cout << "Enter filename: ";
                getline(cin, filename);
                writeToFile(filename);
                break;

            case 4:
                cout << "Enter filename: ";
                getline(cin, filename);
                readFile(filename);
                break;

            case 5:
                cout << "Exiting the editor. Goodbye!\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
