## Jaspers CTF

1. if you cant run "nc -e", install nc.traditional
2. install pwndbg
```
git clone https://github.com/pwndbg/pwndbg
cd pwndbg
./setup.sh


Launch the program using the following command
gdb -ex 'set follow-fork-mode child' -ex 'catch fork' -ex 'catch exec' -ex r  -ex 'b main' -ex c --args nc -lp 4444 -e a.out

disassemble: 
objdump -sdM intel a.out > dis.asm

GDB Cheat Sheet

b main : break at function main
b *0x1234 : break at addr 0x1234

fin : continue till current function returns

si : step single instruction
n : next C statement

x/5i *0x1234  :  examine 5 instructions starting at addr 0x1234
x/5bx *0x1234 :  examine 5 bytes formatted as hex at addr 0x1234
p/x &buf : print addr of buf, formatted as hex
```
