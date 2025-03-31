### **1: Resource Management**

One of the key functions of an **Operating System (OS)** is **resource management**, ensuring that programs get the necessary memory, CPU time, and I/O access to execute efficiently.

#### **How Code Gets Executed**

When you write code in a **compiled language** (e.g., C/C++), the compiler first converts it into machine code. However, simply compiling isn’t enough—the OS must then manage the execution process. This happens in a cycle:

1. **Fetch** – Load instructions from memory.
2. **Decode** – Interpret the instruction.
3. **Execute** – Process the instruction.

This fetch-decode-execute cycle repeats for each instruction until the program completes. The OS ensures that instructions are fetched into temporary memory and executed properly.

For **interpreted languages** (e.g., Python, JavaScript), compilation and execution happen together, a concept called **lazy compilation**—only compiling and executing a line when needed.

#### **Resources Needed for Execution**

To run any code, three key resources are required:

- **Memory (RAM)** – Stores the program, its variables, and ensures no interference from other programs.
- **CPU (Execution Thread)** – A processor core to execute instructions.
- **I/O Drivers** – To read/write data from storage (e.g., HDD, SSD) or communicate with external devices.

The OS is responsible for allocating these resources and enforcing access rules. For example, if a program tries to access memory beyond its allocated range (e.g., accessing address **205** when given **100-200**), the OS raises an error like **segmentation fault** or **index out of bounds** to prevent data corruption.

#### **System Calls: Interacting with the OS**

Programs communicate with the OS using **system calls**, which request resources like memory, file access, or network communication.

- Different programming languages provide **wrappers** around system calls to simplify their use.
    - Example: `read()` system call in C has higher-level wrappers like `scanf()` and `cin`.

By managing resources efficiently, the OS ensures smooth execution, security, and stability for all running programs.
