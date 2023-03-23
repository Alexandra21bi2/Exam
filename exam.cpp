
/*
��������� ���������� �������� ������ � ������� (DFS) ��� �������� ���������� ��������� �� ������ � ���,
��� ������ ���������� �� ����� ������ ����.
�� ��������� ���������� ����� m � ��� �������,
������� ��������������� ��������� �����, � ������� ������ adj ��� �������� ������� ������� ������.
����� ��������� DFS �� ������, ������� ���������� ������ � ������� ���������� � ���������� ������� cnt ������ ���,
����� ��������� ����. � ����� ������� ����� ���������� ���������� �����.
*/

#include <iostream>
#include <vector>

const int N = 100; // ������������ ���-�� �������
int start = 1; // �����
int end = 100; // ���
int cnt = 0; // ������� ���������� �����
std::vector<int> ways[N + 1]; // ������ ��� �������� �����
bool visited[N + 1]; // ������ ��� ����������� ���������� �������

void dfs(int u) {
    visited[u] = true;
    if (u == end) {
        cnt++; // ���� ���������� �� ���� �� ���������� � cnt
    }
    else {
        for (int v : ways[u]) {
            if (!visited[v]) {
                dfs(v);
            }
        }
    }
    visited[u] = false; // �������� ����
}

int main() {
    int m; // ���-�� �����
    std::cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        ways[u].push_back(v);
        ways[v].push_back(u); // ��������� ��� �����������
    }
    dfs(start);
    std::cout << cnt << std::endl;
    return 0;
}