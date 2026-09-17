#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        // Используем двухсторонную очередь, храним в ней индексы
        deque<int> dq;

        for (int i = 0; i < nums.size(); ++i) {
            // Удаляем элементы, вышедшие за границы окна
            if (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            };
            // Удаляем элементы с конца, которые меньше текущего
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            // Добавляем текущий индекс
            dq.push_back(i);

            // Когда окно полное, записываем максимум
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};