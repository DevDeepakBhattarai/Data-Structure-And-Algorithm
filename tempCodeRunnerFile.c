        for (int j = 0; j < 7; j++) {
            if (graph[node][j] == 1 && visited[j] == 0) {
                printf("%d", j);
                visited[j] = 1;
                queueEnqueue(explorationQueue, j);
            }
        }