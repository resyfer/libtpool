#include <include/util.h>
#include <stdio.h>

void
print_info(const char *msg, color_t color, bool exit_process,
		bool print_line, const char* file, int line)
{
	char text_col_bold[10] = {0};
	col_str_style(color, BOLD, text_col_bold);

	// Can't see how to use a ternary operator on an integer (__LINE__)
	if(print_line) {
		printf("\n%s%s Line %d: %s%s\n",
			text_col_bold,
			file,
			line,
			msg,
			RESET);
	} else {
		printf("%s%s%s\n", text_col_bold, msg, RESET);
	}

	if(exit_process) {
		exit(1);
	}
}