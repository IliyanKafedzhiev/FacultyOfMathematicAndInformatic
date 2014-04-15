#include <cstdlib>
#include <utility>
#include <vector>

using namespace std;

int dirs[4][2] = {
  {0, 1},
  {1, 0},
  {0, -1},
  {-1, 0}
};

pair<int, int> add(pair<int, int> pos, int dirIndex) {
  return make_pair(pos.first + dirs[dirIndex][0],
          pos.second + dirs[dirIndex][1]);
}

bool inRectangle(int dimensions[], pair<int, int> pos) {
  return pos.first >= dimensions[0] &&
          pos.first <= dimensions[2] &&
          pos.second <= dimensions[1] &&
          pos.second >= dimensions[3];
}

int main() {
  int N;
  scanf("%d", &N);
  int dimensions[] = {0, N - 1, N - 1, 0};
  int delta[] = {1, -1, -1, 1};
  int dir = 0;
  pair<int, int> pos(0, 0);
  vector<vector<int> > result(N, vector<int>(N));
  int currentNumber = 1;
  while (dimensions[0] <= dimensions[2] && dimensions[3] <= dimensions[1]) {
    pair<int, int> next = pos;
    do {
      pos = next;
      result[pos.first][pos.second] = currentNumber;
      ++currentNumber;
    } while (inRectangle(dimensions, (next = add(pos, dir))));
    dimensions[dir] += delta[dir];
    ++dir;
    dir %= 4;
    pos = add(pos, dir);
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      printf("%d%s", result[i][j], j == N - 1 ? "" : " ");
    }
    printf("\n");
  }
  return 0;
}

