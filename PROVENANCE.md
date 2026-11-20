# Provenance

This project only accepts work that anyone could reproduce from a legally owned copy of the game and lawful tools.
Every pull request carries the provenance checklist from `.github/pull_request_template.md`, and Steward will not
merge a PR until every box is ticked.

## What is not a source

**Do not open, read, search, copy from or paraphrase any of these while working on this project.** That includes
class, function and variable names, file names, struct layouts and comments taken from them. A PR that was
influenced by one is rejected and its functions are re-done from scratch by someone else.

- **Leaked source code or symbols** of the game, or any other leaked or confidential Sega or Smilebit material.
- **Debug builds** of the game.
- **Prototypes** and other pre-release or internal builds.
- **Linker maps**, symbol files and debug information from any build.
- **The Xbox Development Kit**: its headers, libraries, samples and documentation. It is confidential Microsoft
  material. Owning a copy does not make it a source.
- **The KeybadeBlox JSRF-Decompilation repository.** By the owner's ruling this project is a clean start: do not
  open that repository, and do not copy names, types or code from it. Nothing from here is sent to it either.
  See "Prior work" in the README.

## What is a source

- **Your own retail disc**: the game you legally own, dumped yourself.
- **Names that come from the binary itself**: its strings, and what the code unmistakably does.
- **Publicly documented Win32 and Direct3D 8 API names and signatures**, from Microsoft's public documentation.
- **Open-source tools**: the `xbx` tools this repo pins, Wine, your own scripts.
- Your own judgement.

Names for the C runtime, the Xbox SDK libraries and the kernel imports enter the repository only through
`config/symbols.csv`, which maintainers fill from the sources above.

The compiler is not a source of names either. Each contributor runs their own licensed copy of Visual C++ 7.0;
nothing from it is committed.

## What the boxes mean

- **Own work.** You wrote it, or an AI agent you run wrote it under your direction, or you have permission from
  whoever did.
- **No leaked material.** Nothing from leaked or confidential Sega or Smilebit source code, debug symbols, linker
  maps, debug or prototype builds or internal documents; nothing from the Xbox Development Kit; nothing from the
  KeybadeBlox repository.
- **No game data.** No disc images or executable bytes, no game assets, no proprietary Microsoft Xbox SDK files.
  The repo only holds our C++, configuration and a few scripts; the game is read from your own disc when a unit
  is checked.
- **Lawful decompilation.** You worked from a copy of the game you legally own, with tools you are legally allowed
  to use (the open-source `xbx` tools, Wine, your own licensed compiler, your own scripts).
- **Sources listed.** Anything you relied on beyond the repo's own tools is named in the PR.

## Humans and AI agents

Tick exactly one "who made this" box.

AI agents may prepare and submit PRs. An agent has to tick the boxes itself **on every PR**, after checking each
statement against that PR's actual changes, and must also tick the agent acknowledgement. The acknowledgement
says that the human who runs the agent is responsible for the contribution. An earlier PR's ticks never carry
over.

If you are unsure about any box, leave it unticked and ask in the PR.
