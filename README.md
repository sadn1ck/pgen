# pgen - simple CLI password generator written in C++

 
<a href="./LICENSE">
<img src="https://img.shields.io/github/license/sadn1ck/pgen?style=flat-square">
</a>

## Requirements: 
- gcc
- make
- ~/.local/bin in your PATH

## Steps:
```bash
$ sudo apt-get install gcc make

$ git clone https://github.com/sadn1ck/pgen

$ cd pgen

$ mkdir -p ~/.local/bin/

$ vim ~/.bashrc

# Add this line to your bashrc or zshrc
# export PATH=/home/YOURUSERNAME/.local/bin:$PATH
# Change YOURUSERNAME with your user

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
- [x] Separation into proper header files

