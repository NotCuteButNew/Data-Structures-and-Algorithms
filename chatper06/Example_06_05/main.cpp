#include <iostream>
#include <ostream>
#include <string>

struct task {
  std::string name;
  int starting_time;
  int ending_time;
};

std::ostream &operator<<(std::ostream &out, struct task &x) {
  out << x.name << "\t" << x.starting_time << "\t" << x.ending_time;
  return out;
}

int main(int argc, char **argv) {
  if (argc > 1) {
    struct task *tasks = new struct task[argc - 1];
    for (int i = 1; i < argc; i += 3) {
      tasks[i].name = argv[i];
      tasks[i].starting_time = std::stoi(argv[i + 1]);
      tasks[i].ending_time = std::stoi(argv[i + 2]);
    }
    
    for (int i = 1; i < argc; i += 3) {
      std::cout << tasks[i] << std::endl;
    }
  }
  return 0;
}