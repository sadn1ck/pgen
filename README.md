# pgen - simple password CLI generator written in C++

 
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)


## Requirements: 
- gcc
- make
- existing ~/.local/bin in your PATH

## Steps:
```bash
$ sudo apt-get install gcc make

$ git clone https://github.com/sadn1ck/pgen

$ cd pgen

# Add this line to your bashrc or zshrc
# Change YOURUSERNAME with your user
# # export PATH=/home/YOURUSERNAME/.local/bin:$PATH
$ vim ~/.bashrc

$ mkdir -p ~/.local/bin/

# To build the binary from the source files
$ make build

# To copy built binary to the above directory so that it is available everywhere
$ make install

# To clean files and build while developing
$ make # or make all
```

## WIP
- [ ] Tests
- [ ] Docs 
- [ ] Separation into proper header files

