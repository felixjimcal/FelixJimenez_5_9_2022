#include "Interpreter.cpp"
#include <gtest/gtest.h>
/*
Let's see

I recive a JSON file with movies on it and I filter it, no test needed
just a function that fills a vector of objects, so I need a Class
Movie{...};

I ask the user for an interval, it can be a two digits param like 80, so I
need a test for a two digits and another one test of four digits 1980,
and need to call it from the test so must need an object to interpret the decade.

And I return a file with the movies filtered, can be interesting a
mocked data test where just need to change decade param, to reduce time
with a real data example.

----------------------
SO,
* test for Param of two digits (30, 40, ...),
* test for Para of Four digits (1920, 2010, ...)
* test mocked list for a (1900 movies)
* test mocked list for a (2000 - 2019 movies)
* End-to-End test? I will assume the file is generated for now, I will focus on core requirements
*/

namespace {
// Set up tests environment
struct MoviesTest : testing::Test{
    Interpreter interpreter;

    MoviesTest(){
        interpreter.movies.push_back( Movie("A", 1900, {}, {}));
    }
};

TEST_F(MoviesTest, ParseParamOfFourDigits) {
    // Arrange

    // Act
    int expectedResult = 1980;
    int result = interpreter.InterpretDecade(1980);

    // Result
    EXPECT_EQ(expectedResult, result);
}

TEST_F(MoviesTest, ParseParamOfTwoDigits) {
    // Arrange

    // Act
    int expectedResult = 1930;
    int result = interpreter.InterpretDecade(30);

    // Result
    EXPECT_EQ(expectedResult, result);
}

TEST_F(MoviesTest, FilterMoviesMockList) {
    // Arrange
    interpreter.movies.push_back( Movie("B", 1910, {}, {}));
    interpreter.movies.push_back( Movie("C", 1915, {}, {}));
    interpreter.movies.push_back( Movie("C", 1919, {}, {}));
    interpreter.movies.push_back( Movie("D", 1920, {}, {}));
    interpreter.movies.push_back( Movie("E", 2000, {}, {}));
    interpreter.movies.push_back( Movie("F", 2018, {}, {}));

    // Act
    int expectedResult = 3;
    int expectedLastYear = 1919;
    std::string expectedFirstTitle = "B";

    int decade = interpreter.InterpretDecade(10);
    std::vector result = interpreter.FilterMovies(decade);

    // Result
    EXPECT_EQ(expectedResult, result.size());
    EXPECT_EQ(expectedLastYear, result.back().year);
    EXPECT_EQ(expectedFirstTitle, result.front().title);
}

TEST_F(MoviesTest, FilterMoviesMockList2000) {
    // Arrange
    interpreter.movies.push_back( Movie("E", 2000, {}, {}));
    interpreter.movies.push_back( Movie("F", 2018, {}, {}));

    // Act
    int expectedResult = 1;
    int expectedLastYear = 2018;
    std::string expectedFirstTitle = "F";

    int decade = interpreter.InterpretDecade(2010);
    std::vector result = interpreter.FilterMovies(decade);

    // Result
    EXPECT_EQ(expectedResult, result.size());
    EXPECT_EQ(expectedLastYear, result.back().year);
    EXPECT_EQ(expectedFirstTitle, result.front().title);
}
} // namespace
