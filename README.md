Codam project

# Minitalk

**Minitalk** is an inter-process communication project that demonstrates sending messages from a client to a server using Unix signals. The project uses bitwise operations to transmit and reconstruct characters bit-by-bit, with built-in acknowledgments and support for Unicode (UTF-8).

Use the provided Makefile to compile the server and client with make. Run ./server, then ./client PID "string"

## Overview

Minitalk consists of two programs:

- **Server (Receiver):** Listens for incoming signals, reconstructs each character from bits, and prints the message.
- **Client (Sender):** Sends a string message to the server by transmitting each bit of every character using signals.

## Features

- **Signal-based Communication:** Uses `SIGUSR1` and `SIGUSR2` to send bits between processes.
- **Bitwise Operations:** 
  - **Sender:** Extracts bits from each character using a right-shift (`>>`) and bitwise AND (`&`) to isolate each bit.
  - **Receiver:** Reconstructs the character by setting bits with bitwise OR (`|=`) and clearing bits with bitwise AND and NOT (`&= ~(1 << bit)`).
- **Acknowledgments:** After receiving each bit, the server sends back an acknowledgment signal (SIGUSR1) to ensure synchronization.
- **Unicode Support:** Since each byte of the string (including multi-byte UTF-8 characters) is processed individually, Unicode messages are supported.
- **Libft Integration:** Incorporates a custom `libft` for various utility functions.

## How It Works

### Bitwise Processing

1. **Sender Side: Extracting and Sending Bits**
   - For each character, the sender extracts bits using:
     ```c
     bit = (c >> j) & 1;
     ```
     - **`c >> j`:** Shifts the bits of `c` right by `j` positions so that the bit of interest moves into the least significant bit (LSB) position.
     - **`& 1`:** Masks all bits except the LSB, yielding either 0 or 1.
   - Depending on the bit value:
     - **0-bit:** Sends `SIGUSR1`
     - **1-bit:** Sends `SIGUSR2`
   - After each bit is sent, the sender waits for an acknowledgment from the server.

2. **Receiver Side: Reconstructing the Character**
   - The server listens for incoming signals. For each received signal:
     ```c
     if (sig == SIGUSR2)
         received.curr_char |= (1 << received.bit);
     else
         received.curr_char &= ~(1 << received.bit);
     ```
     - **`1 << received.bit`:** Creates a mask with a 1 in the correct bit position.
     - **`|=` Operator:** Sets the bit to 1 (when a 1-bit is received).
     - **`&= ~(1 << received.bit)`:** Clears the bit (when a 0-bit is received).
   - After 8 bits (one full character) are received:
     - The character is printed.
     - The temporary buffer is reset for the next character.
   - The server then sends an acknowledgment signal (`SIGUSR1`) back to the sender after processing each bit.

### Example Breakdown

Consider reconstructing the character `'A'` (ASCII 65 → binary `01000001`), assuming the bits are processed from the least significant (bit 0) to the most significant (bit 7):

| Bit Position | Expected Bit Value | Operation in Receiver                            | Explanation                                              | Resulting `curr_char` (binary) |
|--------------|--------------------|--------------------------------------------------|----------------------------------------------------------|--------------------------------|
| 0            | 1                  | `curr_char |= (1 << 0)`                          | Sets bit 0 to 1                                          | `00000001`                     |
| 1            | 0                  | `curr_char &= ~(1 << 1)`                         | Ensures bit 1 is 0                                       | `00000001`                     |
| 2            | 0                  | `curr_char &= ~(1 << 2)`                         | Ensures bit 2 is 0                                       | `00000001`                     |
| 3            | 0                  | `curr_char &= ~(1 << 3)`                         | Ensures bit 3 is 0                                       | `00000001`                     |
| 4            | 0                  | `curr_char &= ~(1 << 4)`                         | Ensures bit 4 is 0                                       | `00000001`                     |
| 5            | 0                  | `curr_char &= ~(1 << 5)`                         | Ensures bit 5 is 0                                       | `00000001`                     |
| 6            | 1                  | `curr_char |= (1 << 6)`                          | Sets bit 6 to 1                                          | `01000001`                     |
| 7            | 0                  | `curr_char &= ~(1 << 7)`                         | Ensures bit 7 is 0                                       | `01000001`                     |

After processing all bits, `curr_char` equals `01000001`, which corresponds to `'A'`.



