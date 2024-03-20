This is a plugin for Qmmp (1.6.0 or greater) visual.

![Image](https://github.com/TTK-qmmp/qmmp-sonique/blob/master/image/1.png?raw=true)

The following packages are required, including development headers,
which some vendors split into separate packages:

- qmmp (1.x or 2.x)
- qt (5 for qmmp 1.x and 6 for qmmp 2.x)

To build, run Qt's qmake:

If you are building for qmmp 1.x, run: <br/>
`$ qmake-qt5` <br/>
And if you are building for qmmp 2.x, run: <br/>
`$ qmake-qt6` <br/>

Then build with make: <br/>
`$ make`

To install: <br/>
`$ make install`

This installs the plugin into Qmmp's visual plugin directory.  To install
to a staging area, such as for packaging: <br/>
`$ make install INSTALL_ROOT=/path/to/staging`
