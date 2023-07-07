# LeetCode Book

这是我个人的刷题笔记。我为何想要做一个这样的东西呢，是因为我对刷题这个事情感到了很大的厌恶。真的有必要刷那么多题吗？我觉得是完全没必要的。反而，去总结一个问题是如何解决的才是最关键的。我希望自己能够总结出一些关键性的东西，也对你或多或少也有所帮助。我看过许多解题方法，很多都没有从正常人的思维出发解决问题。

我或多或少地想解决这个问题，刷题不是目的而是手段。

## Latex模板

本文采用的Latex模板来源于[kaobook](https://github.com/fmarotta/kaobook)。

## License

Shield: [![CC BY-NC-SA 4.0][cc-by-nc-sa-shield]][cc-by-nc-sa]

[Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License][cc-by-nc-sa].

[![CC BY-NC-SA 4.0][cc-by-nc-sa-image]][cc-by-nc-sa]

[cc-by-nc-sa]: http://creativecommons.org/licenses/by-nc-sa/4.0/
[cc-by-nc-sa-image]: https://licensebuttons.net/l/by-nc-sa/4.0/88x31.png
[cc-by-nc-sa-shield]: https://img.shields.io/badge/License-CC%20BY--NC--SA%204.0-lightgrey.svg

## Build

This project uses `CMake` for building the latex files. And you should use `xelatex` to build.
So at first, you need to setup the environment of the `latex` and `xelatex`. If you don't want
to build for yourself, you could download the PDF at the RELEASE page.

```sh
mkdir build && cd build && cmake .. && cmake --build .
```

And in `build` directory you can find `main.pdf`.

## Development setup

If you want to setup the development environment and change anything you want. I recommend you
to use VsCode as the editor. You should download extensions
[LaTex Workshop](https://marketplace.visualstudio.com/items?itemName=James-Yu.latex-workshop).
After you install the extensions, you can easily do whatever you want. And of course, you can
build any sections. However, with `CMake`, you can just only build the whole project.

When you use VsCode Latex Workshop to build the files, there will be many temp files. Although
you can use Latex Workshop to clean the files. However, it is tedious. So I write a simple
shell script to clean the files. You can use the following command to make your life easier.

```sh
bash clean.sh
```
