#include <algorithm>
#include <iostream>
#include <vector>

int find_root(int *U, int i);
void merge(int *U, int i, int j);

int main(int argc, char **argv) {
  int n = 14;
  int U[15];
  std::vector<int> *p[15];
  for (int i = 1; i <= n; i++)
    p[i] = new std::vector<int>[15];
  for (int i = 1; i <= n; i++)
    U[i] = i;
  merge(U, 1, 11);
  merge(U, 7, 11);
  merge(U, 2, 12);
  merge(U, 12, 8);
  merge(U, 11, 12);
  merge(U, 3, 13);
  merge(U, 4, 13);
  merge(U, 13, 14);
  merge(U, 14, 9);
  merge(U, 5, 14);
  merge(U, 6, 10);
  for (int i = 1; i <= n; i++)
    U[i] = find_root(U, i);
  for (int i = 1; i <= n; i++)
    p[U[i]]->push_back(i);
  for (int i = 1; i <= n; i++) {
    if (!(p[i]->empty())) {
      for (auto it = p[i]->begin(); it != p[i]->end(); it++) {
        std::cout << *it << "\t";
      }
      std::cout << std::endl;
    }
  }
  return 0;
}

int find_root(int *U, int i) {
  if (i == U[i])
    return i;
  else
    U[i] = find_root(U, U[i]);
  return find_root(U, U[i]);
}

void merge(int *U, int i, int j) {
  U[find_root(U, j)] = find_root(U, i);
  return;
}