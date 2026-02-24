

// Безквадратно (square-free) число е такова естествено число, което не се дели на никое число по-голямо от 1, повдигнато на квадрат.
// Примери за безквадратни числа : 1, 2, 3, 5, 6, 7, 10, 11, 13, 14, 15, …
// Примери за числа, които НЕ са безквадратни :
// 4 (2 ^ 2 дели 4), 8 (2 ^ 2 дели 8), 12 (2 ^ 2 дели 12), 45 (3 ^ 2 дели 45), 125 (5 ^ 2 дели 125) …
// Реализирайте програма, която въвежда от стандартния вход две естествени числа N и М, последвани от матрица с размери N x M от естествени числа.
// Премахнете от матрицата всички стълбове, в които се срещат безквадратни числа.Изведете на екрана получената матрица.

#include <iostream>
#include <vector>
#include <set>

bool isSquareless(int number){
    for(int i = 2; i < number; i++){
        if (i * i > number)  break;
        if(number % (i * i) == 0) return false;
    }

    return true;
}

int main() {
    int n, m;
    std::set<int> columnsForRemoval;
    std::cout << "Please enter 2 numbers (N & M) separated with space: ";
    std:: cin >> n >> m;

    if(std::cin.fail() || n <= 0 || m <= 0){
		std::cout << "Invalid input. n must be greater than 0." << std::endl;
		return 1;
	}

    std::vector<std::vector<int>> matrix = std::vector<std::vector<int>>(n, std::vector<int>(m, 0));

    std::cout << "Enter the matrix values:" << std::endl;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            std::cin >> matrix[row][col];
            // check for squareless numbers and mark columns for removal
            if(isSquareless(matrix[row][col]) && columnsForRemoval.find(matrix[row][col]) == columnsForRemoval.end()) {
                columnsForRemoval.insert(col);
            }
        }
    }

    // printout message in case the columnsForRemoval has the same width as the matrix
    // no need to continue if columnsForRemoval == m
    if (columnsForRemoval.size() == m) {
        std::cout << "Nothing to print out as all columns contain squareless numbers." << std::endl;
        return 0;
    }

    // remove columns with squareless numbers
    for (int row = 0; row < n; row++) {
        std::set<int>::reverse_iterator it;
        for (it = columnsForRemoval.rbegin(); it != columnsForRemoval.rend(); ++it) {
             matrix[row].erase(matrix[row].begin() + *it);
        }
    }

    // check the matrix for squareless number
    std::cout << "The result without squareless numbers in any column." << std::endl;
    for (int row = 0; row < matrix.size(); row++) {
        for (int col = 0; col < matrix[row].size(); col++) {
            std::cout << matrix[row][col] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
