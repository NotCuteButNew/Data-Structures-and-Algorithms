#include <algorithm>
#include <iostream>
#include <iterator>
#include <ostream>
#include <stack>
#include <string>

int main(const int argc, char **argv) {
  if (argc > 1) {
    std::stack<int> inputTrack, *holdingTrack, outputTrack;
    holdingTrack = new std::stack<int>[3];
    for (int i = 1; i < argc; i++)
      inputTrack.push(std::stoi(argv[i]));
    int allowOutput = 1;
    while (inputTrack.size() != 0) {
      if (allowOutput == inputTrack.top()) {
        outputTrack.push(allowOutput);
        inputTrack.pop();
        allowOutput++;
      } else {
        for (int j = 0; j < 3; j++) {
          if (holdingTrack[j].size() == 0 ||
              (holdingTrack[j].top() - inputTrack.top() == 1)) {
            holdingTrack[j].push(inputTrack.top());
            inputTrack.pop();
            break;
          } else if (j == 2) {
            std::cout << "Can't sort!" << std::endl;
            return 0;
          } else
            continue;
        }
      }
    }
    int order[3] = {0};
    int max_i = 0, min_i = 0;
    for (int i = 0; i < 3; i++) {
      if (holdingTrack[i].size() != 0) {
        if (holdingTrack[max_i].top() < holdingTrack[i].top())
          max_i = i;
        if (holdingTrack[min_i].top() > holdingTrack[i].top())
          min_i = i;
      }
    }
    order[0] = min_i;
    if (min_i != max_i)
      order[1] = 3 - min_i - max_i;
    order[2] = max_i;
    for (int i = 0; i < 3; i++) {
      while (holdingTrack[order[i]].size() != 0) {
        outputTrack.push(holdingTrack[order[i]].top());
        holdingTrack[order[i]].pop();
      }
    }
    while (outputTrack.size() != 0) {
      std::cout << outputTrack.top() << std::endl;
      outputTrack.pop();
    }
  }
  return 0;
}