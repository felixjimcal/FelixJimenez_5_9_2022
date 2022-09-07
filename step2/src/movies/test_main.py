# Let's see
# 
# I recive a JSON file with movies on it and I filter it, no test needed
# just a function that fills a vector of objects, so I need a Class
# Movie{...};
# 
# I ask the user for an interval, it can be a two digits param like 80, so I
# need a test for a two digits and another one test of four digits 1980,
# and need to call it from the test so must need an object to interpret the decade.
# 
# And I return a file with the movies filtered, can be interesting a
# mocked data test where just need to change decade param, to reduce time
# with a real data example.
# 
# ----------------------
# SO,
# * test for Param of two digits (30, 40, ...),
# * test for Para of Four digits (1920, 2010, ...)
# * End-to-End test? Just check the array of movies if they are correctly filtered

import unittest
from Interpreter import Interpreter

class MoviesTest(unittest.TestCase):

    def test_ShouldParseParamOfFourDigits(self):
        # Arrange

        # Act
        expected_result = 1980
        actual_result = Interpreter.InterpretDecade(expected_result)
        
        # Result
        self.assertEqual(expected_result, actual_result)
    
    def test_ShouldParseParamOfTwoDigits(self):
        # Arrange

        # Act
        expected_result = 1980
        actual_result = Interpreter.InterpretDecade(80)
        
        # Result
        self.assertEqual(expected_result, actual_result)

    def test_ShouldReturnACollectionOfMoviesByDecade(self):
        # Arrange

        # Act
        expected_result = 1980
        actual_result = Interpreter.InterpretDecade(80)
        filteredMovies = Interpreter.FilterMovies(actual_result)
        
        # Result
        self.assertEqual(expected_result, actual_result)
        for movie in filteredMovies:
            self.assertTrue(movie['year'] >= actual_result)
            self.assertTrue(movie["year"] <= actual_result + 9)

if __name__ == '__main__':
    unittest.main()