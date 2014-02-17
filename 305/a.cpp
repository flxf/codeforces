#include <iostream>
#include <string>
#include <deque>

using namespace std;

string solns[8];
int best;
deque<int> best_answers;

void rec(int i, int has, int mask, deque<int> answers) {
  if (i == 8) {
    if (has > best) {
      best = has;
      best_answers = answers;
    }

    return;
  }

  if (solns[i] == "") {
    rec(i + 1, has, mask, answers);
    return;
  }

  if ((i & mask) == 0) {
    answers.push_back(i);
    rec(i + 1, has + 1, mask | i, answers);
    answers.pop_back();
  }
  rec(i + 1, has, mask, answers);
}

int main() {
  int k;
  cin >> k;

  for (int i = 0; i < 8; i++) {
    solns[i] = "";
  }

  int places;
  for (int i = 0; i < k; i++) {
    string num;
    cin >> num;

    places = 0;
    for (int j = 0; j < num.size(); j++) {
      if (num[num.size() - j - 1] != '0') {
        places |= (1 << j);
      }
    }

    solns[places] = num;
  }

  best = 0;
  deque<int> space;
  rec(0, 0, 0, space);

  cout << best << endl;
  while (best_answers.size() != 0) {
    cout << solns[best_answers.front()] << " ";
    best_answers.pop_front();
  }
  cout << endl;
}
