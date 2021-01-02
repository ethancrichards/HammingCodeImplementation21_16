# HammingCodeImplementation21_16
This function takes a 16 bit ascii input and converts it into a hamming coded word that is usable for single bit error transportation.

The codeword will be built using a (21, 16) Hamming code.  That is, this code takes 16 bits (two bytes) of information
and adds in five more parity bits to give a 21-bit codeword.  When transmitted, this code word will allow a user to
determine if the information transmitted arrived correctly—or not—as long as no more than one bit gets corrupted.
Thus it is called a single bit-error correcting code. The non-parity (information) bits will simply be the values they
were in the original 16 bits, only shifted to their new position.

ASSUMPTIONS: The user will type in EXIT as asked. The user will only input two
characters, or the first two characters will get taken when wanting to test
two characters.
