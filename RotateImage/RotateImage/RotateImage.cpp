
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        vector<vector<int>> result(rows, vector<int>(rows));
        // Проходим по всем строкам исходной матрицы 
        for (int i = rows - 1; i >= 0; --i) {
            // Проходим по всем столбцам исходной матрицы
            for (int j = 0; j < rows; ++j) {
                // Переворачиваем матрицу
                result[j][rows - 1 - i] = matrix[i][j];
            }
        }
        // Возвращаем изменение
        matrix = result;
    }
};