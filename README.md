# Group_2_Graph-Theory_Hamiltonian_Graph

# Dungeon Generator & Validator

### Group Members

| No. | Name                         | NRP        |
| --: | ---------------------------- | ---------- |
|   1 | Ahmad Farras Favian Al Efasi | 5025251005 |
|   2 | Daniel Pedrosaputra          | 5025251171 |

---

## 1. Algorithm Explanation

### Dungeon Generator

The Dungeon Generator creates a dungeon represented as an undirected graph.
Each room is represented as a vertex, while each tunnel is represented as an edge. The number of rooms is randomly generated between 5 and 10.
The generator randomly chooses between generating a valid or invalid dungeon with approximately a 50/50 probability.

For a valid dungeon, the algorithm first shuffles the rooms and connects consecutive rooms. This guarantees that at least one Hamiltonian Path exists. Additional random tunnels are then added to make the dungeon structure more varied.

The number of additional tunnels depends on the number of rooms:

| Number of Rooms | Extra Tunnels |
| --------------- | ------------: |
| 5–6             |             1 |
| 7–8             |             2 |
| 9–10            |             3 |

For an invalid dungeon, the rooms are divided into two disconnected groups. Since there is no tunnel connecting the groups, it is impossible to visit every room in one path.


Pseudocode
PROCEDURE GenerateDungeon

    Generate a random number of rooms between 5 and 10

    Randomly choose dungeon type
        If random choice is VALID:
            Shuffle the room order

            FOR each consecutive pair of rooms
                Connect the two rooms with a tunnel
            END FOR

            Determine the number of extra tunnels
                If rooms = 5 or 6, add 1 extra tunnel
                If rooms = 7 or 8, add 2 extra tunnels
                If rooms = 9 or 10, add 3 extra tunnels

            Add random extra tunnels
                Do not add duplicate tunnels
        ELSE:
            Split the rooms into two groups

            Connect the rooms inside the first group

            Connect the rooms inside the second group

            Do not connect the two groups
        END IF

    Display the number of rooms
    Display all rooms
    Display all tunnels

END PROCEDURE


### Dungeon Validator

The Dungeon Validator checks whether the generated dungeon contains a Hamiltonian Path.

A Hamiltonian Path is a path that visits every vertex exactly once.
The validator uses a backtracking algorithm to find all possible Hamiltonian Paths. It starts from every room and recursively tries connected rooms that have not been visited.

When a room is added to the path, it is marked as visited. If the current path cannot continue, the algorithm backtracks and tries another possible route.
If a path visits every room exactly once, the dungeon is considered valid and the path is displayed. If no Hamiltonian Path is found, the dungeon is considered invalid.


Pseudocode
PROCEDURE ValidateDungeon

    foundPath ← FALSE

    FOR each room as a starting room
        Mark all rooms as unvisited
        Clear the current path

        Add the starting room to the path
        Mark the starting room as visited

        FindPaths(starting room)

    END FOR

    IF foundPath = TRUE
        Print "Dungeon is VALID"
    ELSE
        Print "Dungeon is INVALID"
    END IF

END PROCEDURE


PROCEDURE FindPaths(currentRoom)

    IF number of rooms in path = total number of rooms
        Print the current path
        foundPath ← TRUE
        RETURN
    END IF

    FOR each room connected to currentRoom
        IF the room has not been visited
            Mark the room as visited
            Add the room to the path

            FindPaths(room)

            Remove the room from the path
            Mark the room as unvisited
        END IF
    END FOR

END PROCEDURE


---

## 2. Prerequisites

* C compiler supporting standard C (online compiler also works)
* No external libraries are required
* Terminal or Command Prompt
* The program automatically generates the dungeon
* The program randomly generates either a valid or invalid dungeon

---

## 3. Instructions

### 3.1 Compile the Program

Open a terminal in the project directory and run:

```bash
gcc src/main.c -o dungeon
```

### 3.2 Run the Program

On Linux or macOS:

```bash
./dungeon
```

On Windows:

```text
dungeon.exe
```

The program will automatically:

1. Randomly choose a valid or invalid dungeon.
2. Randomly generate 5–10 rooms.
3. Generate the tunnels.
4. Display the generated dungeon.
5. Search for Hamiltonian Paths.
6. Display all Hamiltonian Paths found.
7. Display whether the dungeon is `VALID` or `INVALID`.

No manual input is required.

---

## 4. Sample Run Result

### 4.1 Invalid Dungeon

```text
=================================
       DUNGEON GENERATOR
=================================

Number of Rooms: 8

Rooms:
1 2 3 4 5 6 7 8

Tunnels:
1 - 2
2 - 3
3 - 4
5 - 6
6 - 7
7 - 8

=================================
       DUNGEON VALIDATOR
=================================

Hamiltonian Path(s):

Dungeon is INVALID.
```

The dungeon is invalid because the rooms are separated into two disconnected groups:

```text
1 - 2 - 3 - 4

5 - 6 - 7 - 8
```

There is no tunnel connecting the two groups, so it is impossible to visit all rooms exactly once.

### 4.2 Valid Dungeon

```text
=================================
       DUNGEON GENERATOR
=================================

Number of Rooms: 5

Rooms:
1 2 3 4 5

Tunnels:
1 - 3
1 - 4
2 - 3
2 - 4
4 - 5

=================================
       DUNGEON VALIDATOR
=================================

Hamiltonian Path(s):
1 -> 3 -> 2 -> 4 -> 5
2 -> 3 -> 1 -> 4 -> 5
5 -> 4 -> 1 -> 3 -> 2
5 -> 4 -> 2 -> 3 -> 1

Dungeon is VALID.
```

The dungeon is valid because the validator finds Hamiltonian Paths that visit all five rooms exactly once.

---

## 5. Conclusion

The Dungeon Generator & Validator successfully implements the required dungeon generation and validation algorithms.
The generator creates random dungeon structures containing 5–10 rooms and can produce both valid and invalid dungeons. The validator uses backtracking to determine whether a Hamiltonian Path exists.
Through this process, the program is able to generate a dungeon, validate its structure, and display the possible Hamiltonian Paths when the dungeon is valid.

## 6. AI Tools Usage Disclosure

**Tool:** ChatGPT

AI was used during the preparation of this assignment as a supporting tool to understand the assignment requirements, discuss the dungeon generation and validation approach, develop and review the C implementation, and prepare the README documentation.

### Prompts Used

1. "Explain to me what I must do for the assignment."

2. "What should I do step by step?"

3. "lets just use min 5 rooms and 10 rooms max, use number to represent room, and "-" to represent tunnel"
  
4. "i think its suitable if we have 1 and up to 3 random tunnel following the amount of the room"
   
5. "design the pseudo code for the generator and validator algorithm"
   
6. "now what should i do to build the structure for the c solution that's easy to understand
    and also have 50/50 chance of valid and invalid path"

7. "great, now can you review and paraphrase it?"

8. "now what should i put on the readme based on this previous assignment readme format"

---
