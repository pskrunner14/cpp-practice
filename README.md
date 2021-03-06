# C++ Algorithms & Data Structures

[![C++ Standards](https://github.com/pskrunner14/cpp-algs/blob/master/extra/cpp_status.svg)](https://github.com/pskrunner14/cpp-algs/wiki) [![Under Development](https://github.com/pskrunner14/cpp-algs/blob/master/extra/under-development.svg)](https://github.com/pskrunner14/cpp-algs/wiki) [![Build Status](https://travis-ci.org/pskrunner14/cpp-algs.svg?branch=master)](https://travis-ci.org/pskrunner14/cpp-algs) [![Codacy Badge](https://api.codacy.com/project/badge/Grade/daf097a7fe524ddcaeb8dc005755cdb4)](https://www.codacy.com/app/pskrunner14/cpp-practice?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=pskrunner14/cpp-practice&amp;utm_campaign=Badge_Grade)

These are C++ implementations of various algorithms and data structures optimized and modularized for peak performance and extensibility. This project includes support for C++11 std and can currently only be built on Linux.

**[See Wiki for more details](https://github.com/pskrunner14/cpp-algs/wiki)**

## Install

You need to have any recent C++ compiler with C++11 support installed on your system along with a few pre-requisites:

* [Boost](https://www.boost.org/) (libboost)
* [CMAKE](https://cmake.org/)

The following commands will get you through the installation of the dependencies:

```bash
sudo apt-get install libboost-all-dev
sudo add-apt-repository ppa:george-edison55/cmake-3.x
sudo apt-get update
sudo apt-get install cmake
```

Once you're done with the above installation, you can build the project using CMAKE:

```bash
git clone https://github.com/pskrunner14/cpp-algs.git
cd cpp-algs/
./install.sh
```

## References

* [Introduction to Algorithms](https://mitpress.mit.edu/books/introduction-algorithms-third-edition)
* [Algs4 Algorithms Library](https://algs4.cs.princeton.edu/home/)
* [Stanford CS Education Library](http://cslibrary.stanford.edu/)

## License

This project is distributed under the [MIT License](https://opensource.org/licenses/MIT), see [LICENSE](./LICENSE) for more information.
