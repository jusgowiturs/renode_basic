# STM32 Baremetal Development using Renode

This project demonstrates how to develop and simulate STM32F407 baremetal applications using Renode. It provides a minimal setup including startup code, linker script, CMSIS headers, and a Renode simulation script.

## Prerequisites

### Install the following tools:

- Renode
  - Renode is a virtual development platform that allows you to simulate embedded systems (like STM32) without physical hardware.
- CMake
- GNU Arm Embedded Toolchain

### Toolchain Installation
####  Linux (Ubuntu/Debian)
```bash
sudo apt update
sudo apt install gcc-arm-none-eabi
arm-none-eabi-gcc --version
```
#### Arch Linux
```bash
sudo pacman -S arm-none-eabi-gcc
```
#### macOS
```bash
brew install arm-none-eabi-gcc
```
#### Windows (Chocolatey)
```bash
choco install gcc-arm-embedded
```
#### Project Structure
```.
├── build/                 # Build output (ELF file)
│   └── lab1.elf
├── src/                   # Application source
│   ├── main.c             # User application
│   ├── startup.c          # Reset handler & vector table
│   ├── stm32f407xx.h      # MCU register definitions
│   └── CMSIS/Include/     # ARM core headers
├── linker.ld              # Memory layout
├── CMakeLists.txt         # Build configuration
├── demo_renode.resc       # Renode simulation script
└── renode_board/          # Additional platform 
files
```
#### Code Architecture
| Layer       | File            | Purpose              |
| ----------- | --------------- | -------------------- |
| Application | `main.c`        | User logic           |
| Startup     | `startup.c`     | Boot + Reset Handler |
| MCU         | `stm32f407xx.h` | Peripheral registers |
| Core        | CMSIS           | Cortex-M4 support    |
| Memory      | `linker.ld`     | Flash/RAM layout     |
| Build       | CMake           | Compilation          |
| Simulation  | Renode          | Virtual execution    |

### 
Build Instructions

#### Generate build system:
```bash
cmake -B ./build ./
```
#### Compile project:
```bash
cd build
make lab1
```
#### Output:
```bash
build/lab1.elf
```
### Running in Renode

- Start Renode:
- renode --console
#### Load simulation script:
```bash
i @demo_renode.resc
```
### Useful Analysis Commands
#### Disassembly
```bash
arm-none-eabi-objdump -D build/lab1.elf

# Hex dump
xxd build/lab1.elf | less

# Memory usage
arm-none-eabi-size build/lab1.elf
```
### Execution Flow
```
Power ON
   ↓
Vector Table (startup.c)
   ↓
Reset_Handler()
   ↓
.data → RAM copy
.bss → cleared
   ↓
main()
```