//
// Created by pc on 09.05.2021.
//

// ConsoleApplication1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

#include <vector>
#include <algorithm>
#include <cassert>

#define MILLION 1000000
#define SHOW_VEC(x) for(auto i:x) { std::cout<<i<<" ";} std::cout<<std::endl

#include "windows_console_tools/win_colors.h"
struct threesome {
    int from;
    int to;
    int weight;

    threesome(int from, int to, int weight) : from(from), to(to), weight(weight) {}

    bool operator==(const threesome& other) const {
        return weight == other.weight;
    }

    bool operator!=(const threesome& other) const {
        return weight != other.weight;
    }

    bool operator>(const threesome& other) const {
        return weight > other.weight;
    }

    bool operator<(const threesome& other) const {
        return weight < other.weight;
    }

    bool operator>=(const threesome& other) const {
        return weight >= other.weight;
    }

    bool operator<=(const threesome& other) const {
        return weight <= other.weight;
    }

    friend std::ostream& operator<<(std::ostream& out, const threesome& dt) {
        out << "from " << dt.from;
        out << " to " << dt.to;
        out << " weight " << dt.weight << "\n";
        return out;
    }


};

class node {

public:
    node(int weight) : city_name(weight) {};

    node(const node& other) {
        city_name = other.city_name;
        nodes = other.nodes;
        weights = other.weights;
    }


    std::vector<node*> nodes;
    std::vector<int> weights;
    int city_name;


    bool operator==(const node& other) const {
        return city_name == other.city_name;
    }

    bool operator!=(const node& other) const {
        return city_name != other.city_name;
    }


    void append(const node& other, threesome sth) {

        if (city_name == sth.from) {
            nodes.push_back(new node(other));
            weights.push_back(sth.weight * -1);
            return;
        }
        node* ptr_to_node = search(sth.from);
        ptr_to_node->nodes.push_back(new node(other));
        ptr_to_node->weights.push_back(sth.weight * -1);


    }

    int minimal_route_to(int to, int minimal_value = MILLION) {

        if (city_name == to) return minimal_value;

        if (nodes.empty()) return MILLION;

        int temp_int;

        for (unsigned int i = 0; i < nodes.size(); i++) {

            if (weights[i] < minimal_value) minimal_value = weights[i];

            temp_int = nodes[i]->minimal_route_to(to, minimal_value);
            if (temp_int != MILLION) return temp_int;

        }

        assert(false);
        return MILLION;
    }

    node* search(int value) {
        if (this->city_name == value) return this;

        node* ptr_to_return = nullptr;

        if (nodes.empty()) return nullptr;

        for (auto& i : nodes) {

            ptr_to_return = i->search(value);
            if (ptr_to_return != nullptr) break;
        }

        return ptr_to_return;
    }

    ~node() = default;

    friend std::ostream& operator<<(std::ostream& out, const node& dt) {
        out << "name " << dt.city_name << "\n";
        SHOW_VEC(dt.nodes);
        //   SHOW_VEC(dt.weights);
        return out;
    }

};


int road_trips(int from, int to, int pssngrs, node& tree);


node find_in_vec(const std::vector<node>& data, int search);

int main() {
    int number_of_cities;
    int number_of_roads;
    std::vector<threesome> tab;

    int temp_from;
    int temp_to;
    int temp_weight;

    std::cin >> number_of_cities;
    std::cin >> number_of_roads;

    for (int i = 0; i < number_of_roads; i++) {
        std::cin >> temp_from;
        std::cin >> temp_to;
        std::cin >> temp_weight;

        tab.emplace_back(temp_from, temp_to, temp_weight);

    }
    // SHOW_VEC(tab);

    for (auto& i : tab) {
        i.weight--; //bo kierowca zajmuje niepotrzebne miesce podobno
        // i don't see it but okey
        i.weight = -i.weight; // bo trzeba zrobić maksymalne drzewo rozpinające ale mamy algorytm tylko na minimalne,
        // wiec jak bedziemy pracowac
        // na liczbach pzeciwnych to zadziala
        //dzieki temu zastosujemy algorytm najmniejszego drzewa rozpinajacego od Kruskala
    }

    std::sort(tab.begin(), tab.end());

    SHOW_VEC(tab);

    std::vector<node> forest;

    for (auto i : tab) {
        if (std::find(forest.begin(), forest.end(), i.from) == forest.end()) {
            //potrzebujemy stworzyc las wierzcholkow,
            // ale wierzcholki nie moga sie powtarzac,
            // a nie znamy ich nazwa,
            // wiec szukam czy mam juz taki wierzcholek w lesie
            // i jak nie to dodajemy do lasu
            forest.push_back(node(i.from));
        }

        if (std::find(forest.begin(), forest.end(), i.to) ==
            forest.end()) { //to samo co wyzej ale moglo byc tak ze jakis wierzcholek byl w to, a nie bylo go w from

            forest.push_back(node(i.to));
        }
    }
    SHOW_VEC(forest);
    std::vector<threesome> additional_tab;
    unsigned i = 0;



    while (forest.size() > 1) {
        node to_city = find_in_vec(forest, tab[i].to);

        find_in_vec(forest, tab[i].from).append(to_city, tab[i]);
        //forest[tab[i].to].city_name = MILLION;
        forest.erase(std::find(forest.begin(), forest.end(), to_city));

        i++;
    }


    SHOW_VEC(forest);
    node minimal_spanning_tree = forest[0];

    int from_user;
    int to_user;
    int how_many_people;


    do {

        std::cin >> from_user;
        std::cin >> to_user;

        if (from_user != 0 && to_user != 0) break;

        std::cin >> how_many_people;

        int dzielna = how_many_people / road_trips(from_user, to_user, how_many_people, minimal_spanning_tree);
        int leftovers = how_many_people % road_trips(from_user, to_user, how_many_people, minimal_spanning_tree);

        if (leftovers != 0) dzielna++;

        std::cout << dzielna << std::endl;
    } while (2 > 1);

}

// Liczba_przejazdow = liczba_osob_do_przejazdu / (Liczba_osob-1)
// maksymalne ale minimalne drzewo rozpinające
// las
// 2 tablice struktur albo kolejki
// W2:

//Y(x) = -x
//
//Y(60) = -60
//
//Y(20) = -20
//
//I 60 > 20 a y(60) = -60 < y(20) = -20

//wystarczy zwykly unsigned int


int road_trips(int from, int to, int pssngrs, node& tree) {

    if (tree.search(from)->search(to) != nullptr) {
        return tree.search(from)->minimal_route_to(to);

    }
    else return tree.search(to)->minimal_route_to(from);
    assert(false);
}

node  find_in_vec(const std::vector<node>& data, int search) {

    for (auto i : data)
        if (i.search(search) != nullptr)
            return *i.search(search);

    assert(false);
}


void test_me_daddy() {
    std::cout << cc(white) << "constructor: ";
    node tree(6);
    assert(tree.city_name == 6);
    std::cout << cc(green) << "[ok]";

}