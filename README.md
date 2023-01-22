# libtpool

A thread pool library for C. Easy to use as well. For instructions on basic
usage, visit the [examples](/examples/example.c).

For installation, please go [here](#installation). For documentation, please go
[here](https://libtpool-doxygen.netlify.app/).

## Installation

Make sure to have [make](https://www.gnu.org/software/make/),
[gcc](https://www.gnu.org/software/gcc/) and [git](https://git-scm.com/)
installed.

Then, make sure all the following dependencies are installed:
- [libqueue](https://github.com/resyfer/libqueue)
- [libcol](https://github.com/resyfer/libcol)

Then install the library:

```bash
git clone https://github.com/resyfer/libtpool.git
cd libtpool
make install
cd ..
rm -rf libtpool
```

Provide the password when prompted.

## Development

Update makefile variable `MODE` to be:

```sh
MODE:=dev
```

and then:

```sh
make run # to run the example
# or
make test # to run the tests
```