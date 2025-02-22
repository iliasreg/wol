# Wake-On-LAN (WOL) Implementation in C++

A simple C++ implementation of the Wake-On-LAN protocol to send magic packets and wake up devices on a local network.

---

## **Purpose**
This project demonstrates how to:
1. Parse a MAC address.
2. Construct a WOL magic packet.
3. Send the packet via UDP broadcast to wake up a target machine.

---

## **Usage**

### **Build**
1. Clone the repository:
   ```bash
   git clone https://github.com/iliasreg/wol.git
   cd wol
   ```
2. Compile the project:
   ```bash
   make
   ```

## Testing with a Virtual Machine
- Set up a VM (e.g., VirtualBox or VMware).
- Enable WOL in the VM's network adapter settings.
- Shut down or suspend the VM.
- Run the program on the host machine with the VM's MAC address.
- Verify the VM wakes up.


## Project Structure

 ```bash  
  wol-cpp/
  ├── wol/            # MAC parsing and magic packet creation
  │   ├── wol.cpp
  │   └── wol.hpp
  ├── socket/         # UDP broadcast functionality
  │   ├── socket.cpp
  │   └── socket.hpp
  ├── main.cpp        # Program entry point
  ├── Makefile        # Build automation
  └── README.md       # This file
   ```

## Dependencies
C++11 or later.
Linux/Unix-based system (for socket programming).

## License
This project is licensed under the **MIT** License. See LICENSE for details.
