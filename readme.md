


![App Screenshot](https://github.com/raunaksingh9800/RUNNER/blob/main/IMG/runner-github.png?raw=true)


# RUNNER

Developed a C++ command-line tool that compiles and runs system commands from a `commands.txt` file 📄, handling command parsing, file I/O, and system calls with error handling 🚨. Integrated features for command listing 📝, initialization ⚙️, and efficient data processing using maps and vectors 🔄.


## Build 🛠️

To Build this project run
```
git clone https://github.com/raunaksingh9800/RUNNER.git
```
#### macOS / Linux 🍏🐧
```bash
  g++ main.cpp -o main
```

#### Windows 🖥️
-  Install MinGW or MSYS2
- Once installed, open the Command Prompt or MSYS2 Shell and navigate to the directory where your C++ file is located.
``` bash
g++ main.cpp -o main
```

- Using Microsoft Visual Studio
``` bash
cl /EHsc main.cpp
```
## Run ▶️

MacOs / Linux 🍏🐧
 
```bash
./main
```
Windows  🖥️

```bash
./main.exe
```

## Syntax 💡

| Name | Symbol     | Description                | Example |
| :-------- | :------- | :------------------------- | :---------------- |
| Heading |  `->` | This is like naming your command | ``` -> Run the Program ``` |
| Argument |  `>` | This is your command's unique identifiers you will use this as an argument in your terminal | ``` > run ``` | 
| command |  `$` | You will Write your command to run in the console Here | ``` $ python main.py ``` | 
 

#### 

```
-> Run Test
> test
$ ./test

###Ignored Lines

-> Push To Prod
> push
$ cp ./build ./prod

Ignored Lines

-> Run Build
> build
$ g++ main.cpp -o main

```
## Argument List 🔧
 
### Initialise 🆕

```bash
  runner -init
```

| Name | Argument     | Description                |
| :-------- | :------- | :------------------------- |
| Initialise |  `-init` | Makes a file called `commands.txt` . Where you can add your commands|

 OUTPUT
```bash
Created commands.txt succesfully 🎉 

SYNTAX: 
-> <Heading> 
> <Argument> 
$ <Command> 

EXAMPLE: 
-> Your First Command 
> first 
$ echo hello 

Copy the Above 👆 Code into commands.txt 
Now Run : runner first 
```

### List 📃

```bash
  runner -list
```

| Name | Argument     | Description                |
| :-------- | :------- | :------------------------- |
| List |  `-list` | lists all the commands stored in `commands.txt`|

 OUTPUT
```bash
⏐⎯⎯⎯ Build the project
        ⏐⎯⎯ build

⏐⎯⎯⎯ clear the terminal
        ⏐⎯⎯ cls

⏐⎯⎯⎯ push to prod
        ⏐⎯⎯ push

⏐⎯⎯⎯ run the project
        ⏐⎯⎯ run

⏐⎯⎯⎯ run test
```


## Example 📘

#### File Structure

```
root/
│
├── main.py       
│
├── commands.txt             

```

#### main.py
```python
print("Hello World)
```
#### commands.txt
```python
-> Run the Program
> run
$ python main.py
```

#### Your input in Terminal / Console
```python
➜ runner run
```

#### Output 
```
RUNNER
▶ V 1.0 

Run the Program<Yello text>
Your Command:python main.py

Hello World
```
## Add To Path 🔗

- macOS : [YouTube Tutorial](https://youtu.be/2J58Pc2ZOAQ?si=zcRetl2UBtrtdrUo) 🍏
- Linux : [YouTube Tutorial](https://youtu.be/jIunQSnzs1Y?si=dhZDDfJejSVPGAP1) 🐧
- Windows : [YouTube Tutorial](https://youtu.be/pGRw1bgb1gU?si=EXLIyUoTYgxdq_tY) 🖥️
## Tech Stack

**C++ 11 with only Standard library**

