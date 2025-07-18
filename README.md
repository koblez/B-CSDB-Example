# B-CSDB-Example

*Very* simple example of exploitable C code with the corresponding exploit code and patch.

Additional rust and zig example to see how input - output operations work in these languages.

The code was tested under Linux and may not work under different operating systems.

## C
- `gcc -fno-stack-protector -no-pie -o buffer_overflow buffer_overflow.c`
- `gcc -o user_after_free user_after_free.c`
- `gcc -Wall -Werror -o patched_user_after_free patched_user_after_free.c`
- `gcc -Wall -Werror -o patched_buffer_overflow patched_buffer_overflow.c`

## Rust

## Zig

- `zig build-exe src/main.zig` (in zig folder)

## Attack

The Python library pwntools is used for the attack.
1. Create a virtual environment in the attack folder `python3 -m venv ./.venv`
2. Enter the virtual environment (while located in /attack) `source .venv/bin/activate`
3. Install the requirements `pip install -r requirements.txt`
