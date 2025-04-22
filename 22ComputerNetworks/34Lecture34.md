# Presentation layer
roles of presentation layer -

## encoding transformation
If two communicating devices uses different character sets which are known to one but unknown to another, in that case there needs to be an encoding transformation that will happen to convert character set of request into character set understandable by responding device.

## encryption and decryption
- In RSA model, data is encrypted at sender's end using a public key.
- receiver will have two keys namely public and private key.
- The idea is, whatever is encrypted by the public key at sender's end can only be decrypted by the private key at receiver's end.
- We have SSL and TLS protocols which are based on this model.
- Do not save sensitive data with websites which do not have SSL/TLS certificates. As those websites do not encrypt data before sending it over the internet.

## compression and decompression
- Compression is a technique to reduce the size of data sent over the network.
- receiver can decompress it using the same algorithm used by sender.
