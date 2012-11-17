# C

Pick up from where you've left.

## Requirements

* Unix-y OS
* [Ruby] and `ruby` in `$PATH`

## Installtion

It's just a single executable so a quick symlink will do:

``` bash
git clone http://github.com/5long/c
ln -s `pwd`/c/c /usr/local/bin/c
```

## Usage

Use `c <args>` to record a command and just `c` to replay it.

## Example

``` bash
cd books
zathura Awesome_But_Pretty_Long_Book.pdf
# Record it:
c zathura Awesome_But_Pretty_Long_Book.pdf
# And tomorrow when you feel like reading book again:
c
```

## Features

You can checkout `~/.continuerc` to see the recorded command.

When recording a command,
`c` will try to resolve all arguments to absolute paths
before saving the arguments in `~/.continuerc`.
So you don't have to `cd` back and `c` replaying still works.

## Bugs

There can't be any bugs.
You must have used it the wrong way.

[ruby]: http://ruby-lang.org/

## LICENSE

[WTFPL](http://sam.zoy.org/wtfpl/)
