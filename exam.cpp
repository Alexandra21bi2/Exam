#include <iostream>
#include <vector>

const int N = 100; // Максимальное кол-во городов
int start = 1; // Париж
int end = 100; // Рим
int cnt = 0; // счетчик допустимых путей
std::vector<int> ways[N + 1]; // вектор для хранения путей
bool visited[N + 1]; // массив для обозначения посещенных городов

void dfs(int u) {
    visited[u] = true;
    if (u == end) {
        cnt++; // если добираемся до рима по прибавляем к cnt
    }
    else {
        for (int v : ways[u]) {
            if (!visited[v]) {
                dfs(v);
            }
        }
    }
    visited[u] = false; // обратный путь
}

int main() {
    int m; // кол-во путей
    std::cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        ways[u].push_back(v);
        ways[v].push_back(u); // добавляем оба направления
    }
    dfs(start);
    std::cout << cnt << std::endl;
    return 0;
}
