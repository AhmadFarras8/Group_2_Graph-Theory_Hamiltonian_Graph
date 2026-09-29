# Group_2_Graph-Theory_Hamiltonian_Graph

# Dungeon Generator & Validator

### Group Members

| No. | Name | NRP |
|---:|---|---|
| 1 | Ahmad Farras Favian Al Efasi | 5025251005 |
| 2 | Daniel Pedrosaputra | 5025251171 |

---

## 1. Algorithm Explanation

### Dungeon Generator

The Dungeon Generator is an algorithm used to procedurally create a dungeon represented as an undirected graph.

Each room is represented as a vertex, while each tunnel is represented as an edge. The number of rooms is randomly selected between 5 and 10.

The generator has a 50/50 chance of creating either a valid or invalid dungeon.

For a **valid dungeon**, the rooms are shuffled into a random order and consecutive rooms are connected. This guarantees at least one Hamiltonian Path. Additional random tunnels are then added to make the dungeon structure more varied.

The number of additional tunnels depends on the number of rooms:

| Number of Rooms | Extra Tunnels |
|---|---:|
| 5–6 | 1 |
| 7–8 | 2 |
| 9–10 | 3 |

For an **invalid dungeon**, the rooms are divided into two disconnected groups. Since there is no tunnel connecting the groups, it is impossible to visit every room in a single path.

### Dungeon Validator

The Dungeon Validator checks whether the generated dungeon contains a Hamiltonian Path.

A Hamiltonian Path is a path that visits every vertex exactly once.

The validator uses **Backtracking** to search for all possible Hamiltonian Paths.

It starts from every room and recursively tries every connected room that has not been visited. When a room is added to the current path, it is marked as visited. If the path cannot continue, the algorithm backtracks and tries another possible route.

If the path contains every room exactly once, the path is printed as a valid Hamiltonian Path.

If no Hamiltonian Path can be found, the dungeon is considered invalid.

---

## 2. Prerequisites

* C compiler supporting standard C
* No external libraries are required
* A terminal or command prompt
* The program automatically generates the dungeon
* The program randomly generates either a valid or invalid dungeon

---

## 3. Instructions

### 3.1 Compile the Program

Open a terminal in the repository folder and run:

```bash
gcc src/main.c -o dungeon
