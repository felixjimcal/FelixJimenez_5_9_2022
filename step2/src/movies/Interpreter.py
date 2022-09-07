from fileinput import filename
import json

movies = []
class Interpreter(object):
    def ImportFile():
        with open('movies.json') as jsonFile:
           data = json.load(jsonFile)
           for d in data:
            movies.append(d)

    def InterpretDecade(decade):
        result = decade

        if len(str(decade)) == 2  and decade & 10 == 0:
            result = int(str(19) + str(decade))

        if len(str(decade)) == 4  and decade & 10 == 0:
            result = decade

        return result

    def FilterMovies(decade):
        return [m for m in movies if m['year'] >= decade and m['year'] <= decade + 9]

    def ExportFile(decade, filteredMovies):
        filename = str(decade) + "s-smovies.json"
        file = open(filename, "a")
        file.write(json.dumps(filteredMovies))
        file.close()