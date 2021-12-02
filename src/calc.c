#include "./calc.h"
void getline(char* buf, size_t bufsiz){
    int c;
    while( (c=fgetc(stdin))!=EOF){
      buf[ind]
    }

}
void calculate() {
#define BUF_SIZ 512
  char buf[BUF_SIZ];

  while (1) {
    printf("Please specify a command and 2 numbers, separated by spaces:\n")
    printf("  add num1 num2\n");
    printf("  multiply num1 num2\n");
    printf("  divide num1 num2\n");
    printf("  subtract num1 num2\n");
    printf("  modulus num1 num2\n");
    printf(">");

    memset(buf, 0, BUF_SIZ);
    if (scanf("%s", buf) != 1) {
      fprintf(stderr, "Invalid input.");
    }
    else {
      double a = -1, b = -1, res = -1;
      Command cmd = getCommand(buf);

      if (cmd == CMD_ADD) {
        res = add(a, b);
      }
      else if (cmd == CMD_SUBTRACT) {
        res = subtract(a, b);
      }
      else if (cmd == CMD_MULTIPLY) {
        res = multiply(a, b);
      }
      else if (cmd == CMD_DIVIDE) {
        res = divide(a, b);
      }
      else if (cmd == CMD_MODULUS) {
        res = modulus(a, b);
      }
      printf("%f\n", res);
    }
  }
}

Command getCommand(char* arg) {
  if (!strcmp(arg, "-t")) {
    return CMD_TEST;
  }
  else if (!strcmp(arg, "-h")) {
    return CMD_HELP;
  }
  else if (!strcmp(arg, "mul")) {
    return CMD_MULTIPLY;
  }
  else if (!strcmp(arg, "div")) {
    return CMD_DIVIDE;
  }
  else if (!strcmp(arg, "add")) {
    return CMD_ADD;
  }
  else if (!strcmp(arg, "sub")) {
    return CMD_SUBTRACT;
  }
  else if (!strcmp(arg, "mod")) {
    return CMD_MODULUS;
  }
  else {
    return CMD_INVALID;
  }
}
double getDoubleOrDie(char* c) {
  double x = strtod(c, NULL);
  if (x == 0 && errno == ERANGE) {
    fprintf(stderr, "Error: invalid number %s.\n", c);
    exit(1);
  }
  return x;
}
void getValidNumbers(size_t argc, char** argv, double* out_a, double* out_b) {
  validateArgumentIndexes(argc, argv, 3);
  if (argc < 4) {
    fprintf(stderr, "We need 4 arguments.\n");
    exit(1);
  }
  if (out_a == NULL) {
    fprintf(stderr, "Error: first number must be specified.\n");
    exit(1);
  }
  if (out_b == NULL) {
    fprintf(stderr, "Error: second number must be specified.\n");
    exit(1);
  }
  *out_a = getDoubleOrDie(argv[2]);
  *out_b = getDoubleOrDie(argv[3]);
}
double multiply(double a, double b) {
  return a * b;
}
double divide(double a, double b) {
  return a / b;
}
double add(double a, double b) {
  return a + b;
}
double subtract(double a, double b) {
  return a - b;
}
double modulus(double a, double b) {
  return fmod(a, b);
}
