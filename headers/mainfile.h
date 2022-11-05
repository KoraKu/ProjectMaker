#ifndef MAINFILE_H
#define MAINFILE_H
#endif

#include "const.h"

#define INT_MAIN_C "#include <stdio.h>\n\nint main(int argc, char *argv[]) {\n\tprintf(\"Hello :)\\n\");\n\treturn 0;\n}"
#define INT_MAIN_CPP "#include <iostream>\n\nint main(int argc, char *argv[]) {\n\tstd::cout << \"Hello :)\" << std::endl;\n\treturn 0;\n}"

int newmain(int argc, char *argv[], int language);