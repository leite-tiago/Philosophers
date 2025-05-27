# 🍝 Philosophers

**Philosophers** is a concurrency project developed as part of the 42 curriculum. It involves solving the classic "Dining Philosophers" problem using threads and mutexes in C. The goal is to simulate philosophers who must think, eat, and sleep, while properly handling synchronization to avoid deadlocks and starvation.

---

## 🧠 Simulation Rules

* Philosophers sit at a round table with one fork between each pair.
* Each philosopher must:

  * Take both forks (mutexes) to eat.
  * Eat for a specified time.
  * Sleep for a specified time.
  * Think before eating again.
* If a philosopher doesn't eat within `time_to_die`, they die and the simulation stops.

---

## 📋 Features

* Use of `pthread` library for thread management.
* One thread per philosopher.
* Use of `mutex` to protect shared resources (forks).
* Detection and printing of a philosopher's death.
* Optional `number_of_times_each_philosopher_must_eat` argument to end simulation.
* 
---

## 🚀 Getting Started

### Compilation

```bash
make
```

### Usage

```bash
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

### Example

```bash
./philo 5 800 200 200
```

Runs a simulation with:

* 5 philosophers
* 800ms until death without eating
* 200ms eating
* 200ms sleeping

---

## 📂 File Structure

```
philosophers/
├── include/             # Header files
│   └── philo.h
├── src/                 # Source files
│   ├── main.c           # Entry point
│   ├── init.c           # Initialization logic
│   ├── routine.c        # Philosopher routine implementation
│   ├── monitor.c        # Death and meal check monitoring
│   └── utils.c          # Helper functions
├── Makefile             # Build instructions
└── README.md            # Project documentation
```

---

## 🛠️ Built With

* C programming language
* `pthread` library for multithreading

---

## 📖 What I Learned

* Creating and managing threads using `pthread`
* Synchronizing shared resources with mutexes
* Handling timing and precise sleeping in C
* Preventing common concurrency issues like deadlocks and race conditions

---

## 📜 License

This project is part of the 42 Network curriculum.
