CC = gcc
FLAG_C = -c
FLAG_O = -o
ASAN = -g -fsanitize=address
FLAG_COV = --coverage
FLAG_ER = -Wall -Werror -Wextra
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes
FLAG_TESTS = -lcheck -lm -lgcov -lsubunit

LIB_EQUANTION_C = lib_*.c
LIB_EQUANTION_O = lib_*.o
OUTDIR = BUILD
TESTDIR = TESTS
LIBDIR = quadratic_equation
SUITE_CASES_C = suite_*.c
SUITE_CASES_O = suite_*.o

all: clean gcov_report

lib_quadratic_equation.a:
	rm -rf BUILD
	mkdir BUILD
	for file in $(LIBDIR)/$(LIB_EQUANTION_C); do \
		$(CC) -c $(FLAG_ER)  $(FLAG_COV) -o $(OUTDIR)/$$(basename $$file .c).o $$file; \
	done

	ar rc $(OUTDIR)/lib_quadratic_equation.a $(OUTDIR)/$(LIB_EQUANTION_O) -lm
	ranlib $(OUTDIR)/lib_quadratic_equation.a

check: lib_quadratic_equation.a
	for file in $(TESTDIR)/$(SUITE_CASES_C) $(TESTDIR)/main.c; do \
		$(CC) $(FLAG_C) $(FLAG_ER) $$file -o $(OUTDIR)/$$(basename $$file .c).o; \
	done
	$(CC) $(FLAG_ER) $(FLAG_COV) $(FLAG_O) $(OUTDIR)/tests $(OUTDIR)/main.o $(OUTDIR)/$(SUITE_CASES_O) $(OUTDIR)/lib_quadratic_equation.a $(FLAG_TESTS)
	./$(OUTDIR)/tests

asan: lib_quadratic_equation.a
	for file in $(TESTDIR)/$(SUITE_CASES_C); do \
		$(CC) $(FLAG_C) $(FLAG_ER) $$file -o $(OUTDIR)/$$(basename $$file .c).o; \
	done
	$(CC) $(FLAG_ER) $(FLAG_COV) -o $(OUTDIR)/tests $(OUTDIR)/$(SUITE_CASES_O) $(OUTDIR)/lib_quadratic_equation.a $(FLAG_TESTS) $(ASAN)
	./$(OUTDIR)/tests

valgrind_test: lib_quadratic_equation.a
	for file in $(TESTDIR)/$(SUITE_CASES_CPP); do \
		$(CC) $(FLAG_C) $(FLAG_ER) $$file -o $(OUTDIR)/$$(basename $$file .c).o -g; \
	done
	$(CC) $(FLAG_ER) $(FLAG_COV) -o $(OUTDIR)/tests $(OUTDIR)/$(SUITE_CASES_O) $(OUTDIR)/lib_quadratic_equation.a $(FLAG_TESTS)
	valgrind $(VALGRIND_FLAGS) ./$(OUTDIR)/tests

gcov_report: check
	gcovr --html-details -o $(OUTDIR)/report.html

cpp_check:
	cppcheck --enable=all --force $(LIBDIR)/*.h $(LIBDIR)/*.c $(TESTDIR)/*.c

style_check:
	cp ../materials/linters/.clang-format ./
	clang-format -n $(LIBDIR)/*.h $(LIBDIR)/*.c $(TESTDIR)/*.c
	clang-format -i $(LIBDIR)/*.h $(LIBDIR)/*.c $(TESTDIR)/*.c
	rm -rf .clang-format

clean:
	-rm -rf BUILD
	-rm -rf *.o *.html *.gcda *.gcno *.css *.a *.gcov *.info *.out *.cfg *.txt
	-rm -f tests
	-rm -f report
	find . -type d -name 'tests.dSYM' -exec rm -r {} +
