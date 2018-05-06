# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

It's a MADE UP word that means a type of lung disease.

## According to its man page, what does `getrusage` do?

gets resource usage

## Per that same man page, how many members are in a variable of type `struct rusage`?

16

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

calculuate points to the struct values via pointer contents, so if you passed values you'd need to pass twice as many

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

Sure. I'll convince you, README file no one will actually read.
First it creates a word variable that only holds the actual alpha characters and apostrophe's. Other characters are just left out in the void. It then starts a timer, sends it to the function that will determine if its mispelled. If it is, its added to the list of mispelled words.


## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

fgetc pulls from the stream one character at a time. fscanf could go bananas if it received a word that was longer than expected

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

Once those variables are set, they shouldn't be changed. If in calculation either was changed, it would no longer be a valid/fair calculation.

