# Duvet
CLI spreadsheet program (very jank)

Duvet is a CLI program for managing a 20x20 spreadsheet

# Known Issues
I haven't written proper error handling yet, so often if you do something wrong it will give the wrong error, it's usually fine to just ignore error messages.
because of how the cell picker is written, it is possible to access cells in strange ways (for example acessing a cell that *does* exist by going to row 21 column 18 (this cell should not exist)

There are also very many ways to segfault, try your best not to :)

Also this program has a massive memory leak everytime it runs, your operating system should clean it up though.
