# XOR-Cipher
Simple implementation of XOR Cipher

The XOR operator is extremely common as a component in more complex ciphers. By itself, 
using a constant repeating key, a simple XOR cipher can trivially be broken using frequency analysis. 
If the content of any message can be guessed or otherwise known then the key can be revealed. 

Its primary merit is that it is simple to implement, and that the XOR operation is computationally inexpensive. A simple 
repeating XOR (i.e. using the same key for xor operation on the whole data) cipher is therefore sometimes 
used for hiding information in cases where no particular security is required.
