# B-CSDB-Example

*Very* simple examples of exploitable C code with the corresponding exploit code and patch.

Additionally the example is also ported to rust and zig.

The code was tested under Linux and may not work under different operating systems.

## C
- `gcc -fno-stack-protector -no-pie -o buffer_overflow buffer_overflow.c`

## Rust

## Zig

## Attack

The Python library pwntools is used for the attack.
1. Create a virtual environment in the attack folder `python3 -m venv ./.venv`
2. Enter the virtual environment (while located in /attack) `source .venv/bin/activate`
3. Install the requirements `pip install -r requirements.txt`
