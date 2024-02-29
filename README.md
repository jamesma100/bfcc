# bfint
Simple interpreter for [brainfuck](https://en.wikipedia.org/wiki/Brainfuck)

## Usage
To set up, run:
```
$ mkdir bin/ && make compile
```
This will create the main executable under `./bin/compile`.
Then, interpret your code with:
```
$ ./bin/compile your_code.bf
```

## Examples
There are some examples under `input/` you can try out (some stolen from wikipedia).

### Add two numbers
Here's a program that adds 6 to 3 and outputs the result:
```
$ cat input/add_nums.bf
+++++++++++++++++++++++++++++++++++++++++++++++++++>++++++<[->+<]>.
```
Breakdown: we do 51 increments to get to ASCII '3', then 6 increments in the next slot to get to 6 (decimal). So our memory looks like:
```
data     51 6
location 0  1
```
Then we enter a loop, continuously decrementing at location 0 and incrementing at location 1 until location 0 is 0 (char `\0`), at which point location 1 should have '9'.

```
$ ./bin/compile ./input/add_nums.bf
9
```

### Print "hello world"
Another program that prints "hello world" - this one's a bit harder to trace through.
```
$ ./bin/compile input/hello_world.bf
H
e
l
l
o

W
o
r
l
d
!
```

### User input
Prompt user for 5 input characters and echos it back to you:
```
$ ./bin/compile input/user_in.bf
a
b
c
d
e

a
b
c
d
e
```
