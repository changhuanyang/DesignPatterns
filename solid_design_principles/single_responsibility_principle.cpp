#include <boost/lexical_cast.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Journal {
    string title;
    vector<string> entries;

    explicit Journal(const string& title) : title{title} {}

    void add(const string& entry);

    // persistence is a separate concern
    void save(const string& filename);
};

void Journal::add(const string& entry) {
    static int count = 1;
    entries.push_back(boost::lexical_cast<string>(count++) + ": " + entry);
}

void Journal::save(const string& filename) {
    ofstream ofs(filename);
    for (auto& s : entries) ofs << s << endl;
}

void main() {
    Journal journal{"Dear Diary"};
    journal.add("I ate a bug");
    journal.add("I cried today");

    journal.save("diary.txt");
}