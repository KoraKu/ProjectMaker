# ProjectMaker
A CLI tool to help you setup and manage C and C++ project in a easy and efficient way !

## Usage
#### Creating new Project

To create a new project with ProjectManager you must provide the following arguments :
- `new` 
- The project programming language
> See [Supported Languages](#supported-languages)
- `project`

###### Example :
`pjm new c project` 

This command will create the hierarchy of a project in **the current directory** following this layout :

```
.
├── src
├── headers
├── resources
├── makefile
├── .pjm.info
├── .gitignore 
├── test
└── todo
```

> Note : You will need to create your own `main` file at `./`.

> Note : the makefile is made to work with the `src` & `header` folder along side a `main.c` (or `.cpp`) in `./`.

> Note : `todo`, `test`, the `.o`'s and executable files resulting from the comilation (respectivly stored in `obj/` and `bin/`, both created by `makefile` when compiling) are all **ignored** by `.gitignore` by default.

## Supported Languages
 
ProjectManager support the creation and management of **C** and **C++** projects only.