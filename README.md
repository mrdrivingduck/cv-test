# svd-image-compression

📷 Image compression by Singular Value Decomposition.

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

## License

```
MIT License

Copyright (c) 2019 Mr Dk.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

```

---

