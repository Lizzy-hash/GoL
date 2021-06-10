#include <iostream>
#include <cmath>
#include <algorithm>

std::pair<long long, long long> find_smallest_y(std::pair<long long, long long> *lanterns, int number_of_lanterns);

double alpha(int y, int x);

void sort_pairs(std::pair<long long, long long> *lanterns, int number);

int main() {
    std::cout << "Hello, World!" << std::endl;

    int number_of_big_lanterns;
    std::cin >> number_of_big_lanterns;

    std::pair<long long, long long> *coords_of_big_ones = new std::pair<long long, long long>[number_of_big_lanterns];

    long long temp_x;
    long long temp_y;

    for (int i = 0; i < number_of_big_lanterns; i++) {
        std::cin >> temp_x >> temp_y;
        coords_of_big_ones[i].first = temp_x;
        coords_of_big_ones[i].second = temp_y;
    }

    int number_of_small_lanterns;
    std::cin >> number_of_small_lanterns;

    std::pair<long long, long long> *coords_of_small_ones = new std::pair<long long, long long>[number_of_big_lanterns];

    for (int i = 0; i < number_of_small_lanterns; i++) {
        std::cin >> temp_x >> temp_y;
        coords_of_small_ones[i].first = temp_x;
        coords_of_small_ones[i].second = temp_y;
    }

    std::pair<long long, long long> smallest_y = find_smallest_y(coords_of_big_ones, number_of_big_lanterns);

    std::cout<<smallest_y.first<<" "<<smallest_y.second<<"\n";

    for (int i = 0; i < number_of_big_lanterns; i++) {
        coords_of_big_ones[i].first -= smallest_y.first;
        coords_of_big_ones[i].second -= smallest_y.second;
      // std::cout<<coords_of_big_ones[i].first<<" "<<coords_of_big_ones[i].second<<"\n";
    }

    sort_pairs(coords_of_big_ones, number_of_big_lanterns);

    for(int i = 0 ; i < number_of_big_lanterns; i++){
        std::cout<<coords_of_big_ones[i].first<<" "<<coords_of_big_ones[i].second<<"\n";
    }

    return 0;
}

double alpha(int y, int x) {
    double angle = 0.0;


    if (x > 0) {
        if (y > 0) angle = y / (abs(x) + abs(y));
        else angle = 4 - (abs(y) / (abs(x) + abs(y)));
    } else if (x < 0){
        if (y > 0) angle = 2 - (y / (abs(x) + abs(y)));
        else angle = 2 + (abs(y) / (abs(x) + abs(y)));
    }

    return angle;
}

std::pair<long long, long long> find_smallest_y(std::pair<long long, long long> *lanterns, int number_of_lanterns) {
    std::pair<long long, long long> small;

    for (int i = 1; i < number_of_lanterns; i++) {
        if (lanterns[i - 1].second < lanterns[i].second) small = lanterns[i - 1];
    }

    return small;
}

///this shit doesn't work
void sort_pairs(std::pair<long long, long long> *lanterns, int number) {
    double angle;
    std::pair<long long, long long> temp;

    for(int i = 1; i < number; i++){
        angle = alpha(lanterns[i - 1].first, lanterns[i - 1].second);

        if(alpha(lanterns[i].first, lanterns[i].second) >= angle) {
            temp = lanterns[i - 1];
            lanterns[i - 1] = lanterns[i];
            lanterns[i] = temp;
        }

    }


}