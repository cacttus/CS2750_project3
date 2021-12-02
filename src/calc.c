#include "./calc.h"

void calculate() {
#define BUF_SIZ 512
  char buf[BUF_SIZ];

  while (1) {
    printf("\n");
    printf("Please specify a command and 2 numbers, separated by spaces:\n");
    printf("  add num1 num2\n");
    printf("  mul num1 num2\n");
    printf("  div num1 num2\n");
    printf("  sub num1 num2\n");
    printf("  mod num1 num2\n");
    printf(">");

    double a = -1, b = -1, res = -1;
    Command cmd = CMD_INVALID;
    if (getLineAndParse(buf, BUF_SIZ, &cmd, &a, &b) != 0) {
      printf("Please check the input and try again.\n");
    }
    else {
      bool success = true;

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
      else {
        success = false;
      }

      if (success) {
        printf("%f\n", res);
      }
    }
  }
}
int getCommand(char* arg, Command* out) {
  if (!strcmp(arg, "-t")) {
    *out = CMD_TEST;
  }
  else if (!strcmp(arg, "-h")) {
    *out = CMD_HELP;
  }
  else if (!strcmp(arg, "mul")) {
    *out = CMD_MULTIPLY;
  }
  else if (!strcmp(arg, "div")) {
    *out = CMD_DIVIDE;
  }
  else if (!strcmp(arg, "add")) {
    *out = CMD_ADD;
  }
  else if (!strcmp(arg, "sub")) {
    *out = CMD_SUBTRACT;
  }
  else if (!strcmp(arg, "mod")) {
    *out = CMD_MODULUS;
  }
  else {
    *out = CMD_INVALID;
    return 1;
  }
  return 0;
}
int getDouble(char* c, double* out) {
  char* error_question_mark = 1;
  *out = strtod(c, &error_question_mark);
  if (*out == 0 && error_question_mark == c) {
    fprintf(stderr, "Error: invalid number %s.\n", c);
    return 1;
  }
  return 0;
}
int getLineAndParse(char* raw_buf, int raw_bufsiz, Command* cmd, double* a, double* b) {
#define BUF_SIZ 512
  char str_cmd[BUF_SIZ];
  char str_a[BUF_SIZ];
  char str_b[BUF_SIZ];
  char* arg_buf = 0;
  int arg_buf_idx = 0;

  memset(str_cmd, 0, BUF_SIZ);
  memset(str_a, 0, BUF_SIZ);
  memset(str_b, 0, BUF_SIZ);

  memset(raw_buf, 0, raw_bufsiz);
  fgets(raw_buf, raw_bufsiz, stdin);

  arg_buf = str_cmd;
  for (int i = 0; i < raw_bufsiz; i++) {
    int c = raw_buf[i];
    if (c == ' ' || c == 0 || c == '\n' || c == '\r') {
      if (arg_buf == str_cmd) {
        arg_buf = str_a;
        arg_buf_idx = 0;
      }
      else if (arg_buf == str_a) {
        arg_buf = str_b;
        arg_buf_idx = 0;
      }
      else if (arg_buf == str_b) {
        break;
      }
    }
    else {
      arg_buf[arg_buf_idx++] = c;
    }
  }

  if ((strlen(str_cmd) == 0) || (strlen(str_a) == 0) || (strlen(str_b) == 0)) {
    fprintf(stderr, "Invalid number of arguments. 3 arguments required. Please try again.\n");
    return 1;
  }
  else {
    if (getCommand(str_cmd, cmd) != 0) {
      fprintf(stderr, "Command '%s' is not a recognized command.\n", str_cmd);
      return 1;
    }
    if (getDouble(str_a, a) != 0) {
      fprintf(stderr, "Argument '%s' is not a recognized number format.\n", str_a);
      return 1;
    }
    if (getDouble(str_b, b) != 0) {
      fprintf(stderr, "Argument '%s' is not a recognized number format.\n", str_b);
      return 1;
    }
  }
  return 0;
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
