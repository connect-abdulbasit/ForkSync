# ForkSync: Dining Philosophers in C

**ForkSync** is a C-based implementation of the classic **Dining Philosophers Problem**, a fundamental synchronization and concurrency challenge in operating systems.

## 🧠 About the Project

The Dining Philosophers problem illustrates the challenges of resource sharing, deadlocks, and synchronization in concurrent programming. This simulation uses semaphores (or mutexes) to manage access to shared resources (forks) between competing threads (philosophers).

## 📁 Structure

```

ForkSync/
├── fork\_sync.c        # Main source code
├── Makefile           # Optional: compile script
└── README.md          # Project documentation

````

## ⚙️ How It Works

- Each philosopher is represented by a thread.
- Forks are represented using mutexes.
- Philosophers alternate between **thinking** and **eating**.
- To eat, a philosopher must acquire the left and right forks.
- Synchronization logic prevents **deadlock** and **starvation**.

## 🚀 Getting Started

### Compile

```bash
gcc fork_sync.c -lpthread -o forksync
````

### Run

```bash
./forksync
```

## 🧪 Sample Output

```
Philosopher 1 is thinking...
Philosopher 1 is hungry...
Philosopher 1 picked up fork 1
Philosopher 1 picked up fork 2
Philosopher 1 is eating...
...
```

## 📚 Concepts Demonstrated

* Mutex-based synchronization
* Deadlock avoidance
* Multi-threading in C (using `pthread`)
* Classical OS problems

## 🛠️ Technologies Used

* C (GCC)
* POSIX Threads (`pthread`)
* Standard Linux environment

## 📄 License

This project is licensed under the MIT License. Feel free to use, modify, or share it.
