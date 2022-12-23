#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

namespace dec_2021_1 {
  using namespace std;

  int K_patchCount, M_rivalCowNum, N_johnCowCount;

  //vector<int> grassloc;

  //location, tastiness
  map<int, int> tastiness;
  vector<int> enemy;
  vector<int> amounts;

  vector<int> choices;

  void loadChoices() {
    auto lead = tastiness.begin();
    auto trail = tastiness.begin();
    int max1, temp, total = 0;
    double distance;

    while (lead->first < enemy[0]) {
      total += lead->second;
      lead++;
    }

    amounts.push_back(total);

    for (int post = 0; post < M_rivalCowNum - 1; post++) {
      //initalize the crawler
      max1 = temp = total = 0;

      distance = (double)(enemy[post + 1] - enemy[post]);

      for (lead = tastiness.upper_bound(enemy[post]),trail = lead;
      lead->first < enemy[post + 1];         lead++) {
        temp += lead->second;
        total += lead->second;

        while (lead->first - trail->first >= distance / 2) {        
          temp -= trail->second;
          trail++;
        }
        
        if (max1 < temp) {
            max1 = temp;
        }
      }

      amounts.push_back(max1);
      amounts.push_back(total - max1);
    }

    total = 0;

    lead = tastiness.upper_bound(enemy.back());
    while (lead != tastiness.end()) {
      total += lead->second;
      lead++;
    }

    amounts.push_back(total);
  }


  int main() {

    cin >> K_patchCount >> M_rivalCowNum >> N_johnCowCount;

    int temploc, temptaste, totaltaste = 0;
    for (int x = 0; x < K_patchCount; x++) {
      cin >> temploc >> temptaste;
      tastiness[temploc] = temptaste;
    }

    //sort(tastiness.begin(), tastiness.end());

    for (int x = 0; x < M_rivalCowNum; x++) {
      cin >> temploc;
      enemy.push_back(temploc);
    }

    sort(enemy.begin(), enemy.end());

    for (int x : enemy) {
      if (tastiness.count(x)) {
        tastiness.erase(x);
      }
    }

    loadChoices();

    long long best = 0;

    sort(amounts.begin(), amounts.end());

    if (amounts.size() < N_johnCowCount) {
      for (int x : amounts) {
        best += x;
      }
    }
    else {
      for (int x = amounts.size() - 1; x >= amounts.size() - N_johnCowCount; x--) {
        best += amounts[x];
      }
    }

    cout << best << endl;
    return 0;
  }
}

int main()
{
  dec_2021_1::main();


  return 0;
}
