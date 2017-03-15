### About
Logic-builder is a tool written in Qt-C++ designed for the production of well formed formulae. By taking advantage of [Jan Łukasiewicz's polish notation](https://en.wikipedia.org/wiki/Polish_notation), logic-builder removes the need for parentheses management. WFF's produced with this application currently can be exported in the following ways:
 * as a plaintext with logical symbols
 * as a LaTeX expression 
 * as the produced polish notation in LISP format (no parentheses)
 
with several more export types planned. Logic-builder can export these types to the clipboard or to a file. Planned features include integration with the Fitch software file format, but that's a long term goal.

### Release
Logic-builder's most recent release is alpha-0.1. It has the following supported operators:
 * & produces a binary ∧
 * | produces a binary ∨
 * ~ produces a unary ¬
 * $ produces a binary →
 * % produces a binary ↔
 
Pressing the letters a-z will add a "nullary" statement of that particular letter. The top portion of the application is still under development, so support for managing multiple formulae is lacking.

Additionally, alpha-0.1 has support for autocopy, which will copy a formula to the clipboard automatically as soon as it is wellformed. The resulting string that is copied can be chosen from the Edit->Auto-Copy menu, or disabled completely if desired.
 
### Usage
After launching logic-builder, press any of the operator keybinds listed above to begin a WFF. The lower ouput section's plaintext text box is typically where you'd want to look while filling in the current formula. Underlines appear ( _ _ _ ) where required elements need to be created. They are filled in from left to right.

An example usage:
1. Type & to produce: ___ ∧ ___
2. Type P to fill in the first underlined section: P ∧ ___
3. Type Q to fill in the remaining underlined section: P ∧ Q

Once the formula is complete, the program will move the plaintext to the upper pane (which is still under development). If auto-copy is enabled, the desired output will be copied into the clipboard. At this point, you can also choose to copy the other formats by using the corresponding button on the bottom panel.

Starting a new WFF will clear the bottom output area (with no way to return back). This will be changed in future updates, so that the upper list of plaintext WFF's is actually manipulatable.

### Upcoming features
 * Better handling of multiple formulae (making the upper area functional)
 * Implementing the menu items: undo, redo, adding an about screen / tutorial, etc.
 * Support for quantifiers (∀ and ∃)
 * Support for custom functions (e.g. subset(x,y) )
 * Support for constants (lower case a, b, etc.)
 * Input for larger *ary operators. (number followed by a symbol can produce a different arity than default: e.g. 3& produces ___∧___∧___ ) - this behavior is already somewhat implemented, it just needs a decent control scheme
 * Cleanup of the UI - try and make it less hideous
 * Save / Export - more options to deal with multiple formulae: perhaps an output of all the WFF's created in their own .txt file
 * Fitch integration: make a *.prf file with premises / goals made with this app - so fitch problems can be created outside of fitch
 

### License
Logic-builder is using the open-sourced licensed version of Qt-C++. Qt uses the GNU LGPL license, while any produced code for this particular app is under the MIT license. Feel free to take any code you wish to implement in your own projects.

### Contribution
If you'd like to help out, send me a message and I can explain what I've planned out so far so that you can dive in and I can add you to the repo. If you'd like to request an export format, feel free to make an issue here on GitHub, code it up and make a pull request, or send me a message / email and I can take a look.
