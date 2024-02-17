# MKCD

MKCD is a tiny little command line utility that creates a new directory and then enters it with a single command.

## Usage

```bash
mkcd <directory name>
```

## Installation

```bash
git clone https://github.com/calebstein1/mkcd
cd mkcd
make
sudo make install
```

Then you'll have to add an alias to your .bashrc/.zshrc or wherever you keep your aliases:

```bash
alias mkcd=exec mkcd
```

The reason that this alias is needed is because, since MKCD has no direct access to its parent shell, it achieves the directory change by replacing itself with a new shell process in the newly created directory.
The alias ensures that `mkcd` is always called by `exec`, which replaces the current running shell process with `mkcd`, thereby ensuring that a single `exit` is enough to close the currently running terminal rather than having to exit out of a shell for each `mkcd` call.
