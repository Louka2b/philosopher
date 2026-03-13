<p><em>This project has been created as part of the 42 curriculum by ldeplace.</em></p>

<div align="center">

<h1>
PHILOSOPHERS
</h1>

<h4>Eat, sleep, think, repeat — and try not to die.</h4>

<br>

<a href="#">
<img src="https://img.shields.io/badge/language-C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="Language">
</a>
&nbsp;
<a href="#">
<img src="https://img.shields.io/badge/‎-philosophers-00BABC?style=for-the-badge&logo=42&logoColor=white" alt="42 Project">
</a>
&nbsp;
<a href="#">
<img src="https://img.shields.io/badge/threads-mutex-E06C00?style=for-the-badge&logo=databricks&logoColor=white" alt="Threads & Mutex">
</a>

<br><br>

<kbd>Current Score</kbd>
<br><br>
<a href="https://projects.intra.42.fr">
<img src="https://42cv.dev/api/badge/cmmm23yq10000dgywpv8dqd2n/project/4829816" alt="Score">
</a>

<br>

</div>

<br>

---

## ◈ Description

This project is an implementation of the classic **Dining Philosophers Problem**, originally formulated by Edsger Dijkstra in 1965.

Several philosophers sit around a round table with a large bowl of spaghetti in the center. They spend their lives alternating between three states: **eating**, **sleeping**, and **thinking**. To eat, each philosopher needs to pick up **two forks** — one on their left and one on their right. If a philosopher doesn't start eating within a certain time since their last meal, they **die**.

The goal is to solve this concurrency problem using **POSIX threads** and **mutexes**, ensuring that:

- ▸ No philosopher dies unnecessarily
- ▸ No **deadlock** occurs — the program never freezes
- ▸ No **data race** occurs — shared data is properly protected

---

## ◈ Instructions

### ◇ Prerequisites

- **OS** → Unix-based (Linux / macOS)
- **Compiler** → `cc`
- **Build** → `make`

### ◇ Compilation

```bash
make        # Build the project
make clean  # Remove object files
make fclean # Remove object files and the executable
make re     # Full recompile
```

### ◇ Execution

```bash
./philo nb_philosophers time_to_die time_to_eat time_to_sleep [nb_meals]
```

### ◇ Arguments

| Argument | Type | Description |
|:---|:---:|:---|
| `nb_philosophers` | `int` | Number of philosophers (and forks) sitting at the table |
| `time_to_die` | `int` (ms) | Max time since the **start of the last meal** before a philosopher dies |
| `time_to_eat` | `int` (ms) | Time it takes for a philosopher to eat (holding 2 forks) |
| `time_to_sleep` | `int` (ms) | Time a philosopher spends sleeping |
| `nb_meals` | `int` (optional) | Simulation stops when every philosopher has eaten at least this many times |

### ◇ Usage Examples

```bash
# 5 philosophers, comfortable timing — no one dies
./philo 5 800 200 200

# Simulation stops after each philosopher has eaten 7 times
./philo 5 800 200 200 7

# 4 philosophers, tight timing — no one should die
./philo 4 410 200 200

# 4 philosophers, impossible timing — someone dies
./philo 4 310 200 100

# 1 philosopher — always dies (only 1 fork available)
./philo 1 800 200 200
```

### ◇ Output Format

Each state change is logged with a **timestamp** (in ms since simulation start) and the **philosopher's number** (starting at 1):

```
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
```

> The death message must be printed within **10ms** of the actual death. No messages may appear after a death message.

---

## ◈ Technical Details

### ◇ Rules

- ▸ Each philosopher is a **thread**
- ▸ Each fork is protected by a **mutex**
- ▸ Philosophers do not communicate with each other
- ▸ Philosophers do not know if another philosopher is about to die
- ▸ No global variables

### ◇ Allowed Functions

| Category | Functions |
|:---|:---|
| **Memory** | `memset` · `malloc` · `free` |
| **Output** | `printf` · `write` |
| **Time** | `usleep` · `gettimeofday` |
| **Threads** | `pthread_create` · `pthread_detach` · `pthread_join` |
| **Mutex** | `pthread_mutex_init` · `pthread_mutex_destroy` · `pthread_mutex_lock` · `pthread_mutex_unlock` |

---

## ◈ Resources

### ◇ References

- ▹ [Dining Philosophers Problem — Wikipedia](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- ▹ [POSIX Threads Programming — LLNL](https://hpc-tutorials.llnl.gov/posix/)
- ▹ [Mutex and Threading in C — GeeksforGeeks](https://www.geeksforgeeks.org/mutex-lock-for-linux-thread-synchronization/)
- ▹ [Unix Threads in C — CodeVault (YouTube)](https://www.youtube.com/playlist?list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)
- ▹ `man pthread_create` · `man pthread_mutex_lock` · `man gettimeofday` · `man usleep`

### ◇ Use of AI

I used AI to structure this readme.

---

<div align="center">

<img src="https://42cv.dev/api/badge/cmmm23yq10000dgywpv8dqd2n/stats?cursusId=21&coalitionId=48" alt="42 Stats">

<br><br>

<sub>Made by <strong>ldeplace</strong> at 42</sub>

</div>
