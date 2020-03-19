// open closed principle
// open for extension, closed for modification

#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum class Color { red, green, blue };
enum class Size { small, medium, large };

struct Product {
    string name;
    Color color;
    Size size;
};

struct ProductFilter {
    typedef vector<Product*> Items;

    Items by_color(Items items, const Color color) {
        Items result;
        for (auto& i : items)
            if (i->color == color) result.push_back(i);
        return result;
    }

    Items by_size(Items items, const Size size) {
        Items result;
        for (auto& i : items)
            if (i->size == size) result.push_back(i);
        return result;
    }

    Items by_size_and_color(Items items, const Size size, const Color color) {
        Items result;
        for (auto& i : items)
            if (i->size == size && i->color == color) result.push_back(i);
        return result;
    }
};

int main() {
    Product apple{"Apple", Color::green, Size::small};
    Product tree{"Tree", Color::green, Size::large};
    Product house{"House", Color::blue, Size::large};

    const vector<Product*> all{&apple, &tree, &house};

    ProductFilter pf;
    auto green_things = pf.filter(all, green);
    for (auto& x : green_things) {
        cout << x->name << " is green\n";
    }
    return 0;
}