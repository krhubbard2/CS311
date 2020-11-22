// squarer_test.cpp 
// Kelby Hubbard, Rose Peters, and Yali Wang
// Started: 2020-11-20
// Updated: 2020-11-21

// For CS 311 Fall 2020
// Test program for class Squarer
// For Project 8, Exercise B
// Uses the "doctest" unit-testing framework, version 2
// Requires doctest.h, squarer.h

// CREDIT:
// This file is based off of the skeleton file squarer_test.cpp
// written by Glenn G. Chappell which can be found at
// https://github.com/ggchappell/cs311-2020-03


// Includes for code to be tested
#include "squarer.h"         // For class Squarer
#include "squarer.h"         // Double-inclusion check, for testing only

// Includes for the "doctest" unit-testing framework
#define DOCTEST_CONFIG_IMPLEMENT
                             // We write our own main
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS
                             // Reduce compile time
#include "doctest.h"         // For doctest

// Includes for all test programs
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;

// Additional includes for this test program
// NONE

// Printable name for this test suite
const std::string test_suite_name =
    "class Squarer"
    " - CS 311 Proj 8, Ex B";


// *********************************************************************
// Test Cases
// *********************************************************************


TEST_CASE("Squarer: negative ints")
{
	Squarer sq;
	SUBCASE("Square -1") {
		INFO("-1 squared is 1");
		REQUIRE(sq(-1) == 1);
	}

	SUBCASE("Square -10") {
		INFO("-10 squared is 100");
		REQUIRE(sq(-10) == 100);
	}
	SUBCASE("Square -999") {
		INFO("-999 squared is 998001");
		REQUIRE(sq(-999) == 998001);
	}
}

TEST_CASE("Squarer: positive ints")
{
	Squarer sq;

	SUBCASE("Square 0") {
		INFO("0 squared is 0");
		REQUIRE(sq(0) == 0);
	}

	SUBCASE("Square 1") {
		INFO("1 squared is 1");
		REQUIRE(sq(1) == 1);
	}

	SUBCASE("Square 2") {
		INFO("2 squared is 4");
		REQUIRE(sq(2) == 4);
	}
	SUBCASE("Square 25") {
		INFO("25 squared is 625");
		REQUIRE(sq(25) == 625);
	}
}

TEST_CASE("Squarer: doubles") {
	Squarer sq;
	
	SUBCASE("Square 1.2") {
		INFO("1.2 squared is 1.44");
		REQUIRE(sq(1.2) == doctest::Approx(1.44));
	}

	SUBCASE("Square 4.99") {
		INFO("4.99 squared is 24.9001");
		REQUIRE(sq(4.99) == doctest::Approx(24.9001));
	}

	SUBCASE("Square 7.40") {
		INFO("7.40 squared is 54.76");
		REQUIRE(sq(7.40) == doctest::Approx(54.76));
	}
}

TEST_CASE("Squarer: negative doubles") {
	Squarer sq;

	SUBCASE("Square -1.2") {
		INFO("-1.2 squared is 1.44");
		REQUIRE(sq(-1.2) == doctest::Approx(1.44));
	}

	SUBCASE("Square -4.99") {
		INFO("-4.99 squared is 24.9001");
		REQUIRE(sq(-4.99) == doctest::Approx(24.9001));
	}

	SUBCASE("Square -7.40") {
		INFO("-7.40 squared is 54.76");
		REQUIRE(sq(-7.40) == doctest::Approx(54.76));
	}
}

TEST_CASE("Squarer: const") {
	const Squarer sq;
	SUBCASE("Square 63") {
		INFO("63 squared is 3969");
		REQUIRE(sq(63) ==3969);
	}

	SUBCASE("Square 7") {
		INFO("7 squared is 49");
		REQUIRE(sq(7) == 49);
	}

}


// *********************************************************************
// Main Program
// *********************************************************************


// userPause
// Wait for user to press ENTER: read all chars through first newline.
void userPause()
{
    std::cout.flush();
    while (std::cin.get() != '\n') ;
}


// Main program
// Run all tests. Prompt for ENTER before exiting.
int main(int argc,
         char *argv[])
{
    doctest::Context dtcontext;
                             // Primary doctest object
    int dtresult;            // doctest return code; for return by main

    // Handle command line
    dtcontext.applyCommandLine(argc, argv);
    dtresult = 0;            // doctest flags no command-line errors
                             //  (strange but true)

    if (!dtresult)           // Continue only if no command-line error
    {
        // Run test suites
        cout << "BEGIN tests for " << test_suite_name << "\n" << endl;
        dtresult = dtcontext.run();
        cout << "END tests for " << test_suite_name << "\n" << endl;
    }

    // If we want to do something else here, then we need to check
    // context.shouldExit() first.

    // Wait for user
    std::cout << "Press ENTER to quit ";
    userPause();

    // Program return value is return code from doctest
    return dtresult;
}

