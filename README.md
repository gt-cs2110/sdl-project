Prototype for Basic SDL Project
===============================

This is a simple SDL "hello world". I wonder if we can adapt this into a CS
2110 project — in particular Project 4, which is after they learn about C
pointers and arrays, but before they learn about `malloc()` etc.

* `game.c`: The student's game code. They are editing the videobuffer directly
* `graphics.c`/`graphics.h`: A wrapper around SDL to avoid overwhelming
  students with SDL

This example just cycles through a silly animation when you press space. Escape
or Q exits.
