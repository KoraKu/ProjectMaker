# ProjectMaker
A CLI tool to help you setup and manage C and C++ project in a easy and efficient way !

## Usage
### Creating new Project

To create a new project with ProjectManager you must provide the following arguments :
- `new` 
- `project`
- The project programming language
> See [Supported Languages](#supported-languages)

###### Example :
```
pjm new project c
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

> Note : `todo`, `test`, `.pjm.info`, the `.o`'s and executable files resulting from the comilation (respectivly stored in `obj/` and `bin/`, both created by `makefile` when compiling) are all **ignored** by `.gitignore` by default.

### Creating headers

To create a new header you must provide the following arguments :
- `new`
- `header` or `headeronly` if you do not wish a associated source file
- header name

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

## Supported Languages
 
ProjectManager support the creation and management of **C** and **C++** projects only.