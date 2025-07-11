# minitalk (42 Project)

This repository contains my implementation of the **minitalk** project from 42, which focuses on inter-process communication in C using UNIX signals.

## Project Overview

**minitalk** is a client-server application where the client sends messages to the server, one character at a time, using only UNIX signals. The project demonstrates how to transmit data between processes without using standard IPC mechanisms, relying exclusively on `SIGUSR1` and `SIGUSR2`.

## Key Features

- **Signal-Based Communication:** The client and server communicate by sending signals (`SIGUSR1` and `SIGUSR2`) to transmit data bit by bit.
- **Bitwise Data Transfer:** Each character in the message is broken down into bits, and each bit is sent as a signal from the client to the server.
- **Signal Handling with sigaction:** The server sets up signal handlers using `sigaction` for robust and reliable reception of signals.
- **Process Targeting with kill:** The client uses the `kill` system call to send signals directly to the server process identified by its PID.
- **Asynchronous Message Handling:** The server processes signals asynchronously, reconstructs the message, and displays it in real time.
- **Error Handling:** Validates process IDs, manages edge cases, and handles signal-related errors gracefully.

## How It Works

1. **Server Initialization:** The server starts, sets up signal handlers with `sigaction`, and displays its PID. It listens for incoming signals (`SIGUSR1` and `SIGUSR2`) to reconstruct the message.
2. **Client Message Sending:** The client takes the server’s PID and a message string, encodes each character into bits, and sends the bits as signals (`SIGUSR1` for 0, `SIGUSR2` for 1) using `kill`.
3. **Bitwise Transfer:** The server receives signals and reconstructs each character from the received bits.
4. **Output:** The server prints the full message once all bits are received.

## Example Usage

Clone and build the project:

```sh
git clone https://github.com/iliasgotweirdcodes/minitalk.git
cd minitalk
make
```

Start the server (in one terminal):

```sh
./server
```

Note the server's PID, then send a message from the client (in another terminal):

```sh
./client <server_pid> "Hello, minitalk!"
```

## Project Highlights

- **Inter-Process Communication:** Learn to send and receive data between processes using only UNIX signals.
- **Bit Manipulation:** Practice encoding and decoding information at the bit level.
- **Signal Handling:** Gain experience with asynchronous event management in C via `sigaction`.
- **Process Control:** Use `kill` to target specific processes for communication.
- **Robust Programming:** Develop skills in error checking and resource management.

## References

- [minitalk Project Specification (42)](https://github.com/42Paris/subjects/blob/master/minitalk.pdf)
- [Signal (IPC) - Wikipedia](https://en.wikipedia.org/wiki/Signal_(IPC))
- [UNIX Signals - GeeksforGeeks](https://www.geeksforgeeks.org/signals-c-language/)
- [sigaction - Linux manual page](https://man7.org/linux/man-pages/man2/sigaction.2.html)
- [kill - Linux manual page](https://man7.org/linux/man-pages/man2/kill.2.html)

---

Feel free to explore the code, experiment with different messages, and extend the application for bonus features!
