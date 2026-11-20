# include/game

Shared declarations for the game's own code. Maintainer-only (a protected path): a unit is judged against the
headers already on `main`, so a pull request cannot bring its own.

A unit declares the types and prototypes it needs itself. A declaration moves here when many units need the
same one and must agree on it, because one address has one declaration across the whole tree (`xbx names`
prints the one in use). Ask for an addition in your pull request's notes.
