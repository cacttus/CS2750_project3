#include "./calc.h"

void runOpts(char* opt);

int main(int argc, char** argv) {
  if (argc == 1) {
    calculate();
  }
  else if (argc == 2) {
    runOpts(argv[1]);
  }
  else {
    printf("Invalid number of arguments\n");
    exit(1);
  }

  return 0;
}

void runOpts(char* opt) {
  Command cmd;
  if (getCommand(opt, &cmd)!=0) {
    printf("Invalid Switch %s\n", opt);
    exit(1);
  }

  if (cmd == CMD_TEST) {
    printf("Running tests.\n");
    runTests();
  }
  else if (cmd == CMD_HELP) {
    printf("calc: Simple Calculator Program.\n");
    printf("Usage:\n");
    printf("  calc\n");
    printf("  calc -t\n");
    printf("  calc -h\n");
    printf("Opts:\n");
    printf("  -t: Run tests.\n");
    printf("  -h: Show help.\n");
  }
}