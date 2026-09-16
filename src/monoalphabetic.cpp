#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iomanip>

using namespace std;

// ------------------------------------------------------------
// Utility functions
// ------------------------------------------------------------

string toUpperText(const string& text) {
    string result = text;

    for (size_t i = 0; i < result.length(); i++) {
        if (result[i] >= 'a' && result[i] <= 'z') {
            result[i] = result[i] - 'a' + 'A';
        }
    }

    return result;
}

// ------------------------------------------------------------
// 1. apply_substitution()
// ------------------------------------------------------------

string apply_substitution(const string& text,
                          const string& key) {

    string result = text;

    for (size_t i = 0; i < result.length(); i++) {

        char c = result[i];

        if (c >= 'A' && c <= 'Z') {
            int index = c - 'A';
            result[i] = key[index];
        }
        else if (c >= 'a' && c <= 'z') {
            int index = c - 'a';
            result[i] = tolower(key[index]);
        }
    }

    return result;
}

// ------------------------------------------------------------
// 2. frequency_analysis()
// ------------------------------------------------------------

void frequency_analysis(const string& ciphertext) {

    int frequency[26] = {0};
    int totalLetters = 0;

    for (size_t i = 0; i < ciphertext.length(); i++) {

        char c = ciphertext[i];

        if (c >= 'A' && c <= 'Z') {
            frequency[c - 'A']++;
            totalLetters++;
        }
        else if (c >= 'a' && c <= 'z') {
            frequency[c - 'a']++;
            totalLetters++;
        }
    }

    vector<pair<char, int>> frequencies;

    for (int i = 0; i < 26; i++) {
        frequencies.push_back(
            make_pair(char('A' + i), frequency[i])
        );
    }

    // Sort manually by frequency.
    // No library sorting function is used.
    for (int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {

            if (frequencies[j].second >
                frequencies[i].second) {

                pair<char, int> temp = frequencies[i];
                frequencies[i] = frequencies[j];
                frequencies[j] = temp;
            }
        }
    }

    cout << "\n========== LETTER FREQUENCY ANALYSIS ==========\n";

    cout << left
         << setw(10) << "Letter"
         << setw(10) << "Count"
         << setw(12) << "Percent"
         << "\n";

    cout << "----------------------------------------\n";

    for (int i = 0; i < 26; i++) {

        double percentage = 0.0;

        if (totalLetters > 0) {
            percentage =
                (double)frequencies[i].second
                * 100.0 / totalLetters;
        }

        cout << left
             << setw(10) << frequencies[i].first
             << setw(10) << frequencies[i].second
             << fixed << setprecision(2)
             << percentage << "%\n";
    }

    cout << "\nMost frequent ciphertext letters:\n";

    for (int i = 0; i < 5; i++) {
        cout << frequencies[i].first
             << " (" << frequencies[i].second << ")\n";
    }
}

// ------------------------------------------------------------
// Extract words manually
// ------------------------------------------------------------

vector<string> extractWords(const string& text) {

    vector<string> words;
    string current = "";

    for (size_t i = 0; i < text.length(); i++) {

        char c = text[i];

        if ((c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z')) {

            if (c >= 'a' && c <= 'z') {
                c = c - 'a' + 'A';
            }

            current += c;
        }
        else {

            if (current.length() > 0) {
                words.push_back(current);
                current = "";
            }
        }
    }

    if (current.length() > 0) {
        words.push_back(current);
    }

    return words;
}

// ------------------------------------------------------------
// 3. word_frequency_analysis()
// ------------------------------------------------------------

void word_frequency_analysis(const string& ciphertext) {

    vector<string> words = extractWords(ciphertext);

    vector<pair<string, int>> frequencies;

    for (size_t i = 0; i < words.size(); i++) {

        bool found = false;

        for (size_t j = 0; j < frequencies.size(); j++) {

            if (frequencies[j].first == words[i]) {
                frequencies[j].second++;
                found = true;
                break;
            }
        }

        if (!found) {
            frequencies.push_back(
                make_pair(words[i], 1)
            );
        }
    }

    // Manual sorting
    for (size_t i = 0; i < frequencies.size(); i++) {

        for (size_t j = i + 1; j < frequencies.size(); j++) {

            if (frequencies[j].second >
                frequencies[i].second) {

                pair<string, int> temp = frequencies[i];

                frequencies[i] = frequencies[j];
                frequencies[j] = temp;
            }
        }
    }

    cout << "\n========== WORD FREQUENCY ANALYSIS ==========\n";

    for (size_t i = 0; i < frequencies.size(); i++) {

        cout << frequencies[i].first
             << " -> "
             << frequencies[i].second
             << "\n";
    }

    cout << "\nOne-letter words:\n";

    for (size_t i = 0; i < words.size(); i++) {

        if (words[i].length() == 1) {
            cout << words[i] << " ";
        }
    }

    cout << "\n\nTwo-letter words:\n";

    for (size_t i = 0; i < words.size(); i++) {

        if (words[i].length() == 2) {
            cout << words[i] << " ";
        }
    }

    cout << "\n\nThree-letter words:\n";

    for (size_t i = 0; i < words.size(); i++) {

        if (words[i].length() == 3) {
            cout << words[i] << " ";
        }
    }

    cout << "\n";
}

// ------------------------------------------------------------
// Generate word pattern
//
// Example:
//
// "THAT" -> 0 1 0 2
// "KICK" -> 0 1 1 2
// "TEST" -> 0 1 2 0
// ------------------------------------------------------------

string getPattern(const string& word) {

    string pattern = "";

    int nextNumber = 0;

    char seen[26];
    int values[26];

    for (int i = 0; i < 26; i++) {
        seen[i] = '\0';
        values[i] = -1;
    }

    for (size_t i = 0; i < word.length(); i++) {

        char c = word[i];

        int index = c - 'A';

        if (values[index] == -1) {

            values[index] = nextNumber;
            nextNumber++;
        }

        pattern += char('0' + values[index]);
    }

    return pattern;
}

// ------------------------------------------------------------
// 4. pattern_analysis()
// ------------------------------------------------------------

void pattern_analysis(const string& ciphertext) {

    vector<string> words = extractWords(ciphertext);

    cout << "\n========== PATTERN ANALYSIS ==========\n";

    for (size_t i = 0; i < words.size(); i++) {

        string pattern = getPattern(words[i]);

        bool repeated = false;

        for (size_t j = 0; j < i; j++) {

            if (getPattern(words[j]) == pattern) {
                repeated = true;
                break;
            }
        }

        if (repeated) {

            cout << words[i]
                 << " -> "
                 << pattern
                 << "  [repeated pattern]\n";
        }
    }
}

// ------------------------------------------------------------
// 5. display_partial_plaintext()
// ------------------------------------------------------------

void display_partial_plaintext(
    const string& ciphertext,
    const string& partialKey) {

    string result = ciphertext;

    for (size_t i = 0; i < result.length(); i++) {

        char c = result[i];

        if (c >= 'A' && c <= 'Z') {

            int index = c - 'A';

            if (partialKey[index] != '?') {
                result[i] = partialKey[index];
            }
            else {
                result[i] = '_';
            }
        }
    }

    cout << "\n========== PARTIAL PLAINTEXT ==========\n";
    cout << result << "\n";
}

// ------------------------------------------------------------
// 6. verify_solution()
// ------------------------------------------------------------

bool verify_solution(
    const string& plaintext,
    const string& ciphertext,
    const string& key) {

    string encrypted =
        apply_substitution(plaintext, key);

    if (encrypted == ciphertext) {
        return true;
    }

    return false;
}

// ------------------------------------------------------------
// Main
// ------------------------------------------------------------

int main() {

    ifstream input("data/plaintext.txt");

    if (!input) {

        cout << "Error: Could not open data/plaintext.txt\n";
        return 1;
    }

    string plaintext;
    string line;

    while (getline(input, line)) {

        plaintext += line;
        plaintext += "\n";
    }

    input.close();

    plaintext = toUpperText(plaintext);

    cout << "========== MONOALPHABETIC SUBSTITUTION CIPHER ==========\n";

    cout << "\nPlaintext loaded successfully.\n";

    cout << "\nPlaintext:\n";
    cout << plaintext << "\n";

    // Example substitution key.
    //
    // Plain:  ABCDEFGHIJKLMNOPQRSTUVWXYZ
    // Cipher: QWERTYUIOPASDFGHJKLZXCVBNM
    //
    // This is only an example key.

    string key = "QWERTYUIOPASDFGHJKLZXCVBNM";

    string ciphertext =
        apply_substitution(plaintext, key);

    cout << "\n========== CIPHERTEXT ==========\n";
    cout << ciphertext << "\n";

    frequency_analysis(ciphertext);

    word_frequency_analysis(ciphertext);

    pattern_analysis(ciphertext);

    // Initially unknown key
    string partialKey = "??????????????????????????";

    display_partial_plaintext(
        ciphertext,
        partialKey
    );

    // Example verification
    bool verified =
        verify_solution(
            plaintext,
            ciphertext,
            key
        );

    cout << "\n========== VERIFICATION ==========\n";

    if (verified) {
        cout << "Verification successful.\n";
    }
    else {
        cout << "Verification failed.\n";
    }

    return 0;
}
