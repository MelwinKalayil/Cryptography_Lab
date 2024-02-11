#include <iostream>
#include <string>

using namespace std;

// Function to encrypt the plain text
string encryptVigenere(string text, string key) {
    string result = "";

    // Loop through each character in the text
    for (int i = 0, j = 0; i < text.length(); ++i) {
        char c = text[i];

        // Encrypt only alphabetic characters
        if (c >= 'A' && c <= 'Z') {
            result += (c + key[j] - 2 * 'A') % 26 + 'A';
            j = (j + 1) % key.length();
        } else {
            result += c;
        }
    }

    return result;
}

// Function to decrypt the encrypted text
string decryptVigenere(string text, string key) {
    string result = "";

    // Loop through each character in the text
    for (int i = 0, j = 0; i < text.length(); ++i) {
        char c = text[i];

        // Decrypt only alphabetic characters
        if (c >= 'A' && c <= 'Z') {
            result += (c - key[j] + 26) % 26 + 'A';
            j = (j + 1) % key.length();
        } else {
            result += c;
        }
    }

    return result;
}

int main() {
    int choice;
    string text, key;

    while (true) {
        cout << "\nVigenere Cipher\n";
        cout << "1. Encrypt\n";
        cout << "2. Decrypt\n";
        cout << "3. Exit\n";
        cout << "Enter your choice (1-3): ";
        cin >> choice;
        cin.ignore(); // Ignore the newline character left in the input buffer

        switch (choice) {
            case 1: // Encryption
                cout << "Enter plain text: ";
                getline(cin, text);
                cout << "Enter key: ";
                cin >> key;
                cout << "Encrypted Text: " << encryptVigenere(text, key) << endl;
                break;
            case 2: // Decryption
                cout << "Enter encrypted text: ";
                getline(cin, text);
                cout << "Enter key: ";
                cin >> key;
                cout << "Decrypted Text: " << decryptVigenere(text, key) << endl;
                break;
            case 3: // Exit
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}
