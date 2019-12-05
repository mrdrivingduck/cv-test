# cv-test (temp)

cv-test (temp)

Created by : Mr Dk.

2019 / 12 / 05 @Nanjing

---

## How to use _OpenCV_ with _Visual Studio 2019_ on Windows 10

[Download](https://github.com/opencv/opencv/releases) _OpenCV_ release

Add `build/x64/vc15/bin` into environment variable `PATH`

Copy the file `opencv_worldxxx.dll` and `opencv_worldxxxd.dll` into `C:/Windows/System32` 

( __Or__ copy to `C:/Windows/SysWOW64` for 32-bit 😵 )

* `xxx` means version, like `opencv_world412.dll` and `opencv_world412d.dll`
* One for __debug__, one for __release__

Get into _Visual Studio 2019_

Create a project and enter the __property__ page

* Set the platform to __x64__
* In __VC++ Directories__
    * Include Directories - `build/include`
    * Library Directories - `build/x64/vc15/lib`
* In __Linker/Input__
    * Additional Dependencies - `opencv_worldxxxd.lib` and `opencv_worldxxx.lib`

---

## About

It is the project of the course _Matrix Theory_ of NUAA, Fall, 2019

Compress an image using __Singular Value Decomposition, SVD__

---

## Reference

https://en.wikipedia.org/wiki/Singular_value_decomposition

https://blog.csdn.net/kiripeng/article/details/89099675

https://www.cnblogs.com/didea/p/6044321.html

---

