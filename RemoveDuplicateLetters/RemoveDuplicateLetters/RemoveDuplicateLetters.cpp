#include <string>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    string removeDuplicateLetters(string s) {
        // vector<int> count(26, 0) создаёт вектор из 26 целых чисел
		// и инициализирует их значением 0. Этот вектор будет использоваться для подсчета количества вхождений каждой буквы в строке s.
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
		// вектор<bool> visited(26, false) создаёт вектор из 26 булевых значений
		// и инициализирует их значением false. Этот вектор будет использоваться для отслеживания, была ли уже добавлена буква в результирующую строку.
        vector<bool> visited(26, false);
		// Стек для хранения символов результирующей строки
        stack<char> st;

		// Проходим по каждому символу в строке s
		for (char c : s) { // Для каждого символа уменьшаем его счетчик в count
            count[c - 'a']--;
			if (visited[c - 'a']) { // Если символ уже был добавлен в результирующую строку, пропускаем его
                continue;
            }
			// Удаляем символы из стека, если текущий символ меньше верхнего символа стека
            while (!st.empty() && st.top() > c && count[st.top() - 'a'] > 0) {
                visited[st.top() - 'a'] = false;
                st.pop();
            }
			// Добавляем текущий символ в стек и отмечаем его как посещенный
            st.push(c);
            visited[c - 'a'] = true;
        }

		// Собираем результат из стека в обратном порядке
        string result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
		// Переворачиваем строку, так как символы были добавлены в обратном порядке
        reverse(result.begin(), result.end());
        return result;
    }
};