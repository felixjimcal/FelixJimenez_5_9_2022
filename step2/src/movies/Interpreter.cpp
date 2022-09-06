#include "Interpreter.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTextStream>

void Interpreter::ImportFile()
{
    QString val;
    QFile file;
    file.setFileName("movies.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject obj = doc.object();
    QJsonArray jsonMovies = obj["movies"].toArray();
    foreach (const QJsonValue &value, jsonMovies) {
        std::string title = value["title"].toString().toStdString();
        int year = value["year"].toInt(0);

        std::vector<std::string> cast = {}, genres = {};
        QJsonArray jsonCast = value["cast"].toArray();
        foreach (const QJsonValue &c, jsonCast) {
            cast.push_back(c.toString().toStdString());
        }

        QJsonArray jsonGenres = value["genres"].toArray();
        foreach (const QJsonValue &g, jsonGenres) {
            genres.push_back(g.toString().toStdString());
        }

        movies.push_back(Movie(title, year, cast, genres));
    }
}

int Interpreter::InterpretDecade(int decade)
{
    int result = 2000;

    if (std::to_string(decade).size() == 2 && decade % 10 == 0){
        if(decade > 00){
            result =std::stoi(std::to_string(19) + std::to_string(decade));
        }
    }

    if (std::to_string(decade).size() == 4 && decade % 10 == 0){
        result = decade;
    }
    return result;
}

std::vector<Movie> Interpreter::FilterMovies(int decade)
{
    std::vector<Movie> result;
    std::copy_if (movies.begin(), movies.end(), std::back_inserter(result), [&decade](const Movie movie){
        return movie.year >= decade && movie.year <= decade+9;
    });
    return result;
}

void Interpreter::ExportFile(int decade = 0, std::vector<Movie> filteredMovies = {})
{
    QString fileName = QString::number(decade) + "s-movies.json";
    QFile file(fileName);

    QJsonDocument JsonDocument;
    QJsonObject RootObject = JsonDocument.object();
    RootObject.insert("movies", "");
    QJsonValueRef ref = RootObject.find("movies").value();
    QJsonArray arr;
    for(const auto &movie : filteredMovies){
        QJsonObject m_addvalue = ref.toObject();
        m_addvalue.insert("title", movie.title.c_str());
        m_addvalue.insert("year", movie.year);

        QJsonArray castArray, genresArray;
        for(const auto &c : movie.cast) { castArray.push_back(c.c_str()); }
        for(const auto &g : movie.genres) { genresArray.push_back(g.c_str()); }

        m_addvalue.insert("cast", castArray);
        m_addvalue.insert("genres", genresArray);
        arr.append(m_addvalue);
    }
    ref=arr;

    JsonDocument.setObject(RootObject);
    file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
    file.write(JsonDocument.toJson());
    file.close();
}
