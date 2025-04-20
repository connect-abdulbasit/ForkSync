# Dining Philosophers Problem

This is a basic implementation of the classic **Dining Philosophers Problem**, a synchronization problem often used in Operating Systems to demonstrate concepts like mutexes, semaphores, and thread coordination.

## 🧠 Project Overview

The Dining Philosophers Problem illustrates the challenges of avoiding deadlock and ensuring resource sharing among multiple processes (philosophers) trying to access limited shared resources (forks/chopsticks).

## 👥 Group Members

This project is a group effort by the following members:

- Abdul Basit (myself)
- Taaha Khan  
- Hani Ali  
- Shayan Ahmed  

## 🚧 Project Status

Initial version — under development.

## 🛠 Technologies Used

- C++  
- POSIX Threads / Synchronization Tools (Mutexes, Semaphores, etc.)

## ▶️ How to Run

To compile, run, and remove the kernel module:

1. **Compile the module:**
   ```bash
   make
   ```

2. **Insert the kernel module (requires superuser privileges):**
   ```bash
   sudo insmod DiningPhilosophers_Kernel.ko
   ```

3. **Check the kernel logs for output:**
   ```bash
   sudo dmesg | tail -n 20
   ```

   ```bash
   sudo dmesg -w
   ```

4. **Remove the kernel module when done:**
   ```bash
   sudo rmmod DiningPhilosophers_Kernel
   ```

5. **Verify removal via kernel logs:**
   ```bash
   dmesg | tail -n 20
   ```



