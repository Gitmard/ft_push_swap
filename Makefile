CFLAGS = -Wall -Wextra -Werror -g3

# ========================================
#            MANDATORY PART
# ========================================

# ========== DIRECTORIES ==========

# ---------- MAIN ----------

SRC_DIR = src

# ---------- INSTRUCTIONS ----------

INSTRUCTIONS_DIR = instructions

# ---------- LIB ----------

LIB_DIR = lib

LIB_HASH_SET_DIR = hash_set
LIB_LIST_DIR = list
LIB_LIST_UTILS_DIR = utils
LIB_MEM_DIR = mem
LIB_PRINTF_DIR = printf
LIB_STACK_DIR = stack
LIB_STRING_DIR = string
LIB_UTILS_DIR = utils
LIB_MATH_DIR = math

# ---------- PARSE ----------

PARSE_DIR = parse

# ---------- ALGO ----------

ALGO_DIR = algo
ALGO_SIMPLE_DIR = simple
ALGO_MEDIUM_DIR = medium
ALGO_COMPLEX_DIR = complex
ALGO_ADAPTIVE_DIR = adaptive

# ---------- BENCH ----------

BENCH_DIR = bench

# ---------- HEADERS ----------

HEADERS_DIR = headers

# ========== INCLUDES ==========

# ---------- INSTRUCTIONS ----------

INCLUDES_INSTRUCTIONS =	-I./$(SRC_DIR)/$(INSTRUCTIONS_DIR) \
						-I./$(SRC_DIR)/$(INSTRUCTIONS_DIR)/$(HEADERS_DIR)

# ---------- LIB ----------

INCLUDES_LIB_HASH_SET =	-I./$(SRC_DIR)/$(LIB_DIR)/$(LIB_HASH_SET_DIR) \
						-I./$(SRC_DIR)/$(LIB_DIR)/$(LIB_HASH_SET_DIR)/$(HEADERS_DIR)

INCLUDES_LIB_LIST =		-I./$(SRC_DIR)/$(LIB_DIR)/$(LIB_LIST_DIR) \
						-I./$(SRC_DIR)/$(LIB_DIR)/$(LIB_LIST_DIR)/$(HEADERS_DIR)

INCLUDES_LIB_MEM =		-I./$(SRC_DIR)/$(LIB_DIR)/$(LIB_MEM_DIR) \
						-I./$(SRC_DIR)/$(LIB_DIR)/$(LIB_MEM_DIR)/$(HEADERS_DIR)

INCLUDES_LIB_PRINTF =	-I./$(SRC_DIR)/$(LIB_DIR)/$(LIB_PRINTF_DIR) \
						-I./$(SRC_DIR)/$(LIB_DIR)/$(LIB_PRINTF_DIR)/$(HEADERS_DIR)

INCLUDES_LIB_STACK =	-I./$(SRC_DIR)/$(LIB_DIR)/$(LIB_STACK_DIR) \
						-I./$(SRC_DIR)/$(LIB_DIR)/$(LIB_STACK_DIR)/$(HEADERS_DIR)

INCLUDES_LIB_STRING =	-I./$(SRC_DIR)/$(LIB_DIR)/$(LIB_STRING_DIR) \
						-I./$(SRC_DIR)/$(LIB_DIR)/$(LIB_STRING_DIR)/$(HEADERS_DIR)

INCLUDES_LIB_MAIN =		-I./$(SRC_DIR)/$(LIB_DIR) \
						-I./$(SRC_DIR)/$(LIB_DIR)/$(HEADERS_DIR)

INCLUDES_LIB_UTILS =	-I./$(SRC_DIR)/$(LIB_DIR)/$(LIB_UTILS_DIR) \
						-I./$(SRC_DIR)/$(LIB_DIR)/$(LIB_UTILS_DIR)/$(HEADERS_DIR)

INCLUDES_LIB_GNL =		-I./$(SRC_DIR)/$(LIB_DIR)/$(LIB_GNL_DIR) \
						-I./$(SRC_DIR)/$(LIB_DIR)/$(LIB_GNL_DIR)/$(HEADERS_DIR)

INCLUDES_LIB_MATH =		-I./$(SRC_DIR)/$(LIB_DIR)/$(LIB_MATH_DIR)

INCLUDES_LIB =			$(INCLUDES_LIB_MAIN) \
						$(INCLUDES_LIB_HASH_SET) \
						$(INCLUDES_LIB_LIST) \
						$(INCLUDES_LIB_MEM) \
						$(INCLUDES_LIB_PRINTF) \
						$(INCLUDES_LIB_STACK) \
						$(INCLUDES_LIB_STRING) \
						$(INCLUDES_LIB_UTILS) \
						$(INCLUDES_LIB_MATH)

# ---------- PARSE ----------

INCLUDES_PARSE = 		-I./$(SRC_DIR)/$(PARSE_DIR) \
						-I./$(SRC_DIR)/$(PARSE_DIR)/$(HEADERS_DIR)

# ---------- ALGO ----------

INCLUDES_ALGO_SIMPLE =	-I./$(SRC_DIR)/$(ALGO_DIR)/$(ALGO_SIMPLE_DIR) \
						-I./$(SRC_DIR)/$(ALGO_DIR)/$(ALGO_SIMPLE_DIR)/$(HEADERS_DIR)

INCLUDES_ALGO_MEDIUM =	-I./$(SRC_DIR)/$(ALGO_DIR)/$(ALGO_MEDIUM_DIR) \
						-I./$(SRC_DIR)/$(ALGO_DIR)/$(ALGO_MEDIUM_DIR)/$(HEADERS_DIR)

INCLUDES_ALGO_COMPLEX =	-I./$(SRC_DIR)/$(ALGO_DIR)/$(ALGO_COMPLEX_DIR) \
						-I./$(SRC_DIR)/$(ALGO_DIR)/$(ALGO_COMPLEX_DIR)/$(HEADERS_DIR)

INCLUDES_ALGO_ADAPTIVE = -I./$(SRC_DIR)/$(ALGO_DIR)/$(ALGO_ADAPTIVE_DIR)

INCLUDES_ALGO =			-I./$(SRC_DIR)/$(ALGO_DIR) \
						-I./$(SRC_DIR)/$(ALGO_DIR)/$(HEADERS_DIR) \
						$(INCLUDES_ALGO_SIMPLE) \
						$(INCLUDES_ALGO_MEDIUM) \
						$(INCLUDES_ALGO_COMPLEX) \
						$(INCLUDES_ALGO_ADAPTIVE)

# ---------- BENCH ----------

INCLUDES_BENCH =		-I./$(SRC_DIR)/$(BENCH_DIR) \
						-I./$(SRC_DIR)/$(BENCH_DIR)/$(HEADERS_DIR)

# ---------- MAIN ----------

INCLUDES_MAIN = 		-I./$(SRC_DIR)

INCLUDES =				$(INCLUDES_INSTRUCTIONS) \
						$(INCLUDES_LIB) \
						$(INCLUDES_PARSE) \
						$(INCLUDES_MAIN) \
						$(INCLUDES_ALGO) \
						$(INCLUDES_BENCH)

# ========== FILES ==========

# ---------- MAIN ----------

MAIN_FILES =			./$(SRC_DIR)/push_swap.c

# ---------- INSTRUCTIONS ----------

INSTRUCTIONS_FILES =	./$(SRC_DIR)/$(INSTRUCTIONS_DIR)/push.c \
						./$(SRC_DIR)/$(INSTRUCTIONS_DIR)/reverse_rotate.c \
						./$(SRC_DIR)/$(INSTRUCTIONS_DIR)/rotate.c \
						./$(SRC_DIR)/$(INSTRUCTIONS_DIR)/swap.c

# ---------- LIB ----------

LIB_HASH_SET_FILES =	./$(SRC_DIR)/$(LIB_DIR)/$(LIB_HASH_SET_DIR)/hash_set.c

LIB_LIST_FILES =		./$(SRC_DIR)/$(LIB_DIR)/$(LIB_LIST_DIR)/ft_lstadd.c \
						./$(SRC_DIR)/$(LIB_DIR)/$(LIB_LIST_DIR)/ft_lstclear.c \
						./$(SRC_DIR)/$(LIB_DIR)/$(LIB_LIST_DIR)/ft_lstnew.c \
						./$(SRC_DIR)/$(LIB_DIR)/$(LIB_LIST_DIR)/ft_lstremove.c \
						./$(SRC_DIR)/$(LIB_DIR)/$(LIB_LIST_DIR)/$(LIB_LIST_UTILS_DIR)/list_utils.c

LIB_MEM_FILES =			./$(SRC_DIR)/$(LIB_DIR)/$(LIB_MEM_DIR)/mem.c

LIB_PRINTF_FILES =		./$(SRC_DIR)/$(LIB_DIR)/$(LIB_PRINTF_DIR)/ft_printf.c \
						./$(SRC_DIR)/$(LIB_DIR)/$(LIB_PRINTF_DIR)/parse.c \
						./$(SRC_DIR)/$(LIB_DIR)/$(LIB_PRINTF_DIR)/print.c \
						./$(SRC_DIR)/$(LIB_DIR)/$(LIB_PRINTF_DIR)/utils.c

LIB_STACK_FILES =		./$(SRC_DIR)/$(LIB_DIR)/$(LIB_STACK_DIR)/ft_stackadd.c \
						./$(SRC_DIR)/$(LIB_DIR)/$(LIB_STACK_DIR)/ft_stacknew.c \
						./$(SRC_DIR)/$(LIB_DIR)/$(LIB_STACK_DIR)/ft_stackremove.c \
						./$(SRC_DIR)/$(LIB_DIR)/$(LIB_STACK_DIR)/get_previous.c

LIB_STRING_FILES =		./$(SRC_DIR)/$(LIB_DIR)/$(LIB_STRING_DIR)/string.c

LIB_UTILS_FILES =		./$(SRC_DIR)/$(LIB_DIR)/$(LIB_UTILS_DIR)/binary_search.c \
						./$(SRC_DIR)/$(LIB_DIR)/$(LIB_UTILS_DIR)/check_sort.c \
						./$(SRC_DIR)/$(LIB_DIR)/$(LIB_UTILS_DIR)/print_stack.c \
						./$(SRC_DIR)/$(LIB_DIR)/$(LIB_UTILS_DIR)/sort.c

LIB_MATH_FILES =		./$(SRC_DIR)/$(LIB_DIR)/$(LIB_MATH_DIR)/math.c

LIB_FILES =				$(LIB_HASH_SET_FILES) \
						$(LIB_LIST_FILES) \
						$(LIB_MEM_FILES) \
						$(LIB_PRINTF_FILES) \
						$(LIB_STRING_FILES) \
						$(LIB_STACK_FILES) \
						$(LIB_UTILS_FILES) \
						$(LIB_GNL_FILES) \
						$(LIB_MATH_FILES)

# ---------- PARSE ----------

PARSE_FILES =			./$(SRC_DIR)/$(PARSE_DIR)/free.c \
						./$(SRC_DIR)/$(PARSE_DIR)/normalise_args.c \
						./$(SRC_DIR)/$(PARSE_DIR)/parse.c \
						./$(SRC_DIR)/$(PARSE_DIR)/parse_utils.c \
						./$(SRC_DIR)/$(PARSE_DIR)/precompute_indexes.c

# ---------- ALGO ----------

ALGO_SIMPLE_FILES =		./$(SRC_DIR)/$(ALGO_DIR)/$(ALGO_SIMPLE_DIR)/simple.c \
						./$(SRC_DIR)/$(ALGO_DIR)/$(ALGO_SIMPLE_DIR)/simple_metrics_utils.c

ALGO_MEDIUM_FILES =		./$(SRC_DIR)/$(ALGO_DIR)/$(ALGO_MEDIUM_DIR)/medium.c \
						./$(SRC_DIR)/$(ALGO_DIR)/$(ALGO_MEDIUM_DIR)/medium_utils.c

ALGO_COMPLEX_FILES =		./$(SRC_DIR)/$(ALGO_DIR)/$(ALGO_COMPLEX_DIR)/complex.c \
						./$(SRC_DIR)/$(ALGO_DIR)/$(ALGO_COMPLEX_DIR)/complex_utils.c

ALGO_ADAPTIVE_FILES =	./$(SRC_DIR)/$(ALGO_DIR)/$(ALGO_ADAPTIVE_DIR)/adaptive.c

ALGO_FILES =			$(ALGO_SIMPLE_FILES) \
						$(ALGO_MEDIUM_FILES) \
						$(ALGO_COMPLEX_FILES) \
						$(ALGO_ADAPTIVE_FILES)

# ---------- BENCH ----------

BENCH_FILES = 			./$(SRC_DIR)/$(BENCH_DIR)/bench.c \
						./$(SRC_DIR)/$(BENCH_DIR)/bench_utils.c

# ---------- ALL ----------

ALL_FILES = 			$(MAIN_FILES) \
						$(INSTRUCTIONS_FILES) \
						$(LIB_FILES) \
						$(PARSE_FILES) \
						$(ALGO_FILES) \
						$(BENCH_FILES)

# ========== OBJ ==========

SRCS_OBJ = $(MAIN_FILES:.c=.o)
INSTRUCTIONS_OBJ = $(INSTRUCTIONS_FILES:.c=.o)
LIB_OBJ = $(LIB_FILES:.c=.o)
PARSE_OBJ = $(PARSE_FILES:.c=.o)
ALGO_OBJ = $(ALGO_FILES:.c=.o)
BENCH_OBJ = $(BENCH_FILES:.c=.o)

ALL_OBJ = $(SRCS_OBJ) $(INSTRUCTIONS_OBJ) $(LIB_OBJ) $(PARSE_OBJ) $(ALGO_OBJ) $(BENCH_OBJ)

# ========== DFILES ==========

DFILES = $(ALL_OBJ:.o=.d)

# ========== NAMES ==========

NAME_MAIN = push_swap

NAME_INSTRUCTIONS = instructions.a
NAME_LIB = lib.a
NAME_PARSE = parse.a
NAME_ALGO = algo.a
NAME_BENCH = bench.a

# ========== PROGRESS TRACKING ==========

TOTAL_FILES := $(words $(ALL_FILES))

# Counter file to track progress across make invocations
COUNTER_FILE := .compile_counter

# ========== RULES ==========

all: reset_counter $(NAME_MAIN)

$(NAME_MAIN): $(SRCS_OBJ) $(NAME_ALGO) $(NAME_INSTRUCTIONS) $(NAME_PARSE) $(NAME_LIB) $(NAME_BENCH)
	@echo "\033[1;32m[LINKING]\033[0m $@"
	@$(CC) $(CFLAGS) $(SRCS_OBJ) $(NAME_ALGO) $(NAME_INSTRUCTIONS) $(NAME_PARSE) $(NAME_LIB) $(NAME_BENCH) -o $@
	@echo "\033[1;32m[SUCCESS]\033[0m $(NAME_MAIN) compiled successfully!"
	@rm -f $(COUNTER_FILE)

$(NAME_INSTRUCTIONS): $(INSTRUCTIONS_OBJ)
	@echo "\033[1;34m[ARCHIVE]\033[0m $@"
	@ar rcs $@ $^

$(NAME_LIB): $(LIB_OBJ)
	@echo "\033[1;34m[ARCHIVE]\033[0m $@"
	@ar rcs $@ $^

$(NAME_PARSE): $(PARSE_OBJ)
	@echo "\033[1;34m[ARCHIVE]\033[0m $@"
	@ar rcs $@ $^

$(NAME_ALGO): $(ALGO_OBJ)
	@echo "\033[1;34m[ARCHIVE]\033[0m $@"
	@ar rcs $@ $^

$(NAME_BENCH): $(BENCH_OBJ)
	@echo "\033[1;34m[ARCHIVE]\033[0m $@"
	@ar rcs $@ $^

reset_counter:
	@echo "0" > $(COUNTER_FILE)
	@echo "$(TOTAL_FILES)" >> $(COUNTER_FILE)

# ========================================
#               BONUS PART
# ========================================

# ========== DIRECTORIES ==========

BONUS_SRC_DIR = bonus_src

# ---------- CHECKER ----------

BONUS_CHECKER_DIR = checker

# ---------- INSTRUCTIONS ----------

BONUS_INSTRUCTIONS_DIR = instructions

# ---------- LIB ----------

BONUS_LIB_DIR = lib

BONUS_LIB_HASH_SET_DIR = hash_set
BONUS_LIB_LIST_DIR = list
BONUS_LIB_LIST_UTILS_DIR = utils
BONUS_LIB_MEM_DIR = mem
BONUS_LIB_STACK_DIR = stack
BONUS_LIB_STRING_DIR = string
BONUS_LIB_UTILS_DIR = utils
BONUS_LIB_GNL_DIR = get_next_line

# ---------- PARSE ----------

BONUS_PARSE_DIR = parse

# ---------- HEADERS ----------

BONUS_HEADERS_DIR = headers

# ========== INCLUDES ==========

# ---------- CHECKER ----------

BONUS_INCLUDES_CHECKER = -I./$(BONUS_SRC_DIR)/$(BONUS_CHECKER_DIR)

# ---------- INSTRUCTIONS ----------

BONUS_INCLUDES_INSTRUCTIONS = -I./$(BONUS_SRC_DIR)/$(BONUS_INSTRUCTIONS_DIR) \
							  -I./$(BONUS_SRC_DIR)/$(BONUS_INSTRUCTIONS_DIR)/$(BONUS_HEADERS_DIR)

# ---------- LIB ----------

BONUS_INCLUDES_LIB_HASH_SET = -I./$(BONUS_SRC_DIR)/$(BONUS_LIB_DIR)/$(BONUS_LIB_HASH_SET_DIR) \
							  -I./$(BONUS_SRC_DIR)/$(BONUS_LIB_DIR)/$(BONUS_LIB_HASH_SET_DIR)/$(BONUS_HEADERS_DIR)

BONUS_INCLUDES_LIB_LIST = -I./$(BONUS_SRC_DIR)/$(BONUS_LIB_DIR)/$(BONUS_LIB_LIST_DIR) \
						  -I./$(BONUS_SRC_DIR)/$(BONUS_LIB_DIR)/$(BONUS_LIB_LIST_DIR)/$(BONUS_HEADERS_DIR)

BONUS_INCLUDES_LIB_MEM = -I./$(BONUS_SRC_DIR)/$(BONUS_LIB_DIR)/$(BONUS_LIB_MEM_DIR) \
						 -I./$(BONUS_SRC_DIR)/$(BONUS_LIB_DIR)/$(BONUS_LIB_MEM_DIR)/$(BONUS_HEADERS_DIR)

BONUS_INCLUDES_LIB_STACK = -I./$(BONUS_SRC_DIR)/$(BONUS_LIB_DIR)/$(BONUS_LIB_STACK_DIR) \
						   -I./$(BONUS_SRC_DIR)/$(BONUS_LIB_DIR)/$(BONUS_LIB_STACK_DIR)/$(BONUS_HEADERS_DIR)

BONUS_INCLUDES_LIB_STRING = -I./$(BONUS_SRC_DIR)/$(BONUS_LIB_DIR)/$(BONUS_LIB_STRING_DIR) \
							-I./$(BONUS_SRC_DIR)/$(BONUS_LIB_DIR)/$(BONUS_LIB_STRING_DIR)/$(BONUS_HEADERS_DIR)

BONUS_INCLUDES_LIB_MAIN = -I./$(BONUS_SRC_DIR)/$(BONUS_LIB_DIR) \
						  -I./$(BONUS_SRC_DIR)/$(BONUS_LIB_DIR)/$(BONUS_HEADERS_DIR)

BONUS_INCLUDES_LIB_UTILS = -I./$(BONUS_SRC_DIR)/$(BONUS_LIB_DIR)/$(BONUS_LIB_UTILS_DIR) \
						   -I./$(BONUS_SRC_DIR)/$(BONUS_LIB_DIR)/$(BONUS_LIB_UTILS_DIR)/$(BONUS_HEADERS_DIR)

BONUS_INCLUDES_LIB_GNL = -I./$(BONUS_SRC_DIR)/$(BONUS_LIB_DIR)/$(BONUS_LIB_GNL_DIR) \
						 -I./$(BONUS_SRC_DIR)/$(BONUS_LIB_DIR)/$(BONUS_LIB_GNL_DIR)/$(BONUS_HEADERS_DIR)

BONUS_INCLUDES_LIB = $(BONUS_INCLUDES_LIB_MAIN) \
					 $(BONUS_INCLUDES_LIB_HASH_SET) \
					 $(BONUS_INCLUDES_LIB_LIST) \
					 $(BONUS_INCLUDES_LIB_MEM) \
					 $(BONUS_INCLUDES_LIB_STACK) \
					 $(BONUS_INCLUDES_LIB_STRING) \
					 $(BONUS_INCLUDES_LIB_UTILS) \
					 $(BONUS_INCLUDES_LIB_GNL)

# ---------- PARSE ----------

BONUS_INCLUDES_PARSE = -I./$(BONUS_SRC_DIR)/$(BONUS_PARSE_DIR) \
					   -I./$(BONUS_SRC_DIR)/$(BONUS_PARSE_DIR)/$(BONUS_HEADERS_DIR)

BONUS_INCLUDES = $(BONUS_INCLUDES_CHECKER) \
				 $(BONUS_INCLUDES_INSTRUCTIONS) \
				 $(BONUS_INCLUDES_LIB) \
				 $(BONUS_INCLUDES_PARSE)

# ========== FILES ==========

# ---------- CHECKER ----------

BONUS_CHECKER_FILES = ./$(BONUS_SRC_DIR)/$(BONUS_CHECKER_DIR)/checker_bonus.c \
					  ./$(BONUS_SRC_DIR)/$(BONUS_CHECKER_DIR)/checker_utils_bonus.c

# ---------- INSTRUCTIONS ----------

BONUS_INSTRUCTIONS_FILES = ./$(BONUS_SRC_DIR)/$(BONUS_INSTRUCTIONS_DIR)/push_bonus.c \
						   ./$(BONUS_SRC_DIR)/$(BONUS_INSTRUCTIONS_DIR)/reverse_rotate_bonus.c \
						   ./$(BONUS_SRC_DIR)/$(BONUS_INSTRUCTIONS_DIR)/rotate_bonus.c \
						   ./$(BONUS_SRC_DIR)/$(BONUS_INSTRUCTIONS_DIR)/swap_bonus.c

# ---------- LIB ----------

BONUS_LIB_HASH_SET_FILES = ./$(BONUS_SRC_DIR)/$(BONUS_LIB_DIR)/$(BONUS_LIB_HASH_SET_DIR)/hash_set_bonus.c

BONUS_LIB_LIST_FILES = ./$(BONUS_SRC_DIR)/$(BONUS_LIB_DIR)/$(BONUS_LIB_LIST_DIR)/ft_lstadd_bonus.c \
					   ./$(BONUS_SRC_DIR)/$(BONUS_LIB_DIR)/$(BONUS_LIB_LIST_DIR)/ft_lstclear_bonus.c \
					   ./$(BONUS_SRC_DIR)/$(BONUS_LIB_DIR)/$(BONUS_LIB_LIST_DIR)/ft_lstnew_bonus.c \
					   ./$(BONUS_SRC_DIR)/$(BONUS_LIB_DIR)/$(BONUS_LIB_LIST_DIR)/ft_lstremove_bonus.c \
					   ./$(BONUS_SRC_DIR)/$(BONUS_LIB_DIR)/$(BONUS_LIB_LIST_DIR)/$(BONUS_LIB_LIST_UTILS_DIR)/list_utils_bonus.c

BONUS_LIB_MEM_FILES = ./$(BONUS_SRC_DIR)/$(BONUS_LIB_DIR)/$(BONUS_LIB_MEM_DIR)/mem_bonus.c

BONUS_LIB_STACK_FILES = ./$(BONUS_SRC_DIR)/$(BONUS_LIB_DIR)/$(BONUS_LIB_STACK_DIR)/ft_stackadd_bonus.c \
						./$(BONUS_SRC_DIR)/$(BONUS_LIB_DIR)/$(BONUS_LIB_STACK_DIR)/ft_stacknew_bonus.c \
						./$(BONUS_SRC_DIR)/$(BONUS_LIB_DIR)/$(BONUS_LIB_STACK_DIR)/ft_stackremove_bonus.c \
						./$(BONUS_SRC_DIR)/$(BONUS_LIB_DIR)/$(BONUS_LIB_STACK_DIR)/get_previous_bonus.c

BONUS_LIB_STRING_FILES = ./$(BONUS_SRC_DIR)/$(BONUS_LIB_DIR)/$(BONUS_LIB_STRING_DIR)/string_bonus.c

BONUS_LIB_UTILS_FILES = ./$(BONUS_SRC_DIR)/$(BONUS_LIB_DIR)/$(BONUS_LIB_UTILS_DIR)/check_sort_bonus.c

BONUS_LIB_GNL_FILES = ./$(BONUS_SRC_DIR)/$(BONUS_LIB_DIR)/$(BONUS_LIB_GNL_DIR)/get_next_line_bonus.c \
					  ./$(BONUS_SRC_DIR)/$(BONUS_LIB_DIR)/$(BONUS_LIB_GNL_DIR)/get_next_line_utils_bonus.c

BONUS_LIB_FILES = $(BONUS_LIB_HASH_SET_FILES) \
				  $(BONUS_LIB_LIST_FILES) \
				  $(BONUS_LIB_MEM_FILES) \
				  $(BONUS_LIB_STRING_FILES) \
				  $(BONUS_LIB_STACK_FILES) \
				  $(BONUS_LIB_UTILS_FILES) \
				  $(BONUS_LIB_GNL_FILES)

# ---------- PARSE ----------

BONUS_PARSE_FILES = ./$(BONUS_SRC_DIR)/$(BONUS_PARSE_DIR)/free_bonus.c \
					./$(BONUS_SRC_DIR)/$(BONUS_PARSE_DIR)/normalise_args_bonus.c \
					./$(BONUS_SRC_DIR)/$(BONUS_PARSE_DIR)/parse_bonus.c \
					./$(BONUS_SRC_DIR)/$(BONUS_PARSE_DIR)/parse_utils_bonus.c \

# ---------- ALL ----------

BONUS_ALL_FILES = $(BONUS_CHECKER_FILES) \
				  $(BONUS_INSTRUCTIONS_FILES) \
				  $(BONUS_LIB_FILES) \
				  $(BONUS_PARSE_FILES)

# ========== OBJ ==========

BONUS_CHECKER_OBJ = $(BONUS_CHECKER_FILES:.c=.o)
BONUS_INSTRUCTIONS_OBJ = $(BONUS_INSTRUCTIONS_FILES:.c=.o)
BONUS_LIB_OBJ = $(BONUS_LIB_FILES:.c=.o)
BONUS_PARSE_OBJ = $(BONUS_PARSE_FILES:.c=.o)

BONUS_ALL_OBJ = $(BONUS_CHECKER_OBJ) $(BONUS_INSTRUCTIONS_OBJ) $(BONUS_LIB_OBJ) $(BONUS_PARSE_OBJ)

# ========== DFILES ==========

BONUS_DFILES = $(BONUS_ALL_OBJ:.o=.d)

# ========== NAMES ==========

NAME_CHECKER = checker

BONUS_NAME_INSTRUCTIONS = instructions_bonus.a
BONUS_NAME_LIB = lib_bonus.a
BONUS_NAME_PARSE = parse_bonus.a

# ========== PROGRESS TRACKING ==========

BONUS_TOTAL_FILES := $(words $(BONUS_ALL_FILES))

# ========== RULES ==========

bonus: reset_counter_bonus $(NAME_CHECKER)

$(NAME_CHECKER): $(BONUS_CHECKER_OBJ) $(BONUS_NAME_PARSE) $(BONUS_NAME_INSTRUCTIONS) $(BONUS_NAME_LIB)
	@echo "\033[1;32m[LINKING]\033[0m $@"
	@$(CC) $(CFLAGS) $(BONUS_CHECKER_OBJ) $(BONUS_NAME_PARSE) $(BONUS_NAME_INSTRUCTIONS) $(BONUS_NAME_LIB) -o $@
	@echo "\033[1;32m[SUCCESS]\033[0m $(NAME_CHECKER) compiled successfully!"
	@rm -f $(COUNTER_FILE)

$(BONUS_NAME_INSTRUCTIONS): $(BONUS_INSTRUCTIONS_OBJ)
	@echo "\033[1;34m[ARCHIVE]\033[0m $@"
	@ar rcs $@ $^

$(BONUS_NAME_LIB): $(BONUS_LIB_OBJ)
	@echo "\033[1;34m[ARCHIVE]\033[0m $@"
	@ar rcs $@ $^

$(BONUS_NAME_PARSE): $(BONUS_PARSE_OBJ)
	@echo "\033[1;34m[ARCHIVE]\033[0m $@"
	@ar rcs $@ $^

reset_counter_bonus:
	@echo "0" > $(COUNTER_FILE)
	@echo "$(BONUS_TOTAL_FILES)" >> $(COUNTER_FILE)

# ========================================
#           COMMON RULES
# ========================================

# ########## IMPLICIT RULES ##########

# Rule for mandatory files
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@COMPILED=$$(head -n 1 $(COUNTER_FILE) 2>/dev/null || echo "0"); \
	TOTAL=$$(tail -n 1 $(COUNTER_FILE) 2>/dev/null || echo "$(TOTAL_FILES)"); \
	COMPILED=$$((COMPILED + 1)); \
	PERCENT=$$((COMPILED * 100 / TOTAL)); \
	printf "\033[1;36m[%3d%%]\033[0m %s\n" $$PERCENT $<; \
	echo "$$COMPILED" > $(COUNTER_FILE); \
	echo "$$TOTAL" >> $(COUNTER_FILE)
	@$(CC) $(CFLAGS) -MMD -c $< -o $@ $(INCLUDES)

# Rule for bonus files
$(BONUS_SRC_DIR)/%.o: $(BONUS_SRC_DIR)/%.c
	@COMPILED=$$(head -n 1 $(COUNTER_FILE) 2>/dev/null || echo "0"); \
	TOTAL=$$(tail -n 1 $(COUNTER_FILE) 2>/dev/null || echo "$(BONUS_TOTAL_FILES)"); \
	COMPILED=$$((COMPILED + 1)); \
	PERCENT=$$((COMPILED * 100 / TOTAL)); \
	printf "\033[1;36m[%3d%%]\033[0m %s\n" $$PERCENT $<; \
	echo "$$COMPILED" > $(COUNTER_FILE); \
	echo "$$TOTAL" >> $(COUNTER_FILE)
	@$(CC) $(CFLAGS) -MMD -c $< -o $@ $(BONUS_INCLUDES)

# ---------- CLEAN ----------

clean:
	@echo "\033[1;31m[CLEAN]\033[0m Removing object files and dependencies..."
	@rm -rf $(DFILES) $(ALL_OBJ) $(NAME_INSTRUCTIONS) $(NAME_PARSE) $(NAME_LIB) $(NAME_ALGO) $(NAME_BENCH)
	@rm -rf $(BONUS_DFILES) $(BONUS_ALL_OBJ) $(BONUS_NAME_INSTRUCTIONS) $(BONUS_NAME_PARSE) $(BONUS_NAME_LIB)
	@rm -f $(COUNTER_FILE)
	@echo "\033[1;32m[DONE]\033[0m Clean completed!"

fclean: clean
	@echo "\033[1;31m[FCLEAN]\033[0m Removing executables..."
	@rm -rf $(NAME_MAIN) $(NAME_CHECKER)
	@echo "\033[1;32m[DONE]\033[0m Full clean completed!"

# ---------- re ----------

re: fclean all

.PHONY: all clean fclean re bonus reset_counter reset_counter_bonus

-include $(DFILES)
-include $(BONUS_DFILES)
