# corewar

The whole task is in [this pdf](https://github.com/franckevicz/corewar/blob/master/corewar.en.pdf). It's not described very clear as long as it's a part of the task.
Here is just quick explanation.

[Corewar](https://en.wikipedia.org/wiki/Core_War) is a very peculiar game. It’s about bringing “players” together around a “virtual machine”, which will load some “champions” who will fight against one an- other with the support of “processes”, with the objective being for these champions to stay “alive”.

The processes are executed sequentially within the same virtual machine and mem- ory space. They can therefore, among other things, write and rewrite on top of each others so to corrupt one another, force the others to execute instructions that can damage them, try to rewrite on the go the coding equivalent of a Côtes du Rhône 1982 (that is one delicious French wine!), etc...

The game ends when all the processes are dead. The winner is the last player reported to be “alive”.

This project can be broken down into three distinctive parts:

+ **The assembler**: this is the program that will compile your champions and trans- late them from the language you will write them in (assembly language) into “Byte- code”.Bytecode is a machine code, which will be directly interpreted by the virtual machine.

+ **The virtual machine**: It’s the “arena” in which your champions will be executed. It offers various functions, all of which will be useful for the battle of the champions. Obviously, the virtual machine should allow for numerous simultaneous processes; we are asking you for a gladiator fight, not a one-man show simulator.

Here is the list of commands:
```
• lfork: means long-fork, to be able to fork abut straw from a distance of 15 meters, exactly like with its opcode. Same as a fork without modulo in the address.

• sti: Opcode 11. Take a registry, and two indexes (potentially registries) add the two indexes, and use this result as an address where the value of the first parameter will be copied.

• fork: there is no argument’s coding byte, take an index, opcode 0x0c. Create a new process that will inherit the different states of its father, except its PC, which will be put at (PC + (1st parameter % IDX_MOD)).

• lld: Means long-load, so it’s opcode is obviously 13. It the same as ld, but without % IDX_MOD. Modify the carry.

• ld: Take a random argument and a registry. Load the value of the first argument in the registry. Its opcode is 10 in binary and it will change the carry.

• add: Opcode 4. Take three registries, add the first two, and place the result in the third, right before modifying the carry.

• zjmp: there’s never been, isn’t and will never be an argument’s coding byte behind this operation where the opcode is 9. It will take an index and jump to this address if the carry is 1.

• sub: Same as add, but with the opcode est 0b101, and uses a substraction.

• ldi: ldi, ldi, as per the name, does not imply to go swimming in chestnut cream, even if its code is 0x0a. Instead, it will use 2 indexes and 1 registry, adding the first two, treating that like an address, reading a value of a registry’s size and putting it on the third.

• or: This operation is an bit-to-bit OR, in the same spirit and principle of and, its opcode is obviously 7.

• st: take a registry and a registry or an indirect and store the value of the registry toward a second argument. Its opcode is 0x03. For example, st r1, 42 store the value of r1 at the address (PC + (42 % IDX_MOD))

• aff: The opcode is 10 in the hexadecimal. There is an argument’s coding byte, even if it’s a bit silly because there is only 1 argument that is a registry, which is a registry, and its content is interpreted by the character’s ASCII value to display on the standard output. The code is modulo 256.

• live: The instruction that allows a process to stay alive. It can also record that the player whose number is the argument is indeed alive. No argument’s coding byte, opcode 0x01. Oh and its only argument is on 4 bytes.

• xor: Acts like and with an exclusive OR. As you will have guessed, its opcode in octal is 10.

• lldi: Opcode 0x0e. Same as ldi, but does not apply any modulo to the addresses. It will however, modify the carry.

• and: Apply an & (bit-to-bit AND) over the first two arguments and store the result in a registry, which is the third argument. Opcode 0x06. Modifies the carry.
```

The champion must be written in this "assembly" code in file with `.s` extention. It will look smth like this 
```
.name "stayin' alive"
.comment "Ha, Ha, Ha, stayiiiiin' aliiiiiiiiiive"
	
sti	r1,%:live,%1
sti	r1,%:live2,%1
ld	%1,r3
ld	%33,r6
forks:
add	r2,r3,r2		
xor	r2,%15,r4
live2:
	live 	%4
zjmp	%:endwhile
fork	%:forks
ld	%0,r4
zjmp	%:forks

endwhile:
  ld	%0,r4

live:
  live %4
zjmp %:live
```
And after passing throught ./asm `./asm beegees.s` we'll have our champion with extention `.cor` that is ready to fight

Now we can pass it to ./corewar `./corewar -v beegees.cor` -v is for visual representation(nCurses).

```
make
./asm champs/Gagnant.s
./corewar champs/Gagnant.cor -v
```
On some systems asm works strange and can't compile the champs :( In that case you can use already compiled one.
```
./corewar champs/Gagnant_compiled.cor -v
```
In visualizer speed can be adjusted by keys `+` and `-` on numpad.

Usage:

```
Usage: ./core_war_src [-v] [-a] [-s] [-l] [-dump nbr_cycles] [[-n number] champion1.cor] ...
-v     : Turns on visualizer
-dump  : Dumps memory after nbr_cycles, then reads another nbr_cycles from standard input
-n     : Sets the number of the next player
-a     : Prints output from "aff"
-s     : Turns on sound effect
-l     : Reports executions of command live
```

Have fun!
