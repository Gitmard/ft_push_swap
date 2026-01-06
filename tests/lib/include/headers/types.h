/* ************************************************************************* */
/*                                                                           */
/*      /$$$$$$  /$$$$$$ /$$      /$$  /$$$$$$  /$$$$$$$  /$$$$$$$           */
/*     /$$__  $$|_  $$_/| $$$    /$$$ /$$__  $$| $$__  $$| $$__  $$          */
/*    | $$  \__/  | $$  | $$$$  /$$$$| $$  \ $$| $$  \ $$| $$  \ $$          */
/*    |  $$$$$$   | $$  | $$ $$/$$ $$| $$$$$$$$| $$$$$$$/| $$  | $$          */
/*     \____  $$  | $$  | $$  $$$| $$| $$__  $$| $$__  $$| $$  | $$          */
/*     /$$  \ $$  | $$  | $$\  $ | $$| $$  | $$| $$  \ $$| $$  | $$          */
/*    |  $$$$$$/ /$$$$$$| $$ \/  | $$| $$  | $$| $$  | $$| $$$$$$$/          */
/*     \______/ |______/|__/     |__/|__/  |__/|__/  |__/|_______/           */
/*                                                                           */
/*    File: utils.h                                                          */
/*                                                                           */
/* Free Palestine, fuck fascists                                             */
/*                                                                           */
/*                               Made with love and coffee by SimardCodeTard */
/* ************************************************************************* */

#ifndef TYPES_H
# define TYPES_H
# include "includes.h"

typedef uint8_t						bool_t;

typedef char*						string_t;

typedef enum serialization_result_e	serialization_result_t;

typedef struct test_minimal_params_s
{
	string_t	description;
	string_t	expected;
}	test_minimal_params_t;

typedef struct test_result_s
{
	string_t	got;
	bool_t		success;
}	test_result_t;

typedef struct test_s
{
	test_result_t	(*do_test)(int, void *);
	void			*params;
	bool_t			expect_sigsegv;
	string_t		description;
	string_t		expected;
}									test_t;

typedef struct test_set_result_s
{
	string_t	name;
	uint8_t		success_count;
	uint8_t		failure_count;
}									test_set_result_t;

typedef struct test_set_s
{
	string_t	name;
	test_t		*tests;
	uint16_t	total;
}									test_set_t;

#endif
