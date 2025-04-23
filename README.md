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

- C (Linux Kernel Module)
- Linux Kernel Threads
- Synchronization Primitives (Semaphores)

---

## ▶️ How to Run

### 1. **Compile the kernel module**
```bash
make
```

### 2. **Insert the kernel module**
```bash
sudo insmod DiningPhilosophers_Kernel.ko
```

### 3. **Check the kernel logs**
```bash
sudo dmesg | tail -n 20
```
### 4. **Check the runtime kernel logs**
```bash
sudo dmesg -w
```

### 5. **Remove the kernel module**
```bash
sudo rmmod DiningPhilosophers_Kernel
```

---

## 🛡️ Secure Boot: How to Sign the Module

If you're on a system with **Secure Boot enabled**, you'll need to sign your kernel module before inserting it. Here's how:

### ✅ Step 1: Create a Signing Key

```bash

openssl req -new -x509 -newkey rsa:2048 -keyout MOK.priv -outform DER -out MOK.der -nodes -days 36500 -subj "/CN=My Own Kernel Module Key/"
```

- `MOK.priv`: Private key  
- `MOK.der`: Public certificate to enroll into UEFI

---

### ✅ Step 2: Sign the Kernel Module

Find the `sign-file` script:

```bash
find /usr/src/linux-headers-$(uname -r)/ -name sign-file
```

Then run:

```bash
sudo /usr/src/linux-headers-$(uname -r)/scripts/sign-file sha256 MOK.priv MOK.der DiningPhilosophers_Kernel.ko
```

---

### ✅ Step 3: Enroll the Key into UEFI

```bash
sudo mokutil --import MOK.der
sudo reboot
```

During reboot:

1. A blue MOK manager screen will appear.
2. Select **"Enroll MOK"**.
3. Choose **"Continue"**, enter the password.
4. System will reboot again with the key trusted.

---

### ✅ Step 4: Insert the Signed Module

```bash
sudo insmod DiningPhilosophers_Kernel.ko
```
