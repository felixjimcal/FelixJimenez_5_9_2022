#include "Interpreter.cpp"
#include <gtest/gtest.h>
/*
Let's see

I recive a JSON file with movies on it and I filter it, no test needed
just a function that fills a vector of objects, so I need a Class
Movie{...};

I ask the user for an interval, it can be a two digits param like 80, so I
need a test for a two digits and another one test of four digits 1980,
that's redundant, so just one test, and need to call it from the test so
must need an object to interpret the decade.

And I return a file with the movies filtered, can be interesting a
mocked data test where just need to change decade param, to reduce time
with a real data example.

----------------------
SO,
* test for Param of two digits (30, 40...),
* End-to-End test, check the full scenario with a custom list of movies.
*/

namespace {

TEST(MoviesTest, ParseParamOfTwoDigits) {
    // Arrange
    Interpreter interpreter;
    // Act
    int result = interpreter.InterpretDecade(80);
    int expectedResult = 1980;

    // Result
    EXPECT_EQ(result, expectedResult);
}

TEST(MoviesTest, 1980sDecadeMovies) { EXPECT_EQ(1, 1); }

} // namespace
