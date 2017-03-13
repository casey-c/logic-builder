### About
Logic-builder is a tool written in Qt-C++ designed for the production of well formed formulas. By taking advantage of [Jan Łukasiewicz's polish notation](https://en.wikipedia.org/wiki/Polish_notation), logic-builder removes the need for parentheses management. WFF's produced with this application can be exported in the following ways:
 * as a plaintext with logical symbols
 * a LaTeX expression 
 * the produced polish notation in LISP 
 * a plaintext tree diagram
 
with several more export types planned. Logic-builder can export these types to the clipboard or to a file. Planned features include integration with the Fitch software file format, but that's a long term goal.

### Release
Logic-builder is currently under development and does not have a release executable at this time. 

### License
Logic-builder is using the open-sourced licensed version of Qt-C++. Qt uses the GNU LGPL license, while any produced code for this particular app is under the MIT license. Feel free to take any code you wish to implement in your own projects.

### Contribution
If you'd like to help out, send me a message and I can explain what I've planned out so far so that you can dive in and I can add you to the repo. If you'd like to request an export format, feel free to make an issue here on GitHub, or write up the code and make a pull request.
