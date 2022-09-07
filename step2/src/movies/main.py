
from Interpreter import Interpreter


if __name__ == "__main__":
    Interpreter.ImportFile()
    
    while True:
        try:
            decade = int(input('Type a decade 10-20...80 \n'))
            break
        except:
            print("That's not a valid option")

    decade = Interpreter.InterpretDecade(decade)
    filteredMovies = Interpreter.FilterMovies(decade)
    Interpreter.ExportFile(decade, filteredMovies)
