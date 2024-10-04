#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>

using namespace std;

// Функция для вычисления евклидова расстояния между двумя городами
double calculateDistance(const pair<double, double>& city1, const pair<double, double>& city2) {
    return sqrt(pow(city1.first - city2.first, 2) + pow(city1.second - city2.second, 2));
}

// Функция для вычисления общего расстояния для заданного маршрута
double totalDistance(const vector<pair<double, double>>& cities, const vector<int>& path) {
    double total = 0.0;

    for (size_t i = 0; i < path.size(); i++) {
        int currentCity = path[i];
        int nextCity = path[(i + 1) % path.size()];  // Возвращаемся в начало
        total += calculateDistance(cities[currentCity], cities[nextCity]);
    }

    return total;
}

// Функция для решения задачи коммивояжера
void travelingSalesman(const vector<pair<double, double>>& cities) {
    int numCities = cities.size();
    vector<int> path(numCities);
    iota(path.begin(), path.end(), 0);  // Заполнение индексов 0, 1, ..., numCities - 1

    double minDistance = numeric_limits<double>::max();
    vector<int> optimalPath;

    do {
        double currentDistance = totalDistance(cities, path);
        if (currentDistance < minDistance) {
            minDistance = currentDistance;
            optimalPath = path;
        }
    } while (next_permutation(path.begin(), path.end()));

    // Выводим оптимальный путь и дистанцию
    cout << "Оптимальный путь: ";
    for (int city : optimalPath) {
        cout << city << " ";
    }
    cout << endl;
    cout << "Дистанция: " << minDistance << endl;
}

int main() {

    setlocale(LC_ALL, "Rus");

    // Пример координат городов
    vector<pair<double, double>> cities = {
        {0.0, 0.0},  // Город 0
        {1.0, 2.0},  // Город 1
        {2.0, 1.0},  // Город 2
        {3.0, 3.0}   // Город 3
    };

    travelingSalesman(cities);
    return 0;
}