#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
//test test
int main() {
    vector <string> file;
    string command = "";
    string input = "";
    string inBuffer;
    string fileName;
    int lineNum;
    ofstream outFile;
    ifstream inputFile;
    string copyBuffer="";
    while (input != "quit") {
        cout << "> ";
        cin >> input;

        if (input == "q") {
            break;
        } else if (input == "a") {
            cout << "Enter new line: ";
            getline(cin, inBuffer);
            file.push_back(inBuffer);
        } else if (input[0] == 'd') {
            cin >> lineNum;
            file.erase(file.begin() + (lineNum - 1));
        } else if (input[0] == 'i') {
            cin >> lineNum;
            cout << "Insert line after " << lineNum << "> ";
            cin.ignore();
            getline(cin, inBuffer);
            file.insert(file.begin() + (lineNum - 1), inBuffer);
        } else if (input[0] == 'r') {
            cin >> lineNum;
            cout << "Replace line " << lineNum << "> ";
            cin.ignore();
            getline(cin, inBuffer);
            file[lineNum] = inBuffer;
        } else if (input == "write") {
            cout << "Enter output file name: ";
            cin >> fileName;
            outFile.open(fileName);
            for (auto l : file) {
                outFile << l << endl;
            }
            outFile.close();
        } else if (input == "sort") {
            sort(file.begin(), file.end());
        } else if (input == "stat") {
            int charCount = 0;
            for (auto l : file) {
                charCount += l.size();
            }
            cout << "[" << file.size() << "] [" << charCount << "]" << endl;

        }
        else if (input == "yank") {
            cin >> lineNum;
            if (lineNum > 0 && lineNum <= file.size()){
                copyBuffer = file[lineNum-1];
            }
        }
        else if ( input == "put") {
            cin >> lineNum;
            if (lineNum >= 0 && lineNum <= file.size()) {
                file.insert(file.begin() + lineNum, copyBuffer);
            }
        }
        else if (input=="help") {
            cout<<"Q: Quit \n append: add a new line at the end of the file \n change: Replace old with new (prompt for 2 strings, old and new) \n delete n: Delete line n \n find target: Find target string, print out line containing it, if found\n help: Prints out this list of commands\n insert n: Insert a line after line n \n read: Prompts for file name to read in \n replace n: Replace line n with a new line \n sort: Sort the file \n stat: Stats for file (line count, character count) \n yank n: Copy line n into the copy buffer \n write: Prompts for file to write out to \n";
        }
        else if (input == "read") {
            cout << "Enter file name: ";
            cin >> fileName;
            inputFile.open(fileName);
            while (getline(inputFile, inBuffer)) {
                file.push_back(inBuffer);
            }
            inputFile.close();
        }


         else if (input == "change") {
        string oldStr, newStr;

        cout << "Enter old string: ";
        cin.ignore();
        getline(cin, oldStr);

        cout << "Enter new string: ";
        getline(cin, newStr);
             for (string &l : file) {
            size_t pos = l.find(oldStr);

            while (pos != string::npos) {
                l.replace(pos, oldStr.length(), newStr);

                pos = l.find(oldStr, pos + newStr.length());
            }
        }
        }

        int i = 1;
        for (auto l : file) {
            if (input == "c") {
                cout << "[" << i++ << "] " << "[" << l.size() << "] ";
            } else {
                cout << "[" << i++ << "] ";
            }
            cout << l << endl;;
        }
    }
}