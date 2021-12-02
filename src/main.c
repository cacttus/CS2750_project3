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
  if (!getCommand(opt, &cmd)) {
    printf("Invalid Switch %s\n", opt);
    exit(1);
  }

  if (cmd == CMD_TEST) {
    printf("Run tests.");
    runTests();
  }
  else if (cmd == CMD_HELP) {
    printf("calc: Simple Calculator Program.\n");
    printf("Usage:\n");
    printf("  calc [opts] num1 num2:\n");
    printf("Opts:\n");
    printf("  -t: Run tests.\n");
    printf("  -h: Show help.\n");
  }
}