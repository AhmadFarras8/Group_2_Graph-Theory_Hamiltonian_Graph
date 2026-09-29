#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int graph[11][11];
int visited[11];
int path[10];

int roomCount;
int foundPath = 0;

/* Find all possible Hamiltonian paths using backtracking */
void findPaths(int currentRoom, int pathLength) {

    /* If all rooms have been visited, a Hamiltonian path is found */
    if (pathLength == roomCount) {

        for (int i = 0; i < roomCount; i++) {
            printf("%d", path[i]);

            if (i < roomCount - 1) {
                printf(" -> ");
            }
        }

        printf("\n");

        foundPath = 1;
        return;
    }

    /* Try every room as the next room */
    for (int nextRoom = 1; nextRoom <= roomCount; nextRoom++) {

        /* Check if the room is connected and not visited */
        if (graph[currentRoom][nextRoom] == 1 &&
            visited[nextRoom] == 0) {

            visited[nextRoom] = 1;
            path[pathLength] = nextRoom;

            /* Continue searching from the next room */
            findPaths(nextRoom, pathLength + 1);

            /* Backtrack */
            visited[nextRoom] = 0;
        }
    }
}

/* Validate the dungeon */
void validateDungeon() {

    foundPath = 0;

    printf("\nHamiltonian Path(s):\n");

    /* Try every room as the starting room */
    for (int startRoom = 1; startRoom <= roomCount; startRoom++) {

        /* Reset visited rooms */
        for (int i = 1; i <= roomCount; i++) {
            visited[i] = 0;
        }

        visited[startRoom] = 1;
        path[0] = startRoom;

        /* Search for Hamiltonian paths */
        findPaths(startRoom, 1);
    }

    /* Display the validation result */
    if (foundPath) {
        printf("\nDungeon is VALID.\n");
    } else {
        printf("\nDungeon is INVALID.\n");
    }
}

/* Clear the graph before generating a new dungeon */
void clearGraph() {

    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            graph[i][j] = 0;
        }
    }
}

/* Generate a valid dungeon */
void generateValidDungeon() {

    int rooms[10];
    int extraTunnels;

    /* Randomly choose between 5 and 10 rooms */
    roomCount = rand() % 6 + 5;

    clearGraph();

    /* Create room numbers */
    for (int i = 0; i < roomCount; i++) {
        rooms[i] = i + 1;
    }

    /* Shuffle the rooms */
    for (int i = roomCount - 1; i > 0; i--) {

        int j = rand() % (i + 1);

        int temp = rooms[i];
        rooms[i] = rooms[j];
        rooms[j] = temp;
    }

    /*
        Connect consecutive rooms.

        This guarantees at least one Hamiltonian path.
    */
    for (int i = 0; i < roomCount - 1; i++) {

        int roomA = rooms[i];
        int roomB = rooms[i + 1];

        graph[roomA][roomB] = 1;
        graph[roomB][roomA] = 1;
    }

    /*
        Add extra tunnels.

        5-6 rooms  -> 1 extra tunnel
        7-8 rooms  -> 2 extra tunnels
        9-10 rooms -> 3 extra tunnels
    */
    if (roomCount <= 6) {
        extraTunnels = 1;
    }
    else if (roomCount <= 8) {
        extraTunnels = 2;
    }
    else {
        extraTunnels = 3;
    }

    int addedTunnels = 0;

    while (addedTunnels < extraTunnels) {

        int roomA = rand() % roomCount + 1;
        int roomB = rand() % roomCount + 1;

        /* Avoid self-loops and duplicate tunnels */
        if (roomA != roomB && graph[roomA][roomB] == 0) {

            graph[roomA][roomB] = 1;
            graph[roomB][roomA] = 1;

            addedTunnels++;
        }
    }
}

/* Generate an invalid dungeon */
void generateInvalidDungeon() {

    int splitPoint;

    /* Randomly choose between 5 and 10 rooms */
    roomCount = rand() % 6 + 5;

    clearGraph();

    /*
        Split the rooms into two groups.

        There will be no tunnel connecting the two groups,
        so a Hamiltonian path cannot exist.
    */
    splitPoint = roomCount / 2;

    /* Connect rooms in the first group */
    for (int i = 1; i < splitPoint; i++) {

        graph[i][i + 1] = 1;
        graph[i + 1][i] = 1;
    }

    /* Connect rooms in the second group */
    for (int i = splitPoint + 1; i < roomCount; i++) {

        graph[i][i + 1] = 1;
        graph[i + 1][i] = 1;
    }
}

/* Display the dungeon */
void displayDungeon() {

    printf("\n=================================\n");
    printf("       DUNGEON GENERATOR\n");
    printf("=================================\n\n");

    printf("Number of Rooms: %d\n\n", roomCount);

    printf("Rooms:\n");

    for (int i = 1; i <= roomCount; i++) {
        printf("%d ", i);
    }

    printf("\n\n");

    printf("Tunnels:\n");

    /* Display each tunnel only once */
    for (int i = 1; i <= roomCount; i++) {
        for (int j = i + 1; j <= roomCount; j++) {

            if (graph[i][j] == 1) {
                printf("%d - %d\n", i, j);
            }
        }
    }
}

int main() {

    int dungeonType;

    /* Initialize the random number generator */
    srand(time(NULL));

    /*
        Randomly choose the dungeon type.

        0 = Invalid dungeon
        1 = Valid dungeon

        This gives approximately a 50/50 chance.
    */
    dungeonType = rand() % 2;

    if (dungeonType == 1) {
        generateValidDungeon();
    }
    else {
        generateInvalidDungeon();
    }

    /* Display the generated dungeon */
    displayDungeon();

    /* Run the validator */
    printf("\n=================================\n");
    printf("       DUNGEON VALIDATOR\n");
    printf("=================================\n");

    validateDungeon();

    return 0;
}

