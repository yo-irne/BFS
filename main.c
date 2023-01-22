#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 1000000

int n, m;
int start, end;
int dist[MAX_N];
int visited[MAX_N];
int adjacency_list[MAX_N][2];

void read_input(char* file_name) {
    FILE* file = fopen(file_name, "r");
    fscanf(file, "%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int a, b;
        fscanf(file, "%d %d", &a, &b);
        adjacency_list[i][0] = a;
        adjacency_list[i][1] = b;
    }
    fclose(file);
}

void bfs(int start) {
    int queue[MAX_N];
    int head = 0, tail = 0;
    queue[tail++] = start;
    visited[start] = 1;
    dist[start] = 0;
    while(head != tail) {
        int vertex = queue[head++];
        for(int i = 0; i < m; i++) {
            int neighbor = -1;
            if(adjacency_list[i][0] == vertex) neighbor = adjacency_list[i][1];
            else if(adjacency_list[i][1] == vertex) neighbor = adjacency_list[i][0];
            if(neighbor != -1 && !visited[neighbor]) {
                queue[tail++] = neighbor;
                visited[neighbor] = 1;
                dist[neighbor] = dist[vertex] + 1;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    if(argc < 2) {
        printf("Podaj plik, gamoniu!\n");
        return 1;
    }
    read_input(argv[1]);
    scanf("%d %d", &start, &end);
    bfs(start);
    if(visited[end]) printf("Długość najkrótszej ściażki z %d do %d to %d\n", start, end, dist[end]);
    else printf("Brak ścieżki pomiędzy %d i %d\n", start, end);
    return 0;
}
