#include <iostream>
#include <string>
#include <vector>

using namespace std;

int taxi[100];
int pizza[100];
int girls[100];
string name[100];

bool dec(char* s) {
  for (int i = 1; i < 6; i++) {
    if (s[i - 1] - s[i] < 1) {
      return false;
    }
  }
  return true;
}

bool sam(char* s) {
  for (int i = 1; i < 6; i++) {
    if (s[i - 1] - s[i] != 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int n;
  cin >> n;

  char nums[6];
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p >> name[i];

    string line;
    for (int j = 0; j < p; j++) {
      cin >> line;
      nums[0] = line[0];
      nums[1] = line[1];
      nums[2] = line[3];
      nums[3] = line[4];
      nums[4] = line[6];
      nums[5] = line[7];

      if (sam(nums)) {
        taxi[i]++;
      } else if (dec(nums)) {
        pizza[i]++;
      } else {
        girls[i]++;
      }
    }
  }

  int bestg = 0;
  int bestt = 0;
  int bestp = 0;
  vector<int> gp, tp, pp;

  for (int i = 0; i < n; i++) {
    //cout << taxi[i] << ":" << pizza[i] << ":" << girls[i] << endl;
    if (taxi[i] > taxi[bestt]) {
      bestt = i;
      tp.clear();
      tp.push_back(i);
    } else if (taxi[i] == taxi[bestt]) {
      tp.push_back(i);
    }

    if (pizza[i] > pizza[bestp]) {
      bestp = i;
      pp.clear();
      pp.push_back(i);
    } else if (pizza[i] == pizza[bestp]) {
      pp.push_back(i);
    }

    if (girls[i] > girls[bestg]) {
      bestg = i;
      gp.clear();
      gp.push_back(i);
    } else if (girls[i] == girls[bestg]) {
      gp.push_back(i);
    }
  }

  cout << "If you want to call a taxi, you should call: ";
  cout << name[tp[0]];
  for (int i = 1; i < tp.size(); i++) {
    cout << ", " << name[tp[i]];
  }
  cout << "." << endl;

  cout << "If you want to order a pizza, you should call: ";
  cout << name[pp[0]];
  for (int i = 1; i < pp.size(); i++) {
    cout << ", " << name[pp[i]];
  }
  cout << "." << endl;

  cout << "If you want to go to a cafe with a wonderful girl, you should call: ";
  cout << name[gp[0]];
  for (int i = 1; i < gp.size(); i++) {
    cout << ", " << name[gp[i]];
  }
  cout << "." << endl;
}
