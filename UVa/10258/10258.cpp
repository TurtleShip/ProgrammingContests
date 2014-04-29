#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#define pb(x) push_back(x)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define SZ(c) int((c).size())
#define TRACE(x...) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)

const int INF = 0x3F3F3F3F;
const int NEGINF = 0xC0C0C0C0;
const double EPS = 1e-8;

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef long long LL;

int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

/*
  The problem description is wrong.
  If contestants have the same number of problems, then sort by "INCREASING"
  amounts of penalty time. ( The less penalty, the better )

  Also, there can be problem number up to 12 although the original problem
  statement states that there could be up to only problem number 9.
*/
const int maxProblem = 50; // should be 10, but not trusting problem statment.
typedef struct Score {
  int teamId;
  int solved;
  int timePenalty;
  int numWrongs[maxProblem];
  bool isCorrect[maxProblem];

  Score(int _teamId) {
    teamId = _teamId;
    solved = 0;
    timePenalty = 0;
    fill(numWrongs, numWrongs + maxProblem, 0);
    fill(isCorrect, isCorrect + maxProblem, false);
  }

  Score() {
    Score(-1);
  }

  void addWrong(int pid) {
    if(!isCorrect[pid]) numWrongs[pid]++;
  }

  void addCorrect(int pid, int solvedTime) {
    if(!isCorrect[pid]) {
      isCorrect[pid] = true;
      solved++;
      timePenalty += solvedTime + numWrongs[pid] * 20;
    }
  }
} Score;

bool scoreSort(const Score& s1, const Score& s2) {
  if(s1.solved != s2.solved) return s1.solved > s2.solved;
  if(s1.timePenalty != s2.timePenalty) return s1.timePenalty < s2.timePenalty;
  return s1.teamId < s2.teamId;
}

typedef struct ScoreBoard {
  Score scores[500];
  int numCompetingTeams;
  int teamIds[500];

  ScoreBoard() {
    numCompetingTeams = 0;
    for(int i=0; i <= 400; i++)
      scores[i].teamId = -1;
  }

  Score& getScore(int teamId) {
    if(scores[teamId].teamId == -1) {
      scores[teamId] = *(new Score(teamId));
      teamIds[numCompetingTeams++] = teamId;
    }
    return scores[teamId];
  }

  void addTeam(int teamId) {
    if(scores[teamId].teamId == -1) {
      scores[teamId] = *(new Score(teamId));
      teamIds[numCompetingTeams++] = teamId;
    }
  }


  void printScoreBoard() {
    vector<Score> result;
    for(int i=0; i < numCompetingTeams; i++) {
      result.pb( scores[teamIds[i]] );
    }
    sort(all(result), scoreSort);
    for(int i=0; i < result.size(); i++) {
      printf("%d %d %d\n", result[i].teamId, result[i].solved, result[i].timePenalty);
    }
  }
} ScoreBoard;

int main() {

  int T;
  string input;
  getline(cin, input);
  sscanf(input.c_str(), "%d", &T);
  getline(cin, input);

  for(int cid=1; cid <= T; cid++) {

    if(cid > 1) printf("\n"); // empty line between two consecutive outputs
    set<int> competingTeams;
    int teamId, pid, timeSpent;
    char verdict;
    ScoreBoard scoreBoard;

    while(getline(cin, input) && input.size() > 0) {

      sscanf(input.c_str(), "%d %d %d %c", &teamId, &pid, &timeSpent, &verdict);
      if(verdict == 'C') {
        scoreBoard.getScore(teamId).addCorrect(pid, timeSpent);
      } else if(verdict == 'I') {
        scoreBoard.getScore(teamId).addWrong(pid);
      } else {
        scoreBoard.addTeam(teamId);
      }
    }


    scoreBoard.printScoreBoard();
  }
  return 0;
}
