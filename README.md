```
spaghetti - Makes your code uncompilable by replacing letters with unicode symbols that look the same!

Usage example:
spaghetti [(-h|--help)] [(-V|--version)] [(-v|--verbose)] [(-i|--in) file] [(-o|--out) file] [(-p|--print)] [(-e|--spaghettify)] [(-d|--despaghettify)]

Options:
-h or --help: Displays this information.
-V or --version: Displays the current version number.
-i or --in: Input file instead of stdin.
-o or --out: Output file instead of stdout.
-p or --print: Show how characters are converted.
-e or --spaghettify: Do spaghettification (default).
-d or --despaghettify: Undo spaghettification.

; (3B): ; (37E)
a (61): а (430)
A (41): А (410)
B (42): В (412)
c (63): ϲ (3F2)
C (43): С (421)
e (65): е (435)
E (45): Е (415)
g (67): ɡ (261)
H (48): Н (41D)
i (69): і (456)
I (49): Ι (399)
j (6A): ϳ (3F3)
K (4B): К (41A)
M (4D): М (41C)
N (4E): Ν (39D)
o (6F): о (43E)
O (4F): О (41E)
p (70): р (440)
P (50): Р (420)
s (73): ѕ (455)
S (53): Ѕ (405)
T (54): Т (422)
x (78): х (445)
X (58): Х (425)
y (79): у (443)
Y (59): Υ (3A5)
Z (5A): Ζ (396)
ë (EB): ё (451)
Ë (CB): Ё (401)
ï (EF): ї (457)
Ï (CF): Ї (407)
ö (F6): ӧ (4E7)
Ö (D6): Ӧ (4E6)
```

Installation:

```
make
sudo make install
```

Example code:

```
# Spaghettify from 'main.c' into 'spag.c'
cat main.c | spaghetti > spag.c

# Same as above
spaghetti -i main.c -o spag.c

# Undo spaghettification from 'spag.c'
cat spag.c | spaghetti -d > main2.c

# Same as above
spaghetti -d -i spag.c -o main2.c
```

Warning #1: The output file is either created or cleared if it exists. Previous contents are lost!

Warning #2: Do not use a file as both input and output file. The file contents will be deleted before the file can be spaghettified.
