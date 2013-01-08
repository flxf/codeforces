#include <iostream>
#include <string>

using namespace std;

char buffer[2000000];
int main() {
  string line;

  bool wasamp = true;
  while (getline(cin, line)) {
    //cout << line << endl;

    bool isamp = false;
    for (int i = 0; i < line.length(); i++) {
      if (line[i] != ' ') {
        if (line[i] == '#') {
          isamp = true;
        }
        break;
      }
    }

    if (!wasamp && isamp) {
      cout << endl;
    }

    for (int i = 0; i < line.length(); i++) {
      if (isamp) {
        cout << line[i];
      } else if (line[i] != ' ') {
        cout << line[i];
      }
    }

    if (isamp) {
      cout << endl;
      //cout << (char) 13 << (char) 10;
    }
    wasamp = isamp;
  }

  if (!wasamp) {
    cout << endl;
    //cout << (char) 13 << (char) 10;
  }
}
