# ProjectMaker
A CLI tool to help you setup and manage C and C++ project in a easy and efficient way !

## Installation
Clone the repository into a folder of your choice then execute `make install` in that directory.
You may now delete the cloned repository and Project Manager will be installed on your computer.

> Note : You may want to keep the `makefile` if you wish to unistall Project Manager. Alternatively it can be redownloaded at a later time

## Uninstall
To remove execute `make remove` or manually remove pjm in `~/bin`

## Usage

There are 4 task that Project Manager make easier, one of which is C++ only.

### Creating new Project

To create a new project with ProjectManager you must provide the following arguments :
- `new` 
- `project`
- The project programming language
> See [Supported Languages](#supported-languages)

###### Example :
```
$ pjm new project c
``` 

This command will create the hierarchy of a project in **the current directory** following this layout :

```
.
├── headers
├── src
├── resources
├── makefile
├── .pjm.info
├── .gitignore 
├── test
└── todo
```

> Note : You will need to create your own `main` file at `./`.

> Note : the makefile is made to work with the `src` & `header` folder along side a `main.c` (or `.cpp`) in `./`.

> Note : `todo`, `test`, `.pjm.info`, the `.o`'s and executable files resulting from the compilation (respectivly stored in `obj/` and `bin/`, both created by `makefile` when compiling) are all **ignored** by `.gitignore` by default.
### Creating directories
To automaticaly create sub-dir in `headers` and `src` you must provide the following arguments
- `new`
- `dir`
- directory name
> Important : Make sur you execute the command at the root of your project
###### Example :
```bash
$ pjm new dir math
```

> Note : The `makefile` will automatically create the corresponding directories in `obj` before compiling
### Creating headers

To create a new header you must provide the following arguments :
- `new`
- `header` or `headeronly` if you do not wish a associated source file
- header name

> Important : Make sure you execute the command at the root of your project

###### Example :
```
$ pjm new header functions
```
This command will add two files to our current project :

```
.
├── headers
│   └── functions.h
├── src
│    └── functions.c
├── resources
├── makefile
├── .pjm.info
├── .gitignore 
├── test
└── todo
```

> Note : For header with space in name you may surround the name with `"`.

> Note : The newly created header and source files come with the necessary code to make them work.

> Note : All **non-alphanumerical** characters will be turned to `_` in the header file's text

### Creating class

To create a class the project language must be C++.
Project Manager also generate template class inside the generated files making `class` more useful than `header` when working with C++

Class creation is the same as header creation with the `class` keyword replacing the `header` keyword

###### Example :

`pjm new class entity`

> Note : Everything from header creation also applies to class creation
### Creating main

To create the main file for your program use this command :

```
pjm new main
```

This command will create `main.c / .cpp` in your project directory

## Supported Languages
 
ProjectManager support the creation and management of **C** and **C++** projects only.
