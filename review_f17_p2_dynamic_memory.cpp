#include <iostream>
#include <string>

using namespace std;

class Movie
{
public:
  // EFFECTS: Constructs a Movie with the given title and length in
  // minutes
  Movie(const string &title_in, int length_in)
      : title(title_in), length(length_in) {}
  // EFFECTS: Returns the title of this Movie.
  string get_title() const { return title; }
  // EFFECTS: Returns the length of this Movie in minutes.
  int get_length() const { return length; }

private:
  string title;
  int length;
  // (in minutes)
}; // Movie


class Cinema
{
public:
  // EFFECTS: Constructs a Cinema with the given name and no movies.
  Cinema(const string &name_in) : name(name_in), num_movies(0) {}


  // copy constructor
  Cinema(const Cinema &other){

  }

  // YOU WILL IMPLEMENT THIS IN 2a)
  void add_movie(const string &title, int length) {
    Movie *m = new Movie(title, length);
    if (num_movies == MAX_MOVIES) {
      delete movies[num_movies - 1];
      movies[num_movies - 1] = m;
    } else {
      movies[num_movies] = m;
      num_movies++;
    }
  }

private:
  string name;
  const static int MAX_MOVIES = 20;

  Movie *movies[MAX_MOVIES]; // array of POINTERS to Movie
  int num_movies;            // # of movies in the array (first N elements)
};                           // Cinema


Cinema::Cinema(const Cinema &other): name(other.name), num_movies(other.num_movies) {
  for (int i = 0; i < other.num_movies; i++) {
    add_movie(other.movies[i]->get_title(), other.movies[i]->get_length());
  }
}