# Project Generic CList
This project was made as an exercise for students to use pointers and memory softly within C. You need to implements a
Generic List in C, in other terms, a list that can contains anything without having to code an implementation for each
type.

This project can be later used for your L2 / L3 C projects.

---

## How to Setup the Project

To setup the project you need:
- fork the repository in Github
    - uncheck the `Copy the master branch only`, you want all branches of the repository.
- get the link web URL (`<> Code`/`HTTPS`)
- clone the project within your computer using the terminal
    - $`git clone [url here]`
- once cloned, you will have a `CCourse` folder, open it
- pull the project (update it) through the `git pull` command
- list all project branches using: `git branch -a`
    - the names of branches you can use for this project are:
        - `ProjectGenericCList` : the exercise.
        - `ProjectGenericCList_correction` : the correction of the exercise.
- change the branch using: `git checkout [nameofthebranch]`
    - ex : `git checkout ProjectGenericCList`


### Compile the Project:
- Using CMake:
    - build the project using cmake and the CMakeLists.txt

- Using GCC:
    - Compile using : `gcc -o output main.c clist.c`
    - Execute the output: `./output`


---

## Todo:
The file `clist.h` lists you all functions that you need to implements for this project to work.

The file `clist.c` allows you to write the functions bodies / implementations.

The file `main.c` provides a testing function behaviour that can be used to test each and every step, by commenting out
each region.
